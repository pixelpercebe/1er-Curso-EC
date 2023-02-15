/*-------------------------------------
rutinasAtencion.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
#include "subrutinas.h"

int ticks;
int ESTADO;
int Direccion;
int UltimaDireccion;
int l;
int Cabeza_Fila;
int Cabeza_Columna;
int Cola_Fila;
int Cola_Columna;
int escenarioMatriz[14][14];

//rutina de atencion del teclado que permite actualizar la direccion de la serpiente segun la direccion en la que se este desplazando en ese momento.
void RutAtencionTeclado()
{ 
		if (TeclaPulsada() == ARRIBA && !(UltimaDireccion == ABAJO))
			{
				 Direccion = TeclaPulsada();
			}
		else if (TeclaPulsada() == ABAJO && !(UltimaDireccion == ARRIBA))
			{
				Direccion = TeclaPulsada();
			}
		else if (TeclaPulsada() == 	DERECHA && !(UltimaDireccion == IZQUIERDA))
			{
				Direccion = TeclaPulsada();
			}
		else if (TeclaPulsada() == IZQUIERDA && !(UltimaDireccion == DERECHA))
			{
				Direccion = TeclaPulsada();
			}
}

//rutina de atención del timer0 llama a las subrutinas necesarias segun la prosima posicion a la que se vaya a mover la serpiente.
void RutAtencion_timer0()
{
	if(ESTADO == JUEGO)
	{
		if (El_siguiente_es(Direccion) == TERRENO_NORMAL)
		{
			avanzar_cuerpo();
			retroceder_cuerpo();
		}
		else if(El_siguiente_es(Direccion) == MANZANA)
		{
			desaparecer_manzana(xaux,yaux);
			avanzar_cuerpo();
			l++; //longitud de la serpiente, equivalente a la putuacion.
			generar_manzana();
		}
		else if(El_siguiente_es(Direccion) >= 30000)
		{
			visualizarGame_over();
			ESTADO = GAMEOVER;
			consoleClear();
			iprintf("\x1b[1;3H    ### GAME OVER ###");
			iprintf("\x1b[4;3H*** PRESIONA <B> PARA ***");
			iprintf("\x1b[6;6H** TU PUNTUACION **");
		}
		UltimaDireccion = Direccion;
	}		
}

//Vector de interrupciones del teclado y el timer.
void EstablecerVectorInt()
{
	irqSet(IRQ_KEYS, RutAtencionTeclado);
	irqSet(IRQ_TIMER0, RutAtencion_timer0);
}