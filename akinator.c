#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


void initarr(int arr[]){
    int i;
    for(i=0; i < 6; i++) {
        arr[i] = -1;
    }
}

int main(){
    treenode * root = NULL;
    treenode * aux = NULL;

    //inicialização manual da arvore
    root = createnode("é morto vivo", false);
    aux = createnode("zumbi", true);
    aux->root = root;
    root->left = aux;
    aux = createnode("lobisomen", true);
    root->right = aux;
    aux->root = root;

    while (true){
        printf("pense em um monstro \n\tcomeçar");
        gets();
        walktree(root);
    }


    return 0;
}


// referencias:
//      https://www.youtube.com/watch?v=UbhlOk7vjVY
//      https://www.youtube.com/watch?v=hfwwaNNJ-0A
//      https://github.com/ajlekcahdp4/Akinator     
