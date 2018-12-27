function  mostrarEscenario() {

	var agua = document.getElementById('agua');
	var hongo2= document.getElementById('hongo2');
	var ladrillo = document.getElementById('ladrillo');
	var salida= document.getElementById('salida');
	var salida2= document.getElementById('salida2');
	var piza = document.getElementById("pizarra");
    var entrada= document.getElementById('entrada');
    
    
    var lapiz = piza.getContext("2d");
    
	for(var i=0;i<f;i++)
	{
		for(var j=0;j<c;j++)
		{
			if(m[i][j]==0)
			{
				lapiz.drawImage(ladrillo,j*tam,i*tam,tam,tam);
			}
			else if(m[i][j]==1)  
			{
				lapiz.drawImage(agua,j*tam,i*tam,tam,tam);
			}
			else if(m[i][j]==2)  
			{
				lapiz.drawImage(hongo2,j*tam,i*tam,tam,tam);
			}
			else if(m[i][j]==3)  
			{
				lapiz.drawImage(salida,j*tam,i*tam,tam,tam);
			}
			else if(m[i][j]==4)  
			{
				lapiz.drawImage(salida2,j*tam,i*tam,tam,tam);
			}
			else if(m[i][j]==6)  
			{
				lapiz.drawImage(entrada,0,0,49,72,j*tam,i*tam,tam,tam);
			}
		}
	}

}
function movermario() {
    var mari2 = document.getElementById('mario2');
	var piza = document.getElementById("pizarra");
    var lapiz = piza.getContext("2d");
    var agua = document.getElementById('agua');
    
    
    var id = setInterval(frame, 100);
     
	 function frame() {
    	lapiz.drawImage(agua,posx*tam, posy*tam, tam, tam);
        lapiz.drawImage(mari2, nt*16, 0, 16, 16, posx*tam, posy*tam, tam, tam );
        nt = (nt+1)%4;
       }
}

function moverDerecha(){
   
    var piza = document.getElementById("pizarra");
    var lapiz = piza.getContext("2d");
    var agua = document.getElementById('agua');


    if(m[posy][posx+1]==1  || m[posy][posx+1]==5 || m[posy][posx+1]==3){
		lapiz.drawImage(agua, posx*tam, posy*tam, tam, tam );
		posx++;
	}
	if(m[posy][posx+1]==2){
		lapiz.drawImage(agua, posx*tam, posy*tam, tam, tam );
		posx++;
		contador.innerHTML = parseInt(contador.innerHTML)+1;
	}
	
}
function moverAbajo(){
   
    var piza = document.getElementById("pizarra");
    var lapiz = piza.getContext("2d");
    var agua = document.getElementById('agua');


    if(m[posy+1][posx]==1 || m[posy+1][posx]==5|| m[posy+1][posx]==4){
		lapiz.drawImage(agua, posx*tam, posy*tam, tam, tam );
		posy++;
		if(m[posy][posx]==4)
		{
			alert('cambiando de escenario');

			switch(escenarioActual)
			{
				case 0:
						p=m;
						m=m2;
						posx=posy=1;
						mostrarEscenario2();
						escenarioActual++;
						break;
				case 1:
						m2=m;
						m=p;
						posx=posy=1;
						mostrarEscenario();
						escenarioActual--;
						break;
						
			}
		}
			if(m[posy+1][posx]==2){
		lapiz.drawImage(agua, posx*tam, posy*tam, tam, tam );
		posy++;
		contador.innerHTML = parseInt(contador.innerHTML)+1;
	}
	}
}
function moverArriba(){
   
    var piza = document.getElementById("pizarra");
    var lapiz = piza.getContext("2d");
    var agua = document.getElementById('agua');


    if(m[posy-1][posx]==1 || m[posy-1][posx]==5){
		lapiz.drawImage(agua, posx*tam, posy*tam, tam, tam );
		posy--;
	
	}
	if(m[posy-1][posx]==2){
		lapiz.drawImage(agua, posx*tam, posy*tam, tam, tam );
		pos--;
		contador.innerHTML = parseInt(contador.innerHTML)+1;
	}
}
function moverIzquierda(){
   
    var piza = document.getElementById("pizarra");
    var lapiz = piza.getContext("2d");
    var agua = document.getElementById('agua');

   if(m[posy][posx-1]==1){
		lapiz.drawImage(agua, posx*tam, posy*tam, tam, tam );
		posx--;
	}
		if(m[posy][posx-1]==2){
		lapiz.drawImage(agua, posx*tam, posy*tam, tam, tam );
		posx--;
		contador.innerHTML = parseInt(contador.innerHTML)+1;
	}
}
function  mostrarEscenario2() {

	var agua = document.getElementById('agua');
	var ladrillo2 = document.getElementById('ladrillo2');
	var hongo2 = document.getElementById('hongo2');
	var salida4= document.getElementById('salida4');
	var salida5= document.getElementById('salida5');
    var piza = document.getElementById("pizarra");
    var lapiz = piza.getContext("2d");
    
	for(var i=0;i<f;i++)
	{
		for(var j=0;j<c;j++)
		{
			if(m2[i][j]==0)
			{
				lapiz.drawImage(ladrillo2,j*tam,i*tam,tam,tam);
			}
			else if(m2[i][j]==1)
			{
				lapiz.drawImage(agua,j*tam,i*tam,tam,tam);
			}
			else if(m2[i][j]==2)
			{
				lapiz.drawImage(hongo2,j*tam,i*tam,tam,tam);	
			}
			else if(m2[i][j]==4)  
			{
				lapiz.drawImage(salida4,j*tam,i*tam,tam,tam);
			}
			else if(m2[i][j]==5)  
			{
				lapiz.drawImage(salida5,j*tam,i*tam,tam,tam);
			}
		}
	}

}

