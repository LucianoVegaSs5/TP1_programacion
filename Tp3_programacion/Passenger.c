/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input-UTN.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[20];
	char estadoVuelo[50];

}Passenger;



Passenger* Passenger_new()
{
	Passenger* NuevoPasajero=(Passenger*) malloc(sizeof(Passenger));

	return NuevoPasajero;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->id = id;

		retorno = 1;
	}

	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 1;

	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this !=  NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 1;
	}

	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 1;
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this !=  NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 1;
	}

	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		strcpy(apellido,this->apellido);
		retorno = 1;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 1;
	}

	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno = 1;
	}

	return retorno;
}
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 1;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 1;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setEstadoVuelo (Passenger* this,char* estadoVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno = 1;
	}

	return retorno;
}
int Passenger_getEstadoVuelo (Passenger* this,char* estadoVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno = 1;
	}

	return retorno;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* codigoVueloStr, char* tipoPasajeroStr, char* precioStr, char* estadoVueloStr)
{
	Passenger* pasajero;
	pasajero = Passenger_new();
	int validarCampos = 0;


	if(Passenger_setId(pasajero, atoi(idStr)))
	{
		if(Passenger_setNombre(pasajero, nombreStr))
		{
			if(Passenger_setApellido(pasajero, apellidoStr))
			{
				if(Passenger_setCodigoVuelo(pasajero, codigoVueloStr))
				{
					if(Passenger_setTipoPasajero(pasajero, atoi(tipoPasajeroStr)))
					{
						if(Passenger_setPrecio(pasajero, atof(precioStr)))
						{
							if(Passenger_setEstadoVuelo(pasajero, estadoVueloStr))
							{
								validarCampos = 1;
							}
						}
					}
				}
			}
		}
	}

	if(validarCampos == 0)
	{
		pasajero = NULL;
	}

	return pasajero;
}

void Passenger_print(Passenger* this)
{
	if(this != NULL)
	{
		int idPasajero;
		char nombre[50];
		char apellido[50];
		float precio;
		int tipoPasajero;
		char tipoPasajeroChar[20];
		char codigoVuelo[10];
		char estadoVuelo[20];

		if(Passenger_getId(this, &idPasajero))
		{
			if(Passenger_getNombre(this, nombre))
			{
				if(Passenger_getApellido(this, apellido))
				{
					if(Passenger_getPrecio(this, &precio))
					{
						if(Passenger_getCodigoVuelo(this, codigoVuelo))
						{
							if(Passenger_getEstadoVuelo(this, estadoVuelo))
							{
								if(Passenger_getTipoPasajero(this, &tipoPasajero))
								{
									if(tipoPasajero == 1)
									{
										strcpy(tipoPasajeroChar, "FirstClass");
									}
									else
									{
										if(tipoPasajero == 2)
										{
											strcpy(tipoPasajeroChar, "ExecutiveClass");
										}
										else
										{
											strcpy(tipoPasajeroChar, "EconomyClass");
										}
									}

									printf("%-6d||%-16s||%-12s\t||%-7.2f\t||%-6s\t||%-14s\t||%s\n", idPasajero, nombre, apellido, precio, codigoVuelo, tipoPasajeroChar, estadoVuelo);
								}
							}
						}
					}
				}
			}
		}
	}
}

int Passenger_sortById(void* pasajeroUno, void* pasajeroDos)
{
	int retorno = -1;
	int idPrimerPasajero;
	int idSegundoPasajero;

	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		if(Passenger_getId(pasajeroUno, &idPrimerPasajero))
		{
			if(Passenger_getId(pasajeroDos, &idSegundoPasajero))
			{
				if(idPrimerPasajero > idSegundoPasajero)
				{
					retorno = 1;
				}
				else
				{
					retorno = -1;
				}
			}
		}
	}

	return retorno;
}

