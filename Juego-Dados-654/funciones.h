#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROTOTIPOS
void mostarVector(int[], int);
void cargarVector(int[], int);
void cargarAletorio(int[], int, int);
void cuadro (int x1,int x2,int y1,int y2);
void cargarCadena(char *pal, int tam);
int acumularDados(int dados[], int tam);
void verificarDados(int [], int, bool []);
void sonrisa(int x1,int x2,int y);
void dibujarDado(int posx, int posy, int num, int tam);
void dibujarCuadrado(int posx, int posy, int tam);
int puntuacionmasAlta(char[],int,int);
int cargarNombres(char [], int[], int[]);
int sacarGanador(char [],int [],int[], int, int);
void reglas();

int punto1();


///DESARROLLO
void reglas(){
    cuadro(46,65,2,6);
    rlutil::locate(48,4);
    cout << "REGLAS DEL JUEGO ";
    cuadro(7,116,11,17);
    rlutil::locate(8,12);
    cout << "SeisCincoCuatro es un juego que utiliza 5 dados de 6 caras y necesita por lo menos de 2 participantes.";
    rlutil::locate(8,13);
    cout << "El objetivo del juego es conseguir en orden nuestro Barco (6), nuestro Capitan (5) y la Tripulacion (4),";
    rlutil::locate(8,14);
    cout << "sumarizar los dados restantes que representan la carga, numero que sera el puntaje obtenido en la ronda.";
    rlutil::locate(8,15);
    cout << "Para lograrlo tenemos un total de 3 tiradas. Debemos obtener primero el barco, para luego  poder contratar";
    rlutil::locate(8,16);
    cout << "al capitan, y tanto el barco como el capitan van a ser necesarios para que podamos acceder a la tripulacion.";
    rlutil::locate(8,25);
}

///DIBUJA LOS CUADRADOS DE LOS DADOS
void dibujarCuadrado(int posx, int posy, int tam) {
	for (int y = 1; y <= tam / 2; y++) {
		for (int x = 1; x <= tam; x++) {
			rlutil::locate(x + posx, y + posy);
			cout << (char)219;
		}
	}
}

///DIBUJA EL DADO
void dibujarDado(int posx, int posy, int num, int tam) {
	rlutil::setBackgroundColor(rlutil::BLACK);
	rlutil::setColor(rlutil::LIGHTBLUE);
	rlutil::saveDefaultColor();

	rlutil::setColor(rlutil::BLUE);
	dibujarCuadrado(posx, posy, tam);

	rlutil::setBackgroundColor(rlutil::BLUE);
	rlutil::setColor(rlutil::BLACK);

	switch (num)
	{
	case 1:
		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		cout << (char)254;
		break;

	case 2:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);

		cout << (char)220;


		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);

		cout << (char)223;

		break;

	case 3:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);

		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);

		cout << (char)254;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);

		cout << (char)223;

		break;


	case 4:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);

		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);

		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);

		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);

		cout << (char)223;

		break;

	case 5:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);

		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);

		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);

		cout << (char)254;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);

		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);

		cout << (char)223;
		break;


	case 6:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);

		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);

		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 / 4 + 1);

		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 2 - tam / 4 / 4);

		cout << (char)223;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);

		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);

		cout << (char)223;

		break;

	default:
		break;
	}
	rlutil::resetColor();
	rlutil::setBackgroundColor(rlutil::BLACK);

	rlutil::setColor(rlutil::LIGHTBLUE);
	// sombra

	for (int y = posy + 2; y <= posy + tam / 2 + 1; y++) {
		rlutil::locate(posx + tam + 1, y);

		cout << (char)219;
	}


	for (int x = posx + 2; x <= posx + tam + 1; x++) {
		rlutil::locate(x, posy + tam / 2 + 1);

		cout << (char)223;
	}

	rlutil::locate(posx + tam + 1, posy + 1);

	cout << (char)220;

	rlutil::locate(1, posy + tam/2 + 1);
	rlutil::resetColor();

    }


void mostrarVector(int v[], int tam){
    int i, x;
    x=30;
    for(i=0;i<tam;i++){

        dibujarCuadrado(x,10,7);
        dibujarDado(x,10,v[i],7);
        x+=10;
    }
}

void cargarVector(int v[], int tam){
    int i, y=8;
    for(i=0;i<tam;i++){
        cuadro(4,23,7,13);
        rlutil::locate(5, y);
        cout<<"INGRESE DADO "<<i+1<<": ";
        cin>>v[i];
        y++;
    }
}

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for(i=0;i<tam;i++){
    v[i]=(rand()%limite)+1;
  }
}

