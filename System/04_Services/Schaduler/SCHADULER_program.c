/****************************************************************
 ************   -OS_SCHADULER_program.c           ******************
 ***********					   		       ******************
 ***********   -Created: 2/19/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/ 

/*********		INCLUDING LIB		   ***********/
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	
/*********	  INCLUDING MCAL			***********/
	#include "STK_interface.h"
/*********	  INCLUDING SYSTEM LAYER	***********/
	#include "SCHADULER_interface.h"
	#include "SCHADULER_private.h"
	#include "SCHADULER_config.h"
	
	
	// Array Of Struct to Preiority 
	static Task OS_Tasks[NUM_OF_TASK] = {	NULL	} ;				//Static : 
		
	// Function To Creat Task
	
		void SOS_voidCreatTask (u8 Copy_u8Preiority , u16 Copy_Priodicity , void (*PointerToFunction)(void) )
	{
		OS_Tasks[Copy_u8Preiority].priodicity = Copy_Priodicity ;
		OS_Tasks[Copy_u8Preiority].Fptr = PointerToFunction ;
	}
	
	//
	void SOS_voidStartTask (void)
	{
		/***  Intialization  ***/
		// Determines The Tick Time By SYSTICK
		MSTK_voidInit();
		/*	 Make STK 1 msec And PRIODIC	*/
		/* HSE 8MHZ / 8 = 1 Micro sec So Div 1000 To Be 1msec */
		/* Pointer To Static Function Schaduler */			// Static Becuse No one Can Used IT Anthor OS FILE
		MSTK_voidSetIntervalPeriodic(1000 , Schaduler );
	}
	
	// Every 1msec This Function Will Be Call  Which Order The TASK
	// VAR will Count Every Time I Go Inside SCHADULER To Know  Priodicity Now Or Not 
	volatile  u16 Tick_Count = 0 ;							// Volatile Because Shaduler Is Function Will Call In ISR
	void Schaduler (void)
	{
		
		for( u8 i = 0 ; i < NUM_OF_TASK ; i++ )				// Loop To Arrange Take  By It's Preiority And Priodicity
		{
			if ((Tick_Count % OS_Tasks[i].priodicity )== 0)	// If It is Time Call Task
			{
				OS_Tasks[i].Fptr ();						// Do The Function Of This Task 
			}
		}
		Tick_Count++ ;
	}