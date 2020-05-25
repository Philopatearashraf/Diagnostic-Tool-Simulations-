/********************************/
/*Module Name : CAN0.h          */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/

#ifndef CAN0_H_
#define CAN0_H_
#pragma CHECK_MISRA("none")
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_can.h"
#include "driverlib/can.h"
#pragma RESET_MISRA("all")
extern void Init_CAN(void);
/*****************************************************/
/*Function Name: Init_CAN                            */
/*Inputs: void                                       */
/*Outputs:void                                       */
/*Reentrancy: Non- Reentrant                         */
/*Synchronous: Synchronous                           */
/*Description: Initialize PortB and CAN0 module and  */
/*             their interrupt                       */
/*****************************************************/
extern void CANIntHandler(void);
/*****************************************************/
/*Function Name: CANIntHandler                       */
/*Inputs: void                                       */
/*Outputs:void                                       */
/*Reentrancy: Non- Reentrant                         */
/*Synchronous: Synchronous                           */
/*Description: Interrupt Handler of the CAN module   */
/*             and flag checking for the two objects */
/*****************************************************/
extern void Check_Err(void);
/*****************************************************/
/*Function Name: Check_Err                           */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrancy:Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description:Checks if the Message is correctly set.*/
/*****************************************************/
extern void EstablishingGettingMessage(void);
/*****************************************************/
/*Function Name: EstablishingGettingMessage          */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrancy: Non-Reentrant                          */
/*Synchronous: ASynchronous                          */
/*Description: Establish receiving messages of any ID*/
/*             on CAN0 module through object 1.      */
/*****************************************************/
extern void Send_Command(uint32_t obj,uint32_t MsgID, uint8_t *data);
/*****************************************************/
/*Function Name: Send_Command                        */
/*Inputs: int obj, uint32_t MsgID, uint8_t *data     */
/*Outputs: void                                      */
/*Reentrancy: Reentrant                              */
/*Synchronous: ASynchronous                          */
/*Description: Sending the message of the CAN module */
/*             obj: object number                    */
/*             MsgID: Any Message ID                 */
/*             *data: pointer to data address that   */
/*              would be sent.                       */
/*****************************************************/
extern uint8_t Get_MSG_Data (void);
/*****************************************************/
/*Function Name: Get_MSG_Data                        */
/*Inputs: void                                       */
/*Outputs: data received of data type uint8_t        */
/*Reentrancy:Reentrant                               */
/*Synchronous: Asynchronous                          */
/*Description: Returns received data.                */
/*****************************************************/
extern uint32_t Get_MSG_ID (void);
/*****************************************************/
/*Function Name: Get_MSG_ID                          */
/*Inputs: void                                       */
/*Outputs: Message ID of data type uint32_t          */
/*Reentrancy: Non-Reentrant                          */
/*Synchronous: Synchronous                           */
/*Description:Returns the received message ID.       */
/*****************************************************/
#endif /* CAN0_H_ */
