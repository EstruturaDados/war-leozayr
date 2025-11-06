#include <stdio.h>
#include <stdlib.h>
#include <string.h> 



#define MAX_LIVROS 50
#define TAM_STRING 100

struct Livro {
    char nome [TAM_STRING];
    char autor [TAM_STRING];
    char editora [TAM_STRING];
    int edicao;
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
};


int main() {

    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros;
    int opcao;

    do {

        printf ("==================================\n");
        printf ("      BIBLIOTECA - PARTE 1\n");
        printf ("==================================\n");
        printf ("1 - Cadastrar novo livro\n");
        printf ("2 - Listar todos os Livros\n");
        printf ("0 - Sair\n");
        printf ("----------------------------------\n");
        printf ("Escolha uma opção: ");

        scanf ("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                printf ("---- Cadastro de um novo livro ----\n");

                if (totalLivros < MAX_LIVROS) {
                printf ("Digite o nome do livro: ");
                fgets (biblioteca[totalLivros].nome, TAM_STRING, stdin);

                printf ("Digite o autor do livro: ");
                fgets (biblioteca[totalLivros].autor, TAM_STRING, stdin);

                printf ("Digite a editora do livro: ");
                fgets (biblioteca[totalLivros].editora, TAM_STRING, stdin);

                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                printf ("Digite a edição: ");
                scanf ("%d", &biblioteca[totalLivros].edicao);
                limparBufferEntrada ();

                totalLivros++;

                printf ("\nLivro cadastrado com susesso!\n");

                } else {
                printf ("Biblioteca cheia!!\n");
                }
                break;

            case 2: 
                printf ("---- Lista de livros cadastrados----\n\n");

                if (totalLivros == 0) {
                printf("Nenhum livro cadastrado no momento.\n");
                } else {
                for (int i = 0; i < totalLivros; i++) {
                printf("---------------------------------\n");
                printf("LIVRO %d\n", i + 1);
                printf("Nome: %s\n", biblioteca[i].nome);
                printf("Autor: %s\n", biblioteca[i].autor);
                printf("Editora: %s\n", biblioteca[i].editora);
                printf("Edição: %d\n", biblioteca[i].edicao);
                }
                printf ("--------------------------------\n");
                }


            case 0:
                printf ("\n Saindo do sistema...\n");
                break;

            default:
                printf ("Opção inválida... Tente novamente...\n");
                printf("\nPrecione ENTER para continuar!"); 
                getchar();
                break;
        
        }
    } while (opcao != 0);

    return 0;
}