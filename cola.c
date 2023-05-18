/*
 * MODULO: Cola General
 * FICHERO: cola.c
 * DESCRIPCION: Este modulo implementa la tipologia y funcionalidad necesarias
 *              para crear y usar una cola de cualquier tipo de elemento
 * HISTORICO:
 *              v1.0 Creado el 17/05/2021 por David Canales Parra
 */

#include "cola.h"

/*
 * ACCION: nuevaCola
 * ENTRADA: Una cola y el tamano del dato que vamos a encolar y las funciones de copiado, comparacion y borrado
 * MODIFICA: Inicializa una cola vacia
 */
void nuevaCola(Cola *c, int tamano, void (*copiar)(void *, void *), bool (*iguales)(void *, void *), void (*borrar)(void *)){
    c->principio = NULL;
    c->final = NULL;
    c->n = 0;

    c->tamano_dato = tamano;
    c->copiar = copiar;
    c->iguales = iguales;
    c->borrar = borrar;
}

/*
 * ACCION: encolar
 * ENTRADA: Una cola y el puntero a un elemento
 * MODIFICA: Encola en la cola el elemento
 */
void encolar(Cola *c, void *elem){
    //Me copio el elemento a encolar
    Celda *celda = (Celda *)malloc(sizeof(Celda));
    celda->sig = NULL;
    celda->elem = malloc(c->tamano_dato);
    c->copiar(celda->elem, elem);

    //Encolo el elemento
    if(c->principio == NULL){   //Si es el primer elemento en encolarse
        c->principio = celda;
        c->final = celda;
        celda->ant = NULL;
    }
    else{                       //Si ya hay mas elementos en la cola
        c->final->sig = celda;
        celda->ant = c->final;
        c->final = celda;
    }

    //Aumento el numero de elementos en la cola
    c->n++;
}

/*
 * ACCION: desencolar
 * ENTRADA: Una cola
 * MODIFICA: Elimina el primer elemento de la cola
 * SALIDA: Devuelve -1 si ocurre algun error 0 en otro caso
 */
int desencolar(Cola *c){
    Celda *aux;

    //Aseguro que la cola no este vacia
    if(colaEsVacia(*c)){
        printf("ERROR: No se puede desencolar de una cola vacia.\n");
        return -1;
    }

    //Desencolo
    aux = c->principio;
    c->principio = aux->sig;
    if(longitudCola(*c) == 1)
        c->final = NULL;
    else
        c->principio->ant = NULL;

    //Disminuyo el numero de elementos en la cola
    c->n--;

    //Borro los recursos del elemento
    c->borrar(aux->elem);
    free(aux);

    return 0;
}

/*
 * ACCION: borrarElemento
 * ENTRADA: Una cola y uel puntero a un elemento a eliminar
 * MODIFICA: Elimina la primera ocurrencia en la cola del elemento segun la funcion sonElementosIguales
 * SALIDA: Devuelve -1 si ocurre algun error 0 si no se ha borrado nada y 1 si se consogue borrar
 */
int borrarElemento(Cola *c, void *e){
    Celda *aux;

    if(colaEsVacia(*c)){
        printf("ERROR: No se puede hacer frente de una cola vacia.\n");
        return -1;
    }

    aux = c->principio;
    while(!c->iguales(aux->elem, e) && aux->sig != NULL){
        aux = aux->sig;
    }

    //Si no se ha encontrado ningun elemento igual
    if(!c->iguales(aux->elem, e)) return 0;

    //Sino lo borro
    c->n--;

    //Hago un puente entre los elementos que lo rodean si es que tiene
    if(aux->ant != NULL)
        aux->ant->sig = aux->sig;
    else                            //Si el anterior es NULL, significa que es el primero
        c->principio = aux->sig;

    if(aux->sig != NULL)
        aux->sig->ant = aux->ant;
    else                            //Si el siguiente es NULL, significa que es el ultimo
        c->final = aux->ant;

    c->borrar(aux->elem);
    free(aux);

    return 0;
}

/*
 * FUNCION: frente
 * ENTRADA: Una cola
 * SALIDA: Un puntero al primer elemento de la lista
 */
void* frente(Cola c){
    //Aseguro que la cola no este vacia
    if(!colaEsVacia(c)) return (c.principio->elem);

    printf("ERROR: No se puede hacer frente de una cola vacia.\n");
    exit(-1);
}

/*
 * FUNCION: longitudCola
 * ENTRADA: Una cola
 * SALIDA: La longitud de la lista
 */
int longitudCola(Cola c){
    return c.n;
}

/*
 * FUNCION: colaEsVacia
 * ENTRADA: Una cola
 * SALIDA: Verdadero si la cola esta vacia, falso en otro caso
 */
bool colaEsVacia(Cola c){
    if(longitudCola(c) > 0) return false;

    return true;
}
