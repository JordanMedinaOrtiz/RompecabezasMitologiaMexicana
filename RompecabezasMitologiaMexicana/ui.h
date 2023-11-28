void menu(int x, int y, int inicio, int fin, int suma){
	char tecla = '\0';
	opc = 1;
	
	setbkcolor(BROWN);
	setcolor(WHITE);
	mostrarTexto("->", x, y);
	do{
		if(kbhit()){
			tecla =  getch();
			setbkcolor(BROWN);
			setcolor(BROWN);
		    mostrarTexto("->", x, y);
			if(opc > inicio && tecla == 72){
				y = y - suma;
				opc--;
			}
			if(opc < fin && tecla == 80){
				y = y + suma;
				opc++;
			}
			setbkcolor(BROWN);
		    setcolor(WHITE);
		    mostrarTexto("->", x, y);
		}
	}while(tecla != 13);
}

void seleccionModo(char nickname[]){
	cout<<"Seleccion: "<<nickname;
    
    while(opc != 5){
    	readimagefile("src/tlatoc.jpg", 0, 0, 1400, 700);
	    setbkcolor(BROWN);
	    mostrarTexto("Selecciona Lo Que Deseas Hacer.", 450, 0);
	    mostrarTexto("Jugar Modo Facil", 600, 150);
	    mostrarTexto("Jugar Modo Dificil", 600, 250);
	    mostrarTexto("Ver Tablero de Puntos", 600, 350);
	    mostrarTexto("Reglas del Juego", 600, 450);
	    mostrarTexto("Cambiar de Cuenta", 600, 550);
		menu(550, 150, 1, 5, 100);
		cargando();
		cleardevice();
		switch(opc){
			case OPC1:
				juegoFacil(nickname);
				getch();
				break;
			case OPC2:
				juegoDificil(nickname);
				getch();
				break;
			case OPC3:
				tablero(nickname);
				getch();
				break;
			case OPC4:
				reglas();
				getch();
				break;
			case OPC5:
				return;
				break;
		}
	}
	getch();
}

void seleccionIR(){
	PlaySound("src/musica_azteca.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	int x = 390, y = 0, v = 0;
	char nickname[100];
    
    while(opc != 3){
    	readimagefile("src/tlatoc.jpg", 0, 0, 1400, 700);
	    setbkcolor(BROWN);
	    mostrarTexto("Inicia Sesion o Registrate Para Poder Jugar.", x, y);
	    mostrarTexto("Iniciar Sesion", 600, 250);
	    mostrarTexto("Registro", 650, 350);
	    mostrarTexto("Salir", 652, 450);
		menu(550, 250, 1, 3, 100);
		cargando();
		cleardevice();
		switch(opc){
			case OPC1:
				v = sesion(nickname);
				getch();
				cout<<"Usuario: "<<nickname;
				if(v == 1){
					seleccionModo(nickname);
					break;
				}else break;
			case OPC2:
				registro();
				getch();
				break;
			case OPC3:
				archivoEscritura_Jugadores();
				closegraph();
				break;
		}
	}
	getch();
}

void portada(){
    readimagefile("src/portada.jpg", 0, 0, 1400, 700);
	
    getch();
    cargando();
    cleardevice();
    seleccionIR();
}
