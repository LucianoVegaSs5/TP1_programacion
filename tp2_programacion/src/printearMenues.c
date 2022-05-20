/*
 * printearMenues.c
 *
 *  Created on: 13 may. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "arrayPassenger.h"
#include "UTN_validaciones.h"


void mostrarMenuPrincipal(int *opcion)
{

	getNumeroValidarMaxMin(opcion, "\n\n========== Menu ==========\n\n"
				"1-ALTA\n"
				"2-MODIFICAR\n"
				"3-BAJA\n"
				"4-INFORMAR\n"
				"5-CARGA FORZADA\n"
				"6-SALIR\n",
				"Error, debe elegir una opcion entre 1 - 6\n"
				"Elija una opcion:\n ", 6,1);

}

void mostrarMenuSalida(int *salir)
{
	getNumeroValidarMaxMin(salir, "\n¿ESTA SEGURO DE SALIR?\n"
	    		"1) CONFIRMAR\n"
	 			"2) CANCELAR\n",
				"Error, ingrese una de las opciones (1-2)", 2,1);
}

int preguntaOrdenListado(void)
{
	int opcion;
	int retorno;
	getNumeroValidarMaxMin(&opcion, "1) VER LA LISTA DE MAYOR A MENOR\n2) VER LA LISTA DE MENOR A MAYOR\n","ERROR, INGRESE UNA OPCION VALIDA\n", 2, 1);

	if(opcion == 1)
	{
		retorno = 1;
	}
	else
	{
		retorno = 0;
	}
	return retorno;
}
