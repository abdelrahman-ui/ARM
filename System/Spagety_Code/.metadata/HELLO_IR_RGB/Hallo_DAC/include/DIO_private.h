
/****************************************************************
 ************   DIO_private.h                  ******************
 ***********	Register Defination By #define ******************
 ***********   -Created: 1/30/2021 1:06:25 AM  ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _1_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 


/*From Memory and bus Ach To Memory Map  Base Adrress 
 Base Adrress PortA =0x4001 0800
 Base Adrress PortB =0x4001 0C00
 Base Adrress PortC =0x4001 1000 */

/****************************************************************
 ***********  guard of file will call on time in .c  *************
******************************************************************/
#ifndef   DIO_PRIVATE_H
#define   DIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS		 0x40010800
#define GPIOB_BASE_ADDRESS		 0x40010C00
#define GPIOC_BASE_ADDRESS		 0x40011000

			/*Register Address for Port_A*/
#define GPIOA_CRL			     *((u32 *)(GPIOA_BASE_ADDRESS+0X00 ))
#define GPIOA_CRH			     *((u32 *)(GPIOA_BASE_ADDRESS+0X04 ))
#define GPIOA_IDR			     *((u32 *)(GPIOA_BASE_ADDRESS+0X08 ))
#define GPIOA_ODR			     *((u32 *)(GPIOA_BASE_ADDRESS+0X0C ))
#define GPIOA_BSR			     *((u32 *)(GPIOA_BASE_ADDRESS+0X10 ))
#define GPIOA_BRR			     *((u32 *)(GPIOA_BASE_ADDRESS+0X14 ))
#define GPIOA_LCK			     *((u32 *)(GPIOA_BASE_ADDRESS+0X18 ))
			/*Register Address for Port_B*/
#define GPIOB_CRL			     *((u32 *)(GPIOB_BASE_ADDRESS+0X00 ))
#define GPIOB_CRH			     *((u32 *)(GPIOB_BASE_ADDRESS+0X04 ))
#define GPIOB_IDR			     *((u32 *)(GPIOB_BASE_ADDRESS+0X08 ))
#define GPIOB_ODR			     *((u32 *)(GPIOB_BASE_ADDRESS+0X0C ))
#define GPIOB_BSR			     *((u32 *)(GPIOB_BASE_ADDRESS+0X10 ))
#define GPIOB_BRR			     *((u32 *)(GPIOB_BASE_ADDRESS+0X14 ))
#define GPIOB_LCK			     *((u32 *)(GPIOB_BASE_ADDRESS+0X18 ))
			/*Register Address for Port_B*/
#define GPIOC_CRL			     *((u32 *)(GPIOC_BASE_ADDRESS+0X00 ))
#define GPIOC_CRH			     *((u32 *)(GPIOC_BASE_ADDRESS+0X04 ))
#define GPIOC_IDR			     *((u32 *)(GPIOC_BASE_ADDRESS+0X08 ))
#define GPIOC_ODR			     *((u32 *)(GPIOC_BASE_ADDRESS+0X0C ))
#define GPIOC_BSR			     *((u32 *)(GPIOC_BASE_ADDRESS+0X10 ))
#define GPIOC_BRR			     *((u32 *)(GPIOC_BASE_ADDRESS+0X14 ))
#define GPIOC_LCK			     *((u32 *)(GPIOC_BASE_ADDRESS+0X18 ))


#endif //DIO_PRIVATE_H