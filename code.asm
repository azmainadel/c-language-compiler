.MODEL SMALL

.STACK 100H

.DATA
i DW ?

.CODE
MAIN PROC
MOV AX, @DATA
MOV DS, AX

MOV AX, 0 
MOV i, AX
L2:
MOV AX, i
CMP AX, 4
JL L0
MOV t0, 0
JMP L1
L0:
MOV t0, 1
L1:
MOV AX, i
CMP AX, 1
JNE L3
INC i 
INC i 
JMP L2
L3:

MAIN ENDP
END MAIN