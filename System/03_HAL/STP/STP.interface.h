/****************************************************************
 ************   - STP_interface.h		        ******************
 ***********					   		        ******************
 ***********   - Created: 3/11/2021			    ******************
 ***********   - Author: Abdelrahman_Magdy      ******************
 ***********   - Version : _1_				    ******************
 ***********  -								    ******************
 ****************************************************************/ 

/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/ 

#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H

/*		Synchronous Will Not Return Without End What It For	    */
// Function Send Bit By Bit Strating From The MSB ( Frist Send Bit Is Last One )
void STP_voidSendSynchronous(u8 Copy_u8DataSend );

#endif //STP_INTERFACE_HS