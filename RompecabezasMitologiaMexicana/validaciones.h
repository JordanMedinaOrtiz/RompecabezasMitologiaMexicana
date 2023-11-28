int validaInicioSesion(char nickname[], char contra[]){
	struct Jugador *aux = primerJugador;
	bool bandera = true;
	int tecla = 0;
	
	while(aux != NULL){
		if(nickname == aux->nickname){
			while(bandera){
				if(contra == aux->contra){
			    	setfillstyle(SOLID_FILL, BROWN);
			    	bar(350, 200, 1400, 220);
					mostrarTexto("Inicio de Sesion Correctamente.", 350, 200);
					bandera = false;
					return 1;
				}else{
					mostrarTexto("Contraseña incorrecta. Intentalo Nuevamente.", 350, 200);
					return 0;
				}
				aux = primerJugador;
			}
		}else{
			aux = aux->sig;
		}
	}
	mostrarTexto("Usuario incorrecto. Intentalo Nuevamente.", 350, 200);
	return 0;
}

int validaID(char mensaje[]){
	struct Jugador *aux = primerJugador;
	int valida = 0, id = 0;
	
	do{
		id = (rand() % 1000) + 100;
	}while(id >= 1000);
		
	while(aux != NULL){
		if(aux->id == id){
			do{
				id = (rand() % 1000) + 100;
			}while(id >= 1000);
            aux = primerJugador;
        }else{
            aux = aux->sig;
        }
	}
	
	mostrarTexto(mensaje, 540, 50);
	mostrarNumero(id, 850, 50);
		
	return id;
}

void validaNombre(char *mensaje, struct Jugador *aux, int tamano){
    bool bandera = true;
    int tecla;

    while(bandera){
    	char texto[tamano] = "";
		int x = 680;
    	setfillstyle(SOLID_FILL, BROWN);
    	bar(650, 100, 1400, 125);
		
		do{
			mostrarTexto(mensaje, 540, 100);
        	mostrarTexto(texto, 650, 100);

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
			    	bar(680, 100, i, 125);
				}
				x--;
	        }
    	}while(tecla != 13);
		
		aux->nombre = texto;
    	
		if(aux->nombre.length() > tamano){
			for(int i = x; i <= 1400; i++){
		    	setfillstyle(SOLID_FILL, BROWN);
		    	bar(680, 100, i, 130);
			}
			mostrarTexto("Máximo de caracteres: ", 540, 140);
			mostrarNumero(tamano, 850, 140);
			continue;
		}else{
			for(int i = x; i <= 1400; i++){
		    	setfillstyle(SOLID_FILL, BROWN);
		    	bar(540, 140, i, 160);
			}
			for(int i=0; i<aux->nombre.length(); i++){
				if(isalpha(aux->nombre[i]) || aux->nombre[i] == ' '){
					if(i == aux->nombre.length() -1){
						bandera = false;
					}
				}else break;
			}
		}
	}
}

void validaCorreo(char *mensaje, struct Jugador *aux){
	bool bandera = true;
	int tecla;
	
	while(bandera){
		char texto[100] = "";
		int x = 650;
		
		do{
			mostrarTexto(mensaje, 540, 150);
        	mostrarTexto(texto, 650, 150);

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
			    	bar(650, 150, i, 170);
				}
				x--;
	        }
    	}while(tecla != 13);
		
		aux->correo = texto;
		
		const char *arroba = strchr(aux->correo.c_str(), '@');
	    const char *punto = (arroba != NULL) ? strchr(arroba, '.') : NULL;
	    
	    if(arroba == NULL || punto == NULL || strlen(punto + 1) < 2){
	    	for(int i = x; i <= 1400; i++){
		    	setfillstyle(SOLID_FILL, BROWN);
		    	bar(650, 150, i, 170);
			}
	    	mostrarTexto("Correo Electronico no válido.", 540, 190);
		}else{
			bandera = false;
			for(int i = x; i <= 1400; i++){
		    	setfillstyle(SOLID_FILL, BROWN);
		    	bar(540, 190, i, 210);
			}
		}
	}
}

int validaEdad(char mensaje[]){
	int valida = 0, edad = 0;
	int tecla;
	
	char texto[10] = "";
	int x = 640;	
	
	do{
		mostrarTexto(mensaje, 540, 200);
    	mostrarTexto(texto, 640, 200);

    	tecla = getch();

        if(tecla >= '0' && tecla <= '9'){
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
		    	bar(650, 200, i, 220);
			}
			x--;
        }
	}while(tecla != 13);
	
	stringstream ss(texto);
	ss>>edad;
	
	return edad;
}

