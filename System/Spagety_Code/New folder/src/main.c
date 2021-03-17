/****************************************************************
 ************  - NEC_PROTOCOL_ RGB_LED         ******************
 ***********					   		       ******************
 ***********   -Created: 2/18/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********								   ******************
 ****************************************************************/

		/***************	 INCLUDE LIB	  ***************/

#include "STD_TYPES.h"

#include "BIT_MATH.h"

		/***************	INCLUDE MCAL	 ***************/

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "EXTI0_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

volatile u8 u8StartFlag		 = 0; 			// To Know That Is The Frist Falling edage Or Onther ONE

volatile u32 u32FramData[50]  = {0};

volatile u8 u8EdgeCounter	 = 0 ;
volatile u8 u8Data           = 0 ;

// Function Will Call After Fram End So Analyez It Here data only So i will Start From 17
void voidTakeAction(void)
{
	u8 i = 0;
	u8Data = 0 ;

	if ( (u32FramData[0] >=10000) &&  (u32FramData[0] >=14000) )  // Check  The Start Fram in Avarage of 13500 if in Range
	{
		for( i=0 ; i<8 ;i++)
		{
			if (  (u32FramData[17+i] >= 2000 ) && (u32FramData[17+i] <= 2300 )
			{
				SET_BIT(u8Data , i);
			}
			else
			{
				CLR_BIT(u8Data , i);
			}
		}


	}
	else
	{
		/* Invalid Fram */
	}
	/* To have Anthor One*/
	u8StartFlag = 0 ;
	u8EdgeCounter= 0 ;
	u32FramData[0] =0 ;
}

void voidGetIRFram(void)
{
	if (u8StartFlag == 0 )
	{
	 /* That eql  That is The Frist Falling Edage So Start Timer*/
		/* OPEN TIMER AND COUNT 1 SEC */
		MSTK_voidSetIntervalSingle(1000000 , voidTakeAction) ;    // resate timer  1SEC is big number to not make over flow
		u8StartFlag = 1  ;

	}
	else
	{
		/* Count The Time  FROM EVERY FALLING Edge */
		u32FramData[u8EdgeCounter] =  MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000 , voidTakeAction) ;    // resate timer  1SEC is big number to not make over flow
		u8EdgeCounter ++;

	}


}




void main (void)
{
	/* RCC Intialize  Clock */
	RCC_voidInitSysClock();
	/*	Eable Clock TO GPIO  */
	RCC_voidEnableClock(RCC_APB2 , 2);						  // 8 MHZ
	/* IO_PINS Direction*/
	MGPIO_VidSetPinDirection(GPIOA ,0 ,0b0100);			  	  //A0 IS INPUT FLOATIOG : To sense 1 0
	MGPIO_VidSetPinDirection(GPIOA ,1 ,0b0010);				  //A1 IS OUTPUT PUSH PULL  RED_LED
	MGPIO_VidSetPinDirection(GPIOA ,2 ,0b0010);				  //A2 IS OUTPUT PUSH PULL  GREEN_LED
	MGPIO_VidSetPinDirection(GPIOA ,3 ,0b0010);				  //A3 IS OUTPUT PUSH PULL  BLUE_LED


	/* EXTI */
	MEXTI_voidSetCallBack(voidGetIRFram);				     //When INT Call back THIS FUNCTION
	MEXTI_voidInit();										 // Choice The Line And Falling , Rising or onchange  From Config.h

	/* Enable EXTI0 From NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6);							// 6 = EXTI0

	/* INIT STK */
	MSTK_voidInit();										// AHB / 8 = 1 MICRO SEC

	while(1)
	{


	}


}

