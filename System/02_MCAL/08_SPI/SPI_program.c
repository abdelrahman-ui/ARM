/****************************************************************
 ************   - SPI_program.c		           ******************
 ***********					   		       ******************
 ***********   -Created: 3/15/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/ 

/************** INCLUDE LIB **************/
 #include "STD_TYPE.h"
 #include "BIT_MATH.h"
/************** INCLUDE MCAL**************/
#include "SPI_private.h"
#include "SPI_interface.h"
#include "SPI_config.h"
/*****************************************/
 
 
 void MSPI_VidInit ( void ){

	 #if   MSP1_STATUS == MSPI_ENABLE

	 #if		MSPI1_CLOCK_MODE == MSPI_MODE0

	 CLR_BIT( MSPI1 -> CR1 , 0 ); CLR_BIT( MSPI1 -> CR1 , 1 );

	 #elif	MSPI1_CLOCK_MODE == MSPI_MODE1

	 SET_BIT( MSPI1 -> CR1 , 0 ); CLR_BIT( MSPI1 -> CR1 , 1 );

	 #elif	MSPI1_CLOCK_MODE == MSPI_MODE2

	 CLR_BIT( MSPI1 -> CR1 , 0 ); SET_BIT( MSPI1 -> CR1 , 1 );

	 #elif	MSPI1_CLOCK_MODE == MSPI_MODE3

	 SET_BIT( MSPI1 -> CR1 , 0 ); SET_BIT( MSPI1 -> CR1 , 1 );

	 #endif

	 #if    MSPI1_MASTER_SLAVE == MSPI_MASTER

	 SET_BIT( MSPI1 -> CR1 , 2 );

	 #elif  MSPI1_MASTER_SLAVE == MSPI_SLAVE

	 CLR_BIT( MSPI1 -> CR1 , 2 );

	 #endif

	 #if   MSPI1_DATA_ORDER == MSPI_MSB_FIRST

	 CLR_BIT( MSPI1 -> CR1 , 7 );

	 #elif MSPI1_DATA_ORDER == MSPI_LSB_FIRST

	 SET_BIT( MSPI1 -> CR1 , 7 );

	 #endif

	 #if   MSPI1_SS_MANAGE  == HW_SLAVE_MANAGEMENT

	 CLR_BIT( MSPI1 -> CR1 , 9 );

	 #elif MSPI1_SS_MANAGEb == SW_SLAVE_MANAGEMENT

	 SET_BIT( MSPI1 -> CR1 , 9 );

	 #endif

	 #if   MSPI1_DATA_SIZE == MSPI_8BIT_DATA

	 CLR_BIT( MSPI1 -> CR1 , 11 );

	 #elif MSPI1_DATA_SIZE == MSPI_16BIT_DATA

	 SET_BIT( MSPI1 -> CR1 , 11 );

	 #endif

	 #if   MSPI1_INT_STATUS == MSPI_INT_DISABLE

	 MSPI1 -> CR2 = 0 ;

	 #elif MSPI1_INT_STATUS == MSPI_TXE_INT_ENABLE

	 SET_BIT( MSPI1 -> CR2 , 7 );

	 #elif MSPI1_INT_STATUS == MSPI_RXNE_INT_ENABLE

	 SET_BIT( MSPI1 -> CR2 , 6 );

	 #endif

	 MSPI1 -> CR1 &= 0xFFC7 ;
	 MSPI1 -> CR1 |= ( MSPI1_PRESCALLER << 3 ) ;

	 SET_BIT( MSPI1 -> CR1 , 6 );

	 #elif MSP1_STATUS == MSPI_DISABLE
	 CLR_BIT( MSPI1 -> CR1 , 6 );
	 #endif

 }
 void SPI_voidInitHardCode(void)
 {
	 MSPI1_t->CR1 = 0x0347 ;
	 
 }
 
		//	Only One Slave
 void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit  , u8 *Copy_DataToReceive)
 {
			/* Clear For Slave Select Pin */
		MGPIO_voidSetPinValue(MSPI1_SALAVE_PIN , LOW);
			/* Send Data */
		MSPI1_t -> DR =Copt_u8DataToTransmit ;
			/* Wait Busy Flag */
		while(GET_BIT(MSPI1_t ->SR , BUSY_FLAG) ==1) ;
			/* Return Recive Data */
		*Copy_DataToReceive = MSPI1_t ->DR ;
			/* Set Slave Select Pin */
		MGPIO_voidSetPinValue(MSPI1_SALAVE_PIN , HIGH);
 }
 void MSPI1_voidInitForTFT(void)
 {
	 /* CPOL = 1 / CPHA =1 / Prescaller = Clk/2 / SPI_EN / MSB Frist  */
	 MSPI1_t->CR1 = 0X0347	;
 }