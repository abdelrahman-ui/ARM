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


#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

typedef struct{

	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;

}USART_Type;


#define MUSART1 ( ( volatile USART_Type* ) 0x40013800 )

#define MUSART2 ( ( volatile USART_Type* ) 0x40004400 )

#define MUSART3 ( ( volatile USART_Type* ) 0x40004800 )

#define MUART4 (  ( volatile USART_Type* ) 0x40004C00 )

#define MUART5 (  ( volatile USART_Type* ) 0x40005000 )

#endif /* UART_PRIVATE_H*/
