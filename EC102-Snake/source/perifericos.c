/*-------------------------------------
perifericos.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "sprites.h"


int tecla; //variable para guardar la tecla pulsada
int seg;


/*
 * Funcion que detecta si una tecla se ha pulsado.
 */
int TeclaDetectada() 
{
	//Devuelve TRUE si detecta que se ha pulsado alguna tecla.
	if ((~TECLAS_DAT & 0x03ff)!=0) return 1;
	else return 0;

}

int TeclaPulsada() 
{
	//Devuelve el código de la tecla pulsada utilizando para ello las constantes definidas en 
	//definiciones.h:  A=0;B=1;SELECT=2;START=3;IZQUIERDA=4;DERECHA=5;
	//ARRIBA=6;ABAJO=7;R=8;L=9;
    if ((TECLAS_DAT & 0x0001)==0) return A;//A
    else if ((TECLAS_DAT & 0X0002)==0) return B;//B
    else if ((TECLAS_DAT & 0X0004)==0) return SELECT;//SELECT
    else if ((TECLAS_DAT & 0X0008)==0) return START;//START
    else if ((TECLAS_DAT & 0X0010)==0) return DERECHA;//DER
    else if ((TECLAS_DAT & 0X0020)==0) return IZQUIERDA;//IZQ
    else if ((TECLAS_DAT & 0X0040)==0) return ARRIBA;//ARRIBA
    else if ((TECLAS_DAT & 0X0080)==0) return ABAJO;//ABAJO
    else if ((TECLAS_DAT & 0x0100)==0) return R;//R
    else if ((TECLAS_DAT & 0X0200)==0) return L;//L
    else return -1;
}

void ConfigurarTeclado(int Conf_Tec)
{
	//Configuración del teclado. Modificar su registro de control en base a los bits
        //activados en el parametro Conf_Tec
        TECLAS_CNT = (TECLAS_CNT | Conf_Tec);
}

void ConfigurarTemporizador(int Latch, int Conf_Tempo)
{
	//Configuración del temporizador. El latch es el valor del registro de datos del temporizador
        //Activar los bits del registro de control necesarios en base a los bits activados en el parámetro Conf_Tempo
        TIMER0_DAT = Latch;
        //TIMER0_DAT = 49152;
        TIMER0_CNT = TIMER0_CNT | Conf_Tempo;
        //TIMER0_CNT = (TIMER0_CNT | 0x0043);
}

void HabilitarIntTeclado()
{
	//Habilitar las interrupciones del teclado
	//Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación, 
	//y después volver a habilitar las interrupciones de forma general 
	IME=0;
    
    //Habilitar la interrupcion desde el teclado en la IE
    IE = (IE | 0x00001000);

    //Habilitar las interrupciones poniendo el bit 14 a 1 en TECLAS_CNT.
	IME=1;


    /*
    |-------------------------------------------------|
    |0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0                  |
    |-------------------------------------------------|
    |Habilitamos el bit  numero 14 (HEX:0x4000) para  |
    |habiliitar las interrupciones                    |
    |_________________________________________________|
    **/
}

void InhibirIntTeclado()
{

	//Deshabilitar las interrupciones del teclado
	//Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación, 
	//y después volver a habilitar las interrupciones de forma general 

	IME=0;
    IE = (IE & 0xFFFFEFFF);
	IME=1;
}  

void HabilitarIntTempo()
{

	//Habilitar las interrupciones del temporizador (timer0)
	//Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación, 
	//y después volver a habilitar las interrupciones de forma general 
	IME=0;
    IE = (IE | 0x00000008);
	IME=1;
}

void InhibirIntTempo()
{

	//Deshabilitar las interrupciones del temporizado (timer0)
	//Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación, 
	//y después volver a habilitar las interrupciones de forma general 
	IME=0;
    IE = (IE | 0x00000007);
	IME=1;

}

//inicia el tiempo, aumentan los ticks del timer.
void PonerEnMarchaTempo()
{
     TIMER0_CNT = TIMER0_CNT | 0X0080;
}

//detiene el tiempo, no aumenta los ticks del timer.
void PararTempo()
{
    TIMER0_CNT = TIMER0_CNT | 0XFF7F;
}


 //Esta función consulta si se ha tocado la pantalla táctil.
int Pantalla_tocado() {
touchPosition pos_pantalla;
	touchRead(&pos_pantalla);
  	return !(pos_pantalla.px==0 && pos_pantalla.py==0);
}
