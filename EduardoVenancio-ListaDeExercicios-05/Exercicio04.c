/* 4) Faça um programa que preencha um vetor com 10 números reais. Em seguida,
calcule e mostre na tela a quantidade de números negativos e a soma dos números
positivos desse vetor. */
#include <stdio.h>
#include <stdlib.h>

int main() {
    float valores [10];
    int i, qtdPositivos = 0, qtdNegativos = 0;

    printf("Prencha um vetor de 10 numeros com valores reais\n");

    // Laço de repetição para preencher o ARRAY
    for (i = 0; i <= 9; i++)
    {
        printf("Digite o %d* valor: ", i+1);
        scanf("%f", &valores[i]);
    }
    
    printf("\n");

    for (i = 0; i <= 9; i++)
    {
        if (valores[i] > 0)
        {
            qtdPositivos++;
        }

        else if (valores[i] < 0)
        {
            qtdNegativos++;
        }
    }
    
    printf("Quantidade de numeros positivos encontrados: %d\n", qtdPositivos);
    printf("Quantidade de numeros negativos encontrados: %d\n", qtdNegativos);

    system("pause");
    return 0;
}