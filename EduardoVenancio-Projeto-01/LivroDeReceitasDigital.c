/* Este trabalho tem como objetivo aplicar os conceitos fundamentais da linguagem C
aprendidos em aula para desenvolver uma aplicação console interativa: um Livro de
Receitas Digital.
A aplicação permitirá aos usuários gerenciar uma coleção de receitas, incluindo adicionar
novas receitas, visualizá-las e organizá-las. Este projeto visa consolidar o entendimento
sobre estruturas de dados, modularização com funções, manipulação de strings e
entrada/saída de dados. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ESCOPO GLOBAL
#define MAX_RECEITAS 50                             // Limite constante para o Livro_De_Receitas
const char *categorias[] = {                        // Array de strings para as categorias
    "Entrada.",
    "Prato Principal.",
    "Sobremesa.",
    "Bebida.",
    "Lanche.",
    "Outro."
};




// ENUM (CategoriaReceita)
typedef enum {

    ENTRADA,
    PRATO_PRINCIPAL,
    SOBREMESA,
    BEBIDA,
    LANCHE,
    OUTRO

} CategoriaReceita;




// STRUCT (Receita)
typedef struct Receita
{
    char nome[50];
    char ingredientes[500];
    char instrucoes[1000];
    int tempo_preparo_minutos;
    CategoriaReceita categoria;                     // Vai adicionar o tipo da receita

} Receita;




// FUNÇÕES
void adcionarReceita(Receita *Livro_De_Receitas, int *qntdAtual) {
    /* Objetivo: permitir que o usuário, caso aja espaço suficiente, adcionar uma nova receita
    ao livro. */
    

    char confirmacao;                               // Confirmação para ações
    int categ;                                      // Categoria da receita


    inicioAdcionarReceita:  /* Permitir que o usuário consiga adcionar várias receitas de uma vez,
    sem precisar voltar para o menu principal. */


    system("cls");                                  //  Limpa a tela o terminal


    // Se o livro estiver cheio
    if (*qntdAtual >= MAX_RECEITAS)
    {   
        printf("O livro esta cheio. Nao 'e possivel adcionar uma nova receita.\n");
        system("pause");                            // Permitir que o usuário veja a mensagem acima

        return;                                     // Retorna ao menu principal
    }


    printf("\t+-=-=-=-LIVRO DE RECEITAS DIGITAL-=-=-=-+\n\n");  // Cabeçario
    printf("Adcionar Receita---\n");                // Mostrar ao usuário onde ele se encontra


    // Confirmação
    printf("-> Deseja adicionar uma nova receita? ('S' ou 'N')\n");
    scanf("%s", &confirmacao);


    getchar();                                      // Limpa o Buffer
    system("cls");                                  // Limpa a tela do terminal


    // Verificando a confirmação
    if (confirmacao == 'S')
    {
        printf("\t+-=-=-=-LIVRO DE RECEITAS DIGITAL-=-=-=-+\n\n");  // Cabeçario
        printf("Adcionar Receita---\n");            // Mostrar ao usuário onde ele se encontra


        /* NOME */
        printf("-> Nome da receita: ");
        fgets(Livro_De_Receitas[*qntdAtual].nome, 50, stdin);                   // Adciona o nome ao Livro_De_Receitas
        

        Livro_De_Receitas[*qntdAtual].nome[strcspn(Livro_De_Receitas[*qntdAtual].nome, "\n")] = 0;  // Retira o "\n" deixado pelo FGETS()


        /* Ingredientes */
        printf("-> Ingredientes: ");
        fgets(Livro_De_Receitas[*qntdAtual].ingredientes, 50, stdin);           // Adciona os ingredientes ao Livro_De_Receitas
        

        Livro_De_Receitas[*qntdAtual].ingredientes[strcspn(Livro_De_Receitas[*qntdAtual].ingredientes, "\n")] = 0;  // Retira o "\n" deixado pelo FGETS()
        
        
        /* Instruções */
        printf("-> Instrucoes do modo de preparo: ");
        fgets(Livro_De_Receitas[*qntdAtual].instrucoes, 50, stdin);             // Adciona as instruções ao Livro_De_Receitas
        

        Livro_De_Receitas[*qntdAtual].instrucoes[strcspn(Livro_De_Receitas[*qntdAtual].instrucoes, "\n")] = 0;  // Retira o "\n" deixado pelo FGETS()
        

        /* Tempo de preparo */
        printf("-> Tempo de preparo (Minutos): ");
        scanf("%d", &Livro_De_Receitas[*qntdAtual].tempo_preparo_minutos);      // Adciona o tempo de preparo ao Livro_De_Receitas
        
        
        /* Categorria */
        do {
            system("cls");                          // Limpa a tela do terminal


            printf("Para a categoria, digite:\n");
            printf("-> '0' - Entrada\n");
            printf("-> '1' - Prato principal\n");
            printf("-> '2' - Sobremesa\n");
            printf("-> '3' - Bebida\n");
            printf("-> '4' - Lanche\n");
            printf("-> '5' - Outro\n");
            scanf("%d", &categ);                    // Lê a categoria como um número inteiro


            getchar();                              // Limpa o Buffer


            if (categ < 0 || categ > 5)
            {
                printf("ERRO! Digite o dado corretamente.\n");
                system("pause");
            }

        }
        while (categ < 0 || categ > 5);             // Previnir que o usúario digite o número errado


        // Adciona a categoria ao Livro_De_Receitas
        Livro_De_Receitas[*qntdAtual].categoria = (CategoriaReceita)categ;


        // Incrementar a qndtAtual de receitas
        *qntdAtual += 1;

        
        goto inicioAdcionarReceita;                 // Voltar ao início da Função para verificar se há mais alguma receita para adcionar
    }
    
}



