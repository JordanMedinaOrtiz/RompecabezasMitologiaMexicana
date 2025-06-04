int sesion(char nickname[50]){
	struct Jugador *aux = primerJugador;
	char contra[50];
	int x = 450;
	int tecla = 0;
	int v = 0;
	
	if(aux == NULL){
		mostrarTexto("No Hay Ningun Jugador Registrado.", 480, 0);
		mostrarTexto("Registrate Para Poder Iniciar Sesion.", 450, 50);
	}else{
			mostrarTexto("Inicia Sesion Para Poder Jugar", 480, 0);
			char texto[50] = "";
			int x = 500;
			
			do{
				mostrarTexto("Nickname: ", 350, 100);
	        	mostrarTexto(texto, 500, 100);
	
	        	tecla = getch();
	
		        if(tecla >= 32 && tecla <= 126){
		            int tam = strlen(texto);
		            if(tam < sizeof(texto) - 1){
		                texto[tam] = static_cast<char>(tecla);
		                texto[tam + 1] = '\0';
		                x++;
		            }
		        }else if(tecla == 8){
		            int tam = strlen(texto);
		            if(tam > 0){
		                texto[tam - 1] = '\0';
		            }
		            for(int i = x; i <= 1400; i++){
				    	setfillstyle(SOLID_FILL, BROWN);
				    	bar(500, 100, i, 125);
					}
					x--;
		        }
	    	}while(tecla != 13);
	    	
	    	strcpy(nickname, texto);
			
			char texto2[50] = "";
			x = 540;
			
			do{
				mostrarTexto("Contraseña: ", 350, 150);
	        	mostrarTexto(texto2, 540, 150);
	
	        	tecla = getch();
	
		        if(tecla >= 32 && tecla <= 126){
		            int tam = strlen(texto2);
		            if(tam < sizeof(texto2) - 1){
		                texto2[tam] = static_cast<char>(tecla);
		                texto2[tam + 1] = '\0';
		                x++;
		            }
		        }else if(tecla == 8){
		            int tam = strlen(texto2);
		            if(tam > 0){
		                texto2[tam - 1] = '\0';
		            }
		            for(int i = x; i <= 1400; i++){
				    	setfillstyle(SOLID_FILL, BROWN);
				    	bar(540, 150, i, 175);
					}
					x--;
		        }
	    	}while(tecla != 13);
	    	
	    strcpy(contra, texto2);
		v = validaInicioSesion(nickname, contra);
	}
	
	if(v == 1){
		return 1;
	}else{
		return 2;
	}	
}

void registro(){
	struct Jugador *nuevo = new Jugador;
	mostrarTexto("Registro", 650, 0);
	
	nuevo->id = validaID("Tu ID de usuario es: ");
	cout<<"\nID: "<<nuevo->id;
	validaNombre("Nombre: ", nuevo, 30);
	cout<<"\nNombre Ingresado: "<<nuevo->nombre;
	validaCorreo("Correo: ", nuevo);
	cout<<"\nCorreo Ingresado: "<<nuevo->correo;
	nuevo->edad = validaEdad("Edad: ");
	cout<<"\nEdad Ingresada: "<<nuevo->edad;
	validaNickname("Nickname: ", nuevo, 15);
	cout<<"\nNickname Ingresado: "<<nuevo->nickname;
	validaContra("Contraseña: ", nuevo);
	cout<<"\nContraseña Ingresada: "<<nuevo->contra;
	cout<<"\n";
	nuevo->puntajeMayor = 0;
	nuevo->puntajeTotal = 0;
	nuevo->sig = NULL;
	
	if(primerJugador == NULL){
		primerJugador = nuevo;
		ultimoJugador = nuevo;
	}else{
		ultimoJugador->sig = nuevo;
		ultimoJugador = nuevo;
	}
}

