#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
};

// Função para criar um novo nó
struct No* novoNo(int valor) {
    struct No* no = (struct No*)malloc(sizeof(struct No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

// Função para inserir um valor na árvore
struct No* inserir(struct No* raiz, int valor) {
    if (raiz == NULL) {
        return novoNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

// Percurso em ordem (esquerda -> raiz -> direita)
void mostrarInOrdem(struct No* raiz) {
    if (raiz != NULL) {
        mostrarInOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        mostrarInOrdem(raiz->direita);
    }
}

// Percurso pré-ordem (raiz -> esquerda -> direita)
void mostrarPreOrdem(struct No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        mostrarPreOrdem(raiz->esquerda);
        mostrarPreOrdem(raiz->direita);
    }
}

// Percurso pós-ordem (esquerda -> direita -> raiz)
void mostrarPosOrdem(struct No* raiz) {
    if (raiz != NULL) {
        mostrarPosOrdem(raiz->esquerda);
        mostrarPosOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// Função principal
int main() {
    struct No* raiz = NULL;

    // Inserindo valores na árvore
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);

    // Mostrando os percursos

    printf("Percurso Pre-Ordem: "); /// R,E,D
    mostrarPreOrdem(raiz);   // Deve mostrar: 10 5 3 7 15
    printf("\n");

    printf("Percurso In-Ordem: "); /// E,R,D
    mostrarInOrdem(raiz);    // Deve mostrar: 3 5 7 10 15
    printf("\n");

    

    printf("Percurso Pos-Ordem: "); ///E,D,R
    mostrarPosOrdem(raiz);   // Deve mostrar: 3 7 5 15 10
    printf("\n");

    return 0;
}