/*
 * MODULO: Cola General
 * FICHERO: cola.h
 * DESCRIPCION: Este modulo implementa la tipologia y funcionalidad necesarias
 *              para crear y usar una cola de cualquier tipo de elemento
 * HISTORICO:
 *              v1.0 Creado el 17/05/2021 por David Canales Parra
 */

 #ifndef HHH_COLA_DCP
 #define HHH_COLA_DCP

 //Importaciones
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>

//Aqui definir el tipo de dato 'General'
typedef int General;

typedef struct celda{
    void *elem;
    struct celda *ant;
    struct celda *sig;
} Celda;

typedef struct cola{
    Celda *principio;
    Celda *final;
    int n;
    //Generalizaciones
    int tamano_dato;
    void (*copiar)(void *, void *);
    bool (*iguales)(void *, void *);
    void (*borrar)(void *);
} Cola;

 /*
  * ACCION: nuevaCola
  * ENTRADA: Una cola y el tamano del dato que vamos a encolar y las funciones de copiado, comparacion y borrado
  * MODIFICA: Inicializa una cola vacia
  */
void nuevaCola(Cola *, int , void (*copiar)(void *, void *), bool (*iguales)(void *, void *), void (*borrar)(void *));

 /*
  * ACCION: encolar
  * ENTRADA: Una cola y el puntero a un elemento
  * MODIFICA: Encola en la cola el elemento
  */
void encolar(Cola *, void *);

/*
 * ACCION: desencolar
 * ENTRADA: Una cola
 * MODIFICA: Elimina el primer elemento de la cola
 * SALIDA: Devuelve -1 si ocurre algun error 0 en otro caso
 */
int desencolar(Cola *);

/*
 * ACCION: borrarElemento
 * ENTRADA: Una cola y uel puntero a un elemento a eliminar
 * MODIFICA: Elimina la primera ocurrencia en la cola del elemento segun la funcion sonElementosIguales
 * SALIDA: Devuelve -1 si ocurre algun error 0 si no se ha borrado nada y 1 si se consogue borrar
 */
int borrarElemento(Cola *, void *);

 /*
  * FUNCION: frente
  * ENTRADA: Una cola
  * SALIDA: Un puntero al primer elemento de la lista
  */
void* frente(Cola );

 /*
  * FUNCION: longitudCola
  * ENTRADA: Una cola
  * SALIDA: La longitud de la lista
  */
int longitudCola(Cola );

 /*
  * FUNCION: colaEsVacia
  * ENTRADA: Una cola
  * SALIDA: Verdadero si la cola esta vacia, falso en otro caso
  */
bool colaEsVacia(Cola );

 #endif
