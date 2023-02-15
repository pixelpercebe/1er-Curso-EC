//
// Created by icalb on 04/05/2022.
//

#include "../include/snake_alpha.h"
#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estándar de C
#include <stdlib.h>		//librería estándar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos

//librerías desarrolladas por nosotros para el proyecto
#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"
#include "subrutinas.h"
#include "sprites.h"


void snake_alpha(){

    EstablecerVectorInt();
        //Poner el IME = 1
    HabilitarInterrupciones();
        //Habilitar las interrupciones para el teclado y el bit 14 de TECLAS_CNT
    HabilitarIntTeclado();
        //Habilitar teclas concretas del teclado por interrupcion.
    ConfigurarTeclado(0x40F0);
        //configura el temporizador a dos ticks por segundo, es decir interrumpira cada 0.5 segundos.
    ConfigurarTemporizador(49152,0x0043);
        //pone en marcha las interrupciones del timer, permite que pueda interrumpir cada vez que haya un overflow (cada 0.5 segundos)
    PonerEnMarchaTempo();
        //Establece el fondo de incio como fondo visible.
    visualizarFondo_inicio();
        //Inicia el juego en el estado inicio.
    ESTADO = INICIO;
    
    while (1)
    {
        if (ESTADO == INICIO){
            iprintf("\x1b[10;2HTOCA LA PANTALLA PARA JUGAR");
        }
        if(ESTADO == INICIO && Pantalla_tocado()) //al tocar la pantalla en cualquier ubicación.
        {
                //limpia la pantalla de arriba.
            consoleClear();
                //Manda generar la matriz e inicializar las variables globales.
            configurarMatrizInicio();
                //establece el fondo adecuado al estado del juego en ese momento.
            visualizarFondo_juego();
                //establece el estado a juego, (Estado en el que se desarrolla la partida.)
            ESTADO = JUEGO;
        }
        if (ESTADO == GAMEOVER && TeclaPulsada() == B)//muestra la puntuacion obtenida tras pulsar la tecla B.
        {
            poner_puntuacion(l); 
        }
    }
}

