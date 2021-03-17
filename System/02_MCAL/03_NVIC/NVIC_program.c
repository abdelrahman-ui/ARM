/****************************************************************
 ************   -NVIC_program.c                ******************
 ***********					   		       ******************
 ***********   -Created: 2/3/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 

/****************************************************************
***********  Function _ Implementtion  *************
******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface .h"
#include "NVIC_private.h"
#include "NVIC_config.h"


/************************************************************************************************************************************************************************************/
  
  
  // Function To Set The Interrput Bit Only Give Me The Interrput NUM  1 = SET & 0 = N0 effect(not Disable )

	void MNVIC_voidEnableInterrupt (u8 Copy_u8InterrputNum)								// Why u8 !!? Beacuse I'm From 0 To 239 Only 
	{
		if( Copy_u8InterrputNum <=31 )													// I'm Not Need To cheek if num >= 0 Beacuse it's (u){0:256} So always bigger or equal 0
			{
				//SET_BIT(NVIC_ISER0,Copy_u8InterrputNum);								// From 0:31 Go to ISER0 & Set bit NUM =Copy_u8InterrputNum
				// shift in high speed more than set beacuse of set is 3 assembly operation
				NVIC_ISER0 =(1<<Copy_u8InterrputNum) ; 
			}
		else if( Copy_u8InterrputNum <=59 )												// Sure if not enter  in if so the num >31 So why cheek it is always true 
			{
				Copy_u8InterrputNum-=32;										        // Wait It 32 in int but in regester 32 =0 So the INT -32
																					    // From 0:31 Go to ISER0 & Set bit NUM =Copy_u8InterrputNum
				NVIC_ISER1 = (1 << Copy_u8InterrputNum );
			}
		else
			{
				/*   Return Error   */
			}	
	
	}
	

/************************************************************************************************************************************************************************************/



  // Function To Disable The Interrput Bit Only Give Me The Interrput NUM  1 = Disable & 0 = N0 effect(not Disable )

	  void MNVIC_voidDisableInterrupt( u8 Copy_u8InterrputNum)							/* The Same Comment of MNVIC_Enable	*/		
	  {
		  
		  if( Copy_u8InterrputNum <=31 )													
		  {
			  NVIC_ICER0 = ( 1<<Copy_u8InterrputNum ) ;									/* The Same Comment of MNVIC_Enable	*/
		  }
		  else if( Copy_u8InterrputNum <=59 )												
		  {
			  Copy_u8InterrputNum-=32;										       
		  
			  NVIC_ICER1 = ( 1 << Copy_u8InterrputNum );
		  }
			  																		  /* The Same Comment of MNVIC_Enable	*/
		 else
			  {
				  /*   Return Error   */
			  }
		  
	    }
	  
	  

/************************************************************************************************************************************************************************************/


 // Function To Set The Pendding Flag  Used It For Testing  or Dibugging 
 
	void MNVIC_voidSetPendingFlag( u8 Copy_u8InterrputPendingBit)
	 {
		 
		 if( Copy_u8InterrputNum <=31 )
		 {
			 
			 NVIC_ISPR0 = ( 1<< Copy_u8InterrputPendingBit ) ;									/* The Same Comment of MNVIC_Enable	*/
		
		 }
		 
		 else if( Copy_u8InterrputNum <=59 )
		 {
			 
			 Copy_u8InterrputNum-= 32;
			 
			 NVIC_ISPR1 = ( 1 << Copy_u8InterrputPendingBit );
			 
		 }
		 /* The Same Comment of MNVIC_Enable	*/
		 else
		 {
			 /*   Return Error   */
		 }
		 
	 }
	 
	 
/************************************************************************************************************************************************************************************/


// Function To Clear The Pendding Flag  Used It For Testing  or Dibugging

void MNVIC_voidClearPendingFlag( u8 Copy_u8InterrputPendingBit)
{
	
	if( Copy_u8InterrputNum <=31 )
	{
		
		NVIC_ICPR0 = ( 1<< Copy_u8InterrputPendingBit ) ;									/* The Same Comment of MNVIC_Enable	*/
		
	}
	
	else if( Copy_u8InterrputNum <=59 )
	{
		
		Copy_u8InterrputNum-= 32;
		
		NVIC_ICPR1 = ( 1 << Copy_u8InterrputPendingBit );
		
	}
	/* The Same Comment of MNVIC_Enable	*/
	else
	{
		/*   Return Error   */
	}
	
}


/************************************************************************************************************************************************************************************/


// Function To See The INT Excuit NOW Or Not

u8 MNVIC_voidGetActiveFlag( u8 Copy_u8InterrputActiveBit)
{
	u8 Local_u8Result ;
	if( Copy_u8InterrputNum <=31 )
	{
		
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8InterrputActiveBit);									/* The Same Comment of MNVIC_Enable	*/
		
	}
	
	else if( Copy_u8InterrputNum <=59 )
	{
		
		Copy_u8InterrputNum-= 32;
		
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8InterrputActiveBit);
		
	}
	/* The Same Comment of MNVIC_Enable	*/
	else
	{
		/*   Return Error   */
	}
	
	return Local_u8Result ;
	
}


/************************************************************************************************************************************************************************************/

 //Function To SET interrput Priority of Group and sub 
 // Give Me The ID of Interrput And The Priority Of( Groub And sub ) of this Interrput 
	void MNVIC_voidSetPriority(s8 Copy_s8InterrputID, u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority,u32 Copy_u8GroupAndSubNum )    // Give Me The Interrput_ID , group and sub
	{	
		/* Check That I'm Core Peripheral Or External Becuse of Core Can Be by NEGATIVE */
		/*EX :   ID = 6 , Group = 1 , Sub = 1, GroupSubNum =   0x05fa0400 = ( 3 group , 1 sub ) */	
		u8 Local_u8Priority = Copy_u8SubPriority |( Copy_u8GroupPriority <<( ( Copy_u8GroupAndSubNum - 0x05FA0300 ) / 256)) ;	// (0x05fa0400 -  0x05FA0300) /0x100 = ( 1 )Shift The( 1 )to write at bit[5:7] The Group Piriority  After That put SubPriority 	in the (1) Which i Was Shift 			 
		if( Copy_s8InterrputID >=0 )				// External 
		{
			IPR[Copy_s8InterrputID]	=(Local_u8Priority << 4)								// Pointer Move  8 bit sheft left 4 bit to not be at reserved
		}
		SCB_AIRCR = Copy_u8GroupAndSubNum  ;
	}
	

/************************************************************************************************************************************************************************************/
	// Anthor Function To	Distribute The Four Bit OF NVIC Priority of sub and group 
	
	void_MNVIC_voidDistributeGroupAndSub(void)
	{
		SCB_AIRCR =  MNVIC_GROUP_SUB_DISTRIBUTION  ;  
	}
	
	void MVIC_voidSetGroupAndSubPriority( u8 Copy_u8PeripheralID  ,u8 Copy_u8Priority)
	{
		if( Copy_u8PeripheralID   <  60 )   // I Have Only 60 External Interrput 
		{
			NVIC_IPR[ Copy_u8PeripheralID ] = Copy_u8Priority ;			// Set Priorit To group and sub of the interrput
			
		}
		else
		{
			/* ERROR */	
		}
	}
/************************************************************************************************************************************************************************************/
