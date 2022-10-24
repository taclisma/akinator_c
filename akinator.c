#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "personagem.h"


int main(){
    int i = 0;
    // dados
    monstro *p[10] = {NULL};
    p[0] = createchar("zumbi", 1, 1);
    p[1] = createchar("esqueleto", 1, 0);
    p[2] = createchar("lobisomem", 0, 1);
    //p[3] = createchar("vampiro", 1, 1);

    while (p[i] != NULL){
        printf("%s\n", p[i]->nome);
        i++;
    }
    

    

return 0;
}