#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int chave;
    struct no *esquerda;
    struct no *direita;
} no;


no* criarNo(int chave);
no* insercao(no* raiz, int chave);
no* busca(no* raiz, int chave);
void impressao(no* raiz);



int main(void) {

    no* raiz = NULL;
    int opcao, valor;


    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Inserir um valor na arvore\n");
        printf("2 - Buscar um valor na arvore\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o valor para inserir: ");
                scanf("%d", &valor);
                raiz = insercao(raiz, valor);
                printf("\nArvore in-ordem apos insercao: ");
                impressao(raiz);
                printf("\n");
                break;

            case 2:
                printf("\nDigite o valor para buscar: ");
                scanf("%d", &valor);
                no* resultado = busca(raiz, valor);
                if (resultado != NULL) {
                    printf("\nValor %d encontrado na arvore.\n", valor);
                } else {
                    printf("\nValor %d nao encontrado na arvore.\n", valor);
                }
                break;

            case 0:
                printf("\nSaindo.\n");
                return 0;

            default:
                printf("\nOpcao invalida!\n");
        }
    }

    return 0;
}



no* criarNo(int chave) {
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}



no* insercao(no* raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }

    if (chave < raiz->chave) {
        raiz->esquerda = insercao(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = insercao(raiz->direita, chave);
    }
    return raiz;
}



no* busca(no* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }

    if (chave < raiz->chave) {
        return busca(raiz->esquerda, chave);
    }
    return busca(raiz->direita, chave);
}



void impressao(no* raiz) {
    if (raiz != NULL) {
        impressao(raiz->esquerda);
        printf("%d ", raiz->chave);
        impressao(raiz->direita);
    }
}
