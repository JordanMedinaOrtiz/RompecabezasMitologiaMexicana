void archivoEscritura_Jugadores(){
	Jugador *aux = primerJugador;
	ofstream archivo("archivos/jugadores.txt");
	while(aux != NULL){
		archivo<<aux->id<<"\t";
		archivo<<aux->nombre<<"\t";
		archivo<<aux->correo<<"\t";
		archivo<<aux->edad<<"\t";
		archivo<<aux->nickname<<"\t";
		archivo<<aux->contra<<"\t";
		archivo<<aux->puntajeTotal<<"\t";
		archivo<<aux->puntajeMayor<<endl;
		aux = aux->sig;
	}
	archivo.close();
}

void archivoLectura_Jugadores(){
	Jugador *nuevo = NULL;
	ifstream arch("archivos/jugadores.txt");
	string linea,c;
	if(arch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	else{
		while(getline(arch, linea)){
			nuevo = new Jugador;
			stringstream leer(linea);
			
			leer>>nuevo->id;
			getline(leer, c, '\t');
			getline(leer, nuevo->nombre, '\t');
			getline(leer, nuevo->correo, '\t');
			leer>>nuevo->edad;
			getline(leer, c, '\t');
			getline(leer, nuevo->nickname, '\t');
			getline(leer, nuevo->contra, '\t');
			leer>>nuevo->puntajeTotal;
			getline(leer, c, '\t');
			leer>>nuevo->puntajeMayor;
			getline(leer, c, '\n');
			
			nuevo->sig = NULL;
			
			if(primerJugador == NULL){
				primerJugador = nuevo;
				ultimoJugador = nuevo;
			}else{
				ultimoJugador->sig = nuevo;
				ultimoJugador = nuevo;
			}
		}
	}
	arch.close();
}

void archivoLectura_PreguntasFacil(){
	PreguntasFacil *nuevo = NULL;
	
	ifstream arch("archivos/facil.txt");
	string linea,c;
	
	if(arch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	else{
		while(getline(arch, linea)){
			nuevo = new PreguntasFacil;
			stringstream leer(linea);
			
			leer>>nuevo->id;
			getline(leer, c, '\t');
			getline(leer, nuevo->dios, '\t');
			getline(leer, nuevo->pregunta, '\t');
			getline(leer, nuevo->respuesta1, '\t');			
			getline(leer, nuevo->respuesta2, '\t');			
			getline(leer, nuevo->respuesta3, '\t');			
			getline(leer, nuevo->correcta, '\n');			
			nuevo->sig = NULL;
			
			if(primeraPreguntaFacil == NULL){
				primeraPreguntaFacil = nuevo;
				ultimaPreguntaFacil = nuevo;
			}else{
				ultimaPreguntaFacil->sig = nuevo;
				ultimaPreguntaFacil = nuevo;
			}
		}
	}
	arch.close();
}

void archivoLectura_PreguntasDificil(){
	PreguntasDificil *nuevo = NULL;
	
	ifstream arch("archivos/dificil.txt");
	string linea,c;
	
	if(arch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	else{
		while(getline(arch, linea)){
			nuevo = new PreguntasDificil;
			stringstream leer(linea);
			
			leer>>nuevo->id;
			getline(leer, c, '\t');
			getline(leer, nuevo->pregunta, '\t');
			getline(leer, nuevo->respuesta, '\n');
			nuevo->sig = NULL;
			
			if(primeraPreguntaDificil == NULL){
				primeraPreguntaDificil = nuevo;
				ultimaPreguntaDificil = nuevo;
			}else{
				ultimaPreguntaDificil->sig = nuevo;
				ultimaPreguntaDificil = nuevo;
			}
		}
	}
	arch.close();
}

void archivoLectura_Reglas(){
	Reglas *nuevo = NULL;
	
	ifstream arch("archivos/reglas.txt");
	string linea,c;
	
	if(arch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	else{
		while(getline(arch, linea)){
			nuevo = new Reglas;
			stringstream leer(linea);
			
			leer>>nuevo->id;
			getline(leer, c, '\t');
			getline(leer, nuevo->regla, '\n');			
			nuevo->sig = NULL;
			
			if(primeraRegla == NULL){
				primeraRegla = nuevo;
				ultimaRegla = nuevo;
			}else{
				ultimaRegla->sig = nuevo;
				ultimaRegla = nuevo;
			}
		}
	}
	arch.close();
}
