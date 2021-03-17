/****************************************************************
 ************  -LED_Matrix_config.h            ******************
 ***********					   		       ******************
 ***********   -Created: 2/17/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********								   ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/ 


#ifndef LED_Matrix_CONFIG_H
#define LED_Matrix_CONFIG_H
 
	/*  Please write Pin Pair (Port ,pin) For Rows */
	
#define  LED_MATRIX_ROW_0_PIN			GPIOA , 0
#define  LED_MATRIX_ROW_1_PIN			GPIOA , 1
#define  LED_MATRIX_ROW_2_PIN			GPIOA , 2
#define  LED_MATRIX_ROW_3_PIN			GPIOA , 3
#define  LED_MATRIX_ROW_4_PIN			GPIOA , 4
#define  LED_MATRIX_ROW_5_PIN			GPIOA , 5
#define  LED_MATRIX_ROW_6_PIN			GPIOA , 6
#define  LED_MATRIX_ROW_7_PIN			GPIOA , 7
 
 
 /*  Please write Pin Pair (Port ,pin) For Colume  */
 
 #define  LED_MATRIX_COL_0_PIN			GPIOB , 0
 #define  LED_MATRIX_COL_1_PIN			GPIOB , 1
 #define  LED_MATRIX_COL_2_PIN			GPIOB , 5
 #define  LED_MATRIX_COL_3_PIN			GPIOB , 6
 #define  LED_MATRIX_COL_4_PIN			GPIOB , 7
 #define  LED_MATRIX_COL_5_PIN			GPIOB , 8
 #define  LED_MATRIX_COL_6_PIN			GPIOB , 9
 #define  LED_MATRIX_COL_7_PIN			GPIOB , 10
 

#endif  //LED_Matrix_CONFIG.H