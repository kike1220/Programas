;programa ejemplo para masm

; DEFINICION SEGMENTO DE PILA
PILA segment para stack 'stack'		 
        DB 20 DUP (0)					; Define espacio en la pila
PILA ENDS

;DEFINICION DE AREAS DE TRABAJO

 ; DEFINICION  SEGMENTO DE DATOS
DATOS SEGMENT PARA 'DATA'
MEN1 DB ' EJEMPLO DE  SUMA DE DOS NUMEROS DE 2 DIGITOS$'
SALTA db 13, 10,'$'
NUM1 DB ?
NUM2 DB ?
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
	CALL alimentar_linea
	Call Empaqueta
	Mov dl,al
	MOV NUM1,DL
	CALL alimentar_linea
	Call empaqueta
	LEA DX, SALTA
	CALL ESCRIBE_CADENA
	MOV DL, NUM1
	Add dl,al
	Call desempaqueta     ;Observese que la suma no debe ser mayor a un byte
			
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
	Call leer_car_con_eco 	; Leer el primera car
	Call ascii_binario	;Procesa 1er. caracter
	Mov cl,04
	Shl al,cl	; Instrucción lógica de corrimiento a la izquierda 
	Mov ch,al	; Almacenando el valor de AL a un registro auxiliar
	Call leer_car_con_eco 	; Leer el segundo car
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


CODIGO ENDS 				;Fin segemento de códico
END MAIN			