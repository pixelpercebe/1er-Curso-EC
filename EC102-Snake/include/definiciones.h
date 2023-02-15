/*-------------------------------------
definiciones.h
-------------------------------------*/
#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estandar de C
#include <stdlib.h>		//librería estandar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos

/*
*Define los registros del vector de interrupciones
**/
#define IME		(*(vuint32*)0x04000208) //Interrupt Master Enable -- Habilitar-deshabilitar todas las interrupciones
#define IE		(*(vuint32*)0x04000210) //Interrupt Enable -- Habilitar-deshabilitar las interrupciones de forma individual
#define IF		(*(vuint32*)0x04000214) //Interrupt Flag -- Registro de solicitud de interrupción

/*
* funciones para el tratamiento general de las interrupciones
*/
#define HabilitarInterrupciones() IME=1 //Habilitar todas las interrupciones
#define DeshabilitarInterrrupciones() IME=0 //Deshabilitar todas las interrupciones

/*
*registros del teclado
*/
#define TECLAS_DAT	(*(vu16*)0x4000130) //registro de datos
#define TECLAS_CNT	(*(vu16*)0x4000132) //registro de control

/*
*registros del temporizador Timer0
*/
#define TIMER0_CNT   (*(vuint16*)0x04000102) //registro de control
#define TIMER0_DAT    (*(vuint16*)0x04000100) //registro de datos



/*
*Acceso a los registros de la pantalla táctil
*/
extern touchPosition PANT_DAT;
/*
* Nombres asignados a las teclas para facilitar la comprensión de nuestro código
*/

#define A				0
#define B				1
#define SELECT			2 
#define START			3
#define DERECHA			4 
#define IZQUIERDA		5
#define ARRIBA			6 
#define ABAJO			7
#define R				8 
#define L				9


//ASIGAN UN IDENTIFICADOR A CADA ESTADOS DEL SNAKE
#define INICIO 91
#define GAMEOVER 92
#define JUEGO 93

#define TERRENO_NORMAL 0
#define CABEZA 2
#define MANZANA 3

#define PARED 500000
#define CUERPO_DERECHA 100000
#define CUERPO_IZQUIERDA 200000
#define CUERPO_ABAJO 300000
#define CUERPO_ARRIBA 400000

//VARIABLES GLOBALES.

extern int ind;
extern int ind_b;
extern int xaux;
extern int yaux;
extern int ticks;

extern int ESTADO;

extern int tiempo;
extern int Direccion;
extern int UltimaDireccion;
extern int l;
extern int Cabeza_Fila;
extern int Cabeza_Columna;
extern int Cola_Fila;
extern int Cola_Columna;
extern int direccionQueAcabaDeLLegar;
extern int escenarioMatriz[14][14];


