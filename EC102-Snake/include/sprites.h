extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;

extern u16* gfxcabeza_arriba;
extern u16* gfxcabeza_derecha;
extern u16* gfxcabeza_izquierda;
extern u16* gfxcabeza_abajo;
extern u16* gfxcuerpo;
extern u16* gfxmanzana;



extern u16* gfx_crab_alien;

extern void memoriaReserva();

/* Para cada uno de los 256 valores que puede tomar un Pixel le da un color en la pantalla principal. El valor 0 es transparente y los valores sin definir negros */
extern void EstablecerPaletaPrincipal();


/* Para cada uno de los 256 valores que puede tomar un Pixel le da un color en la pantalla secundaria. El valor 0 es transparente y los valores sin definir negros */
extern void EstablecerPaletaSecundaria();


/* Carga en memoria los Sprites dibujados.*/
extern void GuardarSpritesMemoria();

/*Serpiente*/
extern void MostrarCabeza_arriba(int indice, int x, int y);
extern void BorrarCabeza_arriba(int indice, int x, int y);

extern void MostrarCabeza_derecha(int indice, int x, int y);
extern void BorrarCabeza_derecha(int indice, int x, int y);

extern void MostrarCabeza_izquierda(int indice, int x, int y);
extern void BorrarCabeza_izquierda(int indice, int x, int y);

extern void MostrarCabeza_abajo(int indice, int x, int y); 
extern void BorrarCabeza_abajo(int indice, int x, int y);

extern void MostrarCuerpo(int indice, int x, int y);
extern void BorrarCuerpo(int indice, int x, int y);

/*manzana*/
extern void MostrarManzana(int indice, int x, int y);
extern void BorrarManzana(int indice, int x, int y);


extern void display_crab_alien(int index, int x, int y);