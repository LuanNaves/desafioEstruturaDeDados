#include "requisicao.h"
#include <stdlib.h>
#include <string.h>

struct requisicao {
    char nome[40];
    int inscricao;
    char procedimento[10];
};

Requisicao *cria_requisicao(char nome[], int inscricao, char procedimento[]) {
    Requisicao *requisicao = (Requisicao *) malloc(sizeof(Requisicao));
    if (requisicao != NULL) {
        strcpy(requisicao->nome, nome);
        requisicao->inscricao = inscricao;
        strcpy(requisicao->procedimento, procedimento);    
    }
    return requisicao;
}

char *get_nome(Requisicao *requisicao) {
    return requisicao->nome;
}

int get_inscricao(Requisicao *requisicao) {
    return requisicao->inscricao;
}

char *get_procedimento(Requisicao *requisicao) {
    return requisicao->procedimento;
}

void libera(Requisicao *requisicao) {
    free(requisicao);
}
