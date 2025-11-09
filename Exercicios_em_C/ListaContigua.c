// Contigua

#include <stdio.h>

#define MAX 100

typedef struct {
    int elementos[MAX];
    int tamanho;
} ListaContigua;


void inicializaLista(ListaContigua *lista) {
    lista->tamanho = 0;
}


int buscaSequencial(ListaContigua *lista, int v) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == v) {
            return i;
        }
    }
    return -1;  // Retorna -1 se o valor não for encontrado
}


void insereSequencial(ListaContigua *lista, int v, int posicao) {
    if (posicao < 0 || posicao > lista->tamanho || lista->tamanho >= MAX) {
        printf("Posição inválida ou lista cheia.\n");
        return;
    }
    for (int i = lista->tamanho; i > posicao; i--) {
        lista->elementos[i] = lista->elementos[i - 1];
    }
    lista->elementos[posicao] = v;
    lista->tamanho++;
    printf("Valor %d inserido na posição %d.\n", v, posicao);
}


void removeSequencial(ListaContigua *lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posição inválida.\n");
        return;
    }
    for (int i = posicao; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
    printf("Valor na posição %d removido.\n", posicao);
}



int main() {
    ListaContigua lista;
    inicializaLista(&lista);
    int escolha, valor, posicao;

    while (1) {
        printf("\nEscolha uma operação:\n");
        printf("1. Inserir valor\n");
        printf("2. Buscar valor\n");
        printf("3. Remover valor\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posição onde deseja inserir (0 a %d): ", lista.tamanho);
                scanf("%d", &posicao);
                insereSequencial(&lista, valor, posicao);
                break;
            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                posicao = buscaSequencial(&lista, valor);
                if (posicao != -1) {
                    printf("Valor encontrado na posição %d.\n", posicao);
                } else {
                    printf("Valor não encontrado.\n");
                }
                break;
            case 3:
                printf("Digite a posição do valor a ser removido (0 a %d): ", lista.tamanho - 1);
                scanf("%d", &posicao);
                removeSequencial(&lista, posicao);
                break;
            case 4:
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
    return 0;
}
