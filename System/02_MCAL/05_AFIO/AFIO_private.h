/****************************************************************
 ************   -AFIO_private.h                  ******************
 ***********					   		         ******************
 ***********   -Created: 2/6/2021			     ******************
 ***********   -Author: Abdelrahman_Magdy        ******************
 ***********   -Version : _1_				     ******************
 ***********  -	     						   	 ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/


#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

	typedef struct{
		
	volatile u32 EVCR ;
	volatile u32 MAPR ;
	volatile u32 EXTICR[4]; 
	volatile u32 MAPR2 ;
		
		 }AFIO_t; 


	#define  AFIO_BASE_ADRESS						0X40010000
	#define AFIO_ptr					((volatile AFIO_t *)AFIO_BASE_ADRESS)
	
#endif //AFIO_PRIVATE_H