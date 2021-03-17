/****************************************************************
 ************   -EXIT_interface.h              ******************
 ***********					   		       ******************
 ***********   -Created: 2/3/2021			   ******************
 ***********   -Author: Abdelrahman_Magdy      ******************
 ***********   -Version : _2_				   ******************
 ***********  - Using Pre_build Configeration  ******************
 ****************************************************************/ 

//Here What I'M sell
 
/****************************************************************
***********  guard of file will call on time in .c  *************
******************************************************************/

/*		What I Sell		 */

// Function Init Can be by #define or prameter to Function as intialization it better to be by #def in config.h
 
 #ifndef EXTI_INTERFACE_H
 #define EXTI_INTERFACE_H
 
 
 void (*EXTI0_CallBack) (void) = NULL ;
	`/***********	Function Intialize EXTI	Line & Mode By #define	***********/
	
		 void MEXTI_voitInit(void)  ;
	 
	 /***********	Function To Choice The Sense Mode At The Line	***********/
	   
		 void MEXTI_voidSetSignalLatch(u8 Copy_Exti_Line ,u8 Copy_EXTI_Sense_Mode )  ;
	 
	 /***********		  Function To Enable The Line				***********/
		
		 void MEXTI_voidEnableEXTI(u8 Copy_u8Line) ;
	 
	/***********	Function To Disable The Line					***********/
		
		void MEXTI_voidDisableEXTI(u8 Copy_u8Line); 
	 
	/***********	Function Make SoftWare Interrput				***********/
		 
		 void MEXIT_voidSoftwareInterrput(u8 Copy_u8Line); 
	 
	/***********	Function Take A Pointer To Function				***********/
	
		void EXTI_voidSetCallBack( void (*ptr) (void) );
		

	 

#endif  //EXTI_INTERFACE_H	 