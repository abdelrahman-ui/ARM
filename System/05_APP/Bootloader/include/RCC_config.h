
/*
 * RCC_config.h
 *
 * Created: 1/26/2021 1:06:25 AM
 *  Author: Abdelrahman_Magdy
 *  Version : _1_
 *  Using Pre_build Configeration
 */

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H



/* Options:    RCC_HSE_CRYSTAL
               RCC_HSE_RC
               RCC_HSI
               RCC_PLL			   */
#define RCC_CLOCK_TYPE    RCC_HSI


/* Options:     RCC_PLL_IN_HSI_DIV_2
                RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN_HSE      */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT     RCC_PLL_IN_HSE_DIV_2
#endif


/* Options: 2 to 16 */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL   4
#endif



#endif
