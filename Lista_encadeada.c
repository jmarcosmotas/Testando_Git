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
    novo->next=NULL;
    if(*lista == NULL){
        *lista = novo;
        return;
    }
    NO *atual = *lista;
    while(atual->next){
        atual=atual->next;
    }
    atual->next=novo;
}
void imprimir(NO *lista){
    NO *atual=lista;
    while(lista){
        printf("%s %d\n",atual->dados.nome,atual->dados.idade);
        atual=atual->next;
    }
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
    strcpy(dados.nome,"tatiana");
    inserir(&lista,dados);
    strcpy(dados.nome,"Maria");
    inserir(&lista,dados);
    imprimir(lista);

    return 0;
}