# Diagnostic-Tool-Simulations-
This project is a kind of simulation of a CAN bus Diagnostic tool. One node is the diagnostic tool (node 1) and another one is the ECU that complies with node 1 commands.  

In our case, commands to node 2 can be summarized as follows: turning on a specific on-board LED, controlling the state machine direction, and reading both the on-board LED state and the state machine direction, according to a given control session.  

Default Control Session provides reading information from CAN state machine (node 2). Diagnostic tool can ask CAN State Machine for either the on-board LED state or the current state machine direction.  

Extended Control Session provides writing on the CAN state machine node. Diagnostic tool can overwrite the LED states and the current state machine direction.  

If diagnostic tool asked for a reading while in the extended control session or tried to overwrite while in default control session, it’ll receive a negative response from the CAN state machine node.  

In this document we represent for both nodes (diagnostic tool and CAN state machine) static architecture, API functions’ description, data format of sending commands and receiving information, compilation warning report, and MISRA report.  
