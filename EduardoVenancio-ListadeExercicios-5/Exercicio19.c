/* 19) Elabore uma função que receba um vetor contendo N valores e retorne por
referência o maior e o menor elemento desse vetor. */
#include <stdio.h>
#include <stdlib.h>

void maiorEMenor(int vetor[], int *maiorElemento, int *menorElementor) {
    for (int i = 0; i < 5; i++)
    {
        if (*maiorElemento < vetor[i])
        {
            *maiorElemento = vetor[i];
        }
        if (*menorElementor > vetor[i])
        {
            *menorElementor = vetor[i];
        }
    
    }
    
};

int main() {
    int num[5] = {1, 2, 3, 4, 5};
    int maior = num[0], menor = num[0];

    maiorEMenor(num, &maior, &menor);

    printf("Maior numero = %d\n", maior);
    printf("Menor numero = %d\n", menor);

    system("pause");
    return 0;
};