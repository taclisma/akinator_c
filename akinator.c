#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "personagem.h"
#define TAM 6


void initarr(int arr[]){
    int i;
    for(i=0; i < TAM; i++) {
        arr[i] = -1;
    }
}

int main(){
    int i = 0, j = 0;
    int auxArr[TAM];
    monstro auxcpy;
    monstro *p[10] = {NULL};
    initarr(auxArr);
    auxArr[0] = 1; auxArr[1] = 1;
    p[0] = createchar("zumbi", auxArr);
    auxArr[1] = 0;
    p[1] = createchar("esqueleto", auxArr); //{1, 0}
    auxArr[0] = 0; auxArr[1] = 1;
    p[2] = createchar("lobisomem", auxArr); //{0, 1}
    //p[3] = createchar("vampiro", 1, 1);

    while (p[i] != NULL){
        printf("%s\n", p[i]->nome);
        while(j < TAM){
            printf("%i, ", p[i]->prop[j]);
            j++;
        }
        j = 0;
        i++;
        printf("\n");

    }
    

return 0;
}