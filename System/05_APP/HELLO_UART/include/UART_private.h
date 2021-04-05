/****************************************************************
 ************  - UART_private.h				   ******************
 ***********					   		       ******************
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

typedef struct 
{
	volatile 32 SR		;
	volatile 32 DR		;
	volatile 32 BRR		;
	volatile 32 CR1		;
	volatile 32 CR2		;
	volatile 32 CR3		;
	volatile 32 GRPR	;

	}UART_1_t;
	
#define  BASS_ADDRESS_UART_1_		((volatile UART_1_t *)0x40013800)		 

#define  ENABLE_RX		2
#define  ENABLE_TX		3
#define  ENABLE_UART	13
#define  TC_FLAG		6
#define  RXNE_FLAG		5

#endif // UART_PRIVATE_H
