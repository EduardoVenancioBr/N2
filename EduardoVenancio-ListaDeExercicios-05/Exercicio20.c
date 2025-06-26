/* 20) Elabore uma função que receba por parâmetros os coeficientes de uma equação do
segundo grau. Em seguida, calcule e mostre as raízes dessa equação.
Lembre-se de que as raízes são calculadas com a formula de Bhaskara:
em que ∆ = b2 – 4 * a*c e ax 2 +bx+c= 0 representa uma equação do segundo grau. A
variável a tem de ser diferente de zero. Caso seja igual, imprima a mensagem “Não
é equação de segundo grau” e retorne o valor −1.
Do contrário, retorne o número de raízes e as raízes (por referência) se elas
existirem:
a Se ∆ < 0, não existe real. Número de raízes: 0.
b Se ∆ = 0, existe uma raiz real. Número de raízes: 1.
c Se ∆ > 0, existem duas raízes reais. Número de raízes: 2 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bhaskara(int a, int b, int c, int *y1, int *y2, int *qtdRaizes) {
    int delta, raizDeDelta;

    delta = (b*b) - (4*a*c);
    raizDeDelta = sqrt(delta);

    if (a == 0)
    {
        printf("Não é equcao de segundoo gruau.\n");
        *y1 = -1;
        *qtdRaizes += 1;
    }
    else if (delta == 0)
    {
        *qtdRaizes += 1;

        *y1 = (-b + raizDeDelta)/(2*a);

        if (*y1 < 0)
        {
            *y1 = *y1 * (-1);
        }
        
    }
    else if (delta > 0)
    {
        qtdRaizes += 2;
        *y1 = (-b + raizDeDelta)/(2*a);
        *y2 = (-b - raizDeDelta)/(2*a);
    }
    else
    {
        printf("Erro.\n");
    }

}

int main() {
    int a, b, c, x1, x2, qtdRaizes = 0;

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    printf("Digite o valor de c: ");
    scanf("%d", &c);

    bhaskara(a, b, c, &x1, &x2, &qtdRaizes);

    if (qtdRaizes > 1)
    {
        printf("x1 = %d\nx2 = %d\n", x1, x2);
    }
    if (qtdRaizes == 1)
    {
        printf("x1 = +-%d\n", x1);
    }

    system("pause");
    return 0;
}