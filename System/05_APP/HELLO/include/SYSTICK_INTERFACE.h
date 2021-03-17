/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

#define MSTK_INT_EN   1
#define MSTK_INT_DIS  0

void MSTK_VidInit( void );

void MSTK_VidStart( u32 Copy_PreloadValue );

void MSTK_VidINTStatus( u8 Copy_u8Status );

u8 MSTK_u8ReadFlag( void );

void MSTK_VidSetCallBack( void (*ptr)(void) );

#endif /* SYSTICK_INTERFACE_H_ */
