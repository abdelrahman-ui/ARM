/****************************************************************
 ************  - UART_private.h				   ******************
 ***********   -Created: 3/18/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********								   ******************
 ****************************************************************/

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/

/*****************************************************************
		*  The Archictect Give The API
						- The Name Of Function
						- What is The Input
						- What Is The Output
******************************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR[3];
	volatile u32 GTPR;
}USART_Register;


#define 	USART1 		((USART_Register *) 0x40013800)

#endif
