;PROGRAMA BUSCA EL MAYOR EN UN ARREGLO
; Definicion de stack
.MODEL small
.STACK  100

;DEFINICION DE AREAS DE TRABAJO
.DATA
;variables. 
v db 40,46,64,80,120,200,100, 34,01,10
mayor db 0

.CODE
PRINCI PROC FAR
   ;PROTOCOLO
   push ds
   sub ax,ax
   push ax
   MOV AX,@DATA
   MOV DS,AX

  
   ;INICIA PROGRAMA

  	mov cx, 9 ;cuantos elementos voy a recorrer, empezamos con el 10

inicio:
	 mov si, cx
dec cx
 	 mov dl, v[si]
CALL DESEMPAQUETA
 	cmp dl, mayor
 	jB siguiente
 	mov mayor,dl
siguiente:
 	cmp cx,0
jge inicio

 	
mov dl, mayor
CALL DESEMPAQUETA

	ret

PRINCI ENDP



escribe PROC
 PUSH AX
 MOV AH,02 	; Caracter a desplegar almacenado en dl
 INT 21h
 POP AX
 RET 
escribe ENDP

SALIR_DOS PROC
   MOV AH,4CH
   INT 21H
RET
SALIR_DOS ENDP

LEE PROC
   MOV AH,01
   INT 21H
RET
LEE ENDP

POS_CUR PROC
PUSH AX
PUSH BX
PUSH DX
MOV AH,02
MOV BH,0
MOV DH,05
MOV DL,20
INT 10h
POP DX
POP BX
POP AX
RET
POS_CUR ENDP

limpiar_pantalla PROC
PUSH AX
PUSH BX
PUSH CX
PUSH DX
MOV AX,0600h
MOV BH,71h		; FONDO BLANCO CON PRIMER PLANO AZUL
MOV CX,0000H
MOV DX,184FH
INT 10h
POP DX
POP CX
POP BX
POP AX
RET
limpiar_pantalla ENDP

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
	Call Escribe
	Mov dl,dh	; Recuperando el dato de DH
	And dl,0Fh	; Aplicando mascara
	Call Binario_ascii
	Call Escribe
	Pop cx
	Pop dx
	RET
Desempaqueta ENDP



END PRINCI
  