void validaNickname(char *mensaje, struct Jugador *nuevo, int tamano){
	struct Jugador *aux = primerJugador;
	bool bandera = true;
	int tecla = 0;
	
	while(bandera){
		char texto[tamano] = "";
		int x = 700;
		
		do{
			mostrarTexto(mensaje, 540, 250);
        	mostrarTexto(texto, 700, 250);

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
			    	bar(650, 250, i, 270);
				}
				x--;
	        }
    	}while(tecla != 13);
		
		nuevo->nickname = texto;
		
		if(nuevo->nickname.length() > tamano){
			for(int i = x; i <= 1400; i++){
		    	setfillstyle(SOLID_FILL, BROWN);
		    	bar(650, 250, i, 270);
			}
			mostrarTexto("Máximo de caracteres: ", 540, 290);
			continue;
		}else{
			bandera = false;
			for(int i = x; i <= 1400; i++){
		    	setfillstyle(SOLID_FILL, BROWN);
		    	bar(650, 290, i, 310);
			}
		}
	}
	
	while(aux != NULL){
		if(aux->nickname == nuevo->nickname){
			char texto[tamano] = "";
			int x = 700;
			mostrarTexto("El nombre de usuario ya está en uso", 540, 290);
			
			for(int i = x; i <= 1400; i++){
		    	setfillstyle(SOLID_FILL, BROWN);
		    	bar(650, 250, i, 270);
			}
			
			do{
				mostrarTexto(mensaje, 540, 250);
	        	mostrarTexto(texto, 700, 250);
	
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
				    	bar(650, 250, i, 270);
					}
					x--;
		        }
	    	}while(tecla != 13);
			
			nuevo->nickname = texto;
			
			if(nuevo->nickname.length() > tamano){
				mostrarTexto("Máximo de caracteres: ", 540, 290);
				continue;
			}
            aux = primerJugador;
            for(int i = x; i <= 1400; i++){
		    	setfillstyle(SOLID_FILL, BROWN);
		    	bar(650, 290, i, 310);
			}
        }else{
        	for(int i = x; i <= 1400; i++){
		    	setfillstyle(SOLID_FILL, BROWN);
		    	bar(650, 290, i, 310);
			}
            aux = aux->sig;
        }
	}
}

void validaContra(char *mensaje, struct Jugador *aux){
	bool bandera = true;
	char caracter, contra[50];
	int i = 0;
	int tecla = 0;
	
	char texto[50] = "";
	int x = 730;
	
	do{
		mostrarTexto(mensaje, 540, 300);
    	mostrarTexto(texto, 730, 300);

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
		    	bar(730, 300, i, 320);
			}
			x--;
        }
	}while(tecla != 13);
		
	aux->contra = texto;
}

int validaPreguntaFacil(char respuesta, int pregunta){
	struct PreguntasFacil *aux = primeraPreguntaFacil;
	
	while(aux != NULL){
		if(aux->id == pregunta){
			if(respuesta == 'a'){
				if(aux->respuesta1 == aux->correcta){
					mostrarTexto("Respuesta Correcta", 0, 650);
					return 1;
				}else{
					mostrarTexto("Respuesta Incorrecta", 0, 650);
					return 2;
				}
			}else if(respuesta == 'b'){
				if(aux->respuesta2 == aux->correcta){
					mostrarTexto("Respuesta Correcta", 0, 650);
					return 1;
				}else{
					mostrarTexto("Respuesta Incorrecta", 0, 650);
					return 2;
				}
			}else if(respuesta == 'c'){
				if(aux->respuesta3 == aux->correcta){
					mostrarTexto("Respuesta Correcta", 0, 650);
					return 1;
				}else{
					mostrarTexto("Respuesta Incorrecta", 0, 650);
					return 2;
				}
			}else mostrarTexto("Respuesta No Valida", 0, 650);
			break;
		}else{
			aux = aux->sig;
		}
	}
}

int validaPreguntaDificil(int pregunta){
	struct PreguntasDificil *aux = primeraPreguntaDificil;
	char respuesta[50];
	char texto[100] = "";
	int x = 150;
	int tecla = 0;
	
	do{
		mostrarTexto("Respuesta: ", 0, 500);
    	mostrarTexto(texto, 150, 500);

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
		    	bar(150, 500, i, 525);
			}
			x--;
        }
	}while(tecla != 13);
	
	strcpy(respuesta, texto);
	
	while(aux != NULL){
		if(aux->id == pregunta){
			if(respuesta == aux->respuesta){
				mostrarTexto("Respuesta Correcta", 0, 550);
				return 1;
			}else{
				mostrarTexto("Respuesta Incorrecta", 0, 550);
				return 2;
			}
			break;
		}else{
			aux = aux->sig;
		}
	}
}
