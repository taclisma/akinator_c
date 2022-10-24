#ifndef HEADER_FILE
#define HEADER_FILE


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct treenode {

    int persindex; 
    struct treenode *left;
    struct treenode *right;
    
} treenode;

treenode *createnode(int r, char c){
    treenode* novo = malloc(sizeof(treenode));

    if (novo != NULL){
        novo->left = NULL;
        novo->right = NULL;
    }

    return novo;
}


void walktree(treenode * root){
    if (root == NULL){
        printf("fim\n");
        return;
    }

    //printf("%i\n", root->rad);
    printf("left:");
    walktree(root->left);
    printf("right:");
    walktree(root->right);
}


bool insertnode(treenode **rootptr, int r, char c){
    treenode *root = *rootptr;

    //caso base 1: arvore vazia
    if (root == NULL){
        (*rootptr) = createnode(r, c);
        return true;
    } 

    //caso base 2: nó ja existe
    // if (r == root->rad && c == root->color){
    //     return false;
    // }

    // perguntas possiveis
}

#endif