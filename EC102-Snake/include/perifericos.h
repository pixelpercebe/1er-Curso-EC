/*-------------------------------------
perifericos.h
-------------------------------------*/

extern int TeclaDetectada();
extern int TeclaPulsada();
extern void ConfigurarTeclado(int Conf_Tec);
extern void ConfigurarTemporizador(int Latch, int Conf_Tempo);
extern void HabilitarIntTeclado(); //configura una mascara para el teclado en IE 12
extern void InhibirIntTeclado();
extern void HabilitarIntTempo(); //configura una mascara para el teclado en IE 3
extern void InhibirIntTempo();
extern void PonerEnMarchaTempo();
extern void PararTempo();
extern int Pantalla_tocado();

