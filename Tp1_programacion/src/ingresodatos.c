/*
 * ingresodatos.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include "utn.h"
#include "calculos.h"


void mostrarMenuPrincipal(int* opcion)
{
	pedirNumeros(opcion, "\n\n============== MENU PRINCIPAL==============\n"
						"1)Ingresar kilometros\n"
						"2)Ingresar Precio de Vuelos\n"
						"3)Calcular todos los costos\n"
						"4)Informar Resultados\n"
						"5)Carga forzada de datos\n"
						"6)Salir\n"
						"Ingrese una opcion: ", "Error, el numero ingresado es invalido\n", "Error, elija una opcion valida\n",6,1);
}
