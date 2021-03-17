/****************************************************************
 ************   -NVIC_private                  ******************
 ***********					   		       ******************
 ***********   -Created: 2/3/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 

/****************************************************************
***********  Developer can't Edit in it  **************************
******************************************************************/

	

  #ifndef NVIC_PRIVATE_H
  #define NVIC_PRIVATE_H

/************************** Register _ Defination **************************/ 

		//Base Address			0xE000E100 ;  //Only 7 Register 
		
		#define NVIC_ISER0			*(( u32 * )0xE000E100)					// Enable External INT From	 0 : 31
		#define NVIC_ISER1			*(( u32 * )0xE000E104)					// Enable External INT From	32 : 63
		
		#define NVIC_ICER0			*(( u32 * )0xE000E180)					// Disable External INT From  0 : 31
		#define NVIC_ICER1			*(( u32 * )0xE000E184)					// Disable External INT From  0 : 31

		#define NVIC_ISPR0			*(( u32 * )0xE000E200)					// Enable External Pending Flag From	0  : 31
		#define NVIC_ISPR1			*(( u32 * )0xE000E204)					// Enable External Pending Flag From    32 : 63		
		
		#define NVIC_ICPR0			*(( u32 * )0xE000E280)					// Clear External Pending Flag From	 0  : 31
		#define NVIC_ICPR1			*(( u32 * )0xE000E284)					// Clear External Pending Flag From 32  : 63		
		
		//I Have to Wrire Volatile it is Read Only
		#define NVIC_IABR0			*((volatile u32 * )0xE000E300)			// Clear External Pending Flag From	 0  : 31
		#define NVIC_IABR1			*((volatile u32 * )0xE000E304)			// Clear External Pending Flag From 32  : 63  
		
		#define NVIC_IPR			((volatile u8 *)0xE000E400)				// Without Dereferance I Need it as Pointer Point at The Frist IPR Location and Can acess only 1 Byte Becuse of every 1_byte Refere To Interrput Element 
		
		/*		That not good To Use SCB in NVIC	 	*/ //	 Must be delet after use SCB CODE
		#define SCB_AIRCR		   *( (volatile u8 *)0xE00ED0C)				// The Register Which Have A PassWord To Control The NUM Of (Group & Sub ) In The Four Bit In IPR
		
		/*Group & Sub Num	*/
		
		#define MNVIC_GROUP_4_SUB_0			0x05FA0300					   // Divide The Four Bit To 4 Group And 0 SUB
		#define MNVIC_GROUP_3_SUB_1			0x05FA0400					   // Divide The Four Bit To 3 Group And 1 SUB
		#define MNVIC_GROUP_2_SUB_2			0x05FA0500					   // Divide The Four Bit To 2 Group And 2 SUB
		#define MNVIC_GROUP_1_SUB_3			0x05FA0600					   // Divide The Four Bit To 1 Group And 3 SUB
		#define MNVIC_GROUP_0_SUB_4			0x05FA0700					   // Divide The Four Bit To 0 Group And 4 SUB
		
		
  #endif //NVIC_PRIVATE_H 