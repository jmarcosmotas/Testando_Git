#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int id; 
   char nome[20];
   int idade;
}DADOS;

typedef struct NO{
    DADOS dados;
    struct NO *next;
}NO;

void inserir(NO **lista,DADOS dados){
    NO *novo =(NO*)malloc(sizeof(NO));
    novo->dados = dados;
    if(*lista == NULL){
        *lista = novo;
        novo->next = *lista;
        return;
    }
    NO *atual = *lista;
    while(atual->next != *lista){
        atual=atual->next;
    }
    atual->next=novo;
    novo->next=*lista;
}
void imprimir(NO *lista){
    NO *atual=lista;
    do{
        printf("%s %d\n",atual->dados.nome,atual->dados.idade);
        atual=atual->next;
    }while(atual != lista);
}
int main(){
    NO *lista=NULL;
    DADOS dados;
    
    strcpy(dados.nome,"Joao");
    dados.idade=20;
    inserir(&lista,dados);
    strcpy(dados.nome,"Marcos");
    dados.idade=23;
    inserir(&lista,dados);
    imprimir(lista);

    return 0;
}