void cuadro (int x1,int x2,int y1,int y2) {

    int x=y1, j=y1;
    rlutil::locate(x1, y1);

    cout << (char)201;

    for (int i=0; i<x2-x1-1; i++) {

        cout << (char)205;

    }


    rlutil::locate(x2, y1);
    cout << (char)187;


    for (int i=0; i<y2-y1-1; i++) {
        x++;
        rlutil::locate(x2, x);
        cout << (char)186 << endl;
    }


    cout << endl;

    for (int i=0; i<y2-y1-1; i++) {
        j++;
        rlutil::locate(x1, j);

        cout << (char)186 << endl;
    }


    rlutil::locate(x1, y2);
    cout << (char)200;void cargarCadena(char *pal, int tam);



    for (int i=0; i<x2-x1-1; i++){

        cout << (char)205;


    }

    rlutil::locate (x2, y2);
    cout << (char)188;
}

void sonrisa(int x1,int x2,int y) {


    rlutil::locate(x1, y-1);
    cout << (char)186;
    rlutil::locate(x1, y-2);
    cout << (char)186;
    rlutil::locate(x2, y-1);
    cout << (char)186;
    rlutil::locate(x2, y-2);
    cout << (char)186;
    rlutil::locate(x1, y);
    cout << (char)200;

    for (int i=x1+1; i<x2+1; i++) {
        rlutil::locate(i, y);
        cout << (char)205;
    }

    rlutil::locate(x2, y);
    cout << (char) 188;
    cout << endl << endl;
}


void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}


void verificarDados(int dados[], int tam, bool v654[]){

    for(int i=0;i<tam;i++){
        if(dados[i]==6){
            v654[0]=true;
        }
        if(dados[i]==5){
            v654[1]=true;
        }
        if(dados[i]==4){
            v654[2]=true;
        }
    }
}

int acumularDados(int dados[], int tam){
    int puntaje=0,i;
    if(tam==5){
        for(i=0;i<tam;i++){
            puntaje+=dados[i];
        }
        puntaje=puntaje-15;
    }
    else if(tam==4){
        for(i=0;i<tam;i++){
            puntaje+=dados[i];
        }
        puntaje=puntaje-9;

    }
    else if(tam==3){
        for(i=0;i<tam;i++){
            puntaje+=dados[i];
        }
        puntaje=puntaje-4;

    }
    else if(tam==2){
        for(i=0;i<tam;i++){
            puntaje+=dados[i];
        }

    }
    return puntaje;
}

int cargarNombres(char vnombre[][50],int jugadores, int tam2){
///NOMBRES Y RONDAS
    int rondas,y=3,y2=4;
    char nombre[50];
    for(int i=0;i<jugadores;i++){

        cuadro(37,75,2,28);
        rlutil::locate(38,y);
        cout <<  "Nombre jugador " <<  i+1 << ": ";
        rlutil::locate(38,y2);
        cargarCadena(nombre,50);
        strcpy(vnombre[i],nombre);

        y=y+2;
        y2=y+1;
    }

    cout << endl << endl;
    rlutil::locate(38,25);
    cout << "Ingrese cantidad de rondas: ";
    rlutil::locate(38,26);
    cin >> rondas;

    return rondas;

    system("cls");
}

int sacarGanador(char vnombres[][50], int vpuntajes[], int vtiradas[], int jugadores, int C){
    int maxi,pos,cp=0,ct=0;
    maxi=vpuntajes[0];
    pos=0;

    for(int p=1;p<jugadores;p++){
        if(vpuntajes[p]>maxi){
            maxi=vpuntajes[p];
            pos=p;
        }
        else if(vpuntajes[p]==maxi){
            cp++;
        }

    }

    if(cp==jugadores-1){
        maxi=vtiradas[0];
        pos=0;
        for(int p=1;p<jugadores;p++){
            if(vtiradas[p]<maxi){

                maxi=vpuntajes[p];
                pos=p;

            }
            else if(vtiradas[p]==maxi){
                ct++;
            }
        }
    }

    if(ct!=jugadores-1){
        cuadro(37,96,9,17);
        rlutil::locate(38,10);
        cout << "GANADOR: " << vnombres[pos];
        rlutil::locate(38,13);
        cout << "SUS PUNTOS: " << vpuntajes[pos];
        rlutil::locate(38,16);
        cout << "SUS TIRADAS: " << vtiradas[pos];

        rlutil::locate(60,28);
    }
    else{
        rlutil::locate(60,13);
        cout << "EMPATE";
    }
    return pos;

}


