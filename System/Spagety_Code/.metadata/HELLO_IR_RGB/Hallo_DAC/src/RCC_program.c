/*
 * RCC_program.c
 *
 * Created: 1/26/2021 1:06:58 AM
 *  Author: Abdelrahman_Magdy
 *  Version : _1_
  
 */ 

/* include liberary */
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
/*include file .h */
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
 
  void RCC_voidInitSysClock(void)    //Function To Choose  The Clock Source
  {
	  //Check on #define must Check by #if Not must but # Not take Memory It is Text Replacement It will See Only One Whice i Take
	   
	 #if RCC_CLOCK_TYPE ==  RCC_HSE_CRYSTAL ;
	 //while(! (RCC_CR & (1<<HSERDY)));
	 //SET_BIT=(RCC_CR,HSEON);
	   RCC_CR=0X00010000;/*ENABLE HSE*/
	   RCC_CFGR =0X00000001  //CLOCK HSE 
		
	 #elif RCC_CLOCK_TYPE ==  RCC_HSE_RC ; 
	  RCC_CR=0X00050000;/*ENABLE HSE & BYPATH*/
	    //SET_BIT(RCC_CR,HSEON);
		//SET_BIT(RCC_CR,HSEBYP);
	 RCC_CFGR =0X00000001  //CLOCK HSE 
	 
	 #elif RCC_CLOCK_TYPE ==  RCC_HSI ;
	   RCC_CR=0X00000081;			/*ENABLE HSI+Trimming*/
	   //SET_BIT(RCC_CR,HSION);
	   //Put 1000 at trimming
	   RCC_CFGR =0X00000000   //HSI CLOCK 
	   
	 #elif RCC_CLOCK_TYPE ==  RCC_PLL ;
	 //SET_BIT=(RCC_CR,HSEON);
	 //SET_BIT=(RCC_CR,PLLON);
	 RCC_CR=0X01010000;
	     #if       RCC_PULL_IN ==RCC_PLL_IN_HSI_DIV_2 
		 
	     #elif     RCC_PULL_IN ==RCC_PLL_IN_HSE_DIV_2 
		 
	     #elif     RCC_PULL_IN ==RCC_PLL_IN_HSE
		  
	 #else
		#error (" You Must Select From Clock Type From Config ")  //STOP COMBILLING 
		
	#endif	
  }

 void RCC_voidEnableClock (u8 Copy_u8BusId,u8 Copy_u8PerId )   //Choose The Bus by BusId , And Enable The Perpheral By PerId
 {
	 //Check The Perpheral ID From 0:31
	 if (Copy_u8PerId <= 31)
	 {
		 switch(Copy_u8BusId) 
		 {
			 case RCC_AHB  : SET_BIT( RCC_AHBENR  , Copy_u8PerId);		 break;
			 case RCC_APB1 : SET_BIT( RCC_APB1    , Copy_u8PerId);		 break;
			 case RCC_APB2 : SET_BIT( RCC_APB2    , Copy_u8PerId);		 break;
			// default       :/*Return Error */							 break;
		 }
	 }
	 else
	 {
		 /*Return Error */
	 }
 }
 
 
 
  void RCC_voidEnableClock (u8 Copy_u8BusId,u8 Copy_u8PerId ) //Choose The Bus by BusId , And Disable The Perpheral By PerId
  {
	  //Check The Perpheral ID From 0:31
	  if (Copy_u8PerId <= 31)
	  {
		  switch(Copy_u8BusId)
		  {
			  case RCC_AHB  : CLR_BIT( RCC_AHBENR  , Copy_u8PerId);		 break;
			  case RCC_APB1 : CLR_BIT( RCC_APB1    , Copy_u8PerId);		 break;
			  case RCC_APB2 : CLR_BIT( RCC_APB2    , Copy_u8PerId);		 break;
			  // default       :/*Return Error */							 break;
		  }
	  }
	  else
	  {
		  /*Return Error */
	  }
  }
  
 