#include <stdio.h>
#include <string.h>

void posOrdem(char* pre, char* in, int tam) {
    if (tam <= 0)
        return;

    char raiz = pre[0]; // Primeiro caractere da pré-ordem é sempre a raiz

    // Procurar a raiz na string in-ordem
    int i;
    for (i = 0; i < tam; i++) {
        if (in[i] == raiz)
            break;
    }

    // pre + 1 + i	Onde começa a direita no pre	"z"
    // in + i + 1	Onde começa a direita no in	"z"
    // tam - i - 1	Quantos elementos tem na direita 1


    // Recursivamente processa a subárvore esquerda
    posOrdem(pre + 1, in, i);

    // Recursivamente processa a subárvore direita
    posOrdem(pre + 1 + i, in + i + 1, tam - i - 1);

    // Imprime a raiz (pós-ordem = esquerda, direita, raiz)
    printf("%c", raiz);
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        int n;
        char pre[100], in[100];
        scanf("%d %s %s", &n, pre, in);

        posOrdem(pre, in, n);
        printf("\n");
    }

    return 0;
}
