/*
 * arrayPassenger.h
 *
 *  Created on: 13 may. 2022
 *      Author: Luciano
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct
{
  int id;
  char name[51];
  char lastName[51];
  float price;
  char flycode[10];
  int typePassenger;
  int isEmpty;
  int statusFlight;
}typedef ePassenger;


#endif /* ARRAYPASSENGER_H_ */

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(ePassenger * list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(ePassenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[], int statusFlight);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(ePassenger* list, int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(ePassenger* list, int len, int id);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(ePassenger* list, int len, int order);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(ePassenger* list, int length);

/**
* \brief Sort the elements in the array of passengers, the argument order
* indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN* \return int Return (-1)
* if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengersByCode(ePassenger* list, int len, int order);

/**
 * @brief reccorre el array y cuando encuentra el primer lugar vacio (isEmpty == 0)
 * lo retorna
 *
 * @param list ePassenger
 * @param len int
 * @return  la pocision vacia en el array sino hay lugar (-1) o mayor a (-1)
 */
int buscarLugarVacio(ePassenger list[], int len);

/**
 * @brief muestra todos los campos del pasajero
 *
 * @param passenger
 * @param length
 * @return (0) si esta todo bien sino (-1)
 */
int mostrarPasajero(ePassenger passenger, int length);

/**
 * @brief Funcion que pide los datos al usuario para cargarlos y llama a la funcion addPassenger para adherirlos
 *
 * @param lista (ePassenger)
 * @param tam (int)
 * @param contadorId (int)
 * @return retorna 0 si esta todo bien y -1 sino
 */
int altaPasajero(ePassenger lista[], int tam, int* contadorId,int* primerIngreso);

/**
 * @brief Busca un lugar vacio, una pocision en el array con el isEmpty = 1 para poder adherir al pasajero
 *
 * @param list ePassenger
 * @param len int
 * @return la pocision vacia si algo salio mal -1
 */
int buscarLugarVacio(ePassenger list[], int len);

/**
 * @brief llama a la funcion addPassenger con los datos hardcodeados para adherirlos al sistema
 *
 * @param list (ePassenger)
 * @param len (int )
 * @return	retorna 0 si se cargaron los datos con exito sino -1 si hubo algun error.
 */
int realizarCargaForzada(ePassenger list[], int len);

/**
 * @brief llama a la funcion realizarCargaForzada para validarla y verificar que se hayya hecho una sola vez
 *
 * @param list (ePassenger)
 * @param len  (int)
 */
void cargaForzada(ePassenger list[], int len, int* flagCarga);

/**
 * @brief calcula el total de todos los precios de los pasajeros, validadolos con el isEmpty = 0
 *
 * @param list (ePassenger)
 * @param len (int)
 * @return el total de los precios (float)
 */
float calcularPrecio(ePassenger list[], int len);

/**
 * @brief calcula el promedio de los precios recorriendo la lista
 *
 * @param list (ePassenger)
 * @param len (int)
 * @param precioAcumulado (float)
 * @return el promedio de los precios totales (float)
 */
float calcularPrecioPromedio(ePassenger list[], int len, int precioAcumulado);

/**
 * @brief calcula cuantos pasajeros pagaron mas que el promedio de precios totales
 *
 * @param list (ePassenger)
 * @param len (int)
 * @param precioPromedio (float)
 * @return la cantidad de pasajeros (int)
 */
int calcularPasajerosMayorPrecio(ePassenger list[], int len, float precioPromedio);

/**
 * @brief muestra el menu de la cuarta opcion y llama a las funciones segun la opcion del submenu
 *
 * @param list (ePassenger)
 * @param len (int)
 */
void informarPasajeros(ePassenger list[], int len, int flagDeCarga, int flagDeIngreso);

/**
 * @brief Pide el id del usuario que se necesita borrar y pregunta la confirmacion, si la respuesta es si
 * el isEmpty del pasajero pasa a ser 1 y estar desocupado
 *
 * @param list (ePassenger)
 * @param len (int)
 */
void bajaPasajero(ePassenger list[], int len, int flagDeCarga, int flagDeIngreso);

/**
 * @brief Pregunta por el id del pasajero a modificar y pide los datos para modificarlos, pregunta por la confirmacion y loegos los
 * ingresa
 *
 * @param list (ePassenger)
 * @param len (int)
 */
void modificarPasajero(ePassenger list[], int len, int flagDeCarga, int flagDeIngreso);
