#include <stdio.h>

struct No
{
    char valor;
    struct No *esquerda,*direita
};No;

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
        return buscar(raiz->esq, valor);
    else
        return buscar(raiz->dir, valor);
}

void infixa(No* raiz) {
    if (raiz == NULL) return;
    infixa(raiz->esq);
    printf("%c ", raiz->valor);
    infixa(raiz->dir);
}

void prefixa(No* raiz) {
    if (raiz == NULL) return;
    printf("%c ", raiz->valor);
    prefixa(raiz->esq);
    prefixa(raiz->dir);
}

void posfixa(No* raiz) {
    if (raiz == NULL) return;
    posfixa(raiz->esq);
    posfixa(raiz->dir);
    printf("%c ", raiz->valor);
}


int main() {
    No* raiz = NULL;
    char linha[100];

    while (fgets(linha, sizeof(linha), stdin)) {
        if (linha[0] == 'I') {
            char valor;
            sscanf(linha, "I %c", &valor);
            raiz = inserir(raiz, valor);
        }
        else if (linha[0] == 'P') {
            char valor;
            sscanf(linha, "P %c", &valor);
            if (buscar(raiz, valor))
                printf("%c existe\n", valor);
            else
                printf("%c nao existe\n", valor);
        }
        else if (strncmp(linha, "INFIXA", 6) == 0) {
            infixa(raiz); printf("\n");
        }
        else if (strncmp(linha, "PREFIXA", 7) == 0) {
            prefixa(raiz); printf("\n");
        }
        else if (strncmp(linha, "POSFIXA", 7) == 0) {
            posfixa(raiz); printf("\n");
        }
    }
    return 0;
}