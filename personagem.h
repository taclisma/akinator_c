#ifndef HEADER_FILE2
#define HEADER_FILE2


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct monstro{
    char nome[20];
    int prop[6];
} monstro;

monstro *createchar(char nome[20], int arr[]){
    int i;
    monstro *novo = malloc(sizeof(monstro));

    // inicia array com -1
    for(i=0; i < 6; i++) {
        novo->prop[i] = -1;
    }


    if(novo != NULL){
        strcpy(novo->nome, nome);
        for(i=0; i < 6; i++) {
            novo->prop[i] = arr[i];
        }
    }
    return novo;
}

#endif