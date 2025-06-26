/* 15) Crie uma enumeração representando os meses do ano. Agora, escreva um
programa que leia um valor inteiro do teclado e exiba o nome do mês
correspondente e quantos dias ele possui. */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int mes;

    printf("Digite um numero de 1 a 12: ");\
    scanf("%d", &mes);

    switch (mes)
    {
    case 1:
        printf("Janeiro, 31 dias\n");
        break;
    
    case 2:
        printf("Fevereiro, 28 dias\n");
        break;
    
    case 3:
        printf("Marco, 31 dias\n");
        break;

    case 4:
        printf("Abril, 30 dias\n");
        break;
    
    case 5:
        printf("Maio, 31 dias\n");
        break;

    case 6:
        printf("Junho, 30 dias\n");
        break;

    case 7:
        printf("Julho, 31 dias\n");
        break;

    case 8:
        printf("Agosto, 31 dias\n");
        break;

    case 9:
        printf("Semtebro, 30 dias\n");
        break;

    case 10:
        printf("Outubro, 31 dias\n");
        break;

    case 11:
        printf("Novembro, 30 dias\n");
        break;

    case 12:
        printf("Janeiro, 31 dias\n");
        break;

    default:
        printf("Erro.\n");
    }

    system("pause");
    return 0;
}