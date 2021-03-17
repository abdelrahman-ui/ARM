/****************************************************************
 ************   -AFIO_program.c                ******************
 ***********					   		       ******************
 ***********   -Created: 2/6/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/ 

void MAFIO_voidSetExtiPin(u8 Copy_u8Line ,u8 Copy_u8PortMap)
{
	u8 Local_u8RegIndex=0;
	
	if(Copy_u8Line <=3)
	{
		 Local_u8RegIndex=0;
		 Copy_u8Line -=4;
	}
	else if (Copy_u8Line<=7)
		{
		 Local_u8RegIndex=1;
		  Copy_u8Line -=4;
		}
	else if (Copy_u8Line<=11)
		{
			Local_u8RegIndex=2;
			Copy_u8Line -=8;
		}
	else if (Copy_u8Line<=15)
		{
			Local_u8RegIndex=3;
			Copy_u8Line -=12;
		}
	else
		{
			/*EROOR*/
		}
		/**/
	AFIO->EXTICR[Local_u8RegIndex] &=~((0b111) << (Copy_u8Line*4));				 //	Reseat
	AFIO->EXTICR[Local_u8RegIndex] |=((Copy_u8PortMap) << (Copy_u8Line*4));		 //	Set
	
}

