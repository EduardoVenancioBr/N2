/* 12) Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura deve
conter o número de matrícula do aluno, seu nome e as notas de três provas. Agora,
escreva um programa que leia os dados de cinco alunos e os armazene nessa
estrutura. Em seguida, exiba o nome e as notas do aluno que possui a maior média
geral dentre os cinco. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCT
struct aluno
{
    char matricula[25], nome[50];
    float nota[3], media;
};


int main() {
    int i, j;
    float maiorMedia;
    int indiceDeMaiorMedia = 0;
    struct aluno a[5];

    for (i = 0; i < 5; i++)
    {
        printf("%d* Aluno---\n", i+1);

        printf("Digite a matricula: ");
        fgets(a[i].matricula, 25, stdin);
        a[i].matricula[strcspn(a[i].matricula, "\n")] = '\0';


        // Descarta todos os caracteres. Limpa
        while (getchar() != '\n');


        printf("Digite o nome: ");
        fgets(a[i].nome, 50, stdin);
        a[i].nome[strcspn(a[i].nome, "\n")] = '\0';


        // Descarta todos os caracteres. Limpa
        //while (getchar() != '\n');  

        a[i].media = 0;

        // Prencher as notas
        for (j = 0; j < 3; j++)
        {
            printf("Digite a %d* nota: ", j+1);
            scanf("%f", &a[i].nota[j]);

            a[i].media += a[i].nota[j];
        }
        
        // Calcular a média
        a[i].media = a[i].media / 3.0;

        // Divisória
        printf("\n");
    }

    // Inicializar com o primeiro aluno
    maiorMedia = a[0].media;
    indiceDeMaiorMedia = 0;

    // Encontrara a maior média
    for (i = 0; i < 5; i++)
    {
        if (maiorMedia <= a[i].media)
        {
            maiorMedia = a[i].media;
            indiceDeMaiorMedia = i;
        }
    }

    // Exibir o aluno com a maior média
    printf("Aluno com a maior media:\n");
    printf("Nome: %s\n", a[indiceDeMaiorMedia].nome);
    printf("Media: %.2f\n", a[indiceDeMaiorMedia].media);
    printf("Notas: %.2f, %.2f, %.2f\n", a[indiceDeMaiorMedia].nota[0], a[indiceDeMaiorMedia].nota[1], a[indiceDeMaiorMedia].nota[2]);

    system("pause");
    return 0;
}