/*
 * RCC_config.h
 *
 * Created: 1/26/2021 1:06:25 AM
 *  Author: Abdelrahman_Magdy
 *  Version : _1_
 *  Using Pre_build Configeration
 */ 


#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*The Option To User : RCC_HSE_CRYSTAL
					   RCC_HSE_RC 
					   RCC_HSI
					   RCC_PLL
	MUST BE IN PRIVAT 				   
*/

//Devolper Select one of Option
#define RCC_CLOCK_TYPE			RCC_HSE_CRYSTAL					//Devolper Select RCC_HSE_CRYSTAL now

 /* Option of PLL : RCC_PLL_IN_HSI_DIV_2
					RCC_PLL_IN_HSE_DIV_2
					RCC_PLL_IN_HSE
 
 */
 /*Select value of pll only when you choose pll */
 #if RCC_CLOCK_TYPE == RCC_PLL 
 
  #define RCC_PLL_IN   RCC_PLL_IN_HSE							
   /*PLL_MUL_VALUE  FROM  2 TO 16*/
  #define  RCC_PLL_MUL_VAL   4 //LIKE 4 BY DEFULT 
  
 #endif
  		
#endif /* RCC_CONFIG_H_ */