/* 17) Elabore uma função que receba três notas de um aluno como parâmetros e uma
letra. Se a letra for “A”, a função deverá calcular a média aritmética das notas do
aluno; se for “P”, deverá calcular a média ponderada, com pesos 5, 3 e 2. Retorne a
média calculada para o programa principal. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularNota(float n1, float n2, float n3, char l) {
    if (l == 'A')
    {
        return (n1 + n2 + n3) / 3.0;
    }
    else if (l == 'P')
    {
        return (n1*5 + n2*3 + n3*2) / (5 + 3 + 2);
    }
    else
    {
        printf("Erro.");
    }
    
    return 0;
}

int main() {
    int i;
    float notas[4];
    char letra;

    for (i = 0; i < 3; i++)
    {
        printf("Digite a %d* nota: ", i+1);
        scanf("%f", &notas[i]);
    }
    
    printf("Digite 'A' para media artimetica ou 'P' para media ponderada: ");
    scanf("%s", &letra);

    notas[3] = calcularNota(notas[0], notas[1], notas[2], letra);

    printf("Resultado = %.2f\n", notas[3]);

    system("pause");
    return 0;
}