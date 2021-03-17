/****************************************************************
 ************   -NVIC_config.h                  ******************
 ***********					   		       ******************
 ***********   -Created: 2/3/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/


// Developer can Edit in it 
// Here You Not Need TO Rcc Beacuse It's Core_Periphreral Of ARM 

#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

		/*
		
		 Options : 
		 
				#define MNVIC_GROUP_4_SUB_0			
				#define MNVIC_GROUP_3_SUB_1			
				#define MNVIC_GROUP_2_SUB_2			
				#define MNVIC_GROUP_1_SUB_3			
				#define MNVIC_GROUP_0_SUB_4		

		*/
#define  MNVIC_GROUP_SUB_DISTRIBUTION		MNVIC_GROUP_2_SUB_2          

		

  

#endif //NVIC_CONFIG_H