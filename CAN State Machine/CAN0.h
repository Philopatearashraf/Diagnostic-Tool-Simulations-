/******************************************/
/*Module Name: CAN0.h                     */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/


#ifndef CAN0_H_
#define CAN0_H_


#pragma CHECK_MISRA("none")
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "inc/hw_can.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#pragma RESET_MISRA("all")

/*****************************************************/
/*Function Name: InitCAN0                            */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                          */
/*Synchronous: Synchronous                           */
/*Description: Initialize CAN0 Module                */
/*****************************************************/
extern void InitCAN0(void);

/*****************************************************/
/*Function Name: CANIntHandler                       */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrant: Reentrant                              */
/*Synchronous: Synchronous                           */
/*Description: Interrupt CAN Handler. Detects if     */
/*             an error occurred, sets receiving     */
/*             flag at successful receiving and clear*/
/*             interrupts at Receiving & Transmitting*/
/*****************************************************/
extern void CANIntHandler(void);

/*****************************************************/
/*Function Name: Check_Err                           */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                              */
/*Synchronous: Asynchronous                          */
/*Description: If Error Flag is set by the CAN       */
/*             handler, prints that.                 */
/*****************************************************/
extern void Check_Err (void);

/*****************************************************/
/*Function Name: Send_State                          */
/*Inputs: Message ID (MsgID) and LED State (*LED)    */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description: Sends a message on CAN bus using CAN0 */
/*             module with the Message ID at MsgID.  */
/*             Message contains LED State and is sent*/
/*             through Object 1.                     */
/*             MsgID can be any ID.                  */
/*             *LED can be either "Red", "Green", or */
/*             "Blue".                               */
/*****************************************************/
extern void Send_State (uint32_t MsgID, const char *LED);

/*****************************************************/
/*Function Name: Send_Dir                            */
/*Inputs:Message ID (MsgID) and State Machine        */
/*               Direction (*Dir).                   */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description: Sends a message on CAN bus using CAN0 */
/*             module with the Message ID at MsgID.  */
/*             Message contains State Machine        */
/*             direction and is sent through Object1.*/
/*             MsgID can be any ID.                  */
/*             *Dir can be either Clockwise "CW"     */
/*              ,or Counter Clockwise "CCW".         */
/*****************************************************/
extern void Send_Dir(uint32_t MsgID,const char *Dir);

/*****************************************************/
/*Function Name: Send_Session                        */
/*Inputs: Message ID (MsgID) and Control Session     */
/*                (Ctrl).                            */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description: Sends a message on CAN bus using CAN0 */
/*             module with the Message ID at MsgID.  */
/*             Message contains Control Session      */
/*             required and is sent through Object1. */
/*             MsgID can be any ID.                  */
/*             Ctrl can be either 0 for Default      */
/*             Session or 1 for Extended Session.    */
/*****************************************************/
extern void Send_Session (uint32_t MsgID, int Ctrl);

/*****************************************************/
/*Function Name: Establishing_Getting_MSGs           */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description:Establish receiving messages of any ID */
/*            on CAN0 module through object 2.       */
/*****************************************************/
extern void Establishing_Getting_MSGs(void);

/*****************************************************/
/*Function Name: Get_MSG_ID                          */
/*Inputs: Object number (ObjID)                      */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description:Returns Message ID that's received on */
/*            object number at ObjID.                */
/*            Can't be called unless                 */
/*            Establishing_Getting_MSGs() is called  */
/*            prior.                                 */
/*            ObjID is object number.                */
/*****************************************************/
extern uint32_t Get_MSG_ID(uint32_t ObjID);

/*****************************************************/
/*Function Name: Get_MSG_Data                        */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description:Returns Message Data that's received.  */
/*            Can't be called unless                 */
/*            Establishing_Getting_MSGs() is called  */
/*            prior.                                 */
/*****************************************************/
extern uint8_t Get_MSG_Data (void);
#endif /* CAN0_H_ */
