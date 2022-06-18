/*
 * printearMenues.c
 *
 *  Created on: 24 may. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input-UTN.h"

void preguntarTipoDeLista(int* lista)
{
	pedirNumeros(lista, "\nListar:\n"
				"1)Listar todos los pasajeros\n"
				"2)Listar pasajeros en vuelo\n"
				"3)Listar pasajeros en horario\n"
				"4)Listar vuelos aterrizados\n"
				"5)Listar vuelos en demora\n"
				"Sellecione una opcion: ", "Error elija una opcion valida\n", "Error, elija una opcion entre 1 y 5", 5, 1);
}

void preguntarOrden(int* orden)
{
	pedirNumeros(orden, "\nOrdenar de manera:\n"
					"1) ascendente\n"
					"2) descendente\n", "Error, elija una opcion valida\n", "Error, elija una opcion entre 1 y 2\n", 2, 1);
}
void preguntarSort(int* sort)
{
	pedirNumeros(sort, "\nTipo de ordenamiento:\n"
			"1)Ordenar por id\n"
			"2)Ordenar por apellido\n"
			"Elija una opcion: ", "Error, opcion invalida\n", "Error, elija una opcion valida entre 1 y 2\n", 2, 1);
}

void mostrarMenuPrincipal(int* opcion)
{
	pedirNumeros(opcion, "\nMenu: \n"
			"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
			"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
			"3. Alta de pasajero\n"
			"4. Modificar datos de pasajero\n"
			"5. Baja de pasajero\n"
			"6. Listar pasajeros\n"
			"7. Ordenar pasajeros\n"
			"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
			"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
			"10. Salir.\n", "Error, Elija una opcion valida por favor", "Error, elija una opcion entre 1-10.\n", 10 ,1);
}

void guardarCambios(int* confirmar)
{
	pedirNumeros(confirmar, "¿Desea guardar los cambios?\n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)\n", "Error, escoga una opcion valida", 2, 1);
}

void borrarPasajero(int* confirmar)
{
	pedirNumeros(confirmar, "¿Esta seguro de borrar los datos del pasajero? seleccione 2 si el id es erroneo \n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)\n", "Error, escoga una opcion valida\n", 2, 1);
}

void modificarPasajero(int* confirmar)
{
	pedirNumeros(confirmar, "¿Esta seguro de modificar los datos del pasajero? seleccione 2 si el id es erroneo \n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)\n", "Error, escoga una opcion valida\n", 2, 1);
}

void mostrarMenuSalida(int *salir)
{
	pedirNumeros(salir, "\n¿ESTA SEGURO DE SALIR?\n"
	    		"1) CONFIRMAR\n"
	 			"2) CANCELAR\n",
				"Error, ingrese una de las opciones (1-2)","Error, ingrese una de las opciones (1-2)\n", 2,1);
}

void opcionModificar(int* opcion)
{
	pedirNumeros(opcion, "Modificar: \n"
					"1- Nombre\n"
					"2- Apellido\n"
					"3- Precio\n"
					"4- Codigo de Vuelo\n"
					"5- Tipo de pasajero\n"
					"6- Estado de vuelo\n"
					"Ingrese la opcion que busca modificar: ", "Error, debe de ingresar la opcion a modificar", "Error, elija una opcion valida", 6 , 1);
}

void preguntaContinuar(int* continuar)
{
	pedirNumeros(continuar, "¿Desea continuar? \n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)\n", "Error, escoja una opcion valida", 2, 1);
}
