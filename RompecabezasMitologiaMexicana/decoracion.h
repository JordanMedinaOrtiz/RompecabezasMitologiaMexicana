void cargando(){
	int x = 1200;
    
    setbkcolor(BROWN);
    setcolor(WHITE);
    settextstyle(8, 0, 3);
    outtextxy(x, 650, "Cargando...");

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(x, 675, 1365, 680);

    for(int i = x; i <= 1365; i++){
        setfillstyle(SOLID_FILL, BROWN);
        bar(x, 675, i, 680);
        delay(2);
    }
}

void areaTexto(int x, int y, int ancho, int alto){
    rectangle(x, y, x + ancho, y + alto);
}

void mostrarTexto(char* texto, int x, int y){
    outtextxy(x, y, texto);
}

void mostrarNumero(int numero, int x, int y){
	char texto[50];
    sprintf(texto, "%d", numero);
	
	outtextxy(x, y, texto);
}

void mostrarPreguntaFacil(struct PreguntasFacil *aux, int x, int y){
	char texto[100];
	strcpy(texto, aux->pregunta.c_str());
	
	outtextxy(x, y, texto);
}

void mostrarRespuestaA(struct PreguntasFacil *aux, int x, int y){
	char texto[100];
	strcpy(texto, aux->respuesta1.c_str());
	
	outtextxy(x-30, y, "A)");
	outtextxy(x, y, texto);
}

void mostrarRespuestaB(struct PreguntasFacil *aux, int x, int y){
	char texto[100];
	strcpy(texto, aux->respuesta2.c_str());
	
	outtextxy(x-30, y, "B)");
	outtextxy(x, y, texto);
}

void mostrarRespuestaC(struct PreguntasFacil *aux, int x, int y){
	char texto[100];
	strcpy(texto, aux->respuesta3.c_str());
	
	outtextxy(x-30, y, "C)");
	outtextxy(x, y, texto);
}

void mostrarID(struct Jugador *aux, int x, int y){
	char texto[100];
	int id = aux->id;
	
	sprintf(texto, "%d", id);
	
	outtextxy(x, y, texto);
}

void mostrarNickname(struct Jugador *aux, int x, int y){
	char texto[100];
	strcpy(texto, aux->nickname.c_str());
	
	outtextxy(x, y, texto);
}

void mostrarPuntuacion(struct Jugador *aux, int x, int y){
	char texto[100];
	int puntacion = aux->puntajeTotal;
	
    sprintf(texto, "%d", puntacion);
	
	outtextxy(x, y, texto);
}

void mostrarMejorPuntuacion(struct Jugador *aux, int x, int y){
	char texto[100];
	int puntacion = aux->puntajeMayor;
	
    sprintf(texto, "%d", puntacion);
	
	outtextxy(x, y, texto);
}

void mostrarReglas(struct Reglas *aux, int x, int y){
	char idTexto[100];
	char texto[500];
	int id = aux->id;
	
	if(id == 10){
		strcpy(texto, aux->regla.c_str());
		outtextxy(x-20, y, texto);
	}else{
		sprintf(idTexto, "%d)", id);
		outtextxy(x-30, y, idTexto);
		
		strcpy(texto, aux->regla.c_str());
		outtextxy(x, y, texto);
	}
}

void mostrarPreguntaDificil(struct PreguntasDificil *aux, int x, int y){
	char texto[100];
	strcpy(texto, aux->pregunta.c_str());
	
	outtextxy(x, y, texto);
}
