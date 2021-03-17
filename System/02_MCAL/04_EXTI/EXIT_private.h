/****************************************************************
 ************  - EXIT_private                  ******************
 ***********   - Struct_Design		            ******************
 ***********   - Created: 2/3/2021			    ******************
 ***********   - Author: Abdelrahman_Magdy      ******************
 ***********   - Version : _2_				    ******************
 ***********   - Using Pre_build Configeration  ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/ 

	/*******	Defination The Register   *******/ 

#ifndef EXIT_PRIVATE_H
#define EXIT_PRIVATE_H

	static void (*EXTI0_CallBack) =  NULL ;

   typedef struct 
		{
			/*  	Must be arranged like register map		*/
			
						volatile  u32   IMR		;				// From Here Choice The Line
						volatile  u32   EMR		;				// FOR Event Mask
						volatile  u32   RTSR	;				// For Enable or Disable Raising Trigger For Line
						volatile  u32   FTSR	;				// For Enable or Disable Falling Trigger For Line
						volatile  u32   SWIER   ;				// For The SoftWare Interrput Event 
						volatile  u32   PR		;				// For The Pending 
		}EXTI_t;																					// The New Data Type Of That Struct 


	#define Base_Adress_EXIT			      0X40010400										//From Memory Map 
	
	#define EXTI_Ptr 					 ( ( volatile  EXTI_t * ) Base_Adress_EXIT )			// Pointer Point To EXTI_t ( The Struct ) Casting Pointer To Struct Point To The Frist base  Address Without Dereferance (It is A Pointer )
	
		 /*****  The Line ******/
	
	#define LINE_0			0
	#define LINE_1			1
	#define LINE_2			2
	#define LINE_3			3
	#define LINE_4			4
	#define LINE_5			5
	#define LINE_6			6
	#define LINE_7			7
	#define LINE_8			8
	#define LINE_9			9
	#define LINE_10			10
	#define LINE_11			11
	#define LINE_12			12
	#define LINE_13			13
	#define LINE_14			14
	#define LINE_15			15
	
	
		/******	  Sense_Mode	 ******/
	
	#define Rising_Edage				0
	#define Falling_Edage			    1
	#define On_Change		`			2									// Any Change Happen
	
#endif //EXIT_PRIVATE_H