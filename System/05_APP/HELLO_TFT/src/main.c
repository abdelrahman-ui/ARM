
/************** INCLUDE LIB **************/
 #include "STD_TYPE.h"
 #include "BIT_MATH.h"
/************** INCLUDE MCAL**************/
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"
/************** INCLUDE HCAL**************/
#include "TFT_interface.h"

/* const u16 image[] {}; */

void main (void)
{

	/*RCC init */
	RCC_voidInitSysClock();

	/* EN Clock  SPI1 , GPIOA*/
	RCC_voidEnableClock(RCC_APB2 , 2) ;						//GPIO
	RCC_voidEnableClock(RCC_APB2 , 12) ;					//SPI1

	/* PIN Init */
	MGOIP_voidSetPinDirection(GPIOA , 1 , 0b0010 );			// A0 		OUTPUT PUSH PULL 2M
	MGOIP_voidSetPinDirection(GPIOA , 2 , 0b0010 ); 		// RESAT 	OUTPUT PUSH PUL 2M
	MGOIP_voidSetPinDirection(GPIOA , 5 , 0b10001 );		// CLK		Altrantive Fun Push Pull 10M
	MGOIP_voidSetPinDirection(GPIOA , 7 , 0b1001);			// MOSI		Altrantive Fun Push Pull 10M

	/* Init STK */
	MSTK_voidInit();
	/* Init SPI */
	MSPI1_voidInit();
	/* Init TFT */
	HTFT_voidInit();
	/* Display Image */
	HTFT_voidDisplayImage(image);
	while(1)
	{


	}

}


