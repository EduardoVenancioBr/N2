/* 3) Faça um programa que receba do usuário um vetor X com 10 posições. Em seguida
deverão ser impressos o maior e o menor elemento desse vetor. */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int valores [10], i;

    // Laço de repetição para preencher o ARRAY
    for (i = 0; i <= 9; i++)
    {
        printf("Digite o %d* valor: ", i+1);
        scanf("%d", &valores[i]);
    }
    
    printf("\n");

    int maiorValor = valores[0], menorValor = valores[0];
    // Procurando o maior e o menor valor do ARRAY
    for (i = 0; i <= 9; i++)
    {
        // Condição para ser o maior valor
        if (valores[i] >= maiorValor)
        {
            maiorValor = valores[i];
        }

        // Condição para ser o menor valor
        else if (valores[i] <= menorValor)
        {
            menorValor = valores[i];
        }
    }
    
    printf("Maior valor = %d\nMenor valor = %d\n", maiorValor, menorValor);

    system("pause");
    return 0;
}