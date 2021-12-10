/*========================================================================================
===========================   - ESP_interface.h		`	      ============================
===========================   - Created: 10/19/2021	   	      ============================
===========================   - Author: Abdelrahman_Magdy     ============================
===========================   - Version : _1_		          ============================
===========================   - Note :
					  *-
					  *-
========================================================================================*/ 



/*========================================================================================
		
               * What i sell To Customer
               *  The Archictect Give The API :
						 - The Name Of Function 
						 - What is The Input 
						 - What Is The Output
						 - Macro 
						 
========================================================================================*/ 

/*======================================================================================
=======================  guard of file will call on time in .c	========================
========================================================================================*/

#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H

void ESP8266_VidInit            ( void                                                    ) ;
void ESP8266_VidConnectToWiFi   ( u8 * SSID , u8 * Password                               ) ;
void ESP8266_VidConnectToSrvTcp ( u8 * Copy_u8Domain , u8 * Copy_u8Port                   ) ;
void ESP8266_VidSendHttpReq     ( u8 * Copy_u8Key , u8 * Copy_u8Data , u8 * Copy_u8Length ) ;
u8   ESP8266_u8ReceiveHttpReq   ( u8 * Copy_u8ChannelID , u8 * Copy_u8Length              ) ;

void ESP8266_VidClearBuffer     ( void                                                    ) ;



#endif /* ESP_INTERFACE_H*/