void rompecabezas(int imagen){
	switch(imagen){
		case 1:
			readimagefile("src/r1.jpg", 50, 10, 300, 82);
			break;
		case 2:
			readimagefile("src/r2.jpg", 301, 10, 550, 82);
			break;
		case 3:
			readimagefile("src/r3.jpg", 551, 10, 800, 82);
			break;
		case 4:
			readimagefile("src/r4.jpg", 50, 82, 300, 164);
			break;
		case 5:
			readimagefile("src/r5.jpg", 301, 82, 550, 164);
			break;
		case 6:
			readimagefile("src/r6.jpg", 551, 82, 800, 164);
			break;
		case 7:
			readimagefile("src/r7.jpg", 50, 164, 300, 246);
			break;
		case 8:
			readimagefile("src/r8.jpg", 301, 164, 550, 246);
			break;
		case 9:
			readimagefile("src/r9.jpg", 551, 164, 800, 246);
			break;
		case 10:
			readimagefile("src/r10.jpg", 50, 246, 300, 328);
			break;
		case 11:
			readimagefile("src/r11.jpg", 301, 246, 550, 328);
			break;
		case 12:
			readimagefile("src/r12.jpg", 551, 246, 800, 328);
			break;
		default:
			printf("Imagen no reconocida: %d\n", imagen);
            break;
	}	
}

