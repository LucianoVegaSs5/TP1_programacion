/*
 * UTN.validaciones.c
 *
 *  Created on: 13 may. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "arrayPassenger.h"


void getNumeroValidarMaxMin(int* numero, char mensaje[],char mensajeError[], int max, int min)
{
    int flag = 1;

    do{
        if(flag== 1)
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", numero);
            flag = 0;
        }
        else
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", numero);
        }


    }while(*numero < min || *numero > max );
}

void getString(char cadena[], char mensaje[])
{

    if(cadena != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(cadena);
    }
}

void getNumeroValidarMaxMinFloat(float *numero, char mensaje[],char mensajeError[], int max, int min)
{

    int flag = 1;

    do
    {
        if (flag== 1)
        {
            printf("%s\n", mensaje);
            fflush(stdin);
            scanf("%f", numero);
            flag = 0;
        }
        else
        {
            printf("%s\n", mensajeError);
            fflush(stdin);
            scanf("%f", numero);
        }


    }while(*numero < min || *numero > max );

}
