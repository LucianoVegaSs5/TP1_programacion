/*
 * UTN_validaciones.h
 *
 *  Created on: 13 may. 2022
 *      Author: Luciano
 */

#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_

#endif /* UTN_VALIDACIONES_H_ */


/**
 * @brief pide y valida un numero con los maximos y minimos ingresados por parametros
 *
 * @param numero (int)
 * @param mensaje (string)
 * @param mensajeError (string)
 * @param max (int)
 * @param min (int)
 * @return (0) si esta todo bien sino (-1)
 */
int getNumeroValidarMaxMin(int *numero, char mensaje[],char mensajeError[], int max, int min);

/**
 * @brief
 *
 * @param cadena
 * @param mensaje
 */
void getString(char cadena[], char mensaje[]);

/**
 * @brief
 *
 * @param numero
 * @param mensaje
 * @param mensajeError
 * @param max
 * @param min
 */
void getNumeroValidarMaxMinFloat(float *numero, char mensaje[],char mensajeError[], int max, int min);
