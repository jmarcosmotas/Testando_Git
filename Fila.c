#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *next;
}No;
typedef struct{
    No *inicio;
    No *fim;
}Fila;

void inserir(Fila *f,int x){
    No *novo=(No*)malloc(sizeof(No));
    novo->valor=x;
    novo->next=NULL;
    if(f->inicio == NULL){
        f->inicio=novo;
    }else{
        f->fim->next=novo;
    }
    f->fim=novo;
}

void imprimir(Fila *fila){
    No *atual=fila->inicio;
    while (atual != NULL){
        printf("%d\n",atual->valor);
        atual=atual->next;
    }
    
}
int main(){
    Fila f1;
    f1.inicio = f1.fim =NULL;
    
    inserir(&f1,1);
    inserir(&f1,2);
    inserir(&f1,3);
    inserir(&f1,4);
    inserir(&f1,5);
    inserir(&f1,6);
    imprimir(&f1);

    return 0;
}