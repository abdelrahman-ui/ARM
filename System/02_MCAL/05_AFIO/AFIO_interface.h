/****************************************************************
 ************   -AFIO_interface.h              ******************
 ***********					   		       ******************
 ***********   -Created: 2/6/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  -								  ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

//	Function Take Line & PIN To Be EXTI To Make Pin As EXTI
void MAFIO_voidSetExtiPin(Copy_u8Line ,Copy_u8PortMap);


#endif //AFIO_INTERFACE_H