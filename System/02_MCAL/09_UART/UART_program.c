/****************************************************************
 ************   - UART_program.c		       ******************
 ***********					   		       ******************
 ***********   - Created: 3/18/2021		       ******************
 ***********   - Author: Abdelrahman_Magdy     ******************
 ***********   - Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/ 

/************** INCLUDE LIB **************/
 #include "STD_TYPE.h"
 #include "BIT_MATH.h"
/************** INCLUDE MCAL**************/
#include "UART_private.h"
#include "UART_interface.h"
#include "UART_config.h"
/*****************************************/


/******************************************* Start_FUNCTION  *******************************************/
 void MUART1_voidInit(void)			
 {
	 /* BOUD Rate = 0x341 = 9600    */
	UART_1_t ->BRR = 0x341 ;
	
	/*
	 ENABLE_RX  ,  ENABLE_TX  ,  ENABLE_UART  
	*/
	
	SET_BIT(UART_1_t ->CR1 , ENABLE_UART) ;
	SET_BIT(UART_1_t ->CR1 , ENABL3E_TX ) ;
	SET_BIT(UART_1_t ->CR1 , ENABLE_RX )  ;
	
	/* 
	 Clear All The Status Register
	*/
	UART_1_t -> SR = 0 ;
	
	 
 }
/*******************************************  END_ FUNCTION  *******************************************/



/******************************************* Start_FUNCTION  *******************************************/
 void MUART1_voidTransmit(u8 arr[])  
 {
	  u8 i =0 ; 
	 while(arr[i] != '\0')
	 {
		 UART_1_t -< arr[i];
		/*Check & Clear The Flag Of Transmition Is Complete  */
		/* (GET_BIT(UART_1_t ->SR , TC_FLAG) == 0 ) ; */
		while (((UART_1_t ->SR) & 0x40 ) == 0 );
		i++ ; 
	 }
	 
 }
/*******************************************  END_ FUNCTION  *******************************************/



/******************************************* Start_FUNCTION  *******************************************/
 u8	 MUART1_u8Receive(void)			
 {  
	 
	 /* Wait  Receive Complete */
	 while (((UART_1_t ->SR) & 1<< RXNE_FLAG)==0)) ; 
	 return (0xff & (UART_1_t ->SR));		// To be Only 8 bit Only 0xff 
 }
/*******************************************  END_ FUNCTION  *******************************************/
 