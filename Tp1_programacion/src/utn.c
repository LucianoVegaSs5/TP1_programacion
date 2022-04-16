/*
 * utn.c
 *
 *  Created on: 8 abr. 2022
 *      Author: Luciano
 */


#include <stdio.h>
#include "utn.h"
#include "calculos.h"
#include "ingresodatos.h"
#define valorBitcoin 7677037.38//valor del bitcoin 14/4/2022 en pesos fuente: https://www.ripio.com/ar/


int ejecutarMenuPrincipalUno()
{
	int opcion;
	int kilometrosIngresados;

	opcion = mostrarMenu();

	if(opcion == 1)
	{
		kilometrosIngresados = ingresoDatosOpcionUno();
	}
	else
	{
		printf("\nNecesita ingresar kilometros para continuar \n");
		ejecutarMenuPrincipalUno();
	}

	return kilometrosIngresados;
}

float ejecutarMenuDos(int flagAereolinea)
{
	int opcion;
	float precioVuelo;

	if(flagAereolinea == 0)
	{
		opcion = mostrarMenu();

		if(opcion == 2)
		{
			printf("\nIngrese el precio de Aerolineas: ");
			scanf("%f", &precioVuelo);
		}
		else
		{
			if(opcion == 1)
			{
				printf("\nYa ingreso Los kilometros\n");
				ejecutarMenuDos(0);
			}
			else
			{
				printf("\nNecesita ingresar los precios\n");
				ejecutarMenuDos(0);
			}

		}
	}
	else
	{
		printf("\nIngrese el precio de Latam: ");
		scanf("%f", &precioVuelo);
	}

	return precioVuelo;
}

int ejecutarMenuTres()
{
	int opcion;

	opcion = mostrarMenu();

		switch(opcion)
		{
		case 1:
		 	printf("\nYa ingreso los kilometros.\n");
		 	ejecutarMenuTres();
		 	break;
		case 2:
		 	printf("\nYa ingreso los precios.\n");
		 	ejecutarMenuTres();
		 	break;
		case 3:
			printf("\nCalculando costos...\n");
		 	break;
		default:
		 	printf("\nNecesita calcular los costos para continuar\n");
		 	ejecutarMenuTres();
		 	break;
		}

	return 0;
}

int ejecutarMenuCuatro(int kilometrosIngresados, float precioVueloAereolineas,
	float precioVueloLatam, float debitoAereolineas, float creditoAereolineas,
	float bitcoinAereolineas, float unitarioAereolineas, float debitoLatam,
	float creditoLatam, float bitcoinLatam, float unitarioLatam, float diferenciaPrecio)
{
	int opcion;

	opcion = mostrarMenu();

	if(opcion == 4)
	{
		mostrarCostos(kilometrosIngresados, precioVueloAereolineas,
				precioVueloLatam, debitoAereolineas,creditoAereolineas,
				bitcoinAereolineas, unitarioAereolineas, debitoLatam,
				creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);
	}
	else
	{
		switch(opcion)
		{
			case 1:
				printf("\nYa se ingresaron los kilometros.\n");
				ejecutarMenuCuatro(kilometrosIngresados, precioVueloAereolineas,
						precioVueloLatam, debitoAereolineas,creditoAereolineas,
						bitcoinAereolineas, unitarioAereolineas, debitoLatam,
						creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);
				break;
			case 2:
				printf("Ya se ingresaron los precios.\n");
				ejecutarMenuCuatro(kilometrosIngresados, precioVueloAereolineas,
						precioVueloLatam, debitoAereolineas,creditoAereolineas,
						bitcoinAereolineas, unitarioAereolineas, debitoLatam,
						creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);
				break;
			case 3:
				printf("Los precios ya fueron calculados.\n");
				ejecutarMenuCuatro(kilometrosIngresados, precioVueloAereolineas,
						precioVueloLatam, debitoAereolineas,creditoAereolineas,
						bitcoinAereolineas, unitarioAereolineas, debitoLatam,
						creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);
				break;
			default:
				printf("Debe de mostrar los precios.\n");
				ejecutarMenuCuatro(kilometrosIngresados, precioVueloAereolineas,
						precioVueloLatam, debitoAereolineas,creditoAereolineas,
						bitcoinAereolineas, unitarioAereolineas, debitoLatam,
						creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);
				break;
		}

	}
	return 0;
}

int mostrarCostos(int kilometrosIngresados, float precioVueloAereolineas,
	float precioVueloLatam, float debitoAereolineas, float creditoAereolineas,
	float bitcoinAereolineas, float unitarioAereolineas, float debitoLatam,
	float creditoLatam, float bitcoinLatam, float unitarioLatam, float diferenciaPrecio)
{

    printf("\nKilometros: %d\n"
    		"Precio Aereolineas: %.2f\n"
    		"Precio Latam: %.2f\n"
    		"\nAereolineas: \n"
			"Precio con tarjeta de débito: %.2f"
			" pesos. \n"
			"Precio con tarjeta de crédito: %.2f"
			" pesos. \n"
			"Precio pagado con bitcoin: %.10f"
			" bitcoins \n"
			"Precio unitario: %.2f"
			" pesos por Km.\n"
			"Latam: \n"
			"Precio con tarjeta de débito: %.2f"
			" pesos. \n"
			"Precio con tarjeta de crédito: %.2f"
			" pesos. \n"
			"Precio pagado con bitcoin: %.10f"
			" bitcoins \n"
			"Precio unitario: %.2f"
			" pesos por Km.\n"
			"La diferencia de Precio es: %.2f\n"
			,kilometrosIngresados, precioVueloAereolineas, precioVueloLatam, debitoAereolineas,
			creditoAereolineas, bitcoinAereolineas, unitarioAereolineas,
			debitoLatam, creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);


    return 0;
}

int ejecutarMenuCinco(int kilometrosIngresados, float precioVueloAereolineas,
		float precioVueloLatam, float debitoAereolineas, float creditoAereolineas,
		float bitcoinAereolineas, float unitarioAereolineas, float debitoLatam,
		float creditoLatam, float bitcoinLatam, float unitarioLatam, float diferenciaPrecio)
{
	int opcion;
	int kilometrosIngresadosF;
	float precioVueloLatamF;
	float precioVueloAereolineasF;
	float debitoAereolineasF;
	float creditoAereolineasF;
	float bitcoinAereolineasF;
	float unitarioAereolineasF;
	float debitoLatamF;
	float creditoLatamF;
	float bitcoinLatamF;
	float unitarioLatamF;
	float diferenciaPrecioF;

	kilometrosIngresadosF = 7090;
	precioVueloLatamF = 159339;
	precioVueloAereolineasF = 162965;

	opcion = mostrarMenu();

	switch(opcion)
	{
		case 1:
			printf("\nYa se ingresaron los kilometros.\n");
			ejecutarMenuCinco(kilometrosIngresados, precioVueloAereolineas,
					precioVueloLatam, debitoAereolineas,creditoAereolineas,
					bitcoinAereolineas, unitarioAereolineas, debitoLatam,
					creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);
			break;
		case 2:
			printf("\nYa se ingresaron los precios.\n");
			ejecutarMenuCinco(kilometrosIngresados, precioVueloAereolineas,
					precioVueloLatam, debitoAereolineas,creditoAereolineas,
					bitcoinAereolineas, unitarioAereolineas, debitoLatam,
					creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);
			break;
		case 3:
			printf("\nYa se calcularon los costos.\n");
			ejecutarMenuCinco(kilometrosIngresados, precioVueloAereolineas,
					precioVueloLatam, debitoAereolineas,creditoAereolineas,
					bitcoinAereolineas, unitarioAereolineas, debitoLatam,
					creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);
			break;
		case 4:
			mostrarCostos(kilometrosIngresados, precioVueloAereolineas,
					precioVueloLatam, debitoAereolineas,creditoAereolineas,
					bitcoinAereolineas, unitarioAereolineas, debitoLatam,
					creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);
			ejecutarMenuCinco(kilometrosIngresados, precioVueloAereolineas,
					precioVueloLatam, debitoAereolineas,creditoAereolineas,
					bitcoinAereolineas, unitarioAereolineas, debitoLatam,
					creditoLatam, bitcoinLatam, unitarioLatam, diferenciaPrecio);
			break;
		case 5:
				debitoAereolineasF = calcularDebito(precioVueloAereolineasF, 10);
				debitoLatamF = calcularDebito(precioVueloLatamF, 10);
				creditoAereolineasF = calcularCredito(precioVueloAereolineasF, 25);
				creditoLatamF = calcularCredito(precioVueloLatamF, 25);
				bitcoinAereolineasF = calcularBitcoin(precioVueloAereolineasF, valorBitcoin);
				bitcoinLatamF = calcularBitcoin(precioVueloLatamF, valorBitcoin);
				unitarioAereolineasF = calcularUnitario(precioVueloAereolineasF,kilometrosIngresadosF);
				unitarioLatamF = calcularUnitario(precioVueloLatamF,kilometrosIngresadosF);
				diferenciaPrecioF= calcularDiferencia(precioVueloLatamF, precioVueloAereolineasF);

				mostrarCostos(kilometrosIngresadosF, precioVueloAereolineasF, precioVueloLatamF,
						debitoAereolineasF, creditoAereolineasF, bitcoinAereolineasF, unitarioAereolineasF,
						debitoLatamF, creditoLatamF, bitcoinLatamF, unitarioLatamF, diferenciaPrecioF);
				break;
		case 6:
			printf("\nFin de la funcion.");
			break;

	}

	return opcion;
}
