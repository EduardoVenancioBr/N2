/* 5) Faça um programa que receba do usuário dois arrays, A e B, com 10 números
inteiros cada. Crie um novo array C calculando C = A – B. Mostre na tela os dados do
array C. */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arrayA [10], arrayB [10], arrayC [10], i;

    printf("Array A\n");

    // Laço de repetição para preencher o arrayA
    for (i = 0; i <= 9; i++)
    {
        printf("Digite o %d* valor: ", i+1);
        scanf("%d", &arrayA[i]);
    }

    printf("\nArray B\n");

    // Laço de repetição para preencher o arrayB
    for (i = 0; i <= 9; i++)
    {
        printf("Digite o %d* valor: ", i+1);
        scanf("%d", &arrayB[i]);
    }
    
    printf("\n");

    for (i = 0; i <= 9; i++)
    {
        arrayC[i] = arrayA[i] - arrayB[i];
    }

    printf("Array C = ");

    for (i = 0; i <= 9; i++)
    {
        printf("%d ", arrayC[i]);
    }

    printf("\n");

    system("pause");
    return 0;
}