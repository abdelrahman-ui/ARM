/****************************************************************
 ************   -DIO_program.c               ******************
 ***********					   		       ******************
 ***********   -Created: 1/30/2021 1:06:25 AM  ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 

/****************************************************************
***********  Function _ Implementtion  *************
******************************************************************/

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_interface .h"
#include "DIO_private.h"
#include "DIO_config.h"


/**************************************NEW_FUNCTION************************************************************/
//Every Pin Have 4 Bit So To The Next Pin You Need Four Step
/*I Will Send To FUNCTION THE PORT THE PIN ALL THE MODE=(MODE+CONGF) */
void GOIP_voidSetPinDirection(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8MODE)  
{
	//Frist Switch To Know Which Port 
	switch(copy_u8PORT)
	{
		case GPIOA :
				//Check The Which Pin in Reg 32 every pin 4 bit So (CRL) have 16 bit Controle From Pin 0:7
				   if( copy_u8PIN<=7)   //for crl
				   {   //I'M NEED TOO  ONLY IN 1 PIN IN CRL NOT ALL CRL
					   //About Mode Put In CRL Resate 4 bit by clear 
					   GPIOA_CRL &=~((0b1111) <<	(copy_u8PIN *4 ));	//Make The  4 BITS =0000 ONLY WHICH I USE AND SHEEFT TO THE PIN BY 4 BITS
					   //Know Write The Mode + 
					   GPIOA_CRL|=((copy_u8MODE) << (copy_u8PIN * 4));
				   }
				   else if (copy_u8PIN<=15)   //for crH
				   
				   {   //We must - 8 
					   copy_u8PIN=copy_u8PIN-8;
					   //I'M NEED TOO  ONLY IN 1 PIN IN CRH NOT ALL CRL
					   //About Mode Put In CRH Resate 4 bit by clear
					   GPIOA_CRH &= ~ ((0b1111) <<	(copy_u8PIN *4 ));	//Make The  4 BITS =0000 ONLY WHICH I USE AND SHEEFT TO THE PIN BY 4 BITS
					   //Know Write The Mode +
					   GPIOA_CRH|= ((copy_u8MODE) << (copy_u8PIN * 4));
				   }
		break;
/****************************************************************/		
		case GPIOB :
					//Check The Which Pin in Reg 32 every pin 4 bit So (CRL) have 16 bit Controle From Pin 0:7
					if( copy_u8PIN<=7)   //for crl
					{   //I'M NEED TOO  ONLY IN 1 PIN IN CRL NOT ALL CRL
						//About Mode Put In CRL Resate 4 bit by clear
						GPIOB_CRL &=~((0b1111) <<	(copy_u8PIN *4 ));	//Make The  4 BITS =0000 ONLY WHICH I USE AND SHEEFT TO THE PIN BY 4 BITS
						//Know Write The Mode +
						GPIOB_CRL|=((copy_u8MODE) << (copy_u8PIN * 4));
					}
					else if ( copy_u8PIN<=15)   //for crH
					{   //We must - 8
						copy_u8PIN=copy_u8PIN-8;
						//I'M NEED TOO  ONLY IN 1 PIN IN CRH NOT ALL CRL
						//About Mode Put In CRH Resate 4 bit by clear
						GPIOB_CRH &= ~ ((0b1111) <<	(copy_u8PIN *4 ));	//Make The  4 BITS =0000 ONLY WHICH I USE AND SHEEFT TO THE PIN BY 4 BITS
						//Know Write The Mode +
						GPIOB_CRH|= ((copy_u8MODE) << (copy_u8PIN * 4));
					}
		break;
/****************************************************************/		
		case GPIOC :
					//Check The Which Pin in Reg 32 every pin 4 bit So (CRL) have 16 bit Controle From Pin 0:7
					if( copy_u8PIN<=7)   //for crl
					{   //I'M NEED TOO  ONLY IN 1 PIN IN CRL NOT ALL CRL
						//About Mode Put In CRL Resate 4 bit by clear
						GPIOC_CRL &=~((0b1111) <<	(copy_u8PIN *4 ));	//Make The  4 BITS =0000 ONLY WHICH I USE AND SHEEFT TO THE PIN BY 4 BITS
						//Know Write The Mode +
						GPIOC_CRL|=((copy_u8MODE) << (copy_u8PIN * 4));
					}
					else if ( copy_u8PIN<=15)   //for crH
					{   //We must - 8
						copy_u8PIN=copy_u8PIN-8;
						//I'M NEED TOO  ONLY IN 1 PIN IN CRH NOT ALL CRL
						//About Mode Put In CRH Resate 4 bit by clear
						GPIOC_CRH &= ~ ((0b1111) <<	(copy_u8PIN *4 ));	//Make The  4 BITS =0000 ONLY WHICH I USE AND SHEEFT TO THE PIN BY 4 BITS
						//Know Write The Mode +
						GPIOC_CRH|= ((copy_u8MODE) << (copy_u8PIN * 4));
					}		
		break;
		/****************************************************************/
		default:
		
		break;
	}
}

/**************************************NEW_FUNCTION************************************************************/
//Now When I Kow I'M Out SO OUT(0,1)
void GOIP_voidSetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Val) 
{//EVERY PIN HAVE ONLY 1 BIT 
	
	switch(copy_u8PORT)
	{
		case GPIOA ://CHECK PORT
		
			if(copy_u8Val ==GPIO_HIGH)  //CHECK VAL 
			{  
				SET_BIT(GPIOA_ODR,copy_u8PIN); //PUT VAL
			}
			else if (copy_u8Val ==GPIO_LOW)  ;
		
			{   
				CLR_BIT(GPIOA_ODR,copy_u8PIN);
			}
		break;

/****************************************************************/
		case GPIOB ://CHECK PORT
		
			if(copy_u8Val ==GPIO_HIGH)  //CHECK VAL
			{
				SET_BIT(GPIOB_ODR,copy_u8PIN); //PUT VAL
			}
			else if (copy_u8Val ==GPIO_LOW)  ;
		
			{
				CLR_BIT(GPIOB_ODR,copy_u8PIN);
			}
		break;		
/****************************************************************/
		case GPIOC ://CHECK PORT
	
			if(copy_u8Val ==GPIO_HIGH)  //CHECK VAL
			{
				SET_BIT(GPIOC_ODR,copy_u8PIN); //PUT VAL
			}
			else if (copy_u8Val ==GPIO_LOW)  ;

			{
				CLR_BIT(GPIOC_ODR,copy_u8PIN);
			}
		break;
/****************************************************************/
    default:
	
	 break;
	}
	
}


/**************************************NEW_FUNCTION************************************************************/


u8 GOIP_voidGetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN)  
{
	u8 LOC_u8Result =0 ;
		switch(copy_u8PORT)
			{
				case GPIOA : 
					LOC_u8Result=GET_BIT(GPIOA_IDR,copy_u8PIN);
	
				break;

	/****************************************************************/
				case GPIOB ://CHECK PORT
						LOC_u8Result=GET_BIT(GPIOB_IDR,copy_u8PIN);
				break;
	/****************************************************************/
				case GPIOC ://CHECK PORT
	
						LOC_u8Result=GET_BIT(GPIOC_IDR,copy_u8PIN);
				break;
    /****************************************************************/
				default:
	
				break;
		}
		return LOC_u8Result ;
	
}
