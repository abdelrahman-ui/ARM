/****************************************************************
 ************   -EXTI_program.c                ******************
 ***********					   		       ******************
 ***********   -Created: 2/3/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _2_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 

/****************************************************************
***********  Function _ Implementtion  *************
******************************************************************/

/**************************		_INCLUDING_		**************************/

  /**************  Liberary	**************/
  
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
			
  /**************	 MCAL	**************/
      
    #include "EXTI_interface.h"
    #include "EXTi_config.h"
    #include "EXTi_private.h"
	  
  /**************	 HAL	**************/
  
	/****** I'm In MCAL ******/
	
  /**************	 APP	**************/
	
	/****** I'm In MCAL ******/


	/***********************************************_Start_Function_***********************************************/

	 /* Check About Mode And Line From #define  At Config.h */
	 /* The Prob of #def I will*/
 
		void MEXTI_voitInit(void)  
		{
	/***************************	FOR_EXTI_LINE	***************************/
	/* Not Good TO Turn On Line At Initlizaion It is POWER Consumssion So  */

			#if		EXTI_Line ==	LINE_0
				SET_BIT(EXTI_Ptr->IMR , LINE_0) ;
		
			#elif	EXTI_Line ==	LINE_1
				SET_BIT(EXTI_Ptr->IMR , LINE_1) ;
		
			#elif	EXTI_Line ==	LINE_2
				SET_BIT(EXTI_Ptr->IMR , LINE_2) ;
		
			#elif	EXTI_Line ==	LINE_3
				SET_BIT(EXTI_Ptr->IMR , LINE_3) ;
		
			#elif	EXTI_Line ==	LINE_4
				SET_BIT(EXTI_Ptr->IMR , LINE_4) ;
		
			#elif	EXTI_Line ==	LINE_5
				SET_BIT(EXTI_Ptr->IMR , LINE_5) ;
		
			#elif	EXTI_Line ==	LINE_6
				SET_BIT(EXTI_Ptr->IMR , LINE_6) ;
		
			#elif	EXTI_Line ==	LINE_7
				SET_BIT(EXTI_Ptr->IMR , LINE_7) ;
		
			#elif	EXTI_Line ==	LINE_8
				SET_BIT(EXTI_Ptr->IMR , LINE_8) ;
		
			#elif	EXTI_Line ==	LINE_9
				SET_BIT(EXTI_Ptr->IMR , LINE_9) ;
		
			#elif	EXTI_Line ==	LINE_10
				SET_BIT(EXTI_Ptr->IMR , LINE_10) ;
		
			#elif	EXTI_Line ==	LINE_11
				SET_BIT(EXTI_Ptr->IMR , LINE_11) ;
		
			#elif	EXTI_Line ==	LINE_12
				SET_BIT(EXTI_Ptr->IMR , LINE_12) ;
		
			#elif	EXTI_Line ==	LINE_13
				SET_BIT(EXTI_Ptr->IMR , LINE_13) ;
		
			#elif	EXTI_Line ==	LINE_14
				SET_BIT(EXTI_Ptr->IMR , LINE_14) ;
		
			#elif	EXTI_Line ==	LINE_15
				SET_BIT(EXTI_Ptr->IMR , LINE_15) ;
		
			#else
		
				#error "Wrong Mode and Line Choice !!! ";
		
			#endif
		
		
	/***************************	FOR_SENSE_MODE	***************************/

			#if EXIT_Sense_Mode == Rising_Edage						// Notic In Rising 
		
				SET_BIT( EXTI_Ptr -> RTSR, EXTI_Line );	
			
			#elif EXIT_Sense_Mode == Falling_Edage						// Notic In Falling 
		
				SET_BIT( EXTI_Ptr -> FTSR, EXTI_Line );
			
			#elif EXIT_Sense_Mode == On_Change						// Any Logical Change 
		
				SET_BIT( EXTI_Ptr -> FTSR, EXTI_Line );
				SET_BIT( EXTI_Ptr -> RTSR, EXTI_Line );	
			
			#else	#error "Wrong Mode and Sense Mode Choice !!! ";
		
			#endif
			/* At Init Make Disable */
				// CLR_BIT (EXTI_Ptr ->IMR ,EXTI_Line);   // For Power Consumission
			
		}
	
	/*****************************************************END_FUNCTION*****************************************/
							/******************************************************************/
													   /***START_FUNCTION****/
 
 
 
	 /* Give The Function The Line To Enable It IntTERPUT  */
	 
		void MEXIT_voidEnableEXIT(u8 Copy_u8Line) 
		{
		
			SET_BIT (EXTI_Ptr ->IMR ,EXTI_Line);
		
		}
	
	
	
	/*****************************************************END_FUNCTION*****************************************/
										/******************************************************************/
													 /***START_FUNCTION****/
		
		
											
	/* Give The Function The Line To Disable It IntTERPUT  */

	void MEXIT_voidDisableEXIT(u8 Copy_u8Line)
	{
	
		CLR_BIT (EXTI_Ptr ->IMR ,EXTI_Line);
	
	}



	/*****************************************************END_FUNCTION*****************************************/
								/******************************************************************/
													   /***START_FUNCTION****/
											

	 /* Function Make SoftWare INT at Any Line */
		// If Interrput Enable (PIE) ON This Line And EXTI_IMR Line Writing By '1' , When it is Set To '0' Set Corresponding Pending 
		/* IMR = 1 And PR =0 FOR 0:15 Now You Will Have Software Trigger & And It Clear By Put 1 At PR */
	
	 void MEXIT_voidSoftwareInterrput(u8 Copy_u8Line)
	 {
		 SET_BIT(EXTI_Ptr->SWIER , Copy_u8Line);								  // It will Be Clear Alone
	 
	 }
 
	/*****************************************************END_FUNCTION*****************************************/
								/******************************************************************/
													  /***START_FUNCTION****/

		/* Function To Change Mode And Line At RunTime */
		// Signal Latch == Init But Here I can Change The Line And Sense Mode 
	
	 void MEXIT_voidSetSignalLatch( u8 Copy_u8Line,  u8 Copy_u8EXTISenseMode )
	 {
		 SET_BIT(EXTI->IMR ,Copy_u8Line ) ;
	 
		 switch(Copy_u8EXTISenseMode)
		 {
			 case (Rising_Edage):	 SET_BIT( EXTI_Ptr -> RTSR, EXTI_Line );	break;
				
		  
		 
			 case (Falling_Edage):	SET_BIT( EXTI_Ptr -> FTSR, EXTI_Line );	   break;
				

			 case (On_Change) :		SET_BIT( EXTI_Ptr -> FTSR, EXTI_Line );
									SET_BIT( EXTI_Ptr -> RTSR, EXTI_Line );	  break;
		 
		
			 default: 	 
		 }
	 }
 
	 /*****************************************************END_FUNCTION*****************************************/
								/******************************************************************/
													/***START_FUNCTION****/
 //Give Here The Name Of Function But Ptr Is local So we Must define Global Var 
 
	void EXTI_voidSetCallBack( void (*ptr) (void) ,u8 Copy_ExtiBit)
	{
	
		EXTI0_CallBack() =ptr  ;							// Now The Global EXTI0_Call Will Point TO Any Functiom You Will Pass It To Function Only Give Function It's Name 
		
	
	}
	void EXTI0_IRQHandler(void)								// Clear The Pending Bit By Put '1' In PR
	
	{

		EXTI0_CallBack();
		SET_BIT( EXTI->PR , 0 );					// With Out That It Will Do INT Alaways

	}
	
		 /*****************************************************END_FUNCTION*****************************************/