/*
 * main.c
 *
 *  Created on: Mar 9, 2021
 *      Author: Abdelrahman_Magdy
 */

#include "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "RCC_interface.h"
#include  "DIO_interface .h"
#include  "STK_interface.h"

#include "file.h"

// that is wrong but for time
#include "DIO_private.h"
volatile u16 i ;

void voidSetDAC (void)
{
	GPIOA_ODR = x_raw[i];
	i++ ;
	if (i ==33622 )
	{
		i=0;
	}
}


void main (void)
{
	// The Clock 8MHZ
	RCC_voidInitSysClock();
	// EN Clock at GPIO A
	RCC_voidEnableClock(RCC_APB2,2) ;

	// SET Pin DIR 2MHZ
	GOIP_voidSetPinDirection(GPIOA, 0 , 0b0010);
	GOIP_voidSetPinDirection(GPIOA, 1 , 0b0010);
	GOIP_voidSetPinDirection(GPIOA, 2 , 0b0010);
	GOIP_voidSetPinDirection(GPIOA, 3 , 0b0010);
	GOIP_voidSetPinDirection(GPIOA, 4 , 0b0010);
	GOIP_voidSetPinDirection(GPIOA, 5 , 0b0010);
	GOIP_voidSetPinDirection(GPIOA, 6 , 0b0010);
	GOIP_voidSetPinDirection(GPIOA, 7 , 0b0010);

	// Init STK CLOCK TICK = 1 MICRO
	MSTK_voidInit(void);
	// SET tHE Periodic 125 micro And call back fun
	MSTK_voidSetIntervalPeriodic(125 , voidSetDAC);

	while (1);



}
