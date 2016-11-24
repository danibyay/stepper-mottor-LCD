/*! **********************************************************************************************
 * 2016  ITESM Campus Guadalajara. Laboratorio de Microcontroladores
 *
 * @file:      	SCI.h
 * @author(s): 	Daniela Becerra
 * 				JEsus Martin
 *
 * @brief (User's Manual):
 *    SCI driver for the Freescale S08QG8 Microcontroller.
 *
 **************************************************************************************************/

#ifndef SCI_H_
#define SCI_H_

#include "derivative.h" /* include peripheral declarations */
#include "types.h"
/*************************************************************************************************/
/*********************						Includes						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************						Defines							**********************/
/*************************************************************************************************/
#define SCI_BAUD_RATE						9600
#define MAX_MSG_SIZE						26
#define TRUE								1
#define FALSE								0



// channels are defined

  

/*************************************************************************************************/
/*********************						Typedefs						**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************			 	 Functions Like Macros					**********************/
/*************************************************************************************************/
/*************************************************************************************************/

/* Macros of configuration registers  */
//TX stands for transmission
//RX stands for reception
//EN = enable
//DIS = disable

#define SCIBD_RATE_9600      				SCIBD=26    		// baud rate of 9600
#define SCI_ENABLE_TX						SCIC2_TE=1;			
#define SCI_DISABLE_TX						SCIC2_TE=0;

#define SCI_ENABLE_RX						SCIC2_RE=1;	
#define SCI_DISABLE_RX						SCIC2_RE=0;

#define SCI_TX_INTERRUPT_EN					SCIC2_TIE=1;
#define SCI_TX_INTERRUPT_DIS				SCIC2_TIE=0;

#define SCI_TX_COMPLETE_INTERRUPT_EN		SCIC2_TCIE=1;
#define SCI_TX_COMPLETE_INTERRUPT_DIS		SCIC2_TCIE=0;


/*************************************************************************************************/
/*********************					Extern Variables					**********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************                  Extern Constants                    **********************/
/*************************************************************************************************/

/*************************************************************************************************/
/*********************					Function Prototypes					**********************/
/*************************************************************************************************/

/*************************************************************************************************/

/*!*-----------------------------------------------------------------------------------------------
* \name     SCI_InitTx
* \brief    Initializes the SCI configuration registers
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
void SCI_InitTx(void);

/*!*-----------------------------------------------------------------------------------------------
* \name     SCI_InitRx
* \brief    Enables transmission
* \param    void
* \return   void
-------------------------------------------------------------------------------------------------*/
void SCI_InitRx(void);

/*!*-----------------------------------------------------------------------------------------------
* \name     SCI_SendMessage
* \brief    function that sends an array of char
* \param     the message to send, the size of the message
* \return   void
-------------------------------------------------------------------------------------------------*/
void SCI_SendMessage(const u8 msg[], u8 size);
    
/*!*-----------------------------------------------------------------------------------------------
* \name     SCI_TxIsBusy
* \brief    returns true if the peripheral is sending a message
* \param   	void 
* \return   bool
-------------------------------------------------------------------------------------------------*/
bool SCI_TxIsBusy(void);

/*!*-----------------------------------------------------------------------------------------------
* \name     SCI_SetRxCallBack
* \brief    sets which callback function will be performed when the interruption is fired
* \param   	callback function
* \return   void
-------------------------------------------------------------------------------------------------*/
void SCI_SetRxCallBack(ISR_callback function);

/*!*-----------------------------------------------------------------------------------------------
* \name     SCI_getChar
* \brief    returns the data in the serial data register
* \param   	void 
* \return   char, the byte of data
-------------------------------------------------------------------------------------------------*/
char SCI_getChar(void);

#endif 
