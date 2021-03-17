/****************************************************************
 ************   - STP_program.c		           ******************
 ***********					   		       ******************
 ***********   -Created: 3/11/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  -								   ******************
 ****************************************************************/ 


	/****** INCLUDE LIB ******/

 #include "STD_TYPE.h"
 #include "BIT_MATH.h"

   /******* INCLUDE MCAL ******/
   
 #include  "DIO_interface.h"
 #include  "MSTK_interface.h"
 
  /******* INCLUDE MCAL ******/
  
  #include "STP_private.h"
  #include "STP_interface.h"
  #include "STP_config.h"
  
 /************************************************************************************************************************************/
 
// Function Send Bit By Bit Strating From The MSB ( Frist Send Bit Is Last One )
void STP_voidSendSynchronous(u8 Copy_u8DataSend )
{
	s8 Local_s8Counter ;								// Must Be Signed  Not Unsigned When Reach To Stop When Reach 0 But Unsigned ( 0 - 1 = 255 )  : So It Will Be True Along Time
	u8 Local_u8Bit     ;
	for (Local_s8Counter = 7 ; Local_s8Counter >= 0 ; Local_s8Counter--)
		{
					/*					  Send Bit By Bit Strating From MSB						*/
					
			Local_u8Bit = GET_BIT( Copy_u8DataSend , Local_s8Counter) ;	
					
					/*          Make The Pin By The Data Bit From 7 To 0 bit				   */
					
			MGPIO_voidSetPinValue( HSTP_SERIAL_DATA , Local_u8Bit  )  ; 
			
					/*                      Send Plus To Shift Clock						   */			// The Clock From (100 Nanosec) To bigger 
					
			MGPIO_voidSetPinValue( HSTP_SHIFT_CLOCK , HIGH );												// Raise Clock To Send Bit To Shift Regester
			MSTK_voidBusyWait(1);																			// Wait 1 Micro Sec
			MGPIO_voidSetPinValue( HSTP_SHIFT_CLOCK , LOW );												// Full Clock
			MSTK_voidBusyWait(1);																			// Wait 1 Micro Sec
					
					/*         Send Puls To Store Clock To Move From Shift REF To Store REG    */
					
			MGPIO_voidSetPinValue( HSTP_STORAGE_CLOCK , HIGH );												// Raise Clock To Send Bit To Shift Regester
			MSTK_voidBusyWait(1);																			// Wait 1 Micro Sec
			MGPIO_voidSetPinValue( HSTP_STORAGE_CLOCK , LOW );												// Full Clock
			MSTK_voidBusyWait(1);																			// Wait 1 Micro Sec
		
		
		}	
}