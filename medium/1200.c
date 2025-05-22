#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *esquerda, *direita;
} No;

No* inserir(No* raiz, char valor) {
    if (raiz == NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->esquerda = novo->direita = NULL;
        return novo;
    }
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

int buscar(No* raiz, char valor) {
    if (raiz == NULL) return 0;
    if (raiz->valor == valor) return 1;
    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    else
        return buscar(raiz->direita, valor);
}

void infixa(No* raiz) {
    if (raiz == NULL) return;
    infixa(raiz->esquerda);
    printf("%c ", raiz->valor);
    infixa(raiz->direita);
}

void prefixa(No* raiz) {
    if (raiz == NULL) return;
    printf("%c ", raiz->valor);
    prefixa(raiz->esquerda);
    prefixa(raiz->direita);
}

void posfixa(No* raiz) {
    if (raiz == NULL) return;
    posfixa(raiz->esquerda);
    posfixa(raiz->direita);
    printf("%c ", raiz->valor);
}

int main() {
    No* raiz = NULL;
    char linha[100];

    while (fgets(linha, sizeof(linha), stdin)) {
        // Remover o \n do final da linha, se houver
        linha[strcspn(linha, "\n")] = '\0';

        if (strcmp(linha, "INFIXA") == 0) {
            infixa(raiz); 
            printf("\n");
        }
        else if (strcmp(linha, "PREFIXA") == 0) {
            prefixa(raiz); 
            printf("\n");
        }
        else if (strcmp(linha, "POSFIXA") == 0) {
            posfixa(raiz); 
            printf("\n");
        }
        else if (linha[0] == 'I' && linha[1] == ' ') {
            char valor;
            sscanf(linha, "I %c", &valor);
            raiz = inserir(raiz, valor);
        }
        else if (linha[0] == 'P' && linha[1] == ' ') {
            char valor;
            sscanf(linha, "P %c", &valor);
            if (buscar(raiz, valor))
                printf("%c existe\n", valor);
            else
                printf("%c nao existe\n", valor);
        }
    }

    return 0;
}
