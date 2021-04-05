/****************************************************************
 ************  - TFT_config.h			       ******************
 ***********					   		       ******************
 ***********   -Created: 3/24/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********								   ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
****************************************************************/

#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

/*	Write Pin In Pair Port , Pin  */
#define  TFT_A0_PIN			GPIOA,2
/*
	SPI_Config_TFT :
			config of SPI 
			MSPI1_t-> CR1 = 0x0347 ;
			Clock Ideal High `	   -------	Clock Polarity = 1
			With full Master Write -------	Clock Phase    = 1
			Need Mosst Significant -------  LSB Frist      = 0
			BR		---------------------------------	   = 000


*/
#define TFT_RESEAT_PIN		GPIOA,1


#endif //TFT_CONFIG_H
