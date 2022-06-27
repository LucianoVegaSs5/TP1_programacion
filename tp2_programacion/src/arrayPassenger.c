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

    char estadoDeVuelo[25];
    char tipoPasajero[25];

    if(length > 0)
    {
    	switch(passenger.typePassenger)
    	{
    		case 1:
    			strcpy(tipoPasajero, "TURISTA");
    			break;
    		case 2:
    			strcpy(tipoPasajero,"COMERCIAL");
				break;
    		case 3:
    			strcpy(tipoPasajero,"JUBILADO");
    			break;
    		case 4:
    			strcpy(tipoPasajero,"DISTINTA CAPACIDAD");
    			break;
    	}

    	switch(passenger.statusFlight)
    	{
       		case 1:
   	   			strcpy(estadoDeVuelo,"ACTIVO");
   	   			break;
       		case 2:
       			strcpy(estadoDeVuelo,"DEMORA");
				break;
  	   		case 3:
  	   		strcpy(estadoDeVuelo,"EN ESPERA");
       			break;
   	    }

    printf("||%-6d||%-16s||%-10s\t||%-7.2f\t||%-6s\t||%-14s\t||%s\n",passenger.id, passenger.name, passenger.lastName, passenger.price, passenger.flycode, tipoPasajero, estadoDeVuelo);


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
        if(list != NULL && len >= 0)
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

    if(list != NULL && len >= 0)
    {
        for(i=0; i<len; i++)
        {
        	if(list[i].isEmpty == 0)
        	{
				if(list[i].id == id)
				{
					retorno = i;
					break;
				}
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
        printf("======================================================================================================================\n");
        printf("    iD        Nombre          Apellido        Precio         codVuelo       Tipo de Pasajero       Estado de Vuelo \n");
        printf("======================================================================================================================\n");
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
        printf("=====================================================================================================================\n");

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

    			pedirString(nombre, "Ingrese su nombre: ","Error, no ingrese numeros\n");

    			pedirString(apellido, "Ingrese su apellido: ","Error, no ingrese numeros\n");

    			pedirNumerosFloat(&price, "Ingrese el precio del vuelo: ","Error, solo ingrese numeros\n",
    			"Error, ingrese un precio mayor a 0 \n", 100000000, 1);

    			printf( "Ingrese Su codigo De vuelo: ");
    			fflush(stdin);
    			gets(codVuelo);

    			pedirNumeros(&tipoPasajero, "\nIngrese el tipo de pasajero\n"
    			                            "1- TURISTA\n"
    			                            "2- COMERCIAL\n"
    			                            "3- JUBILADO/A\n"
    			                            "4- DISTINTA CAPACIDAD\n", "Error, debe ingresar solo un numero\n","Error, ingrese una opcion Valida\n"
                                                                "1- TURISTA\n"
    			                                                "2- COMERCIAL\n"
    			                                                "3- JUBILADO/A\n"
    			                                                "4- DISTINTA CAPACIDAD\n", 4,1);

    			pedirNumeros(&estadoVuelo, "Ingrese el estado de Vuelo\n"
    			                            "1- ACTIVO\n"
    			                            "2- DEMORA\n"
    			                            "3- EN ESPERA\n", "Error, debe ingresar solo un numero\n","Error, ingrese una opcion Valida\n"
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
		addPassenger(list, len, 1,"Lucas ", "Gaspar", 3000, 3, "ABC123", 1);
		addPassenger(list, len, 2,"Alejandra","Paz", 5000, 1, "ABC123", 2);
		addPassenger(list, len, 3,"Marcos", "Suarez", 1000, 4, "YZX789", 1);
		addPassenger(list, len, 4,"Romina", "Sosa", 1500, 2, "YZX789", 2);
		addPassenger(list, len, 5,"Jose  ", "Rival", 8000, 1, "LMN456", 2);
		addPassenger(list, len, 6,"Miriam ", "Lopez", 3000, 3, "ABC123", 3);
		addPassenger(list, len, 7,"Roman","Gutierrez", 5000, 4, "ABC123", 1);
		addPassenger(list, len, 8,"Ruben", "Rival", 1000, 4, "YZX789", 3);
		addPassenger(list, len, 9,"Samuel", "Sosa", 1500, 3, "YZX789", 2);
		addPassenger(list, len, 10,"Monica", "Coronel", 8000, 1, "LMN456", 1);


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
		pedirNumeros(&opcion, "INFORMAR\n"
									"1)LISTADO DE LOS PASAJEROS ORDENADOS ALFABETICAMENTE POR APELLIDO Y TIPO DE PASAJERO.\n"
									"2)TOTAL Y PROMEDIO DE LOS PRECIOS DE LOS PASAJEROS. Y CUANTOS PASAJEROS SUPERAN EL PRECIO PROMEDIO.\n"
									"3)LISTADO DE LOS PASAJEROS POR CODIGO DE VUELO Y ESTADO DE VUELOS ‘ACTIVO’\n", "ERROR, INGRESE UNA OPCION VALIDA\n",
									"ERROR, ELIJA UNA OPCION ENTRE 3-1\n", 3,1);

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
	int validacionPocision = 0;
	int opcion;


	if(list != NULL && len > 0 && (flagDeCarga == 1 || flagDeIngreso == 1))
	{
		printf("----------- BAJA -----------\n");
		pedirNumeros(&idPasajeroBorrar, "INGRESE EL ID DEL PASAJERO QUE QUIERE BORRAR\n","ERROR,SOLO DEBE INGRESAR NUMEROS\n", "ERROR, INGRESE UN ID MAYOR A 0\n", 2000, 1);

		validacionPocision = findPassengerById(list, len, idPasajeroBorrar);

		if(validacionPocision < 0)
		{
			printf("EL ID INGRESADO ES INCORRECTO\n");
		}
		else
		{
			printf("PASAJERO CON ID %d\n", idPasajeroBorrar);
	        printf("    iD        Nombre          Apellido        Precio         codVuelo       Tipo de Pasajero       Estado de Vuelo \n");

			mostrarPasajero(list[validacionPocision], len);

			pedirNumeros(&opcion, "\n¿ESTA SEGURO DE BORRAR LOS DATOS DEL PASAJERO?\n"
								"1) CONFIRMAR\n"
								"2) CANCELAR\n","ERROR, ELIJA UNA OPCION VALIDA\n","ERROR, ELIJA UNA OPCION ENTRE 2-1\n",2,1);
			if(opcion == 1)
			{
				if(removePassenger(list, len, idPasajeroBorrar) == 0)
				{
					printf("LOS DATOS FUERON BORRADOS CON EXITO");
				}
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
	int guardar;
	char nombre[51];
	char apellido[51];
	float price;
	char codVuelo[20];
	int tipoPasajero;
	int estadoVuelo;
	int continuar;
	int opcionModificar;

	if(list != NULL && len > 0 && (flagDeCarga == 1 || flagDeIngreso == 1))
	{
		printf("----------- MODIFICAR -----------\n");
		pedirNumeros(&idPasajeroModificar, "INGRESE EL ID DEL PASAJERO QUE QUIERE MODIFICAR\n","Error, solo numeros", "ERROR, INGRESE UN ID MAYOR A 0\n", 2000, 1);
		validacionPocision = findPassengerById(list, len, idPasajeroModificar);

		if(validacionPocision < 0)
		{
			printf("EL ID INGRESADO ES INCORRECTO\n");
		}
		else
		{
			printf("PASAJERO CON ID %d\n", idPasajeroModificar);
			printf("    iD        Nombre          Apellido        Precio         codVuelo       Tipo de Pasajero       Estado de Vuelo \n");

			mostrarPasajero(list[validacionPocision], len);

			list[validacionPocision].id = idPasajeroModificar;

			do{
				 mostrarMenuModificar(&opcionModificar);

				switch(opcionModificar)
				{
					case 1:
						pedirString(nombre, "\nIngrese su nombre: ","Error, no ingrese numeros\n");
						guardarCambios(&guardar);
						if(guardar == 1)
						{
						   	strcpy(list[validacionPocision].name, nombre);
						}
						else
						{
							printf("Operacion cancelada\n");
						}
						break;
					case 2:
						pedirString(apellido, "Ingrese su apellido: ","Error, no ingrese numeros\n");
						guardarCambios(&guardar);
						if(guardar == 1)
						{
							strcpy(list[validacionPocision].lastName, apellido);
						}
						else
						{
							printf("Operacion cancelada\n");
						}
						break;
					case 3:
						pedirNumerosFloat(&price, "Ingrese el precio del vuelo: ","Error, solo ingrese numeros\n",
								    		"Error, ingrese un precio mayor a 0 ", 10000000, 1);
						guardarCambios(&guardar);
						if(guardar == 1)
						{
							list[validacionPocision].price =  price;
						}
						else
						{
							printf("Operacion cancelada\n");
						}
						break;
					case 4:
						printf( "Ingrese Su codigo De vuelo: ");
						fflush(stdin);
						gets(codVuelo);
						guardarCambios(&guardar);
						if(guardar == 1)
						{
							strcpy(list[validacionPocision].flycode, codVuelo);
						}
						else
						{
							printf("Operacion cancelada\n");
						}
						break;
					case 5:
						pedirNumeros(&tipoPasajero, "\nIngrese el tipo de pasajero\n"
														"1- TURISTA\n"
														"2- COMERCIAL\n"
														"3- JUBILADO/A\n"
														"4- DISTINTA CAPACIDAD\n","Error, solo numero", "Error, ingrese una opcion Valida\n"
																		"1- TURISTA\n"
																		"2- COMERCIAL\n"
																		"3- JUBILADO/A\n"
																		"4- DISTINTA CAPACIDAD\n", 4,1);
						guardarCambios(&guardar);
						if(guardar == 1)
						{
							list[validacionPocision].typePassenger = tipoPasajero;
						}
						else
						{
							printf("Operacion cancelada\n");
						}
						break;
					case 6:
						pedirNumeros(&estadoVuelo, "Ingrese el estado de Vuelo\n"
													"1- ACTIVO\n"
													"2- DEMORA\n"
													"3- EN ESPERA\n", "Error, solo numero","Error, ingrese una opcion Valida\n"
															"1- ACTIVO\n"
															"2- DEMORA\n"
															"3- EN ESPERA\n", 3,1);

						guardarCambios(&guardar);
						if(guardar == 1)
						{
							list[validacionPocision].statusFlight = estadoVuelo;
						}
						else
						{
							printf("Operacion cancelada\n");
						}
						break;
				}

				deseaContinuar(&continuar);

			}while(continuar != 2);

		    	printf("    iD        Nombre          Apellido        Precio         codVuelo       Tipo de Pasajero       Estado de Vuelo \n");
				mostrarPasajero(list[validacionPocision], len);
				printf("\nLOS DATOS FUERON MODIFICADOS CON EXITO\n");
		}
	}
	else
	{
		printf("\nSE NECESITAN INGRESAR DATOS PRIMERO\n");
	}
}

