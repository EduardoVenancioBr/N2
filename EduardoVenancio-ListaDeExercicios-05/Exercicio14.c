/* 14) Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do
atleta, seu esporte, idade e altura. Agora, escreva um programa que leia os dados
de cinco atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCT
struct atleta
{
    char nome[50], esporte[50];
    int idade;
    float altura;
};



int main() {
    struct atleta a[5];
    int i, maisVelho, idMaisVelho = 0, idMaiorAltura = 0;
    float maiorAltura;

    for (i = 0; i < 5; i++)
    {
        printf("%d* Atleta---\n", i+1);
        printf("Digite o nome: ");
        fgets(a[i].nome, 50, stdin);
        a[i].nome[strcspn(a[i].nome, "\n")] = '\0';

        // Descarta todos os caracteres. Limpa
        while (getchar() != '\n');

        printf("Digite a idade: ");
        scanf("%d", &a[i].idade);

        while (getchar() != '\n');

        printf("Digite a altura: ");
        scanf("%f", &a[i].altura);

        printf("\n");
    }
    
    maisVelho = a[0].idade;
    maiorAltura = a[0].altura;


    // Verificação
    for (i = 1; i < 5; i++) {
        // Verifica se o atleta atual é o mais velho
        if (maisVelho < a[i].idade)
        {
            maisVelho = a[i].idade;
            idMaisVelho = i;
        }
        
        // Verifica o maior atleta
        if (maiorAltura < a[i].altura)
        {
            maiorAltura = a[i].altura;
            idMaiorAltura = i;
        }
        
    }
    
    // Exibir os resultados
    printf("Atleta mais velho---\n");
    printf("Nome: %s\n", a[idMaisVelho].nome);
    printf("Idade: %d\n", a[idMaisVelho].idade);
    printf("Altura: %f\n", a[idMaisVelho].altura);

    printf("\nAtleta mais alto---\n");
    printf("Nome: %s\n", a[idMaiorAltura].nome);
    printf("Idade: %d\n", a[idMaiorAltura].idade);
    printf("Altura: %f\n", a[idMaiorAltura].altura);

    system("pause");
    return 0;
}