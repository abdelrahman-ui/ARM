/****************************************************************
 ************   -EXIT_config.h                  ******************
 ***********					   		       ******************
 ***********   -Created: 2/3/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _2_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/

/*************	File Which Devlopper Can Choise From it To Config=Init	**************/

#ifndef EXIT_CONFIG_H
#define EXIT_CONFIG_H

/* 
Option Of EXTI_Line :

		- EXTI_LINE0
		- EXTI_LINE1
		- .
		- .
		- .
		- .
		- .
		- .
		- EXTI_LINE14
		- EXTI_LINE15

*/
	#define EXTI_Line				    LINE_0     

/* 
Option Of EXIT_Sense_Mode :
		
		- Rising_Edage			
		- Falling_Edage			    
		- ON_Change			

*/
	#define EXIT_Sense_Mode				Rising		
	

#endif //EXIT_CONFIG_H	