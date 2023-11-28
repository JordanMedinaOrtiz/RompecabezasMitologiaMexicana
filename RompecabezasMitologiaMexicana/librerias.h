#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <ctype.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <graphics.h>
#include <fstream>
#include <sstream>
#include <locale.h>
#include <time.h>
#include <mmsystem.h>

using namespace std;

struct Jugador{
	int id;
	string nombre;
	string correo;
	int edad;
	string nickname;
	string contra;
	int puntajeTotal;
	int puntajeMayor;
	struct Jugador *sig;
}*primerJugador, *ultimoJugador;

struct PreguntasFacil{
	int id;
	string dios;
	string pregunta;
	string respuesta1;
	string respuesta2;
	string respuesta3;
	string correcta;
	struct PreguntasFacil *sig;
}*primeraPreguntaFacil, *ultimaPreguntaFacil;

struct PreguntasDificil{
	int id;
	string pregunta;
	string respuesta;
	struct PreguntasDificil *sig;
}*primeraPreguntaDificil, *ultimaPreguntaDificil;

struct Reglas{
	int id;
	string regla;
	struct Reglas *sig;
}*primeraRegla, *ultimaRegla;

enum MENU{OPC1 = 1, OPC2, OPC3, OPC4, OPC5, OPC6, OPC7};
int opc = 0, x = 0, y = 0;

#include "decoracion.h"
#include "validaciones.h"
#include "funciones.h"
#include "archivo.h"
#include "imprimir.h"
#include "ui.h"
