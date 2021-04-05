/****************************************************************
 ************   - TFT_program.c			       ******************
 ***********					   		       ******************
 ***********   - Created: 3/24/2021			   ******************
 ***********   - Author: Abdelrahman_Magdy     ******************
 ***********   - Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/ 

/************** INCLUDE LIB **************/
 #include "STD_TYPE.h"
 #include "BIT_MATH.h"
/************** INCLUDE MCAL**************/
#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"
/************** INCLUDE HCAL**************/
#include "TFT_private.h"
#include "TFT_interface.h"
#include "TFT_config.h"




/******************************************* Start_FUNCTION  *******************************************/
/*	For Init TFT  :
		
			-	Resat Puls (High 100 micro & Low 1 micro & high 100 micro & low 100 micro & 120 Melay high and stil high )
			-	Sleep Out 0x11
			-	Wait 150 Ms
			-	Color mode And Select The Option(Parameter)From ( 444 (0x03), 365(0x05) , 666(0x06) )  Send Option as Data Not Command 
			-	Display On TFT 0X29
			
			*/

	void HTFT_voidInit(void)
	{
		/*	Resat Puls  */

		MGPIO_voidSetPinValue(TFT_RESEAT_PIN, HIGH) ;
		MSTK_voidSetBusyWait(100);
		MGPIO_voidSetPinValue(TFT_RESEAT_PIN, LOW)  ;
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(TFT_RESEAT_PIN, HIGH) ;
		MSTK_voidSetBusyWait(100);
		MGPIO_voidSetPinValue(TFT_RESEAT_PIN, LOW)  ;
		MSTK_voidSetBusyWait(100);
		MGPIO_voidSetPinValue(TFT_RESEAT_PIN, HIGH) ;
		MSTK_voidSetBusyWait(120000);
		
		/*		Sleep Out Command		*/
		voidWriteCommand(0x11)						;
		MSTK_voidSetBusyWait(150000)					;
		
		/*		Color Mode Command		*/
		voidWriteCommand(0x3A)						;
		voidWriteData(0x05)							;
		
		/*		Display On Command		*/
		voidWriteCommand(0x29)						;
	}
/*******************************************  END_ FUNCTION  *******************************************/

/*******************************************************************************************************/

/******************************************* Start_FUNCTION  *******************************************/

	void HTFT_voidDisplayImage(const u16*Copy_Image)
	{
		u16 Counter ;
		U8 Data ;
		/*	SET SIZE X,Y  */
		
		/*	Set X_ADRESS Start 0 End 127*/
		voidWriteCommand(0x2A);
		/* Start = 00*/
		voidWriteData(0);	
		voidWriteData(0);
		/* Start = 127*/
		voidWriteData(0);
		voidWriteData(127);
		
		
		/*	Set Y_ADRESS Start 0 End 159*/
		voidWriteCommand(0x2B);
		/* Start = 00*/
		voidWriteData(0);
		voidWriteData(0);
		/* Start = 127*/
		voidWriteData(0);
		voidWriteData(159);
		
		/* RAM Write Command Every thing is comming After This Command Display on TFT*/
		voidWriteCommand(0x2C);
		for(Counter = 0 ; Counter < 20480 ; Counter ++)
		{
			/*	Writ For One Pixel The High Byte Then Low Byte For Each Pixel */
			/*Write The High Byte */
			Data =voidWriteData(Copy_Image[Counter] >> 8);
			voidWriteData(Data);
			/*Write The LOW Byte */
			Data = (Copy_Image[Counter] &0x00ff);
			voidWriteData(Data);
		}
	}


/*******************************************  END_ FUNCTION  *******************************************/

/*******************************************************************************************************/

/******************************************* Start_FUNCTION  *******************************************/

/* static  : Beacuse It Private No One Can Call it Out Of Moduel */
	static void voidWriteCommand(u8 Copy_u8Command)
	{
		u8 Local_u8Temp ;			// SPI Resive Data here No Recive So Don't Care
		
		/* Set A0	Pin to Low	*/
		MGPIO_voidSetPinValue(TFT_A0_PIN , LOW) ;
		
		/* Send Command Over SPI */
		 void MSPI_voidSendReceiveSynch(Copy_u8Command ,  &Local_u8Temp );
		
	}
