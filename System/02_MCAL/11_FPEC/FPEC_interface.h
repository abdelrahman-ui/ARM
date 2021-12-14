
/*
 * FPEC_interface.h
 *
 * Created: 5/26/2021 1:06:58 AM
 *  Author: Abdelrahman_Magdy
 *  Version : _1_

 */
#ifndef FPEC_INTERFACE
#define FPEC_INTERFACE

/*
 * FPEC Must Enable HSI .
 * FLASH must erase before write
 - 	FPEC Can :
 	 	 	   * Write half world .
 	 	 	   * Erase Page .
                * Mass Erase .
 */
void FPEC_voidEraseAppArea(void);
	
void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber);

void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length);

#endif
