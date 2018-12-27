;programa para verifiCAR que todas los caracteres de una cadena se encuentran en otra.
; Definicion de stack

.MODEL small
.STACK  100

;DEFINICION DE AREAS DE TRABAJO
.DATA
TABLE1 DB 132,198,18,17,16,15,14,13,12,11
	DB 10,9,8,7,6,5,45,3,210,1
TOTAL DW 20 
CADENA DB 20 dup (" ")
SALTA db 13, 10,'$'



.CODE
PRINCI PROC FAR
   ;PROTOCOLO
   push ds
   sub ax,ax
   push ax
   MOV AX,@DATA
   MOV DS,AX
  ;INICIA PROGRAMA



CALL RECORRE
MOV SI, 0
MOV CX, TOTAL
SUB CX,1
DO1:
	MOV DI,SI
	INC DI
DO2:
		MOV DL, TABLE1[SI]
		MOV BL, TABLE1[DI]
		CMP DL,BL
		JNAE IIF1
			MOV TABLE1[SI],BL
			MOV TABLE1[DI],DL
IIF1:
		INC DI
		CMP DI,TOTAL
	JNAE DO2
	INC SI
	CMP SI, CX
JNAE DO1


CALL RECORRE                                                                                                                                                          
RET

PRINCI ENDP


RECORRE PROC
	LEA SI,TABLE1
	MOV CX, TOTAL
REGRESA: MOV DL, TABLE1[SI]
	CALL DESEMPAQUETA
;MOV DL," "
;CALL ESCRIBE_CAR
	INC SI
	LOOP REGRESA
RET
RECORRE ENDP


escribe_car PROC
 PUSH AX
 MOV AH,02 	; Caracter a desplegar almacenado en dl
 INT 21h
 POP AX
 RET 
escribe_car ENDP


leercadena PROC
PUSH DX
PUSH AX
LEA DX,CADENA
MOV AH,0AH
INT 21H
POP AX
POP DX
RET
leercadena ENDP

MENSAJE PROC
PUSH AX
MOV AH,09H
INT 21H
POP AX
RET
MENSAJE ENDP

LEE PROC
PUSH AX
MOV AH,01
INT 21H
POP AX
RET
LEE ENDP


;Código para la Subrutina Ascii-Binario

Ascii_Binario PROC
	CMP AL,30h
	JL ERROR
	CMP AL,39h
	JG LETRA
	SUB AL,30h	; Restar 30h
	JMP FINN
LETRA:  CMP AL,41h
	JL ERROR
	CMP AL,46h
	JG ERROR
	SUB AL,37h	; Restar 37h
	JMP FINN
ERROR:  MOV AL,0
FINN :   RET
Ascii_Binario ENDP


;Código para la Subrutina Binario-Ascii

Binario_Ascii PROC
	CMP DL,9h
	JG SUMA37
	ADD DL,30h
	JMP FIN
SUMA37: ADD DL,37h
FIN :  RET
Binario_Ascii ENDP

;Código para la Subrutina Empaqueta

Empaqueta PROC
	Push cx
	Call lee 	; Leer el primera car
	Call ascii_binario	;Procesa 1er. caracter
	Mov cl,04
	Shl al,cl	; Instrucción lógica de corrimiento a la izquierda 
	Mov ch,al	; Almacenando el valor de AL a un registro auxiliar
	Call lee 	; Leer el segundo car
	Call ascii_binario	;Procesa 2o. caracter
	Add al,ch	; Sumar  el contenido de los registros
	Pop cx
	RET
Empaqueta ENDP


;Código para la Subrutina Desempaqueta
Desempaqueta PROC
	Push dx
	Push cx
	Mov dh,dl	; Guardando el valor original en DH
	Mov cl,4
	Shr dl,cl	; Cuatro corrimientos a la derecha
	Call Binario_Ascii
	Call Escribe_car
	Mov dl,dh	; Recuperando el dato de DH
	And dl,0Fh	; Aplicando mascara
	Call Binario_ascii
	Call Escribe_car
	Pop cx
	Pop dx
	RET
Desempaqueta ENDP


END PRINCI