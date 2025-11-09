#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10001

void criar_vetor(int vet[]);
void sequencial(int vet[]);
void binario(int vet[]);
void ordenacao_selection_sort(int vet[]);

int main(void) {
    int escolha;
    int vet[TAM];

    criar_vetor(vet);

    printf("Digite o Algoritmo desejado:\n[1] Sequencial\n[2] Binario\n");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            sequencial(vet);
            break;
        case 2:
            ordenacao_selection_sort(vet);
            binario(vet);
            break;
        default:
            printf("\nEsta nao e uma opcao valida\n");
    }

    return 0;
}


void criar_vetor(int vet[]) {
    srand(time(NULL));
    for(int i = 0; i < TAM; i++) {
        vet[i] = rand() % TAM;
    }
}

void sequencial(int vet[]) {
    int i, chave;
    int quantidade_encontrada = 0;
    int comparacoes = 0;

    printf("\n\nDigite o valor da chave buscada, de 0 a 10000: ");
    scanf("%d", &chave);

    for (i = 0; i < TAM; i++) {
        comparacoes++;
        if (chave == vet[i]) {
            quantidade_encontrada += 1;
        }
    }

    printf("\n\nForam encontrados %d elementos iguais a chave %d\n", quantidade_encontrada, chave);
    printf("\nTotal de comparacoes realizadas na busca sequencial: %d\n", comparacoes);
}

void binario(int vet[]) {
    int chave, inicio = 0, fim = TAM - 1, meio, encontrado = 0;
    int comparacoes = 0;

    printf("\n\nDigite o valor da chave buscada, de 0 a 10000: ");
    scanf("%d", &chave);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        comparacoes++;

        if (vet[meio] == chave) {
            encontrado += 1;

            int esquerda = meio - 1;
            while (esquerda >= inicio && vet[esquerda] == chave) {
                encontrado += 1;
                esquerda--;
                comparacoes++;
            }

            int direita = meio + 1;
            while (direita <= fim && vet[direita] == chave) {
                encontrado += 1;
                direita++;
                comparacoes++;
            }

            break;
        } else if (vet[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    printf("\n\nForam encontrados %d elementos iguais a chave %d\n", encontrado, chave);
    printf("\nTotal comparacoes realizadas na busca binaria: %d\n", comparacoes);
}

void ordenacao_selection_sort(int vet[]) {
    int i, j, min, temp;

    for (i = 0; i < TAM - 1; i++) {
        min = i;
        for (j = i + 1; j < TAM; j++) {
            if (vet[j] < vet[min]) {
                min = j;
            }
        }
        temp = vet[min];
        vet[min] = vet[i];
        vet[i] = temp;
    }
}
