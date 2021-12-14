
/*
 * FPEC_program.c
 *
 * Created: 5/26/2021 1:06:58 AM
 *  Author: Abdelrahman_Magdy
 *  Version : _1_

 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"


// Delet All The Flash
void FPEC_voidEraseAppArea(void)
{
	u8 i;

	for (i=4;i<64;i++)  // Loopping From Page 4 To 64
	{
		FPEC_voidFlashPageErase(i);
	}
}
// FUNC Delet The By Page From The Flash
void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber)
{
	/* Wait Busy Flag */
	while (GET_BIT(FPEC->SR,0) == 1);

  	/* Check if FPEC is locked or not */
	if ( GET_BIT(FPEC->CR,7) == 1)
	{
		FPEC -> KEYR = 0x45670123;
		FPEC -> KEYR = 0xCDEF89AB;
	}
	
	/* Page Erase Operation */
	SET_BIT(FPEC->CR,1);

	/* Write Page address */
	FPEC->AR = (u32)(Copy_u8PageNumber * 1024) + 0x08000000 ;

	/* Start operation */
	SET_BIT(FPEC->CR,6);

	/* Wait Busy Flag */
	while (GET_BIT(FPEC->SR,0) == 1);

	/* EOP */
	SET_BIT(FPEC->SR,5);
	CLR_BIT(FPEC->CR,1);
}
 // Func Take The Take Address Which I'd Like To Start From It & Data  & Lenght
void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length)
{
	u8 i;
	volatile u16 Temp;

	while (GET_BIT(FPEC->SR,0) == 1);

	/* Check if FPEC is locked or not */
	if ( /* FPEC_CR->BitAccess.LOCK == 1 */ GET_BIT(FPEC->CR,7) == 1 )
	{
		FPEC -> KEYR = 0x45670123;
		FPEC -> KEYR = 0xCDEF89AB;
	}
	
	
	for (i = 0; i< Copy_u8Length; i++)
	{
		/* Write Flash Programming */
		SET_BIT(FPEC->CR,0);

		/* Half word operation */

		Temp = Copy_u16Data[i];
		*((volatile u16*)Copy_u32Address) = Copy_u16Data[i];
		Copy_u32Address += 2 ;

		/* Wait Busy Flag */
		while (GET_BIT(FPEC->SR,0) == 1);
	
		/* EOP */
		SET_BIT(FPEC->SR,5);
		CLR_BIT(FPEC->CR,0);
	}

}
