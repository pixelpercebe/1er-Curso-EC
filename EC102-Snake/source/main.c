/*---------------------------------------------------------------------------------
Este código se ha desarrollado basándose en el código de dovoto "Simple sprite demo" 
y en otro ejemplo de Jaeden Ameronen
---------------------------------------------------------------------------------*/

#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estandar de C
#include <stdlib.h>		//librería estandar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos

//librerías desarroladas por nosotros para el proyecto
#include "definiciones.h"
#include "fondos.h"
#include "graficos.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "sprites.h"
#include "subrutinas.h"
#include "../include/snake_alpha.h"


//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
//inicializaciones necesarias para el juego.
	powerOn(POWER_ALL_2D);
	lcdMainOnBottom();

//inicializaciones necesarias para los sprites.
	EstablecerPaletaPrincipal();
	inicializarGraficosSprites();
	
//habilita todas las interrupciones.
	HabilitarInterrupciones();

//llamada al juego.
	snake_alpha();
	

	return(0);

}
