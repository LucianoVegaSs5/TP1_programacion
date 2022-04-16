/*
 * calculos.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


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

float calcularBitcoin(float precioVuelo, float valorBit)
{
	float resultado;

	resultado = precioVuelo / valorBit;

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
