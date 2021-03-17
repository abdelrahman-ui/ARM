/*
 * RCC_interface.h
 *
 * Created: 1/26/2021 1:03:13 AM
 *  Author: Abdelrahman_Magdy
 *  Version : _1_
 */ 


#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
 
	/*The Frist Include After Lib*/
   /*  Resgister Defination  */
   
/*  Base Address of RCC ON Bus(AHB)  =0x4002 1000  */
	
	
    #define RCC_CR			   *((/*volatile*/ u32 *)0X40021000)   //Control The Input Clock To The Processor
	#define RCC_CFGR		   *((/*volatile*/u32 *)0X40021004)    //Control The Input Clock To The Processor
	#define RCC_CIR			   *((/*volatile*/u32 *)0X40021008)
	#define RCC_APB2RSTR	   *((/*volatile*/u32 *)0X4002100C)
	#define RCC_APB1RSTR	   *((/*volatile*/u32 *)0X40021010)
	#define RCC_AHBENR		   *((/*volatile*/u32 *)0X40021014)   //Control The Input Clock To The Peripheral
	#define RCC_APB2ENR		   *((/*volatile*/u32 *)0X40021018)   //Control The Input Clock To The Peripheral
	#define RCC_APB1ENR		   *((/*volatile*/u32 *)0X4002101C)   //Control The Input Clock To The Peripheral
	#define RCC_BDCR		   *((/*volatile*/u32 *)0X40021020)
	#define RCC_CSR		       *((/*volatile*/u32 *)0X40021024)


	//MACRO OF BUS
	#define  RCC_AHB		0
	#define  RCC_APB1		1
	#define  RCC_APB2		2 


#endif /* RCC_INTERFACE_H_ */