#include <stdio.h>
#include "cola.h"

void copiar(void *e1, void *e2){
    *(int*)e1 = *(int*)e2;
}

bool iguales(void *e1, void *e2){
    if(*(int*)e1 == *(int*)e2) return true;
    return false;
}

void borrar(void *e){
    //free(e);
}

int main(void){
    Cola c;
    nuevaCola(&c, sizeof(int), copiar, iguales, borrar);

    for(int i = 0; i < 5; i++){
        int a = i+1;
        encolar(&c, &a);
    }

    int a = 5;


    borrarElemento(&c, &a);

    for(int i = 0; i < 5; i++){
        int *b;
        b = frente(c);
        desencolar(&c);
        printf("Res: %d\n", *b);
    }

    return 0;
}