void verDetalhesReceita(Receita *Lista_De_Receitas, int *qntdAtual) {
    /* Objetivo: Imprimir na tela as informações de alguma receita */

    
    int i;                                          // Contador
    int receitaEncontrada = 0;                      // Flag para verificar se a receita foi encontrada
    char verReceita[50];                            // Nome da receita que vai ser detalhada

    inicioVerDetalhesReceita:   /* Permitir ao usuário, caso erre, digitar o 
    nome da receitanovamente. */


    getchar();                                      // Limpa o Buffer


    printf("\n-> Digite o nome da receita para a ver detalhada: ");
    fgets(verReceita, 50, stdin);                   // Armazenamento do dado digitado


    verReceita[strcspn(verReceita, "\n")] = 0;      // Retira o "\n" deixado pelo FGETS()


    // Looping para encontrar a receita digitada
    for (i = 0; i < *qntdAtual; i++) {
        if (strcmp(verReceita, Lista_De_Receitas[i].nome) == 0) {
            system("cls");                          // Limpa a tela do terminal


            printf("\t+-=-=-=-LIVRO DE RECEITAS DIGITAL-=-=-=-+\n\n");  // Cabeçario
            
            
            printf("\n%s---\n\n", Lista_De_Receitas[i].nome);  // Mini cabeçario
            printf("-> Ingredientes: %s\n", Lista_De_Receitas[i].ingredientes);
            printf("-> Instrucoes: %s\n", Lista_De_Receitas[i].instrucoes);
            printf("-> Tempo de preparo: %d minutos\n", Lista_De_Receitas[i].tempo_preparo_minutos);
            printf("-> Categoria: %s\n\n", categorias[Lista_De_Receitas[i].categoria]);


            receitaEncontrada = 1;                  // Receita encontrada
            break;                                  // Sair do loop após encontrar a receita
        }
    }
    if (!receitaEncontrada) {
        printf("Receita nao encontrada. Tente novamente\n");      // Informa ao usuário que a receita não foi encontrada
        
        
        // Permitir o usuário escrever o nome da receita da forma correta
        goto inicioVerDetalhesReceita;
    }

}