/*******************************************  END_ FUNCTION  *******************************************/

/*******************************************************************************************************/

/******************************************* Start_FUNCTION  *******************************************/

/* static  : Beacuse It Private No One Can Call it Out Of Moduel */
	static void voidWriteData(u8 Copy_u8Data)
	{
		
		u8 Local_u8Temp ;			// SPI Resive Data here No Recive So Don't Care
		/* Set A0	Pin to High	*/
		MGPIO_voidSetPinValue(TFT_A0_PIN , HIGH) ;
	
		/* Send DATA Over SPI */
		void MSPI_voidSendReceiveSynch(Copy_u8Data , &Local_u8Temp );
	
	}	
/*******************************************  END_ FUNCTION  *******************************************/
/*******************************************************************************************************/
/******************************************* Start_FUNCTION  *******************************************/

void HTFT_voidFillColor( u16 Copy_u16Color)
{
	u16 Counter ;
	/*	SET SIZE X,Y  */
	
	/*	Set X_ADRESS Start 0 End 127*/
	voidWriteCommand(0x2A);
	/* Start = 00*/
	voidWriteData(0);
	voidWriteData(0);
	/* Start = 127*/
	voidWriteData(0);
	voidWriteData(127);
	
	
	/*	Set Y_ADRESS Start 0 End 159*/
	voidWriteCommand(0x2B);
	/* Start = 00*/
	voidWriteData(0);
	voidWriteData(0);
	/* Start = 127*/
	voidWriteData(0);
	voidWriteData(159);
	
	/* RAM Write Command Every thing is comming After This Command Display on TFT*/
	voidWriteCommand(0x2C);
	for(Counter = 0 ; Counter < 20480 ; Counter ++)
	{
		/*	Writ For One Pixel The High Byte Then Low Byte For Each Pixel */
		/*Write The High Byte */
		Data =voidWriteData(Copy_u16Color >> 8);
		voidWriteData(Data);
		/*Write The LOW Byte */
		Data = (Copy_u16Color &0x00ff);
		voidWriteData(Data);
	}
}


/*******************************************  END_ FUNCTION  *******************************************/
/*******************************************************************************************************/
/******************************************* Start_FUNCTION  *******************************************/

void HTFT_voidDrawRect( u8 X_0,u8 X_1,u8 Y_0,u8 Y_1,u16 Copy_u16Color)	 //SIZE = FROM X_0 TO X_1 & FROM Y_0 TO Y_1 & COLOR
{
	u16 Counter ;
	/*	SET SIZE X,Y  */
	u16 Local_u16Size =( X_1 - X_0 ) * ( Y_1 - Y_0 ) ;
	/*	Set X_ADRESS Start X_0 End X_1*/
	voidWriteCommand(0x2A);
	/* Start = 00*/
	voidWriteData(0);
	voidWriteData(X_0);
	/* Start = 127*/
	voidWriteData(0);
	voidWriteData(X_1);
	
	
	/*	Set Y_ADRESS Start Y_0 End Y_1 */
	voidWriteCommand(0x2B);
	/* Start = 00*/
	voidWriteData(0);
	voidWriteData(Y_0);
	/* Start = 127*/
	voidWriteData(0);
	voidWriteData(Y_1);
	
	/* RAM Write Command Every thing is comming After This Command Display on TFT*/
	voidWriteCommand(0x2C);
	for(Counter = 0 ; Counter < Local_u16Size ; Counter ++)
	{
		/*	Writ For One Pixel The High Byte Then Low Byte For Each Pixel */
		/*Write The High Byte */
		Data =voidWriteData(Copy_u16Color >> 8);
		voidWriteData(Data);
		/*Write The LOW Byte */
		Data = (Copy_u16Color &0x00ff);
		voidWriteData(Data);
	}
}


/*******************************************  END_ FUNCTION  *******************************************/
