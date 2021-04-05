/****************************************************************
 ************   - STK_interface.h                  ******************
 ***********					   		       ******************
 ***********   -Created: 2/9/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/ 

/**************		The Archictect Give The API		**************/


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H
	
	
	
		
/*	1- Function Only Apply The Clock From Configer (AHB or(AHB/8)) & Disable SysTick Interrupt & Disable SysTick  */
			
				void MSTK_voidInit(void);
				
/* 2-  Function Take Count or Ticks So Timer Count Them And you Config ( Tick =Time )     */

				void MSTK_voidSetBusyWait( u32 Copy_u8Ticks);
				
/* 3- Function Asynchronous Take Tick And Start To Count Them , Give Flag And Work One Time ,
		And Give Me Function And i Will Resive In Pointer To Function To Call it After Counting Ticks .
		I Will Tick The Adress Of Function And Give It To Global Var ( Call back )  And ISR D o this Func */				
				
				void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void ( *Copy_ptr ) ( void ));
				
/* 4- The Same Of Function (3) But Only Differant At ISR Will Not Mack Load And Value = 0 */
										
		       void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void ( *Copy_ptr ) ( void ));
		
/* 5- Function Will Stop The Interval If It Was Periodic  */

			   void MSTK_voidStopInterval(void) ;
			   
/* 6- Function  Return The Elapsed Time From Start To Count */
			   
			   u32 MSTK_u32GetElapsedTime(void) ; 
			   
/* 7- Function  Return The Remaining Time To Make ISR */
				
				u32 MSTK_u32GetRemainingTime(void) ;

#endif //STK_INTERFACE_H