///MODO DOS JUGADORES, MODO CONTRA MAQUINA Y MODO SIMULADO
int punto1(int C, char vnombres[][50], int jugadores, int tamcad, int vpuntajes[], int vtiradas[], int rondas){
    int dados[5],tam=5,tiradas=3,embarque,puntaje=0,g,i,puntajeronda=0,tamant,acutiradas=0,pos,confirmacion=0;
    bool barco=false, capitan=false, tripulacion=false,v654[3]={};
    char opcion;

    for(i=0;i<jugadores;i++){
        vpuntajes[i]=0;
        vtiradas[i]=0;
    }
    system("cls");
    for(int x=0;x<jugadores;x++){
        for(g=0;g<rondas;g++){
            for(i=0;i<tiradas;i++){


                ///INFORMACION JUGADOR, RONDAS Y TIRADAS
                cuadro(1,40,1,3);
                cuadro(40,79,1,3);
                cuadro(79,118,1,3);
                rlutil::locate(2,2);

                cout << "JUGADOR:     " << vnombres[x];
                rlutil::locate(50,2);
                cout << "     RONDA:     " << g+1;
                rlutil::locate(89,2);
                cout << "     TIRADA:    " << i+1;
                cuadro(1,40,4,6);
                rlutil::locate(2,5);
                cout << "PUNTAJE ACUMULADO:       " << vpuntajes[x];



                if(C<5){
                    cargarAleatorio(dados,tam,6);

                    rlutil::locate(30,10);
                    mostrarVector(dados,tam);
                }
                else if(C==6){
                    cargarVector(dados,tam);

                    rlutil::locate(30,10);
                    mostrarVector(dados,tam);
                }

                cout << endl;
                ///VERIFICACION DE DADOS
                verificarDados(dados,tam,v654);
                tamant=tam;

                for(int i=0;i<3;i++){
                    if(v654[i]==true){
                        if(i==0 && confirmacion==0){
                            barco=true;
                            tam=4;
                            confirmacion=1;
                        }
                        else if(i==1 && confirmacion==1){
                            capitan=true;
                            tam=3;
                            confirmacion=2;
                        }
                        else if(i==2 &&  confirmacion==2){
                            tripulacion=true;
                            tam=2;
                            confirmacion=3;
                        }
                    }

                }

                ///CUADRO OBJETIVOS
                cuadro(4,26,15,23);
                rlutil::locate(5,16);
                cout << "BARCO: ";
                rlutil::locate(5,19);
                cout << "CAPITAN: ";
                rlutil::locate(5,22);
                cout << "TRIPULACION: ";
                if(barco==true){
                    rlutil::locate(14,16);
                    cout << "X";
                }
                if(capitan==true){
                    rlutil::locate(14,19);
                    cout << "X";
                }
                if(tripulacion==true){
                    rlutil::locate(18,22);
                    cout << "X";
                }

                rlutil::locate(60,28);

                if((C==3 || C==4) && x>0){
                    Sleep(2000);
                    system("cls");
                }

                else{
                    system("pause");
                    system("cls");
                }

                ///SKIPEAR TIRADA O NO

                if((C==3 || C==4) && x>0){
                    if(i<2 && barco==true&&capitan==true&&tripulacion==true){
                        puntaje=acumularDados(dados, tamant);
                        if(puntaje>5){
                            i=2;
                        }
                    }
                    else if(i==2 && barco==true&&capitan==true&&tripulacion==true){
                        puntaje=acumularDados(dados, tamant);

                    }
                }

                else{
                    if(i<2 && barco==true&&capitan==true&&tripulacion==true){
                        cuadro(39,77,9,11);
                        rlutil::locate(40,10);
                        cout << "Desea acumular estos dados? (S/N): ";
                        cin >> opcion;
                    }
                    if(opcion=='s' || opcion=='S'){
                        puntaje=acumularDados(dados, tamant);
                        i=2;
                    }
                    else if(i==2 && barco==true&&capitan==true&&tripulacion==true){
                        puntaje=acumularDados(dados, tamant);
                    }
                }
                puntajeronda=puntaje;
                puntaje=0;
                acutiradas++;
                system("cls");

            }
            ///MUESTRA DE PUNTAJE POR RONDA
            system("cls");
            cuadro(39,59,9,11);
            rlutil::locate(40,10);

            if(puntajeronda!=0){
                cout << "Puntaje ronda " << g+1 << ": " << puntajeronda << endl;
            }
            else{
                cout << "Tirada fallida! :(" << endl;
            }

            vpuntajes[x]+=puntajeronda;
            puntajeronda=0;


            rlutil::locate(60,28);
            system("pause");

            barco=false;
            capitan=false;
            tripulacion=false;
            for (int i=0;i<3;i++){
                v654[i]=0;
            }
            confirmacion=0;
            tam=5;
            opcion=0;
            system("cls");

        }
        ///MUESTRA PUNTAJE TOTAL Y TIRADAS POR JUGADOR

        system("cls");
        vtiradas[x]+=acutiradas;

        cuadro(39,89,9,13);
        rlutil::locate(40,10);
        cout << "Puntaje total de " << vnombres[x] << ": " << vpuntajes[x];
        rlutil::locate(40,12);
        cout << "Tiradas totales: " << vtiradas[x];

        acutiradas=0;
        rlutil::locate(60,28);
        system("pause");
        system("cls");
    }
    ///GANADOR
    cuadro(37,89,9,17);
    pos=sacarGanador(vnombres,vpuntajes,vtiradas,jugadores,C);

    rlutil::locate(60,28);

    if(C!=3 && C!=4){
        return pos;
    }
    else if(C==3 || C==4){
        return 10;
    }
}
#endif // FUNCIONES_H_INCLUDED
