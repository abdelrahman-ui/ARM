/****************************************************************
 ************   - OS_SCHADULER_interface.h        ******************
 ***********					   		       ******************
 ***********   -Created: 2/19/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/ 

/*****************************************************************
		* What i sell To Customer
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
******************************************************************/


#ifndef SCHADULER_INTERFACE_H
#define SCHADULER_INTERFACE_H



	// Function To Creat Task Take The Preiority Of The Function & The Priodicity :  How Many The Function Repeated  And Poiter To Function Of Task 
	void SOS_voidCreatTask (u8 Copy_u8Preiority , u16 Copy_Priodicity , void (*PointerToFunction)(void) ) ;
	
	//  Function To START The Task
	void SOS_voidStartTask (void) ;

#endif //SCHADULER_INTERFACE_H