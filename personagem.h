#ifndef HEADER_FILE2
#define HEADER_FILE2


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct monstro{
    char nome[20];
    int mortovivo;
    int pele;
} monstro;

monstro *createchar(char nome[20], int m, int p){
    monstro *novo = malloc(sizeof(monstro));

    if(novo != NULL){
        strcpy(novo->nome, nome);
        novo->mortovivo =m;
        novo->pele =p;
    }
    return novo;
}

#endif