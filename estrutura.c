#include "estrutura.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

struct estrutura {
    Requisicao** vetor;
    int inicio;
    int fim;
    int tamanho;
};

Estrutura* create() {
    Estrutura* estrutura = (Estrutura*) malloc(sizeof(Estrutura));
    estrutura->inicio = 0;
    estrutura->fim = 0;
    estrutura->tamanho = 0;
    return estrutura;
}

void inserir(Estrutura* estrutura, Requisicao* requisicao) {
    if (estrutura->tamanho == MAX_SIZE) {
        printf("Estrutura cheia.\n");
        return;
    }
    estrutura->vetor[estrutura->fim] = requisicao;
    estrutura->fim = (estrutura->fim + 1) % MAX_SIZE;
    estrutura->tamanho++;
}

Requisicao* remover(Estrutura* estrutura) {
    if (estrutura->tamanho == 0) {
        printf("Estrutura vazia.\n");
        return NULL;
    }
    Requisicao* requisicao = estrutura->vetor[estrutura->inicio];
    estrutura->inicio = (estrutura->inicio + 1) % MAX_SIZE;
    estrutura->tamanho--;
    return requisicao;
}

int get_size(Estrutura* estrutura) {
    return estrutura->tamanho;
}
