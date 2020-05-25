/********************************/
/*Module Name : WriteSession.c  */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#ifndef WRITESESSION_H_
#define WRITESESSION_H_

#pragma CHECK_MISRA("none")
#include "string.h"
#pragma RESET_MISRA("all")
#include "CAN0.h"
#include "Delay.h"
#include "TimeOut.h"
#include "Receive.h"

extern void WriteSession(void);
/******************************************************/
/*Function Name: WriteSession                         */
/*Inputs: void                                        */
/*Outputs: void                                       */
/*Reentrancy: Non- Reentrant                          */
/*Synchronous: Synchronous                            */
/*Description:The Write function which is the Extended*/
/*            session although it can be activated by */
/*            using the Control function              */
/******************************************************/

#endif /* WRITESESSION_H_ */
