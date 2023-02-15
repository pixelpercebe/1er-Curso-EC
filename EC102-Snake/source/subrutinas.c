//
// Created by icalb on 04/05/2022.
//

#include "../include/subrutinas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //NO SE PARA QUE SE USA, PERO PARECE IMPORTANTE PARA MATRICES Y GENERAR NUMEROS RANDOM
#include "definiciones.h"
#include "snake_alpha.h"
#include "sprites.h"
#include "rutinasAtencion.h"

int ind = 2;
int ind_b = 2;
int yaux;
int xaux;

void configurarMatrizInicio() {
    // Pone paredes, la serpiente y la manzana
    HabilitarIntTempo();
    int i;
    int j;
    int n;
    for (i = 0;i <= 14;i++) {
        for (j = 0;j <= 14;j++) {
            escenarioMatriz[i][j] = TERRENO_NORMAL;
        }
    }
    //esto coloca todas las posiciones con terreno normal

    for (n = 0;n <= 14;n++) {
        escenarioMatriz[n][0] = PARED;
        escenarioMatriz[n][14] = PARED;
        escenarioMatriz[0][n] = PARED;
        escenarioMatriz[14][n] = PARED;
    //este bucle pone paredes al escenario
    }
        Cabeza_Fila = 6;
        Cabeza_Columna = 10;
        Cola_Fila = 6;
        Cola_Columna = 10;
        escenarioMatriz[6][10] = CABEZA;
        
        l = 0;
        Direccion = IZQUIERDA;
        UltimaDireccion = IZQUIERDA;

        memoriaReserva();
        EstablecerPaletaPrincipal();
	    GuardarSpritesMemoria();

        generar_manzana();
        iprintf("\x1b[2;1H*INTENTA ATRAPAR LAS MANZANAS*");
    // estos comandos ponen la serpiente en la pantalla, e inicializan las variables necesarias
}

//Subrutina qu se dedica a generar una manzana en una ubicacion aleatorio NO ocupada por la serpiente, y ubica el sprite en esa posicion.
void generar_manzana() {
    xaux = rand() % 14;
    yaux = rand() % 14;
    while (escenarioMatriz[xaux][yaux] > 30000) { //si esta ocupado
        xaux = rand() % 14;
        yaux = rand() % 14;
    }
    escenarioMatriz[xaux][yaux] = MANZANA;
    enseñar_manzana();
}

// te devuelve de que tipo es la siguiente casilla de la matriz, en función de la posición de la cabeza y de la nueva dirección
int El_siguiente_es(int nuevaDireccion) {
    if (nuevaDireccion == IZQUIERDA){
        return escenarioMatriz[Cabeza_Fila][Cabeza_Columna - 1];}
        else if (nuevaDireccion == DERECHA) {
        return escenarioMatriz[Cabeza_Fila][Cabeza_Columna + 1];} 
        else if (nuevaDireccion == ARRIBA) {
        return escenarioMatriz[Cabeza_Fila - 1][Cabeza_Columna];} 
        else 
        return escenarioMatriz[Cabeza_Fila + 1][Cabeza_Columna];
}

//Subrutina que recibe la direccion en la que se mueve la serpiente y modifica las posiciones de la matriz para que coincidan con lo que hay en esa posicion.
void avanzar(){
        if (Direccion == IZQUIERDA){
            escenarioMatriz[Cabeza_Fila][Cabeza_Columna - 1] = CABEZA;
            escenarioMatriz[Cabeza_Fila][Cabeza_Columna] = CUERPO_IZQUIERDA;
            Cabeza_Columna = Cabeza_Columna - 1;
        }else if (Direccion == DERECHA){
            escenarioMatriz[Cabeza_Fila][Cabeza_Columna + 1] = CABEZA;
            escenarioMatriz[Cabeza_Fila][Cabeza_Columna] = CUERPO_DERECHA;
            Cabeza_Columna = Cabeza_Columna + 1;
        }else if (Direccion == ARRIBA){
            escenarioMatriz[Cabeza_Fila - 1][Cabeza_Columna] = CABEZA;
            escenarioMatriz[Cabeza_Fila][Cabeza_Columna] = CUERPO_ARRIBA;
            Cabeza_Fila = Cabeza_Fila - 1;
        }else if (Direccion == ABAJO){
            escenarioMatriz[Cabeza_Fila + 1][Cabeza_Columna] = CABEZA;;
            escenarioMatriz[Cabeza_Fila][Cabeza_Columna] = CUERPO_ABAJO;
            Cabeza_Fila = Cabeza_Fila + 1;
        }
}

