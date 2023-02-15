/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

#include "sprites.h"
#include "definiciones.h"

u16* gfxcabeza_arriba;
u16* gfxcabeza_derecha;
u16* gfxcabeza_izquierda;
u16* gfxcabeza_abajo;
u16* gfxcuerpo;
u16* gfxmanzana;
u16* gfxpersone;



/* Reservar memoria para cada sprite que se quiera mostrar en pantalla.*/
void memoriaReserva()
{
	/*Reserva de memoria para los sprites de la serpiente.*/
	gfxcabeza_arriba= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxcabeza_derecha= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxcabeza_izquierda= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxcabeza_abajo= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxcuerpo= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxmanzana= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxpersone = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
}

/* A cada uno de los 256 valores que puede tomar un pixel en la PALETA PRINCIPAL
   se le puede asignar un color. El valor 0 es transparente. Los valores sin definir son negros. */
void EstablecerPaletaPrincipal() {

	SPRITE_PALETTE[1] = RGB15(31,0,0); // los píxeles con valor 1 serán de color rojo.
	SPRITE_PALETTE[2] = RGB15(0,31,0); // los píxeles con valor 2 serán verdes.
	SPRITE_PALETTE[3] = RGB15(0,0,31); // los píxeles con valor 3 serán azules.

	/*Paleta de colores de los sprites*/
	SPRITE_PALETTE[10] = RGB15(50,246,1); // los píxeles con valor 10 serán de color marron (cuerpo principal)
	SPRITE_PALETTE[11] = RGB15(45,87,44); // los píxeles con valor 11 serán verdes oscuros (detalles).
	SPRITE_PALETTE[12] = RGB15(0,0,0); // los píxeles con valor 3 serán negros (detalles2).
	SPRITE_PALETTE[13] = RGB15(255,255,255); // blanco :)
	SPRITE_PALETTE[14] = RGB15(255,255,153); // ns que color es:(

}

/* definición de un sprite de 16x16 píxeles para dibujar un rombo */
/* Por la forma que tienen de trabajar los bancos de memoria, la imagen del sprite se divide en bloques de 8x8 píxeles. Los primeros 64 (8x8) píxeles que indicamos
aparecerán en el cuadrante superior izquierdo de la imagen del sprite, los siguientes 64 en el cuadrante superior derecho, los siguientes en el cuadrante inferior izquierdo y los
últimos en el cuadrante inferior derecho. */


/*Sprites de de la serpiente.*/
u16 cabeza_arriba [256] =
{
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	13	,	12	,	10	,	10	,	0	,	0	,	0	,	10	,	12	,	12	,	10	,	10,
	0	,	0	,	0	,	10	,	12	,	12	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	10	,	10	,	13	,	12	,	10	,	0	,	0	,	0	,	10	,	10	,	12	,	12	,	10	,	0	,	0	,	0,
	10	,	10	,	12	,	12	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,

};
u16 cabeza_derecha [256] =
{
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	10	,	12	,	12	,	13	,	10	,	0	,	0	,	0	,	10	,	12	,	12	,	12	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	10	,	12	,	12	,	13	,	10	,	0	,	0	,	0	,	10	,	12	,	12	,	12	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,

};
u16 cabeza_izquierda [256] =
{
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	12	,	12	,	12	,	10	,	0	,	0	,	0	,	10	,	13	,	12	,	12	,	10,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	12	,	12	,	12	,	10	,	0	,	0	,	0	,	10	,	13	,	12	,	12	,	10,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
};
u16 cabeza_abajo [256] =
{
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	12	,	12	,	10	,	10,
	0	,	0	,	0	,	10	,	12	,	12	,	10	,	10	,	0	,	0	,	0	,	10	,	12	,	13	,	10	,	10,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	10	,	12	,	12	,	10	,	0	,	0	,	0,
	10	,	10	,	12	,	12	,	10	,	0	,	0	,	0	,	10	,	10	,	12	,	13	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
};

/*Cuerpo de la serpiente*/

u16 cuerpo [256] =
{
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	11	,	11	,	11	,	11	,	0	,	0	,	0	,	10	,	11	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	11	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	11	,	10	,	10	,	12,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0,
	11	,	11	,	11	,	11	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	11	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	11	,	10	,	0	,	0	,	0	,	12	,	10	,	10	,	11	,	10	,	0	,	0	,	0,
	0	,	0	,	0	,	10	,	11	,	10	,	10	,	12	,	0	,	0	,	0	,	10	,	11	,	10	,	10	,	10,
	0	,	0	,	0	,	10	,	11	,	10	,	10	,	10	,	0	,	0	,	0	,	10	,	11	,	11	,	11	,	11,
	0	,	0	,	0	,	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
	12	,	10	,	10	,	11	,	10	,	0	,	0	,	0	,	10	,	10	,	10	,	11	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	11	,	10	,	0	,	0	,	0	,	11	,	11	,	11	,	11	,	10	,	0	,	0	,	0,
	10	,	10	,	10	,	10	,	10	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
};

