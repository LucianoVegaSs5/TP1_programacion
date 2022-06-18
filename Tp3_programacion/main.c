#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "printMenues.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int primeraCargaTxt = 0;
    int primeraCorreccionTxt = 0;
    int primeraCorreccionBin = 0;
    int primeraCargaBin = 0;
    int contadorPasajeroBorrados = 0;
    int carga = 0;
    int guardarTxt = 0;
    int guardarBin = 0;
    int cantidadPasajerosAgregados = 0;
    int salir = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{

   	mostrarMenuPrincipal(&option);

        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaPasajeros, &primeraCargaTxt, primeraCargaBin) != 1)
                {
                	printf("Ocurrio un error al cargar la lista modo txt \n");
                }
                if(cantidadPasajerosAgregados > 0 && primeraCorreccionTxt == 0)
                {
                	if(controller_corregirId(listaPasajeros, cantidadPasajerosAgregados, contadorPasajeroBorrados))
                	{
                		printf("Se realizo la correccion de ids\n");
                		primeraCorreccionTxt = 1;
                	}
                	else
                	{
                		printf("\nNo se pudieron corregir los id de los pasajeros agregados anteriormente.\n");
                	}
                }

                break;
            case 2:
            	if(controller_loadFromBinary("data.bin" , listaPasajeros, &primeraCargaBin, primeraCargaTxt) != 1)
            	{
            		printf("Ocurrio un error al cargar la lista modo bin\n");
            	}
            	if(cantidadPasajerosAgregados > 0 &&  primeraCorreccionBin == 0)
            	{
            		if(controller_corregirId(listaPasajeros, cantidadPasajerosAgregados, contadorPasajeroBorrados))
            	    {
            			printf("Se realizo la correccion de ids\n");
            			primeraCorreccionBin = 1;
            	    }
            	    else
            	    {
            	       	printf("\nNo se pudieron corregir los id de los pasajeros agregados anteriormente.\n");
            	    }
            	}
            	break;
            case 3:
            	if(controller_addPassenger(listaPasajeros, contadorPasajeroBorrados, &cantidadPasajerosAgregados, &carga) != 1)
            	{
            		printf("Ocurrio un error al iniciar el alta\n");
            	}
            	break;
            case 4:
            	printf("4. Modificar datos de pasajero\n");
            	if(controller_editPassenger(listaPasajeros, contadorPasajeroBorrados)!=1)
            	{
            		printf("Necesita tener pasajeros cargados primero\n");
            	}
                break;
            case 5:
            	printf("5. Baja de pasajero\n");
            	if(controller_removePassenger(listaPasajeros, &contadorPasajeroBorrados) != 1)
				{
            		printf("Ocurrio un error inesperado\n");
				}
            	break;
            case 6:
            	printf("6. Listar pasajeros\n");
            	if(controller_ListPassenger(listaPasajeros)!= 1)
            	{
            		printf("Ocurrio un error al intentar mostrar la lista.\n");
            	}
            	break;
            case 7:
            	printf("7. Ordenar pasajeros\n");
            	if(controller_sortPassenger(listaPasajeros) == -1)
            	{
            		printf("Ocurrio un error en el ordenamiento\n");
            	}
                break;
            case 8:
            	if(controller_saveAsText("data.csv", listaPasajeros, &guardarTxt, primeraCargaTxt))
            	{
            		printf("Se ha guardado correctamente el archivo .txt\n");
            	}
            	break;
            case 9:
            	if(controller_saveAsBinary("data.bin", listaPasajeros, &guardarBin, primeraCargaBin))
				{
            		printf("Se ha guardado correctamente el archivo .bin\n");
				}
            	break;
            case 10:
            	if(guardarBin != 1 && guardarTxt !=  1)
            	{
            		printf("No pude irse sin guardar\n");
            	}
            	else
            	{
            		salir = 1;
            	}
                break;
        }

    }while(salir != 1 );

    printf("\nSaliendo del sistema....");
    ll_deleteLinkedList(listaPasajeros);
    return 0;
}