//subrutina que modifica las posiciones de la matriz para que coincida con la posicion de la cola segun su movimiento. 
void retroceder() {
    if (escenarioMatriz[Cola_Fila][Cola_Columna] == CUERPO_DERECHA) {
        escenarioMatriz[Cola_Fila][Cola_Columna] = TERRENO_NORMAL;
        Cola_Columna = Cola_Columna + 1;
    } else if (escenarioMatriz[Cola_Fila][Cola_Columna] == CUERPO_IZQUIERDA) {
        escenarioMatriz[Cola_Fila][Cola_Columna] = TERRENO_NORMAL;
        Cola_Columna = Cola_Columna - 1;
    } else if (escenarioMatriz[Cola_Fila][Cola_Columna] == CUERPO_ARRIBA) {
        escenarioMatriz[Cola_Fila][Cola_Columna] = TERRENO_NORMAL;
        Cola_Fila = Cola_Fila - 1;
    } else {
        // va hacia derecha*
        escenarioMatriz[Cola_Fila][Cola_Columna] = TERRENO_NORMAL;
        Cola_Fila = Cola_Fila + 1;
    }
}

//modifica las posiciones de los sprites eliminandolos y generandolos en la nueva posición.
void avanzar_cuerpo()
{ //la cabeza siempre tendra indice 1
	if (escenarioMatriz[Cabeza_Fila][Cabeza_Columna] == CUERPO_IZQUIERDA){
		BorrarCabeza_izquierda(1, Cabeza_Columna*10+49, Cabeza_Fila*10+17);
	} 
    else if(escenarioMatriz[Cabeza_Fila][Cabeza_Columna] == CUERPO_DERECHA){
        BorrarCabeza_derecha(1, Cabeza_Columna*10+49, Cabeza_Fila*10+17);
    } 
    else if(escenarioMatriz[Cabeza_Fila][Cabeza_Columna] == CUERPO_ARRIBA){
        BorrarCabeza_arriba(1, Cabeza_Columna*10+49, Cabeza_Fila*10+17);
    } 
    else if(escenarioMatriz[Cabeza_Fila][Cabeza_Columna] == CUERPO_ABAJO){
        BorrarCabeza_abajo(1, Cabeza_Columna*10+49, Cabeza_Fila*10+17);
    }
        //el cuerpo tendra indices con numeros ascendentes para controlar su generacion y eliminacion.
        MostrarCuerpo(ind, Cabeza_Columna*10+49, Cabeza_Fila*10+17);
	    avanzar();
	if (Direccion == ARRIBA)
    {
		MostrarCabeza_arriba(1, Cabeza_Columna*10+49, Cabeza_Fila*10+17);
	} 
    else if(Direccion == ABAJO)
    {
        MostrarCabeza_abajo(1, Cabeza_Columna*10+49, Cabeza_Fila*10+17);
    } 
    else if(Direccion == IZQUIERDA)
    {
        MostrarCabeza_izquierda(1, Cabeza_Columna*10+49,Cabeza_Fila*10+17);
    } 
    else if(Direccion == DERECHA)
    {
        MostrarCabeza_derecha(1, Cabeza_Columna*10+49, Cabeza_Fila*10+17);
    }
    //indice de los sprites del cuerpo que se van generando.
    ind = ind +1;
    if (ind == 50){
        ind = 2;
    } 
}


//Elimina el sprite del ultimo cuerpo de la serpiente, es decir elimina el sprite de la cola.
void retroceder_cuerpo(){
BorrarCuerpo(ind_b, Cola_Columna*10+52, Cola_Fila*10+20); 
retroceder();
ind_b = ind_b+1; //ind_b es el indice del proximo sprite de cuerpo que se va a eliminar.
    if (ind_b == 50){
	    ind_b = 2;
    }  
}

    //Muestra la puntuacion del jugador, es decir muestra el numero de manzanas conseguidas.
    void poner_puntuacion(){
        iprintf("\x1b[13;6H·Tu puntuacion:%d",l);
    }

    //muestra el sprite de la manzana.
    void enseñar_manzana(){
        MostrarManzana(51,yaux*10+49,xaux*10+17);
    }

    //Subrutina que elimina el sprite de la manzana y convierte la ubicacion donde estaba ubicada en terreno normal.
    void desaparecer_manzana(int x, int y){
        escenarioMatriz[xaux][yaux] = TERRENO_NORMAL;
        BorrarManzana(51,y*10+49,x*10+17);
    }