#ifndef HEADER_FILE
#define HEADER_FILE


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct treenode { 
    
    char string[30]; // pode ser tanto pergunta quanto resposta
    struct treenode *left;
    struct treenode *right;
    struct treenode *root; // para facilitar voltar e criar novo no de pergunta
    bool tipo; // pergunta = 0/false resp = 1/true 
    
} treenode;

// cria no
treenode *createnode(char s[], bool b){
    treenode* novo = (treenode*) malloc(sizeof(treenode));

    if (novo != NULL){
        strcpy(novo->string, s);
        novo->left = NULL;
        novo->right = NULL;
        novo->root = NULL;
        novo->tipo = b;
    }

    return novo;
}


bool insertnode(treenode *subtreeroot, char q[], char m[]){
    treenode *up = subtreeroot->root; // no de pergunta antes de folha
    treenode *perg;

    // o problema de segmentation fault descoberto em aula 
    // se dava por nao adicionar o caminho de volta para o nó da direita. 
    
    // cria novo nó de pergunta
    perg = createnode(q, false);        
    // coloca como o novo caminho
    if(up->left == subtreeroot) up->left = perg; 
    else up->right = perg;
    perg->left = subtreeroot;           // resp sim
    perg->right = createnode(m, true);  // resp nao
    perg->root = up;                    // aponta up como nova raiz da subarvore
    subtreeroot->root = perg;           // aponta perg (pergunta) como nova raiz da subarvore
    perg->right->root = perg;           // aponta up como nova raiz da subarvore

}

// jogo
bool walktree(treenode * root){
    char resp = '0';
    char strn[30];
    char strq[30];

    if(root->tipo == false){
        printf("%s ?\n\t s para sim e n para nao\n>", root->string);
        scanf("%c", &resp);getchar();

        if (resp == 's'){
            walktree(root->left);
        } else if(resp == 'n') {
            walktree(root->right);
        }

    } else {
        printf("voce estava pensando em %s ?\n\t s para sim e n para nao\n>", root->string);
        scanf("%c", &resp);getchar();

        if(resp == 's'){
            printf("acertei\n\n\n");
            return(true);
        } else if(resp == 'n') {
            printf("no que voce estava pensando?\n>");
            scanf("%[A-Z a-z]s", &strn);getchar();
            fflush (stdin);

            printf("e qual a diferenca entre %s e %s?\n>", root->string, strn);
            scanf("%[A-Z a-z]s", &strq);getchar();
            fflush (stdin);

            insertnode(root, strq, strn);
            printf("\n\n");

        }
    }

}




// funções p achar o problema 
void tab(int n){
    int i;
    for(i = 0; i < n; i++) printf("    ");
}

void printa(treenode * root, int lvl){
    if (root == NULL) {tab(lvl); printf("fim\n"); return;}

    tab(lvl);
    printf("anterior: %s || ", root->root->string);
    printf("item: %s \n", root->string);


    tab(lvl);
    printf("left: \n");

    printa(root->left, lvl++);
    tab(lvl);
    
    printf("right: \n");
    printa(root->right, lvl++);
    tab(lvl);
    printf("acabou\n");


}


#endif
