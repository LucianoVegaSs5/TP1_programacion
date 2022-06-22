/*
 * funciones_tp.h
 *
 *  Created on: 13 jun. 2022
 *      Author: Luciano
 */

#ifndef FUNCIONES_TP_H_
#define FUNCIONES_TP_H_
#define INTERES 25
#define DESCUENTO 10


#endif /* FUNCIONES_TP_H_ */

/**
 * @brief Pide los precios de las aereolineas y los retorna por referencia
 * si se vuele a ingresar los reescribe
 *
 * @param latamKm
 * @param AereolineasKm
 * @return 1 if its all ok alse -1
 */
int ingresarPrecios(float* latamPrecio, float* AereolineasPrecio, int* flagIngreso);

/**
 * @brief pide los kilometros y los retorna por referencia si se vuele a ingresar los reescribe
 *
 * @param kilometros
 * @param primerIngreso
 * @return
 */
int ingresarKilometros(int* kilometros, int* primerIngreso);

/**
 * @brief printea los costos recibidos por parametros
 *
 * @param credito
 * @param debito
 * @param unitario
 * @param bitcoin
 */
void printCosto( float credito, float debito, float unitario, float bitcoin);
/**
 * @brief Cumple la opcion 4 mostrando todos los costos calculados anteriormente y valida que se haya cargado los km, precios y calculado los costos
 *
 * @param creditoPrecioLm
 * @param debitoPrecioLm
 * @param bitcoinPrecioLm
 * @param unitarioPrecioLm
 * @param creditoPrecioAe
 * @param debitoPrecioAe
 * @param bitcoinPrecioAe
 * @param unitarioPrecioAe
 * @param kilometros
 * @param precioLm
 * @param precioAe
 * @param diferencia
 */
void printearCostos(float creditoPrecioLm, float debitoPrecioLm,float bitcoinPrecioLm, float unitarioPrecioLm,
	float creditoPrecioAe,float debitoPrecioAe,float bitcoinPrecioAe,float unitarioPrecioAe, int kilometros,float precioLm,float precioAe, float diferencia);

/**
 * @brief calcula los costos y valida que se hayan cargados los datos necesarios para ejecutar la funcion
 *
 * @param calcular
 * @param creditoPrecioLm
 * @param debitoPrecioLm
 * @param bitcoinPrecioLm
 * @param unitarioPrecioLm
 * @param creditoPrecioAe
 * @param debitoPrecioAe
 * @param bitcoinPrecioAe
 * @param unitarioPrecioAe
 * @param kilometros
 * @param precioLm
 * @param precioAe
 * @return
 */
float calcularCostos(int* calcular, float* creditoPrecioLm, float* debitoPrecioLm,float* bitcoinPrecioLm, float* unitarioPrecioLm,
		float* creditoPrecioAe,float* debitoPrecioAe,float* bitcoinPrecioAe,float* unitarioPrecioAe, int kilometros,float precioLm,float precioAe);
/**
 * @brief recibe los kms y precio de la carga forzada para despues calcularlos y mostrarlos
 *
 * @param kilometros
 * @param precioLm
 * @param precioAe
 */
void cargaForzada(int kilometros, float precioLm, float precioAe);
