#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <ctime>
using namespace std;
#include "rlutil.h"
#include "funciones.h"

///Proyecto Final Juego.
///Materia: Laboratorio en Computación I.
///Profesor/es: Daniel Kloster y Matias Dirube.
///Integrantes: Nicolas Piana Sampietro, Ignacio Molina y Valentin Colombo.
///Nombre del juego: SeisCincoCuatro.

int main() {

    int opc, C,vpuntajes[11]={},vtiradas[11]={},rondas,pos=0,jugadores;
    int puntajemaximo=0,tiradamaximo=0,ct=0;
    char vnombres[11][50], nombremaximo[50];
    while(true) {
        rlutil::setColor(rlutil::LIGHTBLUE);
        system("cls");
        cuadro(36,78,6,18);
        rlutil::locate(38,8);
        cout << "1. Juego nuevo entre dos participantes.";
        rlutil::locate(38,9);
        cout << "2. Juego nuevo entre x participantes.";
        rlutil::locate(38,10);
        cout << "3. Juego nuevo contra la maquina.";
        rlutil::locate(38,11);
        cout << "4. Juego nuevo contra x maquinas. ";
        rlutil::locate(38,12);
        cout << "5. Mostrar puntuacion mas alta.";
        rlutil::locate(38,13);
        cout << "6. Modo simulado.";
        rlutil::locate(38,14);
        cout << "7. Reglas del juego.";
        rlutil::locate(38,15);
        cout << "0. Salir";
        rlutil::locate(37,16);
        cout << "-----------------------------------------";

        rlutil::locate(38,17);
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        system("cls");
        switch(opc) {

        case 1:

            C=1;
            rondas=cargarNombres(vnombres,2,50);
            pos=punto1(C,vnombres,2,50,vpuntajes,vtiradas,rondas);

            break;

        case 2:
            cuadro(39,75,12,14);
            rlutil::locate(40,13);
            cout << "Ingresar cantidad de jugadores: ";
            cin >> jugadores;
            if(jugadores<3 || jugadores>10){
                cuadro(32,82,12,14);
                rlutil::locate(33,13);
                cout << "La cantidad de jugadores debe ser entre 3 y 10...";
                rlutil::locate(60,28);
                break;
            }
            else{
                system("cls");
                C=2;
                rondas=cargarNombres(vnombres,jugadores,50);
                pos=punto1(C,vnombres,jugadores,50,vpuntajes,vtiradas,rondas);
            break;
            }

        case 3:

            C=3;
            rondas=cargarNombres(vnombres,2,50);
            pos=punto1(C,vnombres,2,50,vpuntajes,vtiradas,rondas);

            break;

        case 4:

            cuadro(39,75,12,14);
            rlutil::locate(40,13);
            cout << "Ingresar cantidad de jugadores: ";
            cin >> jugadores;
            if(jugadores<3 || jugadores>10){
                cuadro(32,82,12,14);
                rlutil::locate(33,13);
                cout << "La cantidad de jugadores debe ser entre 3 y 10...";
                rlutil::locate(60,28);
                break;
            }
            else{
                system("cls");
                C=4;
                rondas=cargarNombres(vnombres,jugadores,50);
                pos=punto1(C,vnombres,jugadores,50,vpuntajes,vtiradas,rondas);

            break;
            }


        case 5:
            if((vpuntajes[pos]==0 || pos==-1) && ct==0){
                cuadro(37,68,12,14);
                rlutil::locate(38,13);
                cout << "Todavia no hay puntajes... :/";
                rlutil::locate(60,28);
            }
            else {
                cuadro(37,94,9,17);
                rlutil::locate(38,10);
                cout << "Nombre: " << nombremaximo;
                rlutil::locate(38,13);
                cout << "Puntaje: " << puntajemaximo;
                rlutil::locate(38,16);
                cout << "Tiradas: " << tiradamaximo;

                ct++;

                rlutil::locate(60,28);
            }

            break;

        case 6:

            C=6;
            rondas=cargarNombres(vnombres,2,50);
            pos=punto1(C,vnombres,2,50,vpuntajes,vtiradas,rondas);

            break;

        case 7:
            reglas();
            break;

        case 0:
            cuadro(33,40,6,8);
            rlutil::locate(34,7);
            cout << "ADIOS!" << endl;
            cuadro(55,62,6,8);
            rlutil::locate(56,7);
            cout << "ADIOS!" << endl;
            sonrisa(37,57,14);

            rlutil::locate(8,25);
            return 0;

            break;

        default:

            cuadro(47,69,12,14);
            rlutil::locate(48,13);
            cout << "NO EXISTE ESA OPCION" << endl;

            rlutil::locate(60,28);
            break;
        }

        if(vpuntajes[pos]>puntajemaximo && pos!=10){
            strcpy(nombremaximo,vnombres[pos]);
            tiradamaximo=vtiradas[pos];
            puntajemaximo=vpuntajes[pos];
        }

        system("pause>null");
        system("cls");
    }


    return 0;
}