void juegoFacil(char nickname[]){
	struct PreguntasFacil *aux = primeraPreguntaFacil;
	struct Jugador *auxJugador = primerJugador;
	char respuesta[2];
	int puntaje = 100, opc = 0, correctas = 0, pregunta = 0, auxPregunta[30] = {0}, imagen = 0, auxImagen[12] = {0};
	
	for(int i=0; i<15; i++){		
		aux = primeraPreguntaFacil;
	    setfillstyle(SOLID_FILL, BROWN);
	    bar(0, 350, 1400, 700);
	    bar(1085, 300, 1400, 340);
		
		mostrarTexto("Puntos: ", 1055, 260);
		mostrarNumero(puntaje, 1085, 300);
		
		while(auxJugador != NULL){
			if(auxJugador->nickname == nickname){
				mostrarTexto("Mejor Puntaje: ", 1020, 160);
				mostrarMejorPuntuacion(auxJugador, 1085, 200);
				break;
			}else{
				auxJugador = auxJugador->sig;
			}
		}
		
		do{
            pregunta = (rand() % 30) + 1;
        }while(auxPregunta[pregunta - 1] != 0);
        auxPregunta[pregunta - 1] = 1;
        
        while(aux != NULL){
        	if(aux->id == pregunta){
        		cout<<"\nPregunta "<<aux->id;
        		mostrarPreguntaFacil(aux, 0, 400);
				mostrarRespuestaA(aux, 30, 450);
				mostrarRespuestaB(aux, 30, 500);
				mostrarRespuestaC(aux, 30, 550);
				
				mostrarTexto("Selecciona la opcion correcta: ", 0, 600);
				
				char texto[2] = "";
				x = 350;
				int tecla = 0;
				
				do{
					mostrarTexto("Selecciona la opcion correcta: ", 0, 600);
		        	mostrarTexto(texto, 450, 600);
		
		        	tecla = getch();
		
			        if(tecla >= 97 && tecla <= 99){
			            int tam = strlen(texto);
			            if(tam < sizeof(texto) - 1){
			                texto[tam] = static_cast<char>(tecla);
			                texto[tam + 1] = '\0';
			                x++;
			            }
			        }else if(tecla == 8){
			            int tam = strlen(texto);
			            if(tam > 0){
			                texto[tam - 1] = '\0';
			            }
			            for(int i = x; i <= 1400; i++){
					    	setfillstyle(SOLID_FILL, BROWN);
					    	bar(450, 600, i, 625);
						}
						x--;
			        }
		    	}while(tecla != 13);
						
				strcpy(respuesta, texto);
				
				opc = validaPreguntaFacil(respuesta[0], pregunta);
				
				if(opc == 1){
					PlaySound("src/punto.wav", NULL, SND_FILENAME | SND_LOOP | SND_SYNC);
					PlaySound("src/musica_azteca.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
					puntaje += 10;
					correctas += 1;
					if(correctas <= 12){
						do{
			            imagen = (rand() % 12) + 1;
				        }while(auxImagen[imagen - 1] != 0);
				        auxImagen[imagen - 1] = 1;
				        rompecabezas(imagen);
					}
				}else{
					PlaySound("src/perdida.wav", NULL, SND_FILENAME | SND_LOOP | SND_SYNC);
					PlaySound("src/musica_azteca.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
					puntaje -= 5;
				}
				
				getch();
        		break;
			}else{
				aux = aux->sig;
			}
		}
	}
	
	if(correctas >= 12){
		puntaje += 50;
	}else{
		puntaje /= 2;
	}
	
	auxJugador = primerJugador;
			
	while(auxJugador != NULL){
		if(auxJugador->nickname == nickname){
			auxJugador->puntajeTotal += puntaje;
			if(auxJugador->puntajeMayor < puntaje){
				auxJugador->puntajeMayor = puntaje;
			}
			cleardevice();
			mostrarTexto("Fin del Juego", 550, 300);
			mostrarTexto("Preguntas Contestadas Correctamente: ", 400, 400);
			mostrarNumero(correctas, 1000, 400);
			mostrarTexto("Puntaje Final del Juego: ", 400, 450);
			mostrarNumero(puntaje, 800, 450);
			mostrarTexto("Puntaje Total Acumulado: ", 400, 500);
			mostrarPuntuacion(auxJugador, 800, 500);
			mostrarTexto("Mejor Puntuaje: ", 400, 550);
			mostrarMejorPuntuacion(auxJugador, 700, 550);
			break;
		}else{
			auxJugador = auxJugador->sig;
		}
	}
}

void juegoDificil(char nickname[]){
	struct PreguntasDificil *aux = primeraPreguntaDificil;
	struct Jugador *auxJugador = primerJugador;
	int puntaje = 100, opc = 0, correctas = 0, pregunta = 0, auxPregunta[30] = {0}, imagen = 0, auxImagen[12] = {0};
	
	for(int i=0; i<15; i++){
		aux = primeraPreguntaDificil;
    	setfillstyle(SOLID_FILL, BROWN);
    	bar(0, 450, 1400, 700);
	    bar(1085, 300, 1400, 340);
		
		do{
            pregunta = (rand() % 30) + 1;
        }while(auxPregunta[pregunta - 1] != 0);
        auxPregunta[pregunta - 1] = 1;
        
        mostrarTexto("Puntos: ", 1055, 260);
		mostrarNumero(puntaje, 1085, 300);
		
		while(auxJugador != NULL){
			if(auxJugador->nickname == nickname){
				mostrarTexto("Mejor Puntaje: ", 1020, 160);
				mostrarMejorPuntuacion(auxJugador, 1085, 200);
				break;
			}else{
				auxJugador = auxJugador->sig;
			}
		}
        
        while(aux != NULL){
        	if(aux->id == pregunta){
		        cout<<"\nPregunta "<<aux->id;
        		mostrarPreguntaDificil(aux, 0, 450);
				
				opc = validaPreguntaDificil(pregunta);
				if(opc == 1){
					PlaySound("src/punto.wav", NULL, SND_FILENAME | SND_LOOP | SND_SYNC);
					PlaySound("src/musica_azteca.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
					puntaje += 10;
					correctas += 1;
					if(correctas <= 12){
						do{
			            	imagen = (rand() % 12) + 1;
				        }while(auxImagen[imagen - 1] != 0);
				        auxImagen[imagen - 1] = 1;
				        rompecabezas(imagen);
					}
				}else{
					PlaySound("src/perdida.wav", NULL, SND_FILENAME | SND_LOOP | SND_SYNC);
					PlaySound("src/musica_azteca.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
					puntaje -= 5;
				}
				
				getch();
				break;
			}else{
				aux = aux->sig;
			}
		}
	}
	
	if(correctas >= 12){
		puntaje += 50;
	}else if(correctas < 12){
		puntaje /= 2;
	}
	
	auxJugador = primerJugador;
		
	while(auxJugador != NULL){
		if(auxJugador->nickname == nickname){
			auxJugador->puntajeTotal += puntaje;
			if(auxJugador->puntajeMayor < puntaje){
				auxJugador->puntajeMayor = puntaje;
			}
			cleardevice();
			mostrarTexto("Fin del Juego", 550, 300);
			mostrarTexto("Preguntas Contestadas Correctamente: ", 400, 400);
			mostrarNumero(correctas, 1000, 400);
			mostrarTexto("Puntaje Final del Juego: ", 400, 450);
			mostrarNumero(puntaje, 800, 450);
			mostrarTexto("Puntaje Total Acumulado: ", 400, 500);
			mostrarPuntuacion(auxJugador, 800, 500);
			mostrarTexto("Mejor Puntuaje: ", 400, 550);
			mostrarMejorPuntuacion(auxJugador, 700, 550);
			break;
		}else{
			auxJugador = auxJugador->sig;
		}
	}
}

void ordenarLista(){
	Jugador *aux = primerJugador;
	Jugador *actual, *min;
	Jugador *pivote1 = new Jugador;
	Jugador *pivote2 = new Jugador;
	
	while(aux != NULL){
		min = aux;
		actual = aux->sig;
		while(actual != NULL){
			if(min->puntajeMayor < actual->puntajeMayor){
				min = actual;	
			}
			actual = actual->sig;
		}
		
		pivote1->id = aux->id;
		pivote1->nombre = aux->nombre;
		pivote1->correo = aux->correo;
		pivote1->edad = aux->edad;
		pivote1->nickname = aux->nickname;
		pivote1->contra = aux->contra;
		pivote1->puntajeMayor = aux->puntajeMayor;
		pivote1->puntajeTotal = aux->puntajeTotal;
		
		pivote2->id = min->id;
		pivote2->nombre = min->nombre;
		pivote2->correo = min->correo;
		pivote2->edad = min->edad;
		pivote2->nickname = min->nickname;
		pivote2->contra = min->contra;
		pivote2->puntajeMayor = min->puntajeMayor;
		pivote2->puntajeTotal = min->puntajeTotal;
		
		min->id = pivote1->id;
		min->nombre = pivote1->nombre;
		min->correo = pivote1->correo;
		min->edad = pivote1->edad;
		min->nickname = pivote1->nickname;
		min->contra = pivote1->contra;
		min->puntajeMayor = pivote1->puntajeMayor;
		min->puntajeTotal = pivote1->puntajeTotal;
		
		aux->id = pivote2->id;
		aux->nombre = pivote2->nombre;
		aux->correo = pivote2->correo;
		aux->edad = pivote2->edad;
		aux->nickname = pivote2->nickname;
		aux->contra = pivote2->contra;
		aux->puntajeMayor = pivote2->puntajeMayor;
		aux->puntajeTotal = pivote2->puntajeTotal;
		
		aux = aux->sig;
	}
	
}

void tablero(char nickname[]){
	struct Jugador *aux = primerJugador;
	int y = 150;
	ordenarLista();
	
	mostrarTexto("Tabala de Puntuaciones", 550, 0);
	mostrarTexto("ID del Usuario: ", 0, 100);
	mostrarTexto("Nickname: ", 350, 100);
	mostrarTexto("Puntuacion Total: ", 700, 100);
	mostrarTexto("Mejor Puntuacion: ", 1050, 100);
	
	if(aux == NULL){
		mostrarTexto("No Hay Registros de Jugadores", 400, 200);
		return;
	}
	
	while(aux != NULL){
		if(aux->nickname == nickname){
			setcolor(BLACK);
		}else{
			setcolor(WHITE);
		}
		
		mostrarID(aux, 100, y);
		mostrarNickname(aux, 350, y);
		mostrarPuntuacion(aux, 800, y);
		mostrarMejorPuntuacion(aux, 1150, y);
		y += 50;
		aux = aux->sig;
	}
	setcolor(WHITE);
}

void reglas(){
	struct Reglas *aux = primeraRegla;
	int y = 50;
	
	if(aux == NULL){
		mostrarTexto("No Se Pueden Mostrar Las Reglas. Intentalo Mas Tarde.", 100, 200);
		return;
	}
	
	mostrarTexto("Reglas", 600, 0);
	while(aux != NULL){
		mostrarReglas(aux, 30, y);
		aux = aux->sig;
		y += 30;
	}
}
