/****************************************************************
 ************   -DIO_interface.h               ******************
 ***********					   		       ******************
 ***********   -Created: 1/30/2021 1:06:25 AM  ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 

//Here What I'M sell
 
/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/

#ifndef   DIO_INTERFACE_H
#define   DIO_INTERFACE_H

#define GPIO_LOW    0
#define GPIO_HIGH   1

#define  GPIOA		0
#define  GPIOB		1
#define  GPIOC		2
 
 
#define  PIN0        0
#define  PIN1        1
#define  PIN2        2
#define  PIN3        3
#define  PIN4        4
#define  PIN5        5
#define  PIN6        6
#define  PIN7        7
#define  PIN8        8
#define  PIN9        9
#define  PIN10       10
#define  PIN11       11
#define  PIN12       12
#define  PIN13       13
#define  PIN14       14
#define  PIN15       15

void GOIP_voidSetPinDirection(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8MODE)  ; //MODE == DIR

void GOIP_voidSetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Val)  ; //output with high or low 

u8 GOIP_voidGetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN)  ;					//return 




					//MODES
#define  INPUT_ANALOG                       0b0000
#define  INPUT_FlOAting                     0b0100
#define  INPUT_PULL_UP_DOWEN                  0b1000

#define  OUTPUT_SPEED_10MHZ_PP				0b0001        //push pull 00 mode 01 config
#define  OUTPUT_SPEED_10MHZ_OD				0b0101		  //OPEN DRAIN
#define  OUTPUT_SPEED_10MHZ_AFPP			0b1001 
#define  OUTPUT_SPEED_10MHZ_ODPP			0b1101 

#define  OUTPUT_SPEED_2MHZ_PP				0b0010        //push pull 00 mode 01 config
#define  OUTPUT_SPEED_2MHZ_OD				0b0110		  //OPEN DRAIN
#define  OUTPUT_SPEED_2MHZ_AFPP			    0b1010
#define  OUTPUT_SPEED_2MHZ_ODPP			    0b1110

#define  OUTPUT_SPEED_50MHZ_PP				0b0011        //push pull 00 mode 01 config
#define  OUTPUT_SPEED_50MHZ_OD				0b0111		  //OPEN DRAIN
#define  OUTPUT_SPEED_50MHZ_AFPP			0b1011
#define  OUTPUT_SPEED_50MHZ_ODPP			0b1111



#endif //DIO_INTERFACE_H