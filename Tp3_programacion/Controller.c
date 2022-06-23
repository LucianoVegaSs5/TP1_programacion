#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "string.h"
#include "input-UTN.h"
#include "printMenues.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* primeraCargaTxt, int primeraCargaBin)
{
	FILE* pFile;
	int retorno = -1;

	if(primeraCargaBin == 0)
	{
		if(*primeraCargaTxt == 0)
		{
			if(pArrayListPassenger != NULL && path != NULL)
			{
				pFile = fopen(path, "r");

				if(pFile != NULL)
				{
					if(parser_PassengerFromText(pFile, pArrayListPassenger))
					{
						retorno = 1;
						*primeraCargaTxt = 1;
						printf("La realizo la carga modo txt exitosamente\n");
					}
					else
					{
						printf("Hubo un error en la lectura texto\n");
					}

					fclose(pFile);
				}
			}
			else
			{
				printf("No se pudo realizar la carga de archivos txt\n");
			}
		}
		else
		{
			retorno = 1;
			printf("Ya fue realizada la carga de archivos txt\n");
		}
	}
	else
	{
		retorno = 1;
		printf("No puede tener mas de un archivo cargado\n");
	}

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int* primeraCargaBin, int primeraCargaTxt)
{
	int retorno =-1;
	FILE* pFile;

	if(primeraCargaTxt == 0)
	{
		if(*primeraCargaBin == 0)
		{
			if(path != NULL && pArrayListPassenger !=  NULL )
			{
				pFile = fopen(path, "rb");

				if(pFile != NULL)
				{
					if(parser_PassengerFromBinary(pFile, pArrayListPassenger))
					{
						*primeraCargaBin = 1;
						retorno = 1;
						printf("La carga de datos modo bin fue realizada con exito\n");
					}
					else
					{
						printf("Hubo un error en la lectura binario\n");
					}

					fclose(pFile);
				}

			}
			else
			{
				printf("No se pudo realizar la carga de archivos bin\n");
			}
		}
		else
		{
			retorno = 1;
			printf("Ya fue realizada la carga de archivos modo bin\n");
		}
	}
	else
	{
		retorno = 1;
		printf("No puede tener mas de un archivo cargado\n");
	}

    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int pasajerosBorrados, int* cantidadPasajerosAgregados, int* carga)
{
	int retorno = -1;
	int largo;
	int idAux;
	char idAuxChar[20];
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	char precioAuxChar[20];
	char codVueloAux[8];
	int tipoPasajeroAux;
	char tipoPasajeroAuxChar[20];
	int estadoVueloAux;
	char estadoVueloAuxChar[20];
	Passenger* pasajero;

	if(pArrayListPassenger != NULL)
	{
		printf("\n============ ALTA ============\n");
		largo = ll_len(pArrayListPassenger);

		if(*cantidadPasajerosAgregados == 0)
		{
			*cantidadPasajerosAgregados = 1;
		}

		idAux = *cantidadPasajerosAgregados + pasajerosBorrados + largo;
		itoa(idAux,idAuxChar,10);

		pedirString(nombreAux, "Ingrese su nombre: ", "Error, ingrese su nombre correctamente\n");

		pedirString(apellidoAux, "Ingrese su Apellido: ", "Error, ingrese su nombre Apellido\n");

		pedirNumerosFloat(&precioAux, "Ingrese el precio del voleto: ", "Error, precio no valido", "Error elija un numero mayor a 0",1000000,1);
		gcvt(precioAux,7,precioAuxChar);

		printf("Ingrese el codigo de Vuelo: ");
		fflush(stdin);
		gets(codVueloAux);

		pedirNumeros(&tipoPasajeroAux, "Tipo de pasajero:\n"
						"1)First Class\n"
						"2)Executive Class\n"
						"3)Economy Class\n"
						"Elija la opcion correspondiente: ", "Error, elija una opcion valida", "Error, elija una opcion entre 1 y 3",3,1);

		itoa(tipoPasajeroAux, tipoPasajeroAuxChar, 10);

		pedirNumeros(&estadoVueloAux, "Estado del vuelo:\n"
						"1)Aterrizado\n"
						"2)En horario\n"
						"3)En vuelo\n"
						"4)Demorado\n"
						"Elija la opcion correspondiente: ", "Error, elija una opcion valida", "Error, elija una opcion entre 1 y 4",4,1);

		switch(estadoVueloAux)
		{
			case 1:
				strcpy(estadoVueloAuxChar,"Aterrizado");
				break;
			case 2:
				strcpy(estadoVueloAuxChar,"En horario");
				break;
			case 3:
				strcpy(estadoVueloAuxChar,"En vuelo");
				break;
			case 4:
				strcpy(estadoVueloAuxChar,"Demorado");
				break;
		}


		pasajero =  Passenger_newParametros(idAuxChar, nombreAux, apellidoAux, codVueloAux, tipoPasajeroAuxChar, precioAuxChar, estadoVueloAuxChar);

		if(pasajero != NULL)
		{
			*carga = 1;
			ll_add(pArrayListPassenger, pasajero);
			*cantidadPasajerosAgregados =+ 1;
			printf("Se cargo con exito! Su id es %d, lo necesitara para modificar o borrar datos\n", pasajero->id);
			retorno = 1;
		}
	}
	else
	{
		printf("Ocurrio un error al iniciar el alta.\n");
	}

    return retorno;
}

/**
 * @brief corrige los ids por si se cargan los del data primero y no se repiten los id
 *
 * @param pArrayListPassenger
 * @param cantPasajerosAgregados
 * @return
 */
int controller_corregirId(LinkedList* pArrayListPassenger, int cantPasajerosAgregados, int contadorPasajeroBorrados)
{
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		int len;
		int idModificar;
		int i;
		Passenger* pasajeroAux;

		len = ll_len(pArrayListPassenger);
		if(len > cantPasajerosAgregados)
		{
			for(i = cantPasajerosAgregados; i < len; i++)
			{
				pasajeroAux = ll_get(pArrayListPassenger,i);

				if(pasajeroAux != NULL)
				{
					idModificar = i + cantPasajerosAgregados + contadorPasajeroBorrados;

					if(Passenger_setId(pasajeroAux, idModificar))
					{
						if(ll_set(pArrayListPassenger, i, pasajeroAux) == 0)
						{
							retorno = 1;
						}
					}
				}
			}
		}
	}

	return retorno;
}

/**
 * con un for pide pasajaeros y compara si el id es igual al pasado por parametros y retorna la pocision encontrada
 * @param pArrayListPassenger
 * @param id
 * @return
 */
int controller_findPassengerById(LinkedList* pArrayListPassenger, int id)
{
	int retorno = -1;
	int len;
	Passenger* Pasajero;

	if(pArrayListPassenger != NULL && id > 0)
	{
		len = ll_len(pArrayListPassenger);

		for(int i = 0; i < len; i++)
		{
			Pasajero = ll_get(pArrayListPassenger, i);

			if(Pasajero->id == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger,int cantidadPasajerosBorrados)
{
	int retorno = -1;
	int len;
	int idModificar;
	int pocisionModificar;
	int campoModificar;
	int confirmar;
	int continuar;
	int conservarCambios;
	Passenger* pasajeroModificar;

	/////variablesAux
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	char codVueloAux[8];
	int tipoPasajeroAux;
	int estadoVueloAux;
	char estadoVueloAuxChar[20];


	len = ll_len(pArrayListPassenger);

	if(len > 0)
	{
		if(pArrayListPassenger !=  NULL)
		{
			pedirNumeros(&idModificar,"Ingrese el id del pasajero que desea Modificar: ",
					"Error, ingrese solo numeros\n", "Error, numero invalido\n", (len + cantidadPasajerosBorrados), 1);

			pocisionModificar = controller_findPassengerById(pArrayListPassenger, idModificar);

			if(pocisionModificar > -1)
			{
				pasajeroModificar = ll_get(pArrayListPassenger, pocisionModificar);
			}

			if(pasajeroModificar != NULL)
			{
				printf("Perfil del pasajero:\n\n");
				printf("ID          NOMBRE           APELLIDO 	     PRECIO 	     CODIGO	     TIPO PASAJERO          ESTADO \n");
				Passenger_print(pasajeroModificar);

				modificarPasajero(&confirmar);
				retorno = 1;

				if(confirmar == 1)
				{
					do{
						opcionModificar(&campoModificar);

						switch(campoModificar)
						{
							case 1:
								printf("\nModificar Nombre\n");
								pedirString(nombreAux, "Ingrese su nombre: ", "Error, ingrese su nombre correctamente\n");
								if(Passenger_setNombre(pasajeroModificar, nombreAux))
								{
									printf("Se Modifico correctamente \n");
								}
								else
								{
									printf("Error, modificar nombre\n");
								}
								break;
							case 2:
								printf("\nModificar Apellido\n");
								pedirString(apellidoAux, "Ingrese su Apellido: ", "Error, ingrese su nombre Apellido\n");
								if(Passenger_setApellido(pasajeroModificar, apellidoAux))
								{
									printf("Se Modifico correctamente \n");
								}
								else
								{
									printf("Error, modificar Apellido\n");
								}
								break;
							case 3:
								printf("\nModificar Precio\n");
								pedirNumerosFloat(&precioAux, "Ingrese el precio del voleto: ", "Error, precio no valido\n", "Error elija un numero mayor a 0\n",10000000,1);
								if(Passenger_setPrecio(pasajeroModificar, precioAux))
								{
									printf("Se Modifico correctamente \n");
								}
								else
								{
									printf("Error, modificar Precio\n");
								}
								break;
							case 4:
								printf("\nModificar Codigo de vuelo\n");
								printf("Ingrese el codigo de Vuelo: ");
								fflush(stdin);
								gets(codVueloAux);
								if(Passenger_setCodigoVuelo(pasajeroModificar, codVueloAux))
								{
									printf("Se Modifico correctamente \n");
								}
								else
								{
									printf("Error, modificar Codigo\n");
								}
								break;
							case 5:
								printf("\nModificar Tipo de pasajero\n");
								pedirNumeros(&tipoPasajeroAux, "Tipo de pasajero:\n"
												"1)First Class\n"
												"2)Executive Class\n"
												"3)Economy Class\n"
												"Elija la opcion correspondiente: ", "Error, elija una opcion valida\n", "Error, elija una opcion entre 1 y 3\n",3,1);
								if(Passenger_setTipoPasajero(pasajeroModificar, tipoPasajeroAux))
								{
									printf("Se Modifico correctamente \n");
								}
								else
								{
									printf("Error, modificar tipoPasajero\n");
								}
								break;
							case 6:
								printf("\nModificar Estado de vuelo\n");
								pedirNumeros(&estadoVueloAux, "Estado del vuelo:\n"
										"1)Aterrizado\n"
										"2)En horario\n"
										"3)En vuelo\n"
										"4)Demorado\n"
										"Elija la opcion correspondiente: ", "Error, elija una opcion valida\n", "Error, elija una opcion entre 1 y 4\n",4,1);

								switch(estadoVueloAux)
								{
									case 1:
										strcpy(estadoVueloAuxChar,"Aterrizado");
										break;
									case 2:
										strcpy(estadoVueloAuxChar,"En horario");
										break;
									case 3:
										strcpy(estadoVueloAuxChar,"En vuelo");
										break;
									case 4:
										strcpy(estadoVueloAuxChar,"Demorado");
									break;

								}
								if(Passenger_setEstadoVuelo(pasajeroModificar, estadoVueloAuxChar))
								{
									printf("Se Modifico correctamente \n");
								}
								else
								{
									printf("Error, modificar Estado vuelo\n");
								}
								break;
							}

						preguntaContinuar(&continuar);

						}while(continuar != 2);

						guardarCambios(&conservarCambios);

						if(conservarCambios)
						{
							if(ll_set(pArrayListPassenger, pocisionModificar, pasajeroModificar) == 0)
							{
								printf("\nEl pasajero fue modificado con exito.\n");
							}
							else
							{
								printf("\nError. No se pudo modificar el pasajero\n");
							}
						}
						else
						{
							printf("La operacion ha sido cancelada");
						}
					}
				}
			else
			{
				printf("Ocurrio un error ejecutando la operacion\n");
			}

		}
		else
		{
			printf("\nOcurrio un error al intentar modificar\n");
		}
	}

	return retorno;
}


/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger, int* cantidadPasajerosBorrados)
{
	int retorno = -1;
	int len;
	int idBorrar;
	int pocisionBorrar;
	int confirmar;
	int remover;
	Passenger* pasajeroBorrar;

	len = ll_len(pArrayListPassenger);

	if(len > 0)
	{
		if(pArrayListPassenger != NULL)
		{
			pedirNumeros(&idBorrar,
			"Ingrese el id del pasajero que desea borrar: ", "Error, ingrese solo numeros\n", "Error, numero invalido\n", (len + *cantidadPasajerosBorrados), 1);

			pocisionBorrar = controller_findPassengerById(pArrayListPassenger, idBorrar);

			if(pocisionBorrar > -1)
			{
				pasajeroBorrar = ll_get(pArrayListPassenger, pocisionBorrar);

				if(pasajeroBorrar != NULL)
				{
					printf("Perfil del pasajero:\n\n");
					printf("ID          NOMBRE           APELLIDO 	     PRECIO 	     CODIGO	     TIPO PASAJERO          ESTADO \n");
					Passenger_print(pasajeroBorrar);

					borrarPasajero(&confirmar);
					retorno = 1;
					if(confirmar == 1)
					{
						printf("\nLos datos han sido borrados con exito\n");
						Passenger_delete(pasajeroBorrar);
						remover = ll_remove(pArrayListPassenger, pocisionBorrar);
						if(remover == 0)
						{
							*cantidadPasajerosBorrados =+ 1 ;

						}

					}
					else
					{
						printf("La operacion ha sido cancelada con exito");
					}
				}
				else
				{
					printf("Ocurrio un error ejecutando la operacion\n");
				}
			}
			else
			{
				printf("Error el id es incorrecto\n");
			}
		}
		else
		{
			printf("Ocurrio un error ejecutando la operacion\n");
		}
	}
	else
	{
		retorno = 1;
		printf("\nNecesita tener pasajeros cargados\n");
	}

	return retorno;
}



/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int len;
	int retorno = -1;
	Passenger* pasajero;

	if(pArrayListPassenger != NULL)
	{

		if(ll_isEmpty(pArrayListPassenger) == 0)
		{
			len = ll_len(pArrayListPassenger);
			printf("\n==============================================================================================================\n");
			printf("ID          NOMBRE           APELLIDO 	     PRECIO 	     CODIGO	     TIPO PASAJERO          ESTADO \n");
			printf("==============================================================================================================\n");
			for(int i =0; i<len; i++ )
			{
				pasajero = ll_get(pArrayListPassenger, i);
				Passenger_print(pasajero);
			}
			printf("==============================================================================================================\n");
			printf("Fin de la lista.\n");
		}
		else
		{
			printf("Necesita cargar datos para poder mostrarlos\n");
		}

		retorno = 1;
	}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int orden;

	if(pArrayListPassenger !=  NULL)
	{
		if(ll_isEmpty(pArrayListPassenger))
		{
			preguntarOrden(&orden);
			if(orden== 2)
			{
				orden = 0;
			}
			printf("\n Ordenando la lista...\n");
			if(ll_sort(pArrayListPassenger, Passenger_sortById, orden) == 0)
			{
				printf("La lista fue ordenada por id\n");
			}
			else
			{
				printf("Ocurio un error al ordenar la lista por id\n");
			}
		}

		retorno = 0;
	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger, int* guardarTxt, int primeraCarga)
{

    FILE* pFile;
    Passenger* pPassengerAux;
    int retorno = -1;
   	int idAux;
   	char idAuxChar[20];
   	char nombreAux[50];
   	char apellidoAux[50];
  	float precioAux;
    char precioAuxChar[20];
   	char codVueloAux[8];
   	int tipoPasajeroAux;
   	char tipoPasajeroAuxChar[20];
    char estadoVueloAuxChar[20];
    int len;

    if(primeraCarga)
    {
		if(pArrayListPassenger != NULL && path != NULL)
		{
			pFile = fopen(path, "w");

			if(pFile != NULL)
			{
				len = ll_len(pArrayListPassenger);

				fprintf(pFile, "Id,Name,LastName,Price,FlyCode,TypePassenger,StatusFlight\n");

				printf("\nGuardando la lista...\n");

				ll_sort(pArrayListPassenger,Passenger_sortById, 1);

				for(int i=0; i<len; i++)
				{

					pPassengerAux = (Passenger*) ll_get(pArrayListPassenger, i);

					if(pPassengerAux != NULL)
					{

						if(Passenger_getId(pPassengerAux, &idAux) )
						{
							if(Passenger_getNombre(pPassengerAux, nombreAux))
							{
								if(Passenger_getApellido(pPassengerAux, apellidoAux))
								{
									if(Passenger_getPrecio(pPassengerAux, &precioAux))
									{
										if(Passenger_getCodigoVuelo(pPassengerAux, codVueloAux))
										{
											if(Passenger_getTipoPasajero(pPassengerAux, &tipoPasajeroAux))
											{
												if(Passenger_getEstadoVuelo(pPassengerAux, estadoVueloAuxChar))
												{
													itoa(idAux,idAuxChar,10);
													gcvt(precioAux,7,precioAuxChar);
													itoa(tipoPasajeroAux, tipoPasajeroAuxChar, 10);

													fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n",idAuxChar,nombreAux,apellidoAux,precioAuxChar,codVueloAux,tipoPasajeroAuxChar,estadoVueloAuxChar);
													retorno = 1;
													*guardarTxt = 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}

				fclose(pFile);
			}
		}
		else
		{
			printf("Ocurrio un error al intentar guardar el achivo");
		}
    }
	else
	{
		printf("Necesita primero abrir el archivo\n");
		retorno = 0;
	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger, int* guardarBin, int primeraCarga)
{
	FILE* pFile;
	int retorno = -1;
	int escrituraBin;
	int len;
	len = ll_len(pArrayListPassenger);

	if(primeraCarga)
	{
		pFile = fopen(path, "wb");

		printf("\nGuardando la lista...\n");

		if(pFile != NULL)
		{

			ll_sort(pArrayListPassenger,Passenger_sortById, 1);

			for(int i = 0; i<len; i++)
			{
				escrituraBin = fwrite(ll_get(pArrayListPassenger, i), sizeof(Passenger), 1, pFile);

				if(escrituraBin == 1)
				{
					retorno = 1;
					*guardarBin = 1;
				}
			}

			fclose(pFile);
		}
		else
		{
			printf("Ocurrio un error al intentar guardar el achivo");
		}
	}
	else
	{
		retorno = 0;
		printf("Necesita primero abrir el archivo\n");
	}

    return retorno;
}



