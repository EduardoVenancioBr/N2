/* 2) Faça um programa que leia um vetor de oito posições. Em seguida, leia também dois
valores X e Y quaisquer correspondentes a duas posições no vetor. Seu programa
deverá exibir a soma dos valores encontrados nas respectivas posições X e Y. */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int valores [8], soma, x, y, i;

    // Laço de repetição para preencher o ARRAY
    for (i = 0; i <= 7; i++)
    {
        printf("Digite o %d* valor: ", i+1);
        scanf("%d", &valores[i]);
    }
    
    printf("\n");

    // Lendo as variáveis X e Y
    printf("Digite dois numeros de 0 a 7: ");
    scanf("%d %d", &x, &y);

    printf("\n");

    // Soma dos dois valores
    soma = valores[x] + valores[y];

    printf("Soma = %d\n", soma);

    system("pause");
    return 0;
}