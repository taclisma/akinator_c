#ifndef HEADER_FILE
#define HEADER_FILE


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treenode { // pergunta = 0/false resp = 1/true
    
    char string[30]; 
    struct treenode *left;
    struct treenode *right;
    struct treenode *root; // p voltar e criar novo nó
    bool tipo;
    
    
} treenode;

//cria no
treenode *createnode(char s[], bool b){
    treenode* novo = malloc(sizeof(treenode));

    if (novo != NULL){
        strcpy(novo->string, s);
        novo->left = NULL;
        novo->right = NULL;
        novo->root = NULL;
        novo->tipo = b;
    }

    return novo;
}


bool insertnode(treenode *rootptr, char q[], char m[]){
    treenode *up = rootptr->root; // nó de pergunta antes de folha
    treenode *aux;


    if(up->left == rootptr){ // se o nó da esquerda é o nó da folha que deu a resp errada
        aux = createnode(q, false);
        up->left = aux;
        aux->left = rootptr;
        aux->right = createnode(m, true);
        aux->root = up;
        rootptr->root = aux;
    } else {
        aux = createnode(q, false);
        up->right = aux;
        aux->left = rootptr;
        aux->right = createnode(m, true);
        aux->root = up;
        rootptr->root = aux;
    }
    

}


bool walktree(treenode * root){
    char resp = '0';
    char strn[30];
    char strq[30];

    if(root->tipo == false){
        printf("%s ?\n\t s para sim e n para nao\n>", root->string);
        scanf("%c", &resp);gets();

        if (resp == 's'){
            walktree(root->left);
        } else if(resp == 'n') {
            walktree(root->right);
        }

    } else {
        printf("voce estava pensando em %s ?\n\t s para sim e n para nao\n>", root->string);
        scanf("%c", &resp);gets();

        if(resp == 's'){
            printf("acertei\n");
            return(true);
        } else if(resp == 'n') {
            printf("errei, em que mostro voce estava pensando?\n>");
            scanf(" %[^\n]s", &strn);gets();
            printf("e qual a diferença entre %s e %s?\n>", root->string, strn);
            scanf(" %[^\n]s", &strq);gets();
            insertnode(root, strq, strn); 

        }
    }

}


#endif