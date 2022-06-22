/*
 * funciones_tp.c
 *
 *  Created on: 13 jun. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"
#include "ingresodatos.h"
#define INTERES 25
#define DESCUENTO 10


int ingresarKilometros(int* kilometros, int* primerIngreso)
{
	int retorno = -1;
	int confirmar;

	if(*primerIngreso == 0)
	{
		printf("\nIngresar kilometros: \n ");
		pedirNumeros(kilometros, "\nIngrese la cantidad de kilometros: ", "Error, ingrese un numero valido", "Error, ingrese un numero mayor a 0", 10000000, 1);

		printf("\nLos kilometros fueron cargados con exito\n");
		*primerIngreso = 1;
		retorno = 1;
	}
	else
	{

		printf("\nYa hay cargado precios, Si continua se van a sobreescribir\n");

		pedirNumeros(&confirmar, "¿Desea continuar de todas formas?\n"
							"1)Si\n"
							"2)No\n"
							"Elija una opcion: ", "Error, opcion invalida\n", "Error, elija una opcion entre 1 y 2", 2 , 1);

		if(confirmar == 1)
		{
			printf("\nIngresar kilometros\n ");
			pedirNumeros(kilometros, "\nIngrese la cantidad de kilometros: ", "Error, ingrese un numero valido", "Error, ingrese un numero mayor a 0", 10000000, 1);
			retorno = 1;
			printf("Los kilometros fueron cargados con exito\n");
		}
		else
		{

			retorno = 1;
		}
	}

	return retorno;
}


int ingresarPrecios(float* latamPrecio, float* AereolineasPrecio, int* flagIngreso)
{
	int retorno = -1;
	int confirmar;

	if(*flagIngreso == 0)
	{
		printf("\nIngreso Precios:\n\n");

		getNumeroValidarMaxMinFloat(latamPrecio,"Ingrese el precio de Latam: ", "Error, el valor es demasiado grande o demsiado chico", 9000000, 1);

		getNumeroValidarMaxMinFloat(AereolineasPrecio, "Ingrese el precio de Aereolineas: ", "Error, el valor es demasiado grande o demasiado chico", 9000000, 1);

		retorno = 1;
		printf("Los precios fueron cargados con exito\n");
		*flagIngreso = 1;
				//printf("%.2f latam , %.2f aereolineas\n",*latamKm, *AereolineasKm);
	}
	else
	{
		printf("\nYa hay cargado precios, Si continua se van a sobreescribir\n");

		pedirNumeros(&confirmar, "¿Desea continuar de todas formas?\n"
							"1)Si\n"
							"2)No\n"
							"Elija una opcion: ", "Error, opcion invalida\n", "Error, elija una opcion entre 1 y 2", 2 , 1);

		if(confirmar == 1)
		{
			printf("\nIngreso Precios\n");

			getNumeroValidarMaxMinFloat(latamPrecio,"Ingrese el precio de Latam: ", "Error, el valor es demasiado grande o demsiado chic0", 9000000, 1);

			getNumeroValidarMaxMinFloat(AereolineasPrecio, "Ingrese el precio de Aereolineas: ", "Error, el valor es demasiado grande o demasiado chic0", 9000000, 1);

			retorno = 1;
			printf("Los precios fueron cargados con exito\n");
			*flagIngreso = 1;
			//printf("%.2f latam , %.2f aereolineas\n",*latamKm, *Aereo
		}
		else
		{
			retorno = 1;
		}

	}
	return retorno;
}

float calcularCostos(int* calcular, float* creditoPrecioLm, float* debitoPrecioLm,float* bitcoinPrecioLm, float* unitarioPrecioLm,
		float* creditoPrecioAe,float* debitoPrecioAe,float* bitcoinPrecioAe,float* unitarioPrecioAe, int kilometros,float precioLm,float precioAe){
	int diferencia;

	*creditoPrecioLm = calcularCredito(precioLm, INTERES);
	*creditoPrecioAe = calcularCredito(precioAe, INTERES);

	*debitoPrecioLm = calcularDebito(precioLm, DESCUENTO);
	*debitoPrecioAe = calcularDebito(precioAe, DESCUENTO);

	*bitcoinPrecioLm = calcularBitcoin(precioLm);
	*bitcoinPrecioAe = calcularBitcoin(precioAe);

	*unitarioPrecioLm = calcularUnitario(precioLm, kilometros);
	*unitarioPrecioAe = calcularUnitario(precioAe, kilometros);

	diferencia = calcularDiferencia(precioLm, precioAe);
	*calcular = 1;

	printf("\nCalculando Costos...\n");

	return diferencia;
}

void printCosto( float credito, float debito, float unitario, float bitcoin)
{
	printf("a)Precio con tarjeta de debito: %.2f pesos\n",debito);
	printf("b)Precio con tarjeta de credito: %.2f pesos\n",credito);
	printf("c)Precio pagando con bitcoin: %.7f BTC \n",bitcoin);
	printf("d)Precio unitario: %.2f pesos por km\n", unitario);
}

void printearCostos(float creditoPrecioLm, float debitoPrecioLm,float bitcoinPrecioLm, float unitarioPrecioLm,
	float creditoPrecioAe,float debitoPrecioAe,float bitcoinPrecioAe,float unitarioPrecioAe, int kilometros,float precioLm,float precioAe, float diferencia)
{
	printf("\n\nKilometros ingresados: %d\n", kilometros);

	printf("\nPrecio AEREOLINEAS: %.2f\n", precioAe);
	printCosto(creditoPrecioAe,debitoPrecioAe, unitarioPrecioAe, bitcoinPrecioAe );

	printf("\nPrecio LATAM: %.2f \n", precioLm);
	printCosto(creditoPrecioLm,debitoPrecioLm, unitarioPrecioLm, bitcoinPrecioLm );

	printf("\nLa diferencia de precio es: %.2f pesos", diferencia);
}

void cargaForzada(int kilometros, float precioLm, float precioAe)
{
	float diferencia;

	float creditoLm;
	float creditoAe;

	float debitoLm;
	float debitoAe;

	float bitcoinLm;
	float bitcoinAe;

	float unitarioLm;
	float unitarioAe;

	creditoLm = calcularCredito(precioLm, INTERES);
	creditoAe = calcularCredito(precioAe, INTERES);

	debitoLm = calcularDebito(precioLm, DESCUENTO);
	debitoAe = calcularDebito(precioAe, DESCUENTO);

	bitcoinLm = calcularBitcoin(precioLm);
	bitcoinAe = calcularBitcoin(precioAe);

	unitarioLm = calcularUnitario(precioLm, kilometros);
	unitarioAe = calcularUnitario(precioAe, kilometros);

	diferencia = calcularDiferencia(precioLm, precioAe);
	printf("\nCarga Forzada:");

	printf("\n\nKilometros ingresados: %d\n", kilometros);

	printf("\nPrecio AEREOLINEAS: %.2f\n", precioAe);
	printCosto(creditoAe,debitoAe, unitarioAe, bitcoinAe );

	printf("\nPrecio LATAM: %.2f \n", precioLm);
	printCosto(creditoLm,debitoLm, unitarioLm, bitcoinLm );

	printf("\nLa diferencia de precio es: %.2f pesos", diferencia);

}