void listarNomesReceitas(Receita *Lista_De_Receitas, int *qntdAtual) {
    /* Objetivo: Permitir que o usuário veja todas as receitas do livro*/


    int i;                                          // Contador


    system("cls");                                  // Limpar a tela do terminal


    printf("\t+-=-=-=-LIVRO DE RECEITAS DIGITAL-=-=-=-+\n\n");  // Cabeçario
    printf("Receitas---\n");                        // Mostrar ao usuário onde ele se encontra


    printf("Total: %d\n\n", *qntdAtual);            // Mostrar ao usuário a quantidade atual de receitas no livro


    // Verificando se há receitas para ler
    if (*qntdAtual == 0)
    {
        printf("\nNao ha' receitas... :C\nTente adcionar uma!\n\n");
        system("pause");                            // Permitir que o usuário veja a mensagem acima


        return;                                     // Retorna ao menu principal
    }
    

    // Imprimir as receitas
    for (i = 0; i < *qntdAtual; i++)
    {
        printf("%d- %s\n", i+1, Lista_De_Receitas[i].nome);
    }
    

    // Chamando a função verDetalhesReceitas
    verDetalhesReceita(Lista_De_Receitas, &*qntdAtual);
    

    system("pause");                                // Permitir que o usuário veja as informações
}




void exibirMenu() {
    /* Objetivo: receber informações do usuário e fazer uma conecção entre o 
    usuário e as outras funções. */


    Receita Livro_De_Receitas[MAX_RECEITAS];        // Adciona um limite para o Livro_De_Receitas
    int QNTD_RECEITAS = 0;                          // Quantidade atual de receitas
    char valor_de_entrada[10];                       // Valor digitado pelo usuário
    int entrada;                                    // Conversão do valor_de_entrada para numérico
    char saida;                                     // Verificar se o usuário pretende sair do Livro_De_Receitas


    system("cls");                                  // Limpar a tela do terminal


    // MENU PRINCIPAL
    do {
        printf("\t+-=-=-=-LIVRO DE RECEITAS DIGITAL-=-=-=-+\n\n");  // Cabeçario
        printf("Menu Principal---\n\n");            // Mostrar ao usuário onde ele se encontra


        // Sumário
        printf("Digite:\n");
        printf("-> '1' - Adcionar uma nova receita.\n");
        printf("-> '2' - Exibir todas as receitas.\n");
        printf("-> '9' - Sair.\n");


        // Coleta do valor_de_entrada
        fgets(valor_de_entrada, 10, stdin);


        // Conversão de string para númerico utilizando atoi
        entrada = atoi(valor_de_entrada);


        // Tratamento de opções
        switch (entrada)
        {
        // Saida do programa. O número 9 é o mais distante das opções. Assim, garante que o usuário realmente quer sair
        case 9:
            system("cls");                          // Limpar a tela do terminal


            // Confirmação para a saída
            printf("Tem certeza que quer sair? ('S' ou 'N')\n");
            scanf("%s", &saida);

            
            getchar();                              // Limpa o Buffer
            system("cls");                          // Limpar a tela do terminal
            break;
        
        // Leva o usuário à função adcionarReceita()
        case 1:
            adcionarReceita(Livro_De_Receitas, &QNTD_RECEITAS);
            break;


        // Leva o usuário à função listarNomesReceita()
        case 2:
            listarNomesReceitas(Livro_De_Receitas, &QNTD_RECEITAS);
            break;


        default:
            // Tratamento de erro
            printf("\nERRO! Digite o dado corretamente.\n");    // ao digitar letras, buga o sistema :c|
            system("pause");                                    // Permitir que o usuário veja a mensagem acima
        
            
            break;
        }

        system("cls");                              // Limpar a tela do terminal
        
    }
    while (saida != 'S');
}




// MAIN
int main() {
    exibirMenu();   


    // Imagem do livro para trazer o sentimeto de realidade falsa. "Vivemos na Matrix?" hehehee
    printf(" --------------------------------------------------------\n");  // Topo
    printf("C|\t\t\t\t\t\t\t|\n");                                          // Margem
    printf("C|\t\t\t\t\t\t\t|\n");                                          // Margem
    printf("C|\t\t\t\t\t\t\t|\n");                                          // Margem
    printf("C|\t\t\t\t\t\t\t|\n");                                          // Margem
    printf("C|\t+-=-=-=-LIVRO DE RECEITAS DIGITAL-=-=-=-+       |\n");      // Cabeçario
    printf("C|\t\t\t\t\t\t\t|\n");                                          // Margem
    printf("C|\t\t\t\t\t\t\t|\n");                                          // Margem
    printf("C|\t\t\t\t\t\t\t|\n");                                          // Margem
    printf("C|\t\t\t\t\t\t\t|\n");                                          // Margem
    printf(" --------------------------------------------------------\n");  // Topo
    
    return 0;
}