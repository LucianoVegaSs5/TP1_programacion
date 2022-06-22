/*
 ============================================================================
Luciano Rafael Vega Luna
Division 1D
Traba Practico 1
Laboratorio 1, Programacion 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"
#include "ingresodatos.h"
#include "funciones_tp.h"


#define LMCARGAFORZADA 159339 //Precio de la carga forzada de latam
#define AECARGAFORZADA 162965 //Precio de la carga forzada de aereolineas
#define KMCARGAFORZADA 7090 //km de la carga forzada

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;
	int kilometros;
	float precioLatam;
	float precioAereolineas;
	int primerIngresoKm = 0;
	int primerIngresoPrecios = 0;
	int calcular = 0;

	float diferencia;

	float creditoPrecioLm;
	float debitoPrecioLm;
	float bitcoinPrecioLm;
	float unitarioPrecioLm;

	float creditoPrecioAe;
	float debitoPrecioAe;
	float bitcoinPrecioAe;
	float unitarioPrecioAe;

	do{

		mostrarMenuPrincipal(&opcion);

		switch(opcion)
		{
			case 1:
				if(ingresarKilometros(&kilometros,&primerIngresoKm)!= 1)
				{
					printf("Ocurrio un error al cargar los kilometros\n");
				}
				break;
			case 2:
				if(primerIngresoKm)
				{
					if(ingresarPrecios(&precioLatam, &precioAereolineas, &primerIngresoPrecios) != 1)
					{
						printf("Ocurrio un error al cargar los precios\n");
					}
				}
				else
				{
					printf("\nNecesita cargar kilometros \n");
				}
				break;
			case 3:
				if(primerIngresoKm && primerIngresoPrecios)
				{
					diferencia = calcularCostos(&calcular, &creditoPrecioLm,&debitoPrecioLm,&bitcoinPrecioLm,&unitarioPrecioLm,
							&creditoPrecioAe,&debitoPrecioAe,&bitcoinPrecioAe,&unitarioPrecioAe, kilometros,precioLatam,precioAereolineas);
					if(diferencia < 0)
					{
						printf("Ocurrio un error al calcular costos");
					}
				}
				else
				{
					printf("\nNecesita cargar kilometros y precios \n");
				}
				break;
			case 4:
				if(primerIngresoKm && primerIngresoPrecios && calcular)
				{
					printearCostos(creditoPrecioLm,debitoPrecioLm,bitcoinPrecioLm,unitarioPrecioLm,
							creditoPrecioAe,debitoPrecioAe,bitcoinPrecioAe,unitarioPrecioAe, kilometros,precioLatam,precioAereolineas,diferencia);
				}
				else
				{
					printf("\nNecesita cargar kilometros, precios y calcular los costos\n");

				}
				break;
			case 5:
				cargaForzada(KMCARGAFORZADA,LMCARGAFORZADA, AECARGAFORZADA);
				break;
			case 6:
				printf("\nSaliendo del sistema...");
				break;
			default:
				printf("Error, elija una opcion valida\n");
				break;
		}

	}while(opcion != 6);

	return 0;
}

