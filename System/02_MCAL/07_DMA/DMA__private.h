/****************************************************************
 ************  - DMA_private.h				   ******************
 ***********					   		       ******************
 ***********   -Created: 3/10/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********								   ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/ 

/*****************************************************************
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
******************************************************************/


#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H


	// STRUCT OF GRPOUP REGESTER
	typedef struct 
	{
		volatile u32 CCR			;				/* */
		volatile u32 CNDTR			;				/* */
		volatile u32 CPAR			;				/* */
		volatile u32 CMAR			;				/* */
		volatile u32 Reserved		;				// Reserved  Must be here 
		 } DMA_Channel_t;
		 
	// STRUCT OF REGESTER
	typedef struct
	{
		volatile u32 ISR		    ;				// FOR ALL CHANNEL  /* */ 
		volatile u32 IFCR		    ;				// FOR ALL CHANNEL  /* */ 
		DMA_Channel_t Channel[7]	;				// FOR EVERY CHANNEL HAVE 5 REGISTER { CCR , CPAR ,CMAR , CNDTR , Reserved } 
		} DMA_t;																		   	
		
	// BASE ADDRESS
	
	#define  DMA_BASS_ADRESS		 ((volatile DMA_t *)0x40020000)																					  