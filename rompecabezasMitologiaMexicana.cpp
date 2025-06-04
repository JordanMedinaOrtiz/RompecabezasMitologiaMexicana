#include "librerias.h"

int main(){
	setlocale(LC_CTYPE, "spanish");
	srand(time(NULL));
		
	primerJugador = NULL;
	ultimoJugador = NULL;
	primeraPreguntaFacil = NULL;
	ultimaPreguntaFacil = NULL;
	primeraPreguntaDificil = NULL;
	ultimaPreguntaDificil = NULL;
	primeraRegla = NULL;
	ultimaRegla = NULL;
	
	
	archivoLectura_PreguntasFacil();
	archivoLectura_PreguntasDificil();
	archivoLectura_Reglas();
	archivoLectura_Jugadores();
		
	initwindow(1400, 700, "Dioses de la Mitología Mexicana", 50, 50);
	portada();
	
	getch();
    return 0;
}
