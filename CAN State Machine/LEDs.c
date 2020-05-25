/******************************************/
/*Module Name: LEDs.c                     */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/

#include "LEDs.h"

uint8_t ON = 1;
uint8_t OFF = 0;
uint8_t State;

void InitLEDs (void)
{
    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_GPIOF); /*Enable GPIO Peripheral Port F*/
    while(!SysCtlPeripheralReady((uint32_t)SYSCTL_PERIPH_GPIOF))
    {   } /*Wait till Peripheral is enabled*/
    GPIOPinTypeGPIOOutput((uint32_t)GPIO_PORTF_BASE, (uint8_t)GPIO_PIN_2 | (uint8_t)GPIO_PIN_1 |(uint8_t)GPIO_PIN_3 ); /*Configuring PF2, PF1, and PF3 as outputs*/
}


void Turn_Off_LEDs(void)
{
    GPIOPinWrite((uint32_t)GPIO_PORTF_BASE, (uint8_t)GPIO_PIN_1 | (uint8_t)GPIO_PIN_2 |(uint8_t)GPIO_PIN_3, (uint8_t)0x0);
}

void Turn_On_Green_LEDs (void)
{
    GPIOPinWrite((uint32_t)GPIO_PORTF_BASE, (uint8_t)GPIO_PIN_3, (uint8_t)GPIO_PIN_3);
}

void Turn_On_Red_LEDs(void)
{
    GPIOPinWrite((uint32_t)GPIO_PORTF_BASE, (uint8_t)GPIO_PIN_1, (uint8_t)GPIO_PIN_1);
}

void Turn_On_Blue_LEDs(void)
{
    GPIOPinWrite((uint32_t)GPIO_PORTF_BASE, (uint8_t)GPIO_PIN_2, (uint8_t)GPIO_PIN_2);
}

uint8_t Read_Red_LEDs(void)
{
    if (GPIOPinRead((uint32_t)GPIO_PORTF_BASE, (uint8_t)GPIO_PIN_1))/*Read State*/
        State = ON;
    else
        State = OFF;
    return State;
}

uint8_t Read_Blue_LEDs(void)
{
    if (GPIOPinRead((uint32_t)GPIO_PORTF_BASE, (uint8_t)GPIO_PIN_2)) /*Read State*/
        State = ON;
    else
        State = OFF;
    return State;
}

uint8_t Read_Green_LEDs(void)
{
    if (GPIOPinRead((uint32_t)GPIO_PORTF_BASE, (uint8_t)GPIO_PIN_3))/*Read State*/
        State = ON;
    else
        State = OFF;
    return State;
}
