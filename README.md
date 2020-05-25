# Diagnostic Tool Simulations
This project is a simulation of a CAN bus Diagnostic tool. One node is the diagnostic tool (node 1) and another one is the ECU that complies with node 1 commands.  

In our case, commands to node 2 can be summarized as follows: turning on a specific on-board LED, controlling the state machine direction, and reading both the on-board LED state and the state machine direction, according to a given control session.  

Default Control Session provides reading information from CAN state machine (node 2). Diagnostic tool can ask CAN State Machine for either the on-board LED state or the current state machine direction.  

Extended Control Session provides writing on the CAN state machine node. Diagnostic tool can overwrite the LED states and the current state machine direction.  

If diagnostic tool asked for a reading while in the extended control session or tried to overwrite while in default control session, it’ll receive a negative response from the CAN state machine node.  

## CAN State Machine  
### STATIC ARCHITECTURE  
![](Static%20Architectures/Node%201.png)

## API FUNCTIONS
### ECU Abstraction Layer
#### CAN0


| __Function Name__ | __InitCAN0__ |
|-------------|------------|
| Arguments         | void     | 
| Returned Parameter         | void | 
| Function Description    | Initializes CAN0 Module. | 


| __Function Name__ | __CANIntHandler__ |
|-------------|------------|
| Arguments         | void     | 
| Returned Parameter         | void | 
| Function Description    | Interrupt CAN Handler. Detects if an error occurred, sets receiving flag at successful receiving and clear interrupts at receiving and transmitting.   | 

| __Function Name__ | __Check_Err__ |
|-------------|------------|
| Arguments         | void     | 
| Returned Parameter         | void | 
| Function Description    | If Error Flag is set by the CAN handler, prints it. | 

| __Function Name__ | __Send_State__ |
|-------------|------------|
| Arguments         | Message ID (uint32_t MsgID): MsgID can be any ID for the message to be sent.  LED State (const char *LED): *LED can be either "Red", "Green", or "Blue". | 
| Returned Parameter         | void | 
| Function Description    | Sends a message on CAN bus using CAN0 module with the Message ID at MsgID. Message contains LED State and is sent through Object 1. | 
