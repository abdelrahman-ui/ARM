/****************************************************************
 ************   - DMA_program.c		           ******************
 ***********					   		       ******************
 ***********   -Created: 3/10/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/ 

#include " STD_TYPES.h"
#include " BIT_MATH.h"

#include " DMA_interface.h"
#include " DMA_private.h"
#include " DMA_config.h"

 // FUNCTION TO INITIALISATION THE CHANNEL
 void MDMA_voidChannelInit(void) 
 {	
	 /* 
	  1- Memory To Memory 
	  2- Very High Priority
	  3- Source Size , Destination Size = 32 bit 
	  4- MINC , PINC Activated
	  5- No circuiler  " NO REPEAT "
	  6- DIR 
	  7- Transfer ISR EN
	 */
	 #if (CHANNEL_ID == 1)
	 DMA -> Channel[0].CCR   ;
 }
 
 //FUNCTION TO To Take The Source And Distination Block Lenght
 void MDMA_voidChannelStart(u32 *Copy_Ptr32SourceAddres , u32 *Copy_Ptr32DistinationAddres ,u16 Copy_u16BlockLenght )
 {
	 // Make Sure Channel Is DIS
	 CLR_BIT( DMA->Channel[CHANNEL_ID].CCR ,0 ) ;
	 
	 // Write Address
	 DMA->Channel[CHANNEL_ID].CPAR =  Copy_Ptr32SourceAddres ;
	 DMA->Channel[CHANNEL_ID].CMAR = Copy_Ptr32DistinationAddres ;
	 
	  // Block Lenght 
	 DMA->Channel[CHANNEL_ID].CNDTR = Copy_u16BlockLenght ;
	 
	 // Make Sure Channel Is EN
	 SET_BIT( DMA->Channel[CHANNEL_ID].CCR ,0 ) ;
	 
 }
