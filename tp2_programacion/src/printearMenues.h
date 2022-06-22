/*
 * printearMenues.h
 *
 *  Created on: 13 may. 2022
 *      Author: Luciano
 */

#ifndef PRINTEARMENUES_H_
#define PRINTEARMENUES_H_



#endif /* PRINTEARMENUES_H_ */

/***
 * @brief muestra el menu de opciones y retorna por referencia la opcion elegida
 *
 * @param opcion (int)
 */
void mostrarMenuPrincipal(int *opcion);

/**
 * @brief muestra el menu de salida y retorna por referencia la confirmacion o cancelacion
 *
 * @param salir (int)
 */
void mostrarMenuSalida(int *salir);

/**
 * @brief Pregunta en que orden se quiere ver la lista
 *
 * @return retorna la opcion, 1 menor a mayor y 2 mayor a menor
 */
int preguntaOrdenListado(void);


/**
 * @brief pregunta si desea contunuar modificando datos
 *
 * @param modificar
 */
void deseaContinuar(int* modificar );

/**
 * @brief muestra el menu de modificacion del usuario y pide la opcion
 *
 * @param opcion
 */
void mostrarMenuModificar(int* opcion);

/**
 * @brief Pregunta si el usuario desea guardar cambios
 *
 * @param opcion
 */
void guardarCambios(int* opcion);

