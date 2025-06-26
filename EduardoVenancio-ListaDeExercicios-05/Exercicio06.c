/* 6) Leia uma matriz de tamanho 3×3. Em seguida, imprima a soma dos valores contidos
em sua diagonal principal */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[3][3], soma = 0, i, j;

    for (i = 0; i <= 2; i++)
    {
        printf("%d* Coluna\n", i+1);

        for (j = 0; j <= 2; j++)
        {
            printf("a%d%d)Digite um numero: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }

        printf("\n");

    }

    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 2; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");

    }

    soma = matriz[0][0] + matriz[1][1] + matriz[2][2];

    printf("\nSoma da diagonal principal = %d\n", soma);

    system("pause");
    return 0;
}