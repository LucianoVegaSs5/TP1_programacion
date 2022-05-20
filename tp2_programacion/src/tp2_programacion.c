/*
 ============================================================================

Trabajo practico Nro2
Luciano Rafael Vega Luna
DIVISION 1D
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "arrayPassenger.h"
#include "UTN_validaciones.h"
#include "printearMenues.h"

#define NOMBRE 51
#define LEN 10 //LARGO

int main(void)
{
	setbuf(stdout, NULL);
	ePassenger list[LEN];
	int validarInicializacion;
    int opcion;
    int salir;
    int iDs = 6;
    int flagCarga = 0;
    int primerIngreso = 0;

    validarInicializacion = initPassengers(list, LEN);

    if(validarInicializacion == 0)
   {
    	do
    	{
           	mostrarMenuPrincipal(&opcion);

           	switch(opcion)
    	   	{
    	   		case 1:
    	   			altaPasajero(list, LEN, &iDs, &primerIngreso);
    		  	    break;
    			case 2:
    				modificarPasajero(list, LEN, flagCarga, primerIngreso);
    	            break;
        		case 3:
        			bajaPasajero(list, LEN, flagCarga, primerIngreso);
   	   			    break;
  	   			case 4:
  	   				informarPasajeros(list, LEN, flagCarga, primerIngreso);
        			break;
   	    		case 5:
   	    			cargaForzada(list, LEN, &flagCarga);
   	   			    break;
   	   			case 6:
        			mostrarMenuSalida(&salir);
  	    			break;
       		}

    	}while(salir != 1);
   }
}
