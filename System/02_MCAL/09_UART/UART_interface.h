/****************************************************************
 ************   - UART_interface.h		        ******************
 ***********					   		        ******************
 ***********   - Created: 3/18/2021			    ******************
 ***********   - Author: Abdelrahman_Magdy      ******************
 ***********   - Version : _1_				    ******************
 ***********  -								    ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/ 


#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void MUART1_voidInit(void)			;
void MUART1_voidTransmit(u8 arr[])  ;
u8	 MUART1_u8Receive(void)			;


#endif // UART_INTERFACE_H