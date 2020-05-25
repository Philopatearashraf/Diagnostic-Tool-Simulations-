/********************************/
/*Module Name : ControlSession.h*/
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/

#ifndef CONTROLSESSION_H_
#define CONTROLSESSION_H_

#pragma CHECK_MISRA("none")
#include "string.h"
#pragma RESET_MISRA("all")
#include "CAN0.h"
#include "Delay.h"
#include "TimeOut.h"
#include "Receive.h"

extern void ControlSession (void);
/*****************************************************/
/*Function Name: ControlSession                      */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrancy: Non- Reentrant                         */
/*Synchronous: Synchronous                           */
/*Description: Send Session Control Command and      */
/*             waiting for a  Timeout in case of no  */
/*             response or a late one.               */
/*****************************************************/
#endif /* CONTROLSESSION_H_ */
