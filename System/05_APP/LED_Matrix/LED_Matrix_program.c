/****************************************************************
 ************   -LED_Matrix_program.c          ******************
 ***********					   		       ******************
 ***********   -Created: 2/27/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/ 

void HLED_MATRIX_voidinit(void)
{
	
	/*		output push pull 2mhz	*/
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW_0_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW_1_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW_2_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW_3_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW_4_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW_5_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW_6_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_ROW_7_PIN ,0b0010);
	
	MGPIO_voidSetPinDirection(LED_MATRIX_COL_0_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL_1_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL_2_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL_3_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL_4_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL_5_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL_6_PIN ,0b0010);
	MGPIO_voidSetPinDirection(LED_MATRIX_COL_7_PIN ,0b0010);

}


/******************************************************************************************/
// Function To Display Take the array in poiter the element of dic from Led matrix studio
// Array Will Have The Value Of 8 Row
void HLED_MATRIX_u8Display(u8 *Copy_u8Data)
{
	
	
	/*		Disable all Columns 	*/
	HLED_MATRIX_voidDiableAllCol();
	
	/*		Enable COL_0		*/
	MGPIO_voidSetPinValue(LED_MATRIX_COL_0_PIN ,LOW);
	
	/* Send The Value Of Row 0:7 in COL_0*/
	HLED_MATRIX_u8SetRowVal(Copy_u8Data[0]);
	
	/*		DELAY = 1SEC/8*8 = 2.5 msec  */

	MSTK_voidSetBusyWait(2500);				// TICK = 1 MICRO

	/*********************************************************************************/

	/*		Disable all Columns 	*/
	HLED_MATRIX_voidDiableAllCol();

	/*		Enable COL_1		*/
	MGPIO_voidSetPinValue(LED_MATRIX_COL_1_PIN ,LOW);

	/* Send The Value Of Row 0:7 in COL_1*/
	HLED_MATRIX_u8SetRowVal(Copy_u8Data[1]);

	/*		DELAY = 1SEC/8*8 = 2.5 msec  */

	MSTK_voidSetBusyWait(2500);				// TICK = 1 MICRO

	*******************************************************************************/

	/*		Disable all Columns 	*/
	HLED_MATRIX_voidDiableAllCol();

	/*		Enable COL_2		*/
	MGPIO_voidSetPinValue(LED_MATRIX_COL_2_PIN ,LOW);

	/* Send The Value Of Row 0:7 in COL_2*/
	HLED_MATRIX_u8SetRowVal(Copy_u8Data[2]);

	/*		DELAY = 1SEC/8*8 = 2.5 msec  */

	MSTK_voidSetBusyWait(2500);				// TICK = 1 MICRO
	
	/*********************************************************************************/
	
	/*		Disable all Columns 	*/
	HLED_MATRIX_voidDiableAllCol();
	
	/*		Enable COL_3		*/
	MGPIO_voidSetPinValue(LED_MATRIX_COL_3_PIN ,LOW);
	
	/* Send The Value Of Row 0:7 in COL_3*/
	HLED_MATRIX_u8SetRowVal(Copy_u8Data[3]);
	
	/*		DELAY = 1SEC/8*8 = 2.5 msec  */
	
	MSTK_voidSetBusyWait(2500);				// TICK = 1 MICRO
	
	/*********************************************************************************/
	
	/*		Disable all Columns 	*/
	HLED_MATRIX_voidDiableAllCol();
	
	/*		Enable COL_4		*/
	MGPIO_voidSetPinValue(LED_MATRIX_COL_4_PIN ,LOW);
	
	/* Send The Value Of Row 0:7 in COL_4*/
	HLED_MATRIX_u8SetRowVal(Copy_u8Data[4]);
	
	/*		DELAY = 1SEC/8*8 = 2.5 msec  */
	
	MSTK_voidSetBusyWait(2500);				// TICK = 1 MICRO
	
	/*********************************************************************************/
	
	/*		Disable all Columns 	*/
	HLED_MATRIX_voidDiableAllCol();
	
	/*		Enable COL_5		*/
	MGPIO_voidSetPinValue(LED_MATRIX_COL_5_PIN ,LOW);
	
	/* Send The Value Of Row 0:7 in COL_5*/
	HLED_MATRIX_u8SetRowVal(Copy_u8Data[5]);
	
	/*		DELAY = 1SEC/8*8 = 2.5 msec  */
	
	MSTK_voidSetBusyWait(2500);				// TICK = 1 MICRO
	
	/*********************************************************************************/
	
	/*		Disable all Columns 	*/
	HLED_MATRIX_voidDiableAllCol();
	
	/*		Enable COL_6		*/
	MGPIO_voidSetPinValue(LED_MATRIX_COL_6_PIN ,LOW);
	
	/* Send The Value Of Row 0:7 in COL_6*/
	HLED_MATRIX_u8SetRowVal(Copy_u8Data[6]);
	
	/*		DELAY = 1SEC/8*8 = 2.5 msec  */
	
	MSTK_voidSetBusyWait(2500);				// TICK = 1 MICRO
	
	
	/*********************************************************************************/

	/*		Disable all Columns 	*/
	HLED_MATRIX_voidDiableAllCol();

	/*		Enable COL_7		*/
	MGPIO_voidSetPinValue(LED_MATRIX_COL_7_PIN ,LOW);

	/* Send The Value Of Row 0:7 in COL_7*/
	HLED_MATRIX_u8SetRowVal(Copy_u8Data[7]);

	/*		DELAY = 1SEC/8*8 = 2.5 msec  */

	MSTK_voidSetBusyWait(2500);				// TICK = 1 MICRO

	
	}

	//Function Diable All COL
	void HLED_MATRIX_voidDiableAllCol(void)
	{
	/*		Disable all Columns 	*/
	MGPIO_voidSetPinValue(LED_MATRIX_COL_0_PIN ,HIGH);
	MGPIO_voidSetPinValue(LED_MATRIX_COL_1_PIN ,HIGH);
	MGPIO_voidSetPinValue(LED_MATRIX_COL_2_PIN ,HIGH);
	MGPIO_voidSetPinValue(LED_MATRIX_COL_3_PIN ,HIGH);
	MGPIO_voidSetPinValue(LED_MATRIX_COL_4_PIN ,HIGH);
	MGPIO_voidSetPinValue(LED_MATRIX_COL_5_PIN ,HIGH);
	MGPIO_voidSetPinValue(LED_MATRIX_COL_6_PIN ,HIGH);
	MGPIO_voidSetPinValue(LED_MATRIX_COL_7_PIN ,HIGH);
	
	
	}

	void HLED_MATRIX_u8SetRowVal(u8 Copy_u8Data)
	{
	u8 Local_u8BIT =0 ;
	
	/*		 Take The Value Of ROW and Take Evey Bit Alone And Put The Value Of Row		*/
	Local_u8BIT = GET_BIT(Copy_u8Data,0);
	MGPIO_voidSetPinValue(LED_MATRIX_ROW_0_PIN ,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,1);
	MGPIO_voidSetPinValue(LED_MATRIX_ROW_1_PIN ,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,2);
	MGPIO_voidSetPinValue(LED_MATRIX_ROW_2_PIN ,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,3);
	MGPIO_voidSetPinValue(LED_MATRIX_ROW_3_PIN ,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,4);
	MGPIO_voidSetPinValue(LED_MATRIX_ROW_4_PIN ,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,5);
	MGPIO_voidSetPinValue(LED_MATRIX_ROW_5_PIN ,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Data,6);
	MGPIO_voidSetPinValue(LED_MATRIX_ROW_6_PIN ,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Data,7);
	MGPIO_voidSetPinValue(LED_MATRIX_ROW_7_PIN ,Local_u8BIT);
	}
