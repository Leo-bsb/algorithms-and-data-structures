// Encadeada

#include <stdio.h>

#define MAX 100

typedef struct No {
    int valor;
    int proximo;
} No;

typedef struct {
    No nos[MAX];
    int cabeca;
    int tamanho;
    int livre;  // Índice do próximo nó livre na lista
} ListaEncadeadaEstatica;


void inicializaLista(ListaEncadeadaEstatica *lista) {
    lista->cabeca = -1;  // Indica que a lista está vazia
    lista->tamanho = 0;
    lista->livre = 0;

    // Configura todos os nós como livres
    for (int i = 0; i < MAX - 1; i++) {
        lista->nos[i].proximo = i + 1;
    }
    lista->nos[MAX - 1].proximo = -1;  // Último nó não aponta para ninguém
}


int buscaSequencial(ListaEncadeadaEstatica *lista, int v) {
    int atual = lista->cabeca;
    int posicao = 0;

    while (atual != -1) {
        if (lista->nos[atual].valor == v) {
            return posicao;
        }
        atual = lista->nos[atual].proximo;
        posicao++;
    }

    return -1;  // Retorna -1 se o valor não for encontrado
}


void insereSequencial(ListaEncadeadaEstatica *lista, int v, int posicao) {
    if (posicao < 0 || posicao > lista->tamanho || lista->livre == -1) {
        printf("Posição inválida ou lista cheia.\n");
        return;
    }


    int novo = lista->livre;
    lista->livre = lista->nos[novo].proximo;

    lista->nos[novo].valor = v;

    if (posicao == 0) {
        lista->nos[novo].proximo = lista->cabeca;
        lista->cabeca = novo;
    } else {
        int atual = lista->cabeca;
        for (int i = 0; i < posicao - 1; i++) {
            atual = lista->nos[atual].proximo;
        }
        lista->nos[novo].proximo = lista->nos[atual].proximo;
        lista->nos[atual].proximo = novo;
    }

    lista->tamanho++;
    printf("Valor %d inserido na posição %d.\n", v, posicao);
}


void removeSequencial(ListaEncadeadaEstatica *lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posição inválida.\n");
        return;
    }

    int atual = lista->cabeca;
    int anterior = -1;

    for (int i = 0; i < posicao; i++) {
        anterior = atual;
        atual = lista->nos[atual].proximo;
    }

    if (anterior == -1) {
        lista->cabeca = lista->nos[atual].proximo;
    } else {
        lista->nos[anterior].proximo = lista->nos[atual].proximo;
    }


    lista->nos[atual].proximo = lista->livre;
    lista->livre = atual;

    lista->tamanho--;
    printf("Valor na posição %d removido.\n", posicao);
}


int main() {
    ListaEncadeadaEstatica lista;
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

