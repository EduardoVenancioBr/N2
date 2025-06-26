/* 8) Leia uma string do teclado e conte quantas vogais (a, e, i, o, u) ela possui. Entre com
um caractere (vogal ou consoante) e substitua todas as vogais da palavra dada por
esse caractere. Ao final, imprima a nova string e o número de vogais que ela possui. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[50], substituicao;
    int i, qtdVogais = 0;

    printf("Digite uma palavra: ");
    fgets(string, 50, stdin);

    printf("Digite um caractere para substiuir todas as vogais da palavra: ");
    scanf("%c", &substituicao);

    for (i = 0; string[i] != '\0' ; i++)
    {
        if (string[i] == 'a' || string[i] == 'A')
        {
            string[i] = substituicao;
            qtdVogais++;
        }
        else if (string[i] == 'e' || string[i] == 'E')
        {
            string[i] = substituicao;
            qtdVogais++;
        }
        else if (string[i] == 'i' || string[i] == 'I')
        {
            string[i] = substituicao;
            qtdVogais++;
        }
        else if (string[i] == 'o' || string[i] == 'O')
        {
            string[i] = substituicao;
            qtdVogais++;
        }
        else if (string[i] == 'u' || string[i] == 'U')
        {
            string[i] = substituicao;
            qtdVogais++;
        }
    }
    
    printf("\nNova string = %s\n", string);
    printf("Quantidade de vogais = %d\n", qtdVogais);

    system("pause");
    return 0;
}