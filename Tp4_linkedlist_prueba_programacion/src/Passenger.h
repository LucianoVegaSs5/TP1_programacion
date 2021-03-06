/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	char estadoVuelo[50];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* codigoVueloStr, char* tipoPasajeroStr, char* precioStr, char* estadoVueloStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo (Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo (Passenger* this,char* estadoVuelo);

int Passenger_sortById(void* pasajeroUno, void* pasajeroDos);
void Passenger_print(Passenger* this);

int Passenger_filtrarPorEstadoDemorado(void* pasajero);
int Passenger_filtrarPorEstadoAterrizado(void* pasajero);
int Passenger_filtrarPorEstadoEnHorario(void* pasajero);
int Passenger_filtrarPorEstadoEnVuelo(void* pasajero);


#endif /* PASSENGER_H_ */
