/* 16) Elabore uma função para verificar se um número é um quadrado perfeito. Um
quadrado perfeito é um número inteiro não negativo que pode ser expresso como
o quadrado de outro número inteiro. Exemplos: 1, 4, 9 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void minecraft(int num) {
    int raiz = sqrt(num);

    if (num < 0)
    {
        printf("Nao e um quadrado perfeito\n");
    }
    else if (raiz * raiz == num)
    {
        printf("Quadrado perfeito\n");
    }
    else
    {
        printf("Nao e um quadrado perfeito\n");
    }
    
}

int main() {
    int x;

    printf("Digite um numero: ");
    scanf("%d", &x);

    minecraft(x);

    system("pause");
    return 0;
}