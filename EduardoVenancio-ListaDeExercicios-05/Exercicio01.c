/* 1) Faça um programa que leia cinco valores e os armazene em um vetor. Em seguida,
mostre todos os valores lidos juntamente com a média dos valores. */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int valores [5], i;
    float media = 0.0;

    // Laço de repetição para preencher o ARRAY
    for (i = 0; i <= 4; i++)
    {
        printf("Digite o %d* valor: ", i+1);
        scanf("%d", &valores[i]);
        media += valores[i];
    }
    
    printf("\n");

    // Calcula a média dos valores
    media = media/5.0;

    // Imprime os valores
    for (i = 0; i <= 4; i++)
    {
        printf("%d ", valores[i]);
    }
    
    printf("\n");

    printf("Media = %.2f\n", media);

    system("pause");
    return 0;
}