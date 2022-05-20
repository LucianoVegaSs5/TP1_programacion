/*
 * arrayPassenger.c
 *
 *  Created on: 13 may. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "UTN_validaciones.h"
#include "printearMenues.h"

struct
{
  int id;
  char name[51];
  char lastName[51];
  float price;
  char flycode[10];
  int typePassenger;
  int isEmpty;
  int statusFlight;
}typedef ePassenger;

int mostrarPasajero(ePassenger passenger, int length)
{
    int retorno =-1;

    if(length > 0)
    {
    	printf("      %d       ",passenger.id);
    	printf("%s       ", passenger.name);
    	printf("%s       ", passenger.lastName);
    	printf("%.2f        ",passenger.price);
    	printf("%s              ",passenger.flycode);

    	switch(passenger.typePassenger)
    	{
    		case 1:
    			printf("TURISTA                  ");
    			break;
    		case 2:
    			printf("COMERCIAL                ");
				break;
    		case 3:
    		    printf("JUBILADO                 ");
    			break;
    		case 4:
    		    printf("DISTINTA CAPACIDAD       ");
    			break;
    	}

    	switch(passenger.statusFlight)
    	{
       		case 1:
   	   			printf("ACTIVO\n");
   	   			break;
       		case 2:
       			printf("DEMORA\n");
				break;
  	   		case 3:
   	 		    printf("EN ESPERA\n");
       			break;
   	    	}

        retorno = 0;
    }

    return retorno;
}

int buscarLugarVacio(ePassenger list[], int len)
{
    int retorno = -1;
    int i;

    if(len > 0 && list !=  NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int initPassengers (ePassenger * list, int len)
{
    int retorno = -1;
    int i;
    if(list != NULL && len >0)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty = 1; // Declaramos vacios todas las pocisiones
        }
        retorno = 0;
    }

    return retorno;
}

int addPassenger(ePassenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
    int retorno = -1;
    int lugarVacio;

    lugarVacio = buscarLugarVacio(list, len);
    if(lugarVacio > -1)
    {
        if(list != NULL && len > 0)
        {
            list[lugarVacio].isEmpty = 0;//Declaramos que el lugar ya no esta vacio
            list[lugarVacio].id = id;
            strcpy(list[lugarVacio].name, name);
            strcpy(list[lugarVacio].lastName, lastName);
            list[lugarVacio].price = price;
            list[lugarVacio].typePassenger = typePassenger;
            strcpy(list[lugarVacio].flycode, flycode);
            list[lugarVacio].statusFlight = statusFlight;
            retorno = 0;
        }
    }
    return retorno;
}

int findPassengerById(ePassenger* list, int len,int id)
{
    int i;
    int retorno =-1;

    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id == id)
            {
                retorno = i;
            }
        }
    }

    return retorno;
}

int removePassenger(ePassenger* list, int len, int id)
{
    int i;
    int retorno =-1;

    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id == id)
            {
                list[i].isEmpty = 1;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int sortPassengers(ePassenger* list, int len, int order)
{
    int i;
    int j;
    int diferencia;
    ePassenger guardar;
    int retorno = -1;

    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            for(j=i+1; j<len-1; j++)
            {
                if(order == 0)//De menor a mayor
                {
                    if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
                    {
                        diferencia = strcmp(list[i].lastName, list[j].lastName);

                        if(diferencia < 0)
                        {
                            guardar = list[j];
                            list[j] = list[i];
                            list[i] = guardar;
                        }
                        else
                        {
                            if(diferencia  == 0)
                            {
                                if(list[i].typePassenger >= list[j].typePassenger)
                                {
                                    guardar = list[j];
                                    list[j] = list[i];
                                    list[i] = guardar;
                                }
                            }
                        }
                    }
                }

                else //de mayor a menor
                {
                    if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
                    {
                        diferencia = strcmp(list[i].lastName, list[j].lastName);

                        if(diferencia > 0)
                        {
                            guardar = list[j];
                            list[j] = list[i];
                            list[i] = guardar;
                        }
                        else
                        {
                            if(diferencia  == 0)
                            {
                                if(list[i].typePassenger <= list[j].typePassenger)
                                {
                                    guardar = list[j];
                                    list[j] = list[i];
                                    list[i] = guardar;
                                }
                            }
                        }
                    }
                }
            }
        }

        retorno = 0;
    }

    return retorno;
}

int printPassenger(ePassenger* list, int length)
{
    int i;
    int retorno = -1;

    if(list != NULL && length > 0)
    {
        printf("\n      iD      Nombre      Apellido        Precio       codVuelo         Tipo de Pasajero        Estado de Vuelo\n\n");
        for(i=0; i<length; i++)
        {
            if(list[i].isEmpty == 0)
            {
                if(mostrarPasajero(list[i], length)== 0)
                {
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

int sortPassengersByCode(ePassenger* list, int len, int order)
{
    int i;
    int j;
    ePassenger guardar;
    int retorno = -1;
    int diferencia;

    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            for(j=i+1; j<len-1; j++)
            {
                if(order == 0)//De menor a mayor
                {
                    if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
                    {
                        diferencia =  strcmp(list[i].flycode, list[j].flycode);

                        if(diferencia < 0)
                        {
                            guardar = list[j];
                            list[j] = list[i];
                            list[i] = guardar;
                        }
                        else
                        {
                            if(diferencia == 0)
                            {
                                if(list[i].statusFlight > list[j].statusFlight)
                                {
                                    guardar = list[j];
                                    list[j] = list[i];
                                    list[i] = guardar;
                                }
                            }
                        }
                    }
                }
                else //de mayor a menor
                {
                    if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
                    {
                        diferencia =  strcmp(list[i].flycode, list[j].flycode);

                        if(diferencia > 0)
                        {
                            guardar = list[j];
                            list[j] = list[i];
                            list[i] = guardar;
                        }
                        else
                        {
                            if(diferencia == 0)
                            {
                                if(list[i].statusFlight < list[j].statusFlight)
                                {
                                    guardar = list[j];
                                    list[j] = list[i];
                                    list[i] = guardar;
                                }
                            }
                        }
                    }
                }
            }
        }

        retorno = 0;
    }

    return retorno;
}

int altaPasajero(ePassenger lista[], int tam, int* contadorId, int* primerIngreso)
{
    int retorno = -1;
    int validarGuardado;
	ePassenger auxPassenger;
	char nombre[51];
	char apellido[51];
	float price;
	char codVuelo[20];
	int tipoPasajero;
	int estadoVuelo;

    		if(lista != NULL && tam>0 && contadorId != NULL)
    		{
    			printf("----------- ALTA -----------\n");


    			auxPassenger.id=*contadorId;
    			(*contadorId)++;

    			getString(nombre, "Ingrese su nombre: ");

    			getString(apellido, "Ingrese su apellido: ");

    			getNumeroValidarMaxMinFloat(&price, "Ingrese el precio del vuelo: ",
    			"Error, ingrese un precio mayor a 0 y menor a 10000", 10000, 1);

    			getString(codVuelo, "Ingrese Su codigo De vuelo: ");

    			getNumeroValidarMaxMin(&tipoPasajero, "Ingrese el tipo de pasajero\n"
    			                            "1- TURISTA\n"
    			                            "2- COMERCIAL\n"
    			                            "3- JUBILADO/A\n"
    			                            "4- DISTINTA CAPACIDAD\n", "Error, ingrese una opcion Valida\n"
                                                                "1- TURISTA\n"
    			                                                "2- COMERCIAL\n"
    			                                                "3- JUBILADO/A\n"
    			                                                "4- DISTINTA CAPACIDAD\n", 4,1);

    			getNumeroValidarMaxMin(&estadoVuelo, "Ingrese el estado de Vuelo\n"
    			                            "1- ACTIVO\n"
    			                            "2- DEMORA\n"
    			                            "3- EN ESPERA\n", "Error, ingrese una opcion Valida\n"
    			                                            "1- ACTIVO\n"
    			                                            "2- DEMORA\n"
    			                                            "3- EN ESPERA\n", 3,1);

    			strcpy(auxPassenger.name, nombre);
    			strcpy(auxPassenger.lastName, apellido);
    			auxPassenger.price = price;
    			strcpy(auxPassenger.flycode, codVuelo);
    			auxPassenger.typePassenger = tipoPasajero;
    			auxPassenger.statusFlight = estadoVuelo;

    			retorno = 1;
    		}

    		if(retorno == 1)
    		{
    			validarGuardado = addPassenger(lista, tam, auxPassenger.id, auxPassenger.name,
    					auxPassenger.lastName, auxPassenger.price, auxPassenger.typePassenger, auxPassenger.flycode, auxPassenger.statusFlight);

    			if(validarGuardado == 0)
    			{
    				printf("\n SE A GUARDADO CORRECTAMENTE, SU NUMERO DE ID ES:  %d \n", auxPassenger.id);
    				retorno = 0;
    				*primerIngreso = 1;
    			}
    			else
    			{
    				printf("\n NO HAY ESPACIO SUFICIENTE \n ");
    			}
    		}

	return retorno;
}

int realizarCargaForzada(ePassenger list[], int len){

	int retorno =-1;

	if(list != NULL && len > 0)
	{
		addPassenger(list, len, 1,"Lucas ", "Gaspar", 3000, 3, "ABC123", 3);
		addPassenger(list, len, 2,"Alejandra","Paz ", 5000, 2, "ABC123", 2);
		addPassenger(list, len, 3,"Marcos", "Suarez", 1000, 4, "YZX789", 2);
		addPassenger(list, len, 4,"Romina", "Sosa  ", 1500, 3, "YZX789", 1);
		addPassenger(list, len, 5,"Jose  ", "Rival ", 8000, 1, "LMN456", 1);

		retorno = 0;

	}

	return  retorno;
}

void cargaForzada(ePassenger list[], int len, int* flagCarga)
{
	int validarCargaForzada;

	if(*flagCarga == 1)
	{
		printf("LA CARGA DE DATOS YA FUE REALIZADA");
	}
	else
	{
		if(list != NULL && len > 0)
		{
			printf("----------- CARGA FORZADA -----------\n");
			validarCargaForzada= realizarCargaForzada(list, len);

			if(validarCargaForzada == 0)
			{
					printf("SE REALIZO LA CARGA DE DATOS DE LA CARGA FORZADA\n");
					*flagCarga = 1;
			}
			else
			{
				printf("AlGO SALIO MA\nL");
			}

		}

	}

}

float calcularPrecio(ePassenger list[], int len)
{
    float precioAcumulado = 0;
    int i;
    for(i=0; i<len; i++)
    {
    	if(list[i].isEmpty == 0)
    	{
    		precioAcumulado = precioAcumulado + list[i].price;
    	}
    }

    return precioAcumulado;
}

float calcularPrecioPromedio(ePassenger list[], int len, int precioAcumulado)
{
    float precioPromedio;
    int contadorPasajeros = 0;
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            contadorPasajeros = contadorPasajeros + 1;
        }
    }

    precioPromedio = precioAcumulado / contadorPasajeros;

    return precioPromedio;
}

int calcularPasajerosMayorPrecio(ePassenger list[], int len, float precioPromedio)
{
    int contadorPasajerosMayorPrecio = 0;

    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            if(list[i].price > precioPromedio)
            {
                contadorPasajerosMayorPrecio = contadorPasajerosMayorPrecio + 1;
            }
        }

    }

    return contadorPasajerosMayorPrecio;
}

void informarPasajeros(ePassenger list[], int len, int flagDeCarga, int flagDeIngreso)
{
	float precioTotal;
	float precioPromedio;
	int pasajerosMayorPrecio;
	int validarSort;

	int opcion;
	int opcionOrden;

	if(list !=  NULL && len > 0 &&(flagDeCarga == 1 || flagDeIngreso == 1))
	{
		printf("----------- INFORMAR -----------\n");
		getNumeroValidarMaxMin(&opcion, "INFORMAR\n"
										"1)LISTADO DE LOS PASAJEROS ORDENADOS ALFABETICAMENTE POR APELLIDO Y TIPO DE PASAJERO.\n"
										"2)TOTAL Y PROMEDIO DE LOS PRECIOS DE LOS PASAJEROS. Y CUANTOS PASAJEROS SUPERAN EL PRECIO PROMEDIO.\n"
										"3)LISTADO DE LOS PASAJEROS POR CODIGO DE VUELO Y ESTADO DE VUELOS ‘ACTIVO’\n", "ERROR, INGRESE UNA OPCION VALIDA\n", 3,1);

		switch(opcion)
		{
			case 1:
				opcionOrden = preguntaOrdenListado();
				validarSort = sortPassengers(list, len, opcionOrden);
				if(validarSort == 0)
				{
					printPassenger(list, len);
				}
				else
				{
					printf("ALGO SALIO MAL\n");
				}
				break;

			case 2:
				precioTotal = calcularPrecio(list, len);
				printf("EL TOTAL DE LOS PRECIOS DE LOS PASAJEROS ES %.2f PESOS.\n", precioTotal);
				precioPromedio = calcularPrecioPromedio(list, len, precioTotal);
				printf("El PROMEDIO DE LOS PRECIOS ES DE %.2f PESOS.\n", precioPromedio);
				pasajerosMayorPrecio = calcularPasajerosMayorPrecio(list, len, precioPromedio);
				printf("LA CANTIDAD DE PASAJEROS QUE SUPERA EL PRECIO PROMEDIO ES %d PASAJEROS.", pasajerosMayorPrecio);
				break;

			case 3:
				opcionOrden = preguntaOrdenListado();
				validarSort = sortPassengersByCode(list, len, opcionOrden);
				if(validarSort == 0)
				{
						printPassenger(list, len);
				}
				else
				{
					printf("ALGO SALIO MAL\n");
				}
				break;
		}
	}
	else
	{
		printf("SE NECESITA INGRESAR DATOS PRIMERO\n");
	}

}

void bajaPasajero(ePassenger list[], int len, int flagDeCarga, int flagDeIngreso)
{
	int idPasajeroBorrar;
	int validacionPocision;
	int opcion;


	if(list != NULL && len > 0 && (flagDeCarga == 1 || flagDeIngreso == 1))
	{
		printf("----------- BAJA -----------\n");
		getNumeroValidarMaxMin(&idPasajeroBorrar, "INGRESE EL ID DEL PASAJERO QUE QUIERE BORRAR\n", "ERROR, INGRESE UN ID MAYOR A 0\n", 2000, 1);
		validacionPocision = findPassengerById(list, len, idPasajeroBorrar);

		if(validacionPocision < 0)
		{
			printf("EL ID INGRESADO ES INCORRECTO\n");
		}
		else
		{
			printf("PASAJERO CON ID %d\n", idPasajeroBorrar);
			printf("\n      iD      Nombre      Apellido        Precio     Tipo de Pasajero      codVuelo      Estado de Vuelo\n\n");
			mostrarPasajero(list[validacionPocision], len);
			getNumeroValidarMaxMin(&opcion, "¿ESTA SEGURO DE BORRAR LOS DATOS DEL PASAJERO?\n"
								"1) CONFIRMAR\n"
								"2) CANCELAR\n","ERROR, ELIJA UNA OPCION VALIDA",2,1);
			if(opcion == 1)
			{
				list[validacionPocision].isEmpty = 1;
				printf("LOS DATOS FUERON BORRADOS CON EXITO");
			}
			else
			{
				printf("OPERACION CANCELADA\n");
			}
		}
	}
	else
	{
		printf("SE NECESITA INGRESAR PRIMERO\n");
	}
}

void modificarPasajero(ePassenger list[], int len, int flagDeCarga, int flagDeIngreso)
{
	int idPasajeroModificar;
	int validacionPocision;
	int opcion;
	char nombre[51];
	char apellido[51];
	float price;
	char codVuelo[20];
	int tipoPasajero;
	int estadoVuelo;


	if(list != NULL && len > 0 && (flagDeCarga == 1 || flagDeIngreso == 1))
	{
		printf("----------- MODIFICAR -----------\n");
		getNumeroValidarMaxMin(&idPasajeroModificar, "INGRESE EL ID DEL PASAJERO QUE QUIERE MODIFICAR\n", "ERROR, INGRESE UN ID MAYOR A 0\n", 2000, 1);
		validacionPocision = findPassengerById(list, len, idPasajeroModificar);

		if(validacionPocision < 0)
		{
			printf("EL ID INGRESADO ES INCORRECTO\n");
		}
		else
		{
			printf("PASAJERO CON ID %d\n", idPasajeroModificar);
			printf("\n      iD      Nombre      Apellido        Precio     Tipo de Pasajero      codVuelo      Estado de Vuelo\n\n");
			mostrarPasajero(list[validacionPocision], len);

			list[validacionPocision].id= idPasajeroModificar;

			getString(nombre, "Ingrese el nuevo nombre: ");
			getString(apellido, "Ingrese el nuevo apellido: ");

			getNumeroValidarMaxMinFloat(&price, "Ingrese el nuevo precio del vuelo: ",
			"Error, ingrese un precio mayor a 0 y menor a 10000", 10000, 1);

			getString(codVuelo, "Ingrese Su nuevo codigo De vuelo: ");

			getNumeroValidarMaxMin(&tipoPasajero, "Ingrese el tipo de pasajero\n"
			   		                            "1- TURISTA\n"
			   		                            "2- COMERCIAL\n"
			   		                            "3- JUBILADO/A\n"
			   		                            "4- DISTINTA CAPACIDAD\n", "Error, ingrese una opcion Valida\n"
		                                                        "1- TURISTA\n"
		    	                                                "2- COMERCIAL\n"
		   		                                                "3- JUBILADO/A\n"
																"4- DISTINTA CAPACIDAD\n", 4,1);

			getNumeroValidarMaxMin(&estadoVuelo, "Ingrese el estado de Vuelo\n"
		    	                            "1- ACTIVO\n"
		  		                            "2- DEMORA\n"
		  		                            "3- EN ESPERA\n", "Error, ingrese una opcion Valida\n"
													"1- ACTIVO\n"
			  	                                    "2- DEMORA\n"
				                                    "3- EN ESPERA\n", 3,1);

			getNumeroValidarMaxMin(&opcion, "¿ESTA SEGURO DE MODIFICAR LOS DATOS DEL PASAJERO?\n"
								"1) CONFIRMAR\n"
								"2) CANCELAR\n","ERROR, ELIJA UNA OPCION VALIDA",2,1);
			if(opcion == 1)
			{

			   	strcpy(list[validacionPocision].name, nombre);
			  	strcpy(list[validacionPocision].lastName, apellido);
			  	list[validacionPocision].price = price;
		    	strcpy(list[validacionPocision].flycode, codVuelo);
		    	list[validacionPocision].typePassenger = tipoPasajero;
		    	list[validacionPocision].statusFlight = estadoVuelo;

				printf("\n      iD      Nombre      Apellido        Precio     Tipo de Pasajero      codVuelo      Estado de Vuelo\n\n");
				mostrarPasajero(list[validacionPocision], len);

				printf("LOS DATOS FUERON MODIFICADOS CON EXITO");

				printf("OCURRIO UN ERROR");

			}
			else
			{
				printf("OPERACION CANCELADA\n");
			}
		}
	}
	else
	{
		printf("SE NECESITAN INGRESAR DATOS PRIMERO\n");
	}
}

