/*
 ============================================================================
 Name        : tp1programacion.c
 Author      : Luciano Vega
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"
#include "ingresodatos.h"

 //valor del bitcoin 14/4/2022 en pesos fuente: https://www.ripio.com/ar/
#define valorBitcoin 7677037.38

int main(void)
{
	setbuf(stdout,NULL);

	/**variables 1ra opción.*/
	int kilometrosIngresados;

	/**variables 2da opción.*/
	float precioVueloLatam;
	float precioVueloAereolineas;

	/**variables 3er y 4ta opcion.*/
	float debitoAereolineas;
	float creditoAereolineas;
	float bitcoinAereolineas;
	float unitarioAereolineas;
	float debitoLatam;
	float creditoLatam;
	float bitcoinLatam;
	float unitarioLatam;
	float diferenciaPrecio;

	/**Mostramos el menu principal y pedimos los kilometros*/
	kilometrosIngresados = ejecutarMenuPrincipalUno();

	/**Mostramos el menu principal y pedimos los precios*/
	precioVueloAereolineas = ejecutarMenuDos(0);
	precioVueloLatam = ejecutarMenuDos(1);

	/**Mostramos el menu principal y calulamos los costos*/
	ejecutarMenuTres();

	debitoAereolineas = calcularDebito(precioVueloAereolineas, 10);
	debitoLatam = calcularDebito(precioVueloLatam, 10);
	creditoAereolineas = calcularCredito(precioVueloAereolineas, 25);
	creditoLatam = calcularCredito(precioVueloLatam, 25);
	bitcoinAereolineas = calcularBitcoin(precioVueloAereolineas, valorBitcoin);
	bitcoinLatam = calcularBitcoin(precioVueloLatam, valorBitcoin);
	unitarioAereolineas = calcularUnitario(precioVueloAereolineas ,kilometrosIngresados);
	unitarioLatam = calcularUnitario(precioVueloLatam ,kilometrosIngresados);
	diferenciaPrecio = calcularDiferencia(precioVueloLatam, precioVueloAereolineas);

	/**Mostramos el menu principal y enseñamos los costos*/
	ejecutarMenuCuatro(kilometrosIngresados, precioVueloAereolineas,
			precioVueloLatam, debitoAereolineas,creditoAereolineas,
			bitcoinAereolineas, unitarioAereolineas, debitoLatam,
			creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);

	/**Mostramos el menu principal y enseñamos los costos forzados
	Volvemos a dar como parametros las variables de la opcion 4 por si se
	pide volver a mostrar*/
	ejecutarMenuCinco(kilometrosIngresados, precioVueloAereolineas,
			precioVueloLatam, debitoAereolineas,creditoAereolineas,
			bitcoinAereolineas, unitarioAereolineas, debitoLatam,
			creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);

	/**mostramos el menu principal, habilitamos la opcion salir,
	si el susuario lo pide informar resultados y carga forzada una vez más
	y habilitamos el salir**/

	if(ejecutarMenuCinco(kilometrosIngresados, precioVueloAereolineas,
					precioVueloLatam, debitoAereolineas,creditoAereolineas,
					bitcoinAereolineas, unitarioAereolineas, debitoLatam,
					creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio) != 6)
	{
		printf("\nFin de la funcion.");
	}


	return 0;
}
