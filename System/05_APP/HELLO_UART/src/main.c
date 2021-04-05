/*
 * main.c
 *
 *  Created on: Mar 19, 2021
 *      Author: Abdelrahman_Magdy
 */
/************** INCLUDE LIB **************/
 #include "STD_TYPE.h"
 #include "BIT_MATH.h"
/************** INCLUDE MCAL**************/
#include "UART_private.h"
#include "UART_interface.h"
#include "UART_config.h"
#include "RCC_interface.h"
#include "DIO_interface .h"
/*****************************************/

int main (void)
{
	u8 x ;
	/* 8 MHZ */
	RCC_voidInitSysClock(void) ;
	/* EN GPIOA  At APB2 */
	RCC_voidEnableClock (RCC_APB2 , 2);
	/* EN UART   At APB2*/
	RCC_voidEnableClock (RCC_APB2 , 14);
	/*	A9 = TX ( OUTPUT ) */
	GOIP_voidSetPinDirection(GPIOA ,PIN9,OUTPUT_SPEED_50MHZ_PP)  ;
	/* A10 =RX ( INPUT FLOATING )	*/
	GOIP_voidSetPinDirection(GPIOA ,PIN10,INPUT_FlOAting)  ;
	/* Init For UART */
	MUART1_voidInit(void);
	/* LED ON PIN0 DIR*/
	GOIP_voidSetPinDirection(GPIOA ,PIN0,OUTPUT_SPEED_2MHZ_PP)
	while(1)
	{
		/* Send A*/
		MUART1_voidTransmit("97") ;
		x = MUART1_u8Receive(void);
		if ( x == '5')
		{
			/* Open Led on PIN0 */
			GOIP_voidSetPinValue(GPIOA ,PIN0,HIGH)  ;
		}
		else if ( x== 'R')
		{
			/* OFF Led on PIN0 */
			GOIP_voidSetPinValue(GPIOA ,PIN0,LOW)  ;

		}
	}
	return 0 ;
}



