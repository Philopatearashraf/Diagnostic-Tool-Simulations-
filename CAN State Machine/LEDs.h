/******************************************/
/*Module Name: LEDs.h                     */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose:Final Project                  */
/******************************************/

#ifndef LEDS_H_
#define LEDS_H_

#pragma CHECK_MISRA("none")
#include <stdbool.h>
#include <stdint.h>
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
/*Function Name: InitLEDs                            */
/*Inputs: void                                       */
/*Outputs:void                                       */
/*Reentrant: Non- Reentrant                         */
/*Synchronous: Synchronous                           */
/*Description: Initialize on-board LEDs              */
/*****************************************************/
extern void InitLEDs (void);

/*****************************************************/
/*Function Name: Turn_Off_LEDs                       */
/*Inputs: void                                       */
/*Outputs:void                                       */
/*Reentrant: Non- Reentrant                         */
/*Synchronous: Asynchronous                          */
/*Description: Turn off on-board LEDs                */
/*****************************************************/
extern void Turn_Off_LEDs(void);

/*****************************************************/
/*Function Name: Turn_On_Green_LEDs                  */
/*Inputs: void                                       */
/*Outputs:void                                       */
/*Reentrant: Non- Reentrant                         */
/*Synchronous: Asynchronous                          */
/*Description: Turn on green on-board LEDs           */
/*****************************************************/
extern void Turn_On_Green_LEDs (void);

/*****************************************************/
/*Function Name: Turn_On_Red_LEDs                    */
/*Inputs: void                                       */
/*Outputs:void                                       */
/*Reentrant: Non- Reentrant                         */
/*Synchronous: Asynchronous                          */
/*Description: Turn on red on-board LEDs             */
/*****************************************************/
extern void Turn_On_Red_LEDs(void);

/*****************************************************/
/*Function Name: Turn_On_Blue_LEDs                   */
/*Inputs: void                                       */
/*Outputs:void                                       */
/*Reentrant: Non- Reentrant                         */
/*Synchronous: Asynchronous                          */
/*Description: Turn on blue on-board LED             */
/*****************************************************/
extern void Turn_On_Blue_LEDs(void);

/*****************************************************/
/*Function Name: Read_Red_LEDs                       */
/*Inputs: void                                       */
/*Outputs: Red LED State                             */
/*Reentrant: Non- Reentrant                         */
/*Synchronous: Asynchronous                          */
/*Description: Returns red on-board LED state.       */
/*****************************************************/
extern uint8_t Read_Red_LEDs(void);

/*****************************************************/
/*Function Name: Read_Blue_LEDs                      */
/*Inputs: void                                       */
/*Outputs: Blue LED State                            */
/*Reentrant: Non- Reentrant                         */
/*Synchronous: Asynchronous                          */
/*Description: Returns blue on-board LED state.      */
/*****************************************************/
extern uint8_t Read_Blue_LEDs(void);

/*****************************************************/
/*Function Name: Read_Green_LEDs                     */
/*Inputs: void                                       */
/*Outputs: Green LED State                           */
/*Reentrant: Non- Reentrant                         */
/*Synchronous: Asynchronous                          */
/*Description: Returns Green on-board LED state.     */
/*****************************************************/
extern uint8_t Read_Green_LEDs(void);

#endif /* LEDS_H_ */