/*manzana*/

u16 manzana [256] =
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	12	,	0	,	0	,	0	,	0	,	0	,	0	,	12	,	10,
0	,	0	,	0	,	0	,	0	,	12	,	12	,	10	,	0	,	0	,	0	,	0	,	12	,	1	,	1	,	1,
0	,	0	,	0	,	12	,	1	,	1	,	14	,	1	,	0	,	0	,	0	,	12	,	1	,	14	,	14	,	14,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	12	,	12	,	12	,	0	,	0	,	0	,	0	,	0,
10	,	10	,	12	,	0	,	0	,	0	,	0	,	0	,	10	,	12	,	0	,	0	,	0	,	0	,	0	,	0,
12	,	12	,	12	,	0	,	0	,	0	,	0	,	0	,	1	,	1	,	1	,	12	,	0	,	0	,	0	,	0,
1	,	1	,	1	,	1	,	12	,	0	,	0	,	0	,	1	,	1	,	1	,	1	,	12	,	0	,	0	,	0,
0	,	0	,	0	,	12	,	1	,	1	,	14	,	1	,	0	,	0	,	0	,	12	,	1	,	1	,	1	,	1,
0	,	0	,	0	,	12	,	1	,	1	,	1	,	1	,	0	,	0	,	0	,	0	,	12	,	1	,	1	,	12,
0	,	0	,	0	,	0	,	0	,	12	,	12	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
1	,	1	,	1	,	1	,	12	,	0	,	0	,	0	,	1	,	1	,	1	,	1	,	12	,	0	,	0	,	0,
1	,	1	,	1	,	1	,	12	,	0	,	0	,	0	,	1	,	1	,	1	,	12	,	0	,	0	,	0	,	0,
12	,	12	,	12	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0,
};

/* Carga en memoria cada uno de los sprites que hemos dibujado. */

void GuardarSpritesMemoria(){ 
	
int i;
	/*Sprites de la serpiente y manzana*/
	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxcabeza_arriba[i] = cabeza_arriba[i*2] | (cabeza_arriba[(i*2)+1]<<8);				
	}

	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxcabeza_derecha[i] = cabeza_derecha[i*2] | (cabeza_derecha[(i*2)+1]<<8);				
	}

	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxcabeza_izquierda[i] = cabeza_izquierda[i*2] | (cabeza_izquierda[(i*2)+1]<<8);				
	}

	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxcabeza_abajo[i] = cabeza_abajo[i*2] | (cabeza_abajo[(i*2)+1]<<8);				
	}

	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxcuerpo[i] = cuerpo[i*2] | (cuerpo[(i*2)+1]<<8);				
	}

for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxmanzana[i] = manzana[i*2] | (manzana[(i*2)+1]<<8);				
	}
}

/* Esta función dibuja un sprite en la posición x-y de pantalla. 
A cada sprite que se quiera mostrar en pantalla se le debe asignar un indice distinto, 
un valor entre 0 y 126. */
void MostrarCabeza_arriba(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcabeza_arriba,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}
void BorrarCabeza_arriba(int indice, int x, int y)
{
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcabeza_arriba,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain);
}

void MostrarCabeza_derecha(int indice, int x, int y)
{
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcabeza_derecha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}
void BorrarCabeza_derecha(int indice, int x, int y)
{
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcabeza_derecha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain);
}

void MostrarCabeza_izquierda(int indice, int x, int y)
{ 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcabeza_izquierda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}
void BorrarCabeza_izquierda(int indice, int x, int y)
{
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcabeza_izquierda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain);
}

void MostrarCabeza_abajo(int indice, int x, int y)
{ 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcabeza_abajo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}


void BorrarCabeza_abajo(int indice, int x, int y)
{
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcabeza_abajo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain);
}


void MostrarCuerpo(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcuerpo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}
void BorrarCuerpo(int indice, int x, int y)
{
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcuerpo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain);
}

void MostrarManzana(int indice, int x, int y)
{ 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxmanzana,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}
void BorrarManzana(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxmanzana,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain);
}

