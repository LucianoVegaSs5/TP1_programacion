/*
 * calculos.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Luciano
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_


/***
 * @fn calcularDebito
 * @brief calcula el precio final de un pago con debito
 *
 * @param precioVuelo
 * @param descuento
 * @return El descuento al pagar con debito
 */
float calcularDebito(float precioVuelo, int descuento);
/**
 * @fn calcularCredito
 * @brief calcula el precio final de un pago con credito
 *
 * @param precioVuelo
 * @param interes
 * @return
 */
float calcularCredito(float precioVuelo, int interes);
/**
 * @fn calcularBitcoin
 * @brief calcula el precio final de un pago hecho con bitcoins
 *
 * @param precioVuelo
 * @param valorBit
 * @return e valor del pago en bitcoins
 */
float calcularBitcoin(float precioVuelo, float valorBit);
/**
 *@fn calcularUnitario
 * @brief calcula el precio por kilometro ingresado
 *
 * @param precioVuelo
 * @param kilometrosIngresados
 * @return el valor del kilometro en pesos
 */
float calcularUnitario(float precioVuelo, int kilometrosIngresados);
/**
 * @fn calculardiferencia
 * @brief calcula la diferencia de precio entre ambos vuelos
 *
 * @param precioVueloLatam
 * @param precioVueloAereolineas
 * @return la diferencia del precio
 */
float calcularDiferencia(float precioVueloLatam, float precioVueloAereolineas);



#endif /* CALCULOS_H_ */
