/*
 * main.c
 *
 * Created: 5/26/2021 1:06:58 AM
 *  Author: Abdelrahman_Magdy
 *  Version : _1_

 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "USART_interface.h"
#include "FPEC_interface.h"

void Parser_voidParseRecord(u8* Copy_u8BufData);

volatile u8  u8RecBuffer[100]   ;
volatile u8  u8RecCounter    = 0;
volatile u8  u8TimeOutFlag   = 0;
volatile u16 u16TimerCounter = 0;
volatile u8  u8BLWriteReq    = 1;
typedef void (*Function_t)(void);				// Pointer To Func
Function_t addr_to_call = 0; // The Type of That Varible it is pointer to func

void func(void)
{
#define SCB_VTOR   *((volatile u32*)0xE000ED08)
	// 0x08001000 Is The Address Of Vector Table
	SCB_VTOR = 0x08001000;
	// 0x08001004 Is The Address Of Start Up Code
	addr_to_call = *(Function_t*)(0x08001004); //The Frist Address In THe Flash @ App Area The Frist Adress Have The Reset Address (0x0800 1000 ) Init The Stack Pointer So The App Area Will Start From 0x0800 1004
	addr_to_call();
}


void main(void)
{
	u8 Local_u8RecStatus;

	RCC_voidInitSysClock();			  			/* Init CLK HSI  */
	RCC_voidEnableClock(RCC_APB2,14); 			/*  EN USART1	 */
	RCC_voidEnableClock(RCC_APB2,2);  			/*  EN PortA  	 */
	RCC_voidEnableClock(RCC_AHB,4);   			/*  EN FPEC  	 */

	//	The Dir of uart 1
	MGPIO_VidSetPinDirection(GPIOA,9,0b1010);   /* TX AFPP -->A9 */
	MGPIO_VidSetPinDirection(GPIOA,10,0b0100);  /* RC Input Floating  ---> A10 */
	/* BR 9600 EN--(RX,TX) */
	MUSART1_voidInit();

	MSTK_voidInit();
	 /* Sleep To 15 Sec After Call Func wating TO NOT JUMP APP Without finsh bootloader   */
	MSTK_voidSetIntervalSingle(15000000,func);

	while(u8TimeOutFlag == 0)
	{

		Local_u8RecStatus = MUSART1_u8Receive( &(u8RecBuffer[u8RecCounter]) );
		if (Local_u8RecStatus == 1)					/*	 If You Receive 	*/
		{
			MSTK_voidStopInterval();				/* Stop The Timer	After Receive 	*/

			if(u8RecBuffer[u8RecCounter] == '\n')	/* Wait Untile The End Of Buffer */
			{
				/* Must Be After Frist Record Becuse If There Is No Record If It Before Record It Will delet The Flash Always
				   After Receive All Frist Record
				   Need To Clear The Flash Memory efore Write On It It Will Give Error
				   So The Best Place Of That Delet Here  */
				if (u8BLWriteReq == 1)					/* If you receive from uart  frist recored only */
				{
					FPEC_voidEraseAppArea();			// It Erase From Page 4 To 63
					u8BLWriteReq = 0;					// It Will Be Ture Frist Time Only will never retrune zero
				}
				
				/* Parse one recored  */
				Parser_voidParseRecord(u8RecBuffer);		// Parsing or flashing one record of the flash
				MUSART1_voidTransmit("ok");					// After Flashing The Record Send ok
				u8RecCounter = 0;
			}

			else
			{
				u8RecCounter ++ ;		// Move The Second line Until Recevice The Frist '\n' From Here You REC frist Line Record
			}

			MSTK_voidSetIntervalSingle(15000000,func);
		}

		else
		{
				/*	Nothing To Receive	*/
		}
	}
}
