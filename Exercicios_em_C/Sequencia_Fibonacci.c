#include <stdio.h>
#include <time.h>

int fibonacci(int posicao);

int main (void){
int posicao, final;
clock_t inicio = clock();


printf("=-=-=-=-=-Sequencia de Fibonnaci-=-=-=-=-=\n");
printf("\nDigite a posicao que voce deseja:");
scanf("%d", &posicao);
final = fibonacci(posicao);

printf("\n\nO valor total da Sequencia de Fibonacci com a posicao %d e %d\n", posicao, final);
double tempo_total = (double)(clock() - inicio) / (CLOCKS_PER_SEC / 1000);
printf("\nTempo total = %.2f ms\n", tempo_total);
}

int fibonacci(int posicao){

    if (posicao == 0 || posicao == 1){
                return posicao;
    }

    return fibonacci(posicao - 1) + fibonacci(posicao - 2);
}
