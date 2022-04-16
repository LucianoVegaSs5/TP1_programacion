/*
 * ingresodatos.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include "utn.h"
#include "calculos.h"
#include "ingresodatos.h"

int mostrarMenu()
{
int opcion;

	do
	{
		printf( "\n1)Ingresar Kilómetros\n"
				"2)Ingresar Precio de Vuelos\n"
				"3)Calcular todos los costos\n"
				"4)Informar Resultados\n"
				"5)Carga forzada de datos\n"
				"6)Salir\n");

		printf("Elija una opcion: ");
		scanf("%d", &opcion);

	}while(opcion > 6 || opcion < 1);

    return opcion;
}
int ingresoDatosOpcionUno()
{
	int kilometrosIngresados;

	do
	{
		printf("\nIngrese la cantidad de kilometros: ");
		scanf("%d", &kilometrosIngresados);

	}while(kilometrosIngresados < 1);

	return kilometrosIngresados;
}

