/****************************************************************
 ************   -NVIC_interface.h              ******************
 ***********					   		       ******************
 ***********   -Created: 2/3/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 

//Here What I'M sell
 
/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/

// What i Sell 

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

  // Function To Set The Interrput Bit Only Give Me The Interrput NUM  1 = SET & 0 = N0 effect(not Disable )
		void MNVIC_voidEnableInterrupt (u8 Copy_u8InterrputNum);
		
  // Function To Disable The Interrput Bit Only Give Me The Interrput NUM  1 = Disable & 0 = N0 effect(not Disable )
       void MNVIC_voidDisableInterrupt (u8 Copy_u8InterrputNum)	;
	   
  // Function To Set The Pendding Flag  Used It For Testing  or Dibugging
	   void MNVIC_voidSetPendingFlag( u8 Copy_u8InterrputPendingBit);
	   
  // Function To Clear The Pendding Flag  Used It For Testing  or Dibugging
	   void MNVIC_voidClearPendingFlag( u8 Copy_u8InterrputPendingBit);
	   
  // Function To See The INT Excuit NOW Or Not
	   u8 MNVIC_voidGetActiveFlag( u8 Copy_u8InterrputActiveBit);
	   
   /*
    To Disterpute Group And Sub And Anthor One To SET Priority i can use :
	
      void MNVIC_voidSetPriority(s8 Copy_s8InterrputID, u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority,u32 Copy_u8GroupAndSubNum );
			OR 
	  void_MNVIC_voidDistributeGroupAndSub(void);
	  void MVIC_voidSetGroupAndSubPriority( u8 Copy_u8PeripheralID  ,u8 Copy_u8Priority);
		
   */
   //Function To SET interrput Priority of Group and sub
   // Give Me The ID of Interrput And The Priority Of( Groub And sub ) of this Interrput
   void MNVIC_voidSetPriority(s8 Copy_s8InterrputID, u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority,u32 Copy_u8GroupAndSubNum ); 
	
	// Two Funtion One To Disterpute Group And Sub And Anthor One To SET Priority 
	void_MNVIC_voidDistributeGroupAndSub(void);
	void MVIC_voidSetGroupAndSubPriority( u8 Copy_u8PeripheralID  ,u8 Copy_u8Priority);
	
	
 
		/*	
	 // PassWord =0x{05fa}0[3:7]00
		#define  GroupAndSubNum_3			0x05fa0300					// PassWord + 4 Bits For group And 0 For Sub In  IPR []
		#define  GroupAndSubNum_4			0x05fa0400					// PassWord + 3 Bits For group And 1 For Sub In  IPR [] 
		#define  GroupAndSubNum_5			0x05fa0500					// PassWord + 2 Bits For group And 2 For Sub In  IPR [] 
		#define  GroupAndSubNum_6			0x05fa0600					// PassWord + 1 Bits For group And 3 For Sub In  IPR []
		#define  GroupAndSubNum_7			0x05fa0700					// PassWord + 0 Bits For group And 4 For Sub In  IPR [] 
		
		*/

#endif //NVIC_INTERFACE_H