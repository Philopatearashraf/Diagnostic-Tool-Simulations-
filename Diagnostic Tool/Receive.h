/********************************/
/*Module Name : Receive.h       */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#ifndef RECEIVE_H_
#define RECEIVE_H_
#include "CAN0.h"
#include "UART_Init.h"
extern void Receive(uint32_t MsgID);
/*****************************************************/
/*Function Name: Receive                             */
/*Inputs:uint32_t MsgID                              */
/*Outputs: void                                      */
/*Reentrancy: Non- Reentrant                         */
/*Synchronous: Synchronous                           */
/*Description: Receiving el Response from Node 2 and */
/*             then Respond to the returned MsgID    */
/*             and Data also it's Responsible for    */
/*             applying the current active session   */
/*             either Default session or Extended    */
/*****************************************************/
#endif /* RECEIVE_H_ */
