/* 18) Faça uma função que receba, por parâmetro, uma matriz A contendo seis linhas e
seis colunas. Essa função deve retornar, por referência, a soma dos elementos da
sua diagonal principal e da sua diagonal secundária. */
#include <stdio.h>
#include <stdlib.h>

int dgnPrincipal, dgnSecundaria;

void calcularMatriz(int matA[6][6], int *dgnPrincipal, int *dgnSecundaria) {
    *dgnPrincipal = 0;
    *dgnSecundaria = 0;
    
    *dgnPrincipal = matA[0][0] + matA[1][1] + matA[2][2] + matA[3][3] + matA[4][4] + matA[5][5];
    *dgnSecundaria = matA[0][5] + matA[1][4] + matA[2][3] + matA[3][2] + matA[4][1] + matA[5][0];
}

int main() {
    int i, j, cont = 1;
    int matA[6][6];
    int dgnP, dgnS;

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            matA[i][j] = cont;
            cont++;
        }
        
    }
    
    calcularMatriz(matA, &dgnP, &dgnS);

    printf("Diagonal principal: %d\n", dgnP);
    printf("Diagonal secundaria: %d\n", dgnS);

    system("pause");
    return 0;
};