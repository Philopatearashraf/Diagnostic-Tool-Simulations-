/********************************/
/*Module Name : UART_Init.h     */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/

#ifndef UART_INIT_H_
#define UART_INIT_H_

#pragma CHECK_MISRA("none")
#include <stdint.h>
#include <stdbool.h>
#include "interrupt.h"
#include "inc/hw_can.h"
#include "inc/hw_memmap.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "tm4c123gh6pm.h"
#pragma RESET_MISRA("all")

extern void InitConsole(void);
/*********************************************************/
/*Function Name: InitConsole                             */
/*Inputs: void                                           */
/*Outputs: void                                          */
/*Reentrancy: Non- Reentrant                             */
/*Synchronous: Synchronous                               */
/*Description: Initialization of Port A and its UART0    */
/*             module                                    */
/*********************************************************/
extern void PrintCANMessageInfo(const tCANMsgObject *psCANMsg, uint32_t ui32MsgObj);
/*********************************************************/
/*Function Name: PrintCANMessageInfo                     */
/*Inputs: tCANMsgObject *psCANMsg, uint32_t ui32MsgObj   */
/*Outputs: void                                          */
/*Reentrancy: Non- Reentrant                             */
/*Synchronous: Synchronous                               */
/*Description: Prints information of a CAN Message       */
/*             *psCANMsg:pointer to CAN Message Structure*/
/*             ui32MsgObj: Object number                 */
/*********************************************************/
extern void PrintStatus(void);
/*********************************************************/
/*Function Name: PrintStatus                             */
/*Inputs: void                                           */
/*Outputs: void                                          */
/*Reentrancy: Reentrant                                  */
/*Synchronous: Synchronous                               */
/*Description: Prints Message ID and data that are       */
/*             received on the CAN0 module from node 2   */
/*********************************************************/
#endif /* UART_INIT_H_ */
