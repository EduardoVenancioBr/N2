/* 11) Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e
armazene esses dados em uma estrutura. Em seguida, imprima na tela os dados da
estrutura lida. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCT
struct cadastro
{
    char nome[50], endereco[50];
    int idade;
};

int main() {
    struct cadastro c;

    printf("Digite seu nome: ");
    fgets(c.nome, 50, stdin);
    c.nome[strcspn(c.nome, "\n")] = '\0';   // Remove o '\n'

    printf("Digite sua idade: ");
    scanf("%d", &c.idade);

    //Limpa o buffer de entrada
    while (getchar() != '\n');   // Descarta todos os caracteres. Limpa

    printf("Digite seu endereco: ");
    fgets(c.endereco, 50, stdin);
    c.endereco[strcspn(c.endereco, "\n")] = '\0';

    printf("Nome: %s\n", c.nome);
    printf("Idade: %d\n", c.idade);
    printf("Endereco: %s\n", c.endereco);

    system("pause");
    return 0;
}