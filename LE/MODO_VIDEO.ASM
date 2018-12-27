;PROGRAMA QUE MUESTRA EL MODO DE VIDEO

; Definicion de stack
.MODEL small
.STACK  100

;DEFINICION DE AREAS DE TRABAJO
.DATA
;variables. 
Modo1 db "Modo Grafico. 40x25. 256 colores. 320x200 pixels. 1 Pagina$", 0  
Modo2 db "Modo Texto. 80x25. 16 colores. 8 Paginas$",0 
Modo3 db "Modo Texto. 40x25. 16 colores. 8 Paginas$", 0     

.CODE
PRINCI PROC FAR
   ;PROTOCOLO
   push ds
   sub ax,ax
   push ax
   MOV AX,@DATA
   MOV DS,AX
  

   ;INICIA PROGRAMA

  	; modo de video 
	mov al, 00h 
	mov ah, 0 
	int 10h 
	
	;imprimimos cadena del modo GRAFICO 
	mov dx, offset Modo3 
	mov ah, 9 
	int 21h 
	; hacemos esperar al programa que el usuario toque una tecla                   
	mov ah,0 
	int 16h  
	;Convetimos al modo 80x25 e imprimimos la cadena en tipo texto   
	mov al, 03h 
	mov ah, 0 
	int 10h 
	
	mov dx, offset Modo2 
	mov ah, 9 
	int 21h  
	;idem 40x25  
	mov ah, 0 
	int 16h 
	mov al, 13h 
	mov ah, 0 
	int 10h 
	mov dx, offset Modo1 
	mov ah, 9 
	int 21h 
	mov ah, 0 
	int 16h 
	;devolvemos el handle a Windows  
	ret                           
       


PRINCI ENDP



ESCRIBE PROC
   MOV AH,02
   INT 21H
 RET
ESCRIBE ENDP

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


END PRINCI
  
