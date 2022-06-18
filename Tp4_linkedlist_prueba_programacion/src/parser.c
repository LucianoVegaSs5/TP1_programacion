#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "input-UTN.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	char idAux[4];
	char nombreAux[25];
	char apellidoAux[25];
	char precioAux[25];
	char tipoPasajeroAux[25];
	char estadoVueloAux[25];
	char codigoAux[8];
	Passenger* pasajero;

	if(pFile != NULL)
	{
		if(pArrayListPassenger != NULL)
		{
			fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idAux, nombreAux, apellidoAux, precioAux, codigoAux, tipoPasajeroAux, estadoVueloAux);
			do
			{
				if(fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idAux, nombreAux, apellidoAux, precioAux, codigoAux, tipoPasajeroAux, estadoVueloAux) == 7)
				{

					if(strcmp(tipoPasajeroAux,"FirstClass") == 0)
					{
						strcpy(tipoPasajeroAux, "1");
					}
					else
					{
						if(strcmp(tipoPasajeroAux,"ExecutiveClass") == 0)
						{
							strcpy(tipoPasajeroAux, "2");
						}
						else
						{
							strcpy(tipoPasajeroAux, "3");
						}
					}

				}

				pasajero =  Passenger_newParametros(idAux,nombreAux,apellidoAux,codigoAux,tipoPasajeroAux, precioAux,estadoVueloAux);


				if(pasajero != NULL)
				{
					ll_add(pArrayListPassenger, pasajero);
					retorno = 1;
				}
				else
				{
					printf("Error al levantar datos, porfavor intentelo de nuevo\n");
				}

			}while(!feof(pFile));
		}
	}
	else
	{
		printf("Lo sentimos!Hubo urror al cargar el archivo modo txt.\n");
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int lecturaBin;
	Passenger* nuevoPasajero;

	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			nuevoPasajero = Passenger_new();

			if(nuevoPasajero != NULL)
			{
				lecturaBin = fread(nuevoPasajero,sizeof(Passenger),1,pFile);

				if(lecturaBin != 0)
				{
					if(ll_add(pArrayListPassenger ,nuevoPasajero) == 0)
					{
						retorno = 1;
					}
				}
			}
		}
	}
	else
	{
		printf("Error en Lectura en Binario\n");
	}

    return retorno;
}
