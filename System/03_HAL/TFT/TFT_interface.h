/****************************************************************
 ************   - UART_interface.h		        ******************
 ***********					   		        ******************
 ***********   - Created: 3/24/2021			    ******************
 ***********   - Author: Abdelrahman_Magdy      ******************
 ***********   - Version : _1_				    ******************
 ***********  -								    ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/ 


#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16*Copy_Image);				// Must Constant To go to Flash Not RAM & u16  1pixel = 2byte(2*8)  
void HTFT_voidFillColor( u16 Copy_u16Color);
void HTFT_voidDrawRect( u8 X_0,u8 X_1,u8 Y_0,u8 Y_1,u16 Copy_u16Color);

#endif //TFT_INTERFACE_H