;programa para tasm QUE REPITE UN PATRON 7 VECES USANDO MOVSW
; Definicion de stack

.MODEL small
.STACK  100

;DEFINICION DE AREAS DE TRABAJO
.DATA
patron DB '***###'
marquesina db 43 DUP(?)

.CODE
PRINCI PROC FAR
   ;PROTOCOLO
   push ds
   sub ax,ax
   push ax
   MOV AX,@DATA
   MOV DS,AX
   MOV ES,AX

   ;INICIA PROGRAMA

   CLD
   MOV  CX,21
   LEA DI,MARQUESINA
   LEA SI,PATRON
   REP MOVSW
   MOV AL, '$'
   MOV [DI],AL
   LEA DX,MARQUESINA
   MOV AH,09
   INT 21H
   mov ah,01
   int 21h
   RET

PRINCI ENDP

END PRINCI