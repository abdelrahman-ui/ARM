/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "TYPES.h"
#include "MACROS.h"

#include "GPIO_INTERFACE.h"
#include "DELAY_INTERFACE.h"

#include "S_T_P_INTERFACE.h"
#include "S_T_P_CONFIGI.h"

void STP_VidInit( void ){

	MGPIO_VidSetPinDirection( STP_DATA_PORT       , STP_DATA_PIN       , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_VidSetPinDirection( STP_BIT_LATCH_PORT  , STP_BIT_LATCH_PIN  , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_VidSetPinDirection( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , OUTPUT_SPEED_2MHZ_PP );

}

void STP_VidByteOutput ( u8 Copy_u8Data ){

	u8 LOC_u8Iterator ;

	MGPIO_VidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , LOW );

	for( LOC_u8Iterator = 8 ; LOC_u8Iterator > 0 ; LOC_u8Iterator-- ){

		MGPIO_VidSetPinValue( STP_DATA_PORT , STP_DATA_PIN , ( GET_BIT( Copy_u8Data , ( LOC_u8Iterator - 1 ) ) ) );

		MGPIO_VidSetPinValue( STP_BIT_LATCH_PORT , STP_BIT_LATCH_PIN , HIGH  );
		_delay_us( 5 );
		MGPIO_VidSetPinValue( STP_BIT_LATCH_PORT , STP_BIT_LATCH_PIN , LOW	 );

	}

	MGPIO_VidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , HIGH );
	_delay_us( 5 );
	MGPIO_VidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , LOW  );

}

void STP_VidHalfWordOutput ( u16 Copy_u8Data ){

	u8 LOC_u8Iterator ;

	MGPIO_VidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , LOW );

	for( LOC_u8Iterator = 16 ; LOC_u8Iterator > 0 ; LOC_u8Iterator-- ){

		MGPIO_VidSetPinValue( STP_DATA_PORT , STP_DATA_PIN , ( GET_BIT( Copy_u8Data , ( LOC_u8Iterator - 1 ) ) ) );

		MGPIO_VidSetPinValue( STP_BIT_LATCH_PORT , STP_BIT_LATCH_PIN , HIGH  );
		_delay_us( 5 );
		MGPIO_VidSetPinValue( STP_BIT_LATCH_PORT , STP_BIT_LATCH_PIN , LOW	 );

	}

	MGPIO_VidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , HIGH );
	_delay_us( 5 );
	MGPIO_VidSetPinValue( STP_BYTE_LATCH_PORT , STP_BYTE_LATCH_PIN , LOW  );

}
