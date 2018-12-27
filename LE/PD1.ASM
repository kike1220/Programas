;programa ejemplo para masm

; DEFINICION SEGMENTO DE PILA
PILA segment para stack 'stack'		 
        DB 20 DUP (0)					; Define espacio en la pila
PILA ENDS

;DEFINICION DE AREAS DE TRABAJO

 ; DEFINICION  SEGMENTO DE DATOS
DATOS SEGMENT PARA 'DATA'
MEN1 DB ' EJEMPLO DE CARGADO DE DATOS$'
SALTA db 13, 10,'$'
Operando1 DB 08h
Operando2 DB 09h
Resultado DW 0000h 
DATOS ENDS

; DEFINICION  SEGMENTO DE CODIGO
CODIGO SEGMENT PARA 'CODE'
  
MAIN PROC FAR 							;Inicia proceso
      ASSUME SS:PILA, DS:DATOS,CS:CODIGO ;	;Alineación de Segmentos
     									;PROTOCOLO
       PUSH DS
   SUB AX,AX
   PUSH AX
   MOV AX,SEG DATOS
   MOV DS,AX

   ;INICIA PROGRAMA
     	
	LEA DX, MEN1
	CALL ESCRIBE_CADENA
	CALL LEER_CAR_SIN_ECO
	sub ax, ax
 	sub bx, bx
 	mov al, Operando1
 	mov bl, Operando2
 	mul bl
 	mov Resultado, ax
	MOV DL, AH
	CALL escribe_car 
	CALL alimentar_linea
	MOV DL, AL
	CALL escribe_car 
	
    RET
    MAIN ENDP				;Fin PROCEDIMIENTO PRINCIPAL


leer_car_con_eco PROC
 MOV AH,01	; Deja el caracter leído en al
 INT 21h
 RET
leer_car_con_eco ENDP


leer_car_sin_eco PROC
 MOV AH,08	; Deja el caracter leído en al
 INT 21h
 RET
Leer_car_sin_eco ENDP


escribe_car PROC
 PUSH AX
 MOV AH,02 	; Caracter a desplegar almacenado en dl
 INT 21h
 POP AX
 RET 
escribe_car ENDP

escribe_cadena PROC
 PUSH AX
 MOV AH,09 	; La direccion se almacena en el registro Dx
 INT 21h
 POP AX
 RET
escribe_cadena ENDP


alimentar_linea PROC
 PUSH DX
 MOV DL,0Ah	; salto de línea
 CALL ESCRIBE_CAR
 MOV DL,0Dh	; retorno de carro
 CALL ESCRIBE_CAR
 POP DX
 RET
alimentar_linea ENDP


sal_a_dos PROC
 MOV AH,4C 	
 INT 21h
 RET
sal_a_dos ENDP


;Código para la Subrutina Ascii-Binario

AsciiBinario PROC
	CMP AL,30h
	JL ERROR
	CMP AL,39h
	JG LETRA
	SUB AL,30h	; Restar 30h
	JMP FIN
LETRA:  CMP AL,41h
	JL ERROR
	CMP AL,46h
	JG ERROR
	SUB AL,37h	; Restar 37h
	JMP FIN
ERROR:  MOV AL,0
FIN :   RET
AsciiBinario ENDP


;Código para la Subrutina Binario-Ascii

BinarioAscii PROC
	CMP DL,9h
	JG SUMA37
	ADD DL,30h
	JMP FI
SUMA37: ADD DL,37h
FI :  RET
BinarioAscii ENDP




CODIGO ENDS 				;Fin segemento de códico
END MAIN			