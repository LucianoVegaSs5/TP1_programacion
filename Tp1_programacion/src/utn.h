/*
 * utn.h
 *
 *  Created on: 8 abr. 2022
 *      Author: Luciano Vega
 */

#ifndef UTN_H_
#define UTN_H_


/**
 * @fn ejecutarMenuPrincipalUno
 * @brief Ejecuta el menu principal y llama a la funcion de ingreso de datos
 *
 * @return los kilometros ingresados
 */
int ejecutarMenuPrincipalUno();

/// @fn ejecutarMenuDos
/// @brief ejecuta el menu principal y pide los precios de la segunda opcion
///
/// @param flagAereolinea
/// @return
float ejecutarMenuDos(int flagAereolinea);

/**
 * @fn ejecutarMenuTres
 * @brief ejecuta el menu principal y llama a todas las funciones
 *  de calculo para calcular los costos
 *
 * @return 0
 */
int ejecutarMenuTres();

/// @fn ejecutarMenuCuatro
/// @brief ejecuta el menu principal y
/// pide los datos calculados para llamar a la funcion "mostrarCostos()"
///
/// @param kilometrosIngresados
/// @param precioVueloAereolineas
/// @param precioVueloLatam
/// @param debitoAereolineas
/// @param creditoAereolineas
/// @param bitcoinAereolineas
/// @param unitarioAereolineas
/// @param debitoLatam
/// @param creditoLatam
/// @param bitcoinLatam
/// @param unitarioLatam
/// @param diferenciaPrecio
/// @return
int ejecutarMenuCuatro(int kilometrosIngresados, float precioVueloAereolineas,
float precioVueloLatam, float debitoAereolineas, float creditoAereolineas,
float bitcoinAereolineas, float unitarioAereolineas, float debitoLatam,
float creditoLatam, float bitcoinLatam, float unitarioLatam, float diferenciaPrecio);

/// @fn mostrarCostos
/// @brief pide los datos a mostrar en orden
///
/// @param kilometrosIngresados
/// @param precioVueloAereolineas
/// @param precioVueloLatam
/// @param debitoAereolineas
/// @param creditoAereolineas
/// @param bitcoinAereolineas
/// @param unitarioAereolineas
/// @param debitoLatam
/// @param creditoLatam
/// @param bitcoinLatam
/// @param unitarioLatam
/// @param diferenciaPrecio
/// @return
int mostrarCostos(int kilometrosIngresados, float precioVueloAereolineas,
float precioVueloLatam, float debitoAereolineas, float creditoAereolineas,
float bitcoinAereolineas, float unitarioAereolineas, float debitoLatam,
float creditoLatam, float bitcoinLatam, float unitarioLatam, float diferenciaPrecio);

/// @fn ejecutarMenuCinco
/// @brief pide los datos calculados por si se pide de nuevo la opcion 4 y
/// calcula los datos para la carga forzada y habilita el salir de la opcion 6.
///
/// @param kilometrosIngresados
/// @param precioVueloAereolineas
/// @param precioVueloLatam
/// @param debitoAereolineas
/// @param creditoAereolineas
/// @param bitcoinAereolineas
/// @param unitarioAereolineas
/// @param debitoLatam
/// @param creditoLatam
/// @param bitcoinLatam
/// @param unitarioLatam
/// @param diferenciaPrecio
/// @return
int ejecutarMenuCinco(int kilometrosIngresados, float precioVueloAereolineas,
float precioVueloLatam, float debitoAereolineas, float creditoAereolineas,
float bitcoinAereolineas, float unitarioAereolineas, float debitoLatam,
float creditoLatam, float bitcoinLatam, float unitarioLatam, float diferenciaPrecio);

#endif /* UTN_H_ */
