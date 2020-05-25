/******************************************/
/*Module Name: CAN State Machine          */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/

#ifndef NEGATIVERESPONSE_H_
#define NEGATIVERESPONSE_H_

#include "CAN0.h"

/*****************************************************/
/*Function Name:  Negative_Response_Read             */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description: Responds to Read Commands from        */
/*             Diagnostic tool if not allowed.       */
/*****************************************************/
void Negative_Response_Read(void);

/*****************************************************/
/*Function Name:  Negative_Response_Write            */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description: Responds to Write Commands from       */
/*             Diagnostic tool if not allowed.       */
/*****************************************************/
void Negative_Response_Write(void);

#endif /* NEGATIVERESPONSE_H_ */
