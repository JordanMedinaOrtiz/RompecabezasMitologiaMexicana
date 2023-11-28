void imprimir_PreguntasFacil(){
	struct PreguntasFacil *aux = primeraPreguntaFacil;
	
	if(aux == NULL){
		cout<<"No hay elementos en la lista"; 
		return;
	}
	
	cout<<"Mostrando la lista completa"<<endl;
	while(aux != NULL){
		cout<<"Ubicacion\t"; 
		cout<<aux<<endl;
		cout<<"ID\t\t";
		cout<<aux->id<<endl;
		cout<<"Pregunta\t";
		cout<<aux->pregunta<<endl;
		cout<<"Inciso A\t";
		cout<<aux->respuesta1<<endl;
		cout<<"Inciso B\t";
		cout<<aux->respuesta2<<endl;
		cout<<"Inciso C\t";
		cout<<aux->respuesta3<<endl;
		cout<<"Siguiente\t";
		cout<<aux->sig<<endl<<endl;
		aux = aux->sig;
	}
	cout<<endl<<endl<<"Primer NODO: "<<primeraPreguntaFacil;
	cout<<endl<<"Ultimo NODO: "<<ultimaPreguntaFacil;
}

void imprimir_PreguntasDificil(){
	struct PreguntasDificil *aux = primeraPreguntaDificil;
	
	if(aux == NULL){
		cout<<"No hay elementos en la lista"; 
		return;
	}
	
	cout<<"\n\nMostrando la lista completa"<<endl;
	while(aux != NULL){
		cout<<"Ubicacion\t"; 
		cout<<aux<<endl;
		cout<<"ID\t\t";
		cout<<aux->id<<endl;
		cout<<"Pregunta\t";
		cout<<aux->pregunta<<endl;
		cout<<"Respuesta\t";
		cout<<aux->respuesta<<endl;
		cout<<"Siguiente\t";
		cout<<aux->sig<<endl<<endl;
		aux = aux->sig;
	}
	cout<<endl<<endl<<"Primer NODO: "<<primeraPreguntaDificil;
	cout<<endl<<"Ultimo NODO: "<<ultimaPreguntaDificil;
}

void imprimir_Reglas(){
	struct Reglas *aux = primeraRegla;
	
	if(aux == NULL){
		cout<<"No hay elementos en la lista"; 
		return;
	}
	
	cout<<"\n\nMostrando la lista completa"<<endl;
	while(aux != NULL){
		cout<<"Ubicacion\t"; 
		cout<<aux<<endl;
		cout<<"ID\t\t";
		cout<<aux->id<<endl;
		cout<<"Regla\t";
		cout<<aux->regla<<endl;
		cout<<"Siguiente\t";
		cout<<aux->sig<<endl<<endl;
		aux = aux->sig;
	}
	cout<<endl<<endl<<"Primer NODO: "<<primeraRegla;
	cout<<endl<<"Ultimo NODO: "<<ultimaRegla;
}
