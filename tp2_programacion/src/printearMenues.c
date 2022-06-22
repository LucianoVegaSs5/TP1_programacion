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

	pedirNumeros(opcion, "\n\n========== Menu ==========\n"
				"1-ALTA\n"
				"2-MODIFICAR\n"
				"3-BAJA\n"
				"4-INFORMAR\n"
				"5-CARGA FORZADA\n"
				"6-SALIR\n",
				"Error, solo debe ingresar un numero\n",
				"Error, debe elegir una opcion entre 1 - 6\n"
				"Elija una opcion:\n ", 6,1);

}

void mostrarMenuSalida(int *salir)
{
	pedirNumeros(salir, "\n¿ESTA SEGURO DE SALIR?\n"
	    		"1) CONFIRMAR\n"
	 			"2) CANCELAR\n",
				"Error, solo debe ingresar un numero\n",
				"Error, ingrese una de las opciones (1-2)", 2,1);
}

void mostrarMenuModificar(int* opcion)
{
	pedirNumeros(opcion, "\n MODIFICAR: \n"
				"1-NOMBRE\n"
				"2-APELLIDO\n"
				"3-PRECIO\n"
				"4-CODIGO DE VUELO\n"
				"5-TIPO DE PASAJERO\n"
				"6-ESTADO DE VUELO\n",
				"Error, solo debe ingresar un numero\n",
				"Error, debe elegir una opcion entre 1 - 6\n"
				"Elija una opcion:\n ", 6,1);

}

void guardarCambios(int* opcion)
{
	pedirNumeros(opcion, "¿ESTA SEGURO DE MODIFICAR LOS DATOS DEL PASAJERO?\n"
								"1) CONFIRMAR\n"
								"2) CANCELAR\n","Error, solo numero","ERROR, ELIJA UNA OPCION VALIDA",2,1);
}
void deseaContinuar(int* modificar )
{
	pedirNumeros(modificar, "\n¿DEASEA CONTINUAR?\n"
		    		"1) CONFIRMAR\n"
		 			"2) CANCELAR\n",
					"Error, solo debe ingresar un numero\n",
					"Error, ingrese una de las opciones (1-2)", 2,1);
}

int preguntaOrdenListado(void)
{
	int opcion;
	int retorno;
	pedirNumeros(&opcion, "1) VER LA LISTA DE MAYOR A MENOR\n2) VER LA LISTA DE MENOR A MAYOR\n","ERROR, INGRESE UNA OPCION VALIDA\n",
			"ERROR, ELIJA UNA OPCION ENTRE 1-2", 2, 1);

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
