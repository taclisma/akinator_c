#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


int main(){
    char menu = 'a';
    bool play = true;
    treenode * root = NULL;
    treenode * aux = NULL;

    //inicialização manual da arvore
    root = createnode("sabe latir", false);
    aux = createnode("cachorro", true);
    aux->root = root;
    root->left = aux;
    aux = createnode("gato", true);
    root->right = aux;
    aux->root = root;

    while (true){
        printf("pense em um animal \n\tenter para comecar, x para sair\n>");
        scanf("%c", &menu);
        if (menu == 'x'){
            break;
        } else{
            walktree(root);
        }

    }

        // função que imprime arvore
        // printa(root, 1);

    return 0;
}


// referencias:
//      https://www.youtube.com/watch?v=UbhlOk7vjVY
//      https://www.youtube.com/watch?v=hfwwaNNJ-0A
//      https://github.com/ajlekcahdp4/Akinator     

// link do repositorio github: 
//      https://github.com/taclisma/akinator_c
