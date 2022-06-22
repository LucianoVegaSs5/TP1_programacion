/*
 * calculos.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#define INTERES 25
#define DESCUENTO 10
#define BITCOIN_VALOR 7677037.38//valor del bitcoin 14/4/2022 en pesos fuente: https://www.ripio.com/ar/


float calcularDebito(float precioVuelo, int descuento)
{
	float resultado;

	resultado = precioVuelo - precioVuelo *((float) descuento/100);

	return resultado;
}

float calcularCredito(float precioVuelo, int interes)
{
	float resultado;

	resultado = precioVuelo + precioVuelo *((float) interes/100);

	return resultado;
}

float calcularBitcoin(float precioVuelo)
{
	float resultado;

	resultado = precioVuelo / BITCOIN_VALOR;

	return resultado;
}

float calcularUnitario(float precioVuelo, int kilometrosIngresados)
{
	float resultado;

	resultado = precioVuelo / kilometrosIngresados;

	return resultado;
}

float calcularDiferencia(float precioVueloLatam, float precioVueloAereolineas)
{
	float resultado;

	if(precioVueloLatam > precioVueloAereolineas)
	{
		resultado = precioVueloLatam - precioVueloAereolineas;
	}
	else
	{
		resultado = precioVueloAereolineas - precioVueloLatam;
	}

	return resultado;
}
