int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* prmeraCargaTxt, int primeraCargaBin);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int* primeraCargaBin, int prmeraCargaTxt);
int controller_addPassenger(LinkedList* pArrayListPassenger, int pasajerosBorrados, int* cantidadPasajerosAgregados, int* carga);
int controller_editPassenger(LinkedList* pArrayListPassenger,int cantidadPasajerosBorrados);
int controller_removePassenger(LinkedList* pArrayListPassenger, int* cantidadPasajerosBorrados);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger, int* guardarTxt, int primeraCarga);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger, int* guardarBin, int primerraCarga);
int controller_corregirId(LinkedList* pArrayListPassenger, int cantPasajerosAgregados, int contadorPasajeroBorrados);
int controller_findPassengerById(LinkedList* pArrayListPassenger, int id);