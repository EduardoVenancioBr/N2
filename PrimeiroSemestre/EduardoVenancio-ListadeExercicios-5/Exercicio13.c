/* 13) Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma
pessoa. Agora, escreva um programa que leia os dados de seis pessoas. Calcule e
exiba os nomes da pessoa mais nova e da mais velha. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCT
struct pessoa
{
    char nome[50];
    int dataDeNascimento[3];
    //int dia, mes, ano;
};


int main() {
    struct pessoa p[6];
    int i;
    int indNova = 0, indVelha = 0;

    for (i = 0; i < 6; i++)
    {
        printf("%d* Pessoa---\n", i+1);
        printf("Digite o nome: ");
        fgets(p[i].nome, 50, stdin);
        p[i].nome[strcspn(p[i].nome, "\n")] = '\0';

        // Descarta todos os caracteres. Limpa
        //while (getchar() != '\n');

        printf("Digite a data de nascimento(dd/mm/aaaa): ");
        scanf("%d %d %d", &p[i].dataDeNascimento[0], &p[i].dataDeNascimento[1], &p[i].dataDeNascimento[2]);

        while (getchar() != '\n');

        printf("\n");
    }
    
    indNova = 0;
    indVelha = 0;


    // Verificação
    for (i = 1; i < 6; i++) {
        // Verifica se a pessoa atual é mais nova
        if (p[i].dataDeNascimento[2] > p[indNova].dataDeNascimento[2] || 
            (p[i].dataDeNascimento[2] == p[indNova].dataDeNascimento[2] && p[i].dataDeNascimento[1] > p[indNova].dataDeNascimento[1]) ||
            (p[i].dataDeNascimento[2] == p[indNova].dataDeNascimento[2] && p[i].dataDeNascimento[1] == p[indNova].dataDeNascimento[1] && p[i].dataDeNascimento[0] > p[indNova].dataDeNascimento[0])) {
            indNova = i; // Atualiza o índice da pessoa mais nova
        }
        // Verifica se a pessoa atual é mais velha
        if (p[i].dataDeNascimento[2] < p[indVelha].dataDeNascimento[2] || 
            (p[i].dataDeNascimento[2] == p[indVelha].dataDeNascimento[2] && p[i].dataDeNascimento[1] < p[indVelha].dataDeNascimento[1]) ||
            (p[i].dataDeNascimento[2] == p[indVelha].dataDeNascimento[2] && p[i].dataDeNascimento[1] == p[indVelha].dataDeNascimento[1] && p[i].dataDeNascimento[0] < p[indVelha].dataDeNascimento[0])) {
            indVelha = i; // Atualiza o índice da pessoa mais velha
        }
    }
    
    // Exibir os resultados
    printf("Pessoa mais velha---\n");
    printf("Nome: %s\n", p[indNova].nome);
    printf("Data de nascimento: %d/%d/%d\n", p[indNova].dataDeNascimento[0], p[indNova].dataDeNascimento[1], p[indNova].dataDeNascimento[2]);

    printf("\nPessoa mais nova---\n");
    printf("Nome: %s\n", p[indVelha].nome);
    printf("Data de nascimento: %d/%d/%d\n", p[indVelha].dataDeNascimento[0], p[indVelha].dataDeNascimento[1], p[indVelha].dataDeNascimento[2]);

    system("pause");
    return 0;
}