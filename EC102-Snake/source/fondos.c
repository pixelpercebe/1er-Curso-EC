
#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

/* Si queremos visualizar distintos fondos, aquí se debe incluir el fichero de cabecera (fichero .h) de cada fondo. Estos ficheros de cabecera se generan automáticamente durante la compilación. */

#include "fondos.h"
#include "graficos.h"

#include "fondo_inicio.h"
#include "Fondo_juego.h"
#include "game_over.h"

#include "sprites.h"


/* Se elige el canal de DMA que se utilizará para copiar las imágenes en memoria.*/
static const int DMA_CHANNEL = 3;

/* Para cada fondo que se quiera visualizar hay que escribir un procedimiento como el siguiente */


/*Fondo que se muestra al inicio del juego.*/
void visualizarFondo_inicio() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     fondo_inicioBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     fondo_inicioBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*Fondo que se muestra al jugar.*/
void visualizarFondo_juego() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     Fondo_juegoBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     Fondo_juegoBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

/*Fondo que se muestra al tereminar el juego.*/
void visualizarGame_over() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     game_overBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     game_overBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}



