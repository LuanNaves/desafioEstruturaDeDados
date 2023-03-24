#include "estrutura.h"
#include <stdlib.h>
#include <stdio.h>

struct estrutura {
    Requisicao** vetor;
    Requisicao** aux;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
};

Estrutura* create() {
    Estrutura* estrutura = (Estrutura*) malloc(sizeof(Estrutura));
    if (estrutura != NULL) {
        estrutura->inicio = 0;
        estrutura->fim = 0;
        estrutura->tamanho = 0;
        estrutura->capacidade = 50;
        estrutura->vetor = (Requisicao**) malloc(estrutura->capacidade * sizeof(Requisicao*));
        if (estrutura->vetor == NULL) {
            printf("Erro: falha na alocação de memória.\n");
            exit(1);
        }
    }
    return estrutura;
}

void inserir(Estrutura* estrutura, Requisicao* requisicao) {
    if (estrutura->tamanho == estrutura->capacidade) {
        estrutura->capacidade *= 2;
        Requisicao** aux = (Requisicao**) realloc(estrutura->vetor, estrutura->capacidade * sizeof(Requisicao*));
        if (aux != NULL) {
            estrutura->vetor = aux;
        }
        else {
            printf("Erro: falha na alocação de memória.\n");
            exit(1);
        }
    }
    estrutura->vetor[estrutura->fim] = requisicao;
    estrutura->fim = (estrutura->fim + 1) % estrutura->capacidade;
    estrutura->tamanho++;
}

Requisicao* remover(Estrutura* estrutura) {
    if (estrutura->tamanho == 0) {
        printf("Estrutura vazia.\n");
        return NULL;
    }
    Requisicao* requisicao = estrutura->vetor[estrutura->inicio];
    estrutura->inicio = (estrutura->inicio + 1) % estrutura->capacidade;
    estrutura->tamanho--;
    return requisicao;
}

int get_size(Estrutura* estrutura) {
    return estrutura->tamanho;
}

void destroy(Estrutura* estrutura) {
    for (int i = 0; i < estrutura->tamanho; i++) {
        libera(estrutura->vetor[i]);
    }
    free(estrutura->vetor);
    free(estrutura);
}

