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
    struct No* no = (struct No*)malloc(sizeof(struct No)); // Aloca memória
    no->valor = valor;       // Define o valor
    no->esquerda = NULL;     // Ainda não tem filho esquerdo
    no->direita = NULL;      // Ainda não tem filho direito
    return no;
}

// Função para inserir um valor na árvore
struct No* inserir(struct No* raiz, int valor) {
    if (raiz == NULL) {
        return novoNo(valor);  // Se a árvore está vazia, cria novo nó
    }

    if (valor < raiz->valor) {
        // Se o valor for menor, insere à esquerda
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        // Se for maior ou igual, insere à direita
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;  // Retorna a raiz atualizada
}

// Percurso in-ordem (esquerda -> raiz -> direita)
void mostrarInOrdem(struct No* raiz) {
    if (raiz != NULL) {
        mostrarInOrdem(raiz->esquerda);   // Visita esquerda
        printf("%d ", raiz->valor);       // Visita raiz
        mostrarInOrdem(raiz->direita);    // Visita direita
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

    printf("Valores da arvore em ordem: ");
    mostrarInOrdem(raiz); // Deve mostrar: 3 5 7 10 15

    return 0;
}