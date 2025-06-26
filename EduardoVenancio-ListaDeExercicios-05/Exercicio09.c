/* 9) Objetivo: Faça um programa que leia uma string e imprima uma mensagem dizendo se ela é
um palíndromo ou não. Um palíndromo é uma palavra que tem a propriedade de
poder ser lida tanto da direita para a esquerda como da esquerda para a direita.
Exemplos: ovo, arara, rever, asa, osso etc. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[50], str2[50];
    int i, j;

    printf("*OBS.: TODAS AS LETRAS PRECISAM ESTAR DO MESMO TAMANHO*\nDigite uma palavra: ");
    fgets(str1, 50, stdin);
    
    // Remove o caractere de nova linha
    str1[strcspn(str1, "\n")] = 0;

    // Calcula o comprimento da string
    j = strlen(str1);

    // Inverte a string
    for (i = 0; i < j; i++) {
        str2[i] = str1[j - i - 1];
    }
    str2[i] = '\0'; // Termina a string invertida

    // Verificação
    printf("\nStr2 = %s\n", str2);

    if (strcmp(str1, str2) == 0)
    {
        printf("Palindromo\n");
    }
    else if(str1 != str2)
    {
        printf("Nao palindromo\n");
    }

    system("pause");
    return 0;
}