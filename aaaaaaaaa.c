#include <stdio.h>
#include <string.h>

// Requisito: Criação da struct Territorio
// Documentação: A struct agrupa dados relacionados (nome, cor, tropas) de um território.
typedef struct {
    char nome[30];  
    char cor[10];   
    int tropas;     
} Territorio;

#define NUM_TERRITORIOS 5

int main() {
    
    // Vetor com capacidade para armazenar 5 estruturas do tipo Territorio.
    Territorio lista_territorios[NUM_TERRITORIOS];
    int i;
    
    // ---  CADASTRO DOS TERRITÓRIOS ---
    printf("===========================================\n");
    printf("      CADASTRO DE TERRITÓRIOS       \n");
    printf("===========================================\n");

    // Usabilidade: Mensagens claras para orientar o usuário.
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("\n--- Território %d de %d ---\n", i + 1, NUM_TERRITORIOS);

        printf("Nome do Território: ");
        // Uso de fgets para leitura segura de string.
        
        fgets(lista_territorios[i].nome, 30, stdin);
        
        // Remove o '\n' lido pelo fgets, se ele estiver presente, para uma exibição limpa.
        lista_territorios[i].nome[strcspn(lista_territorios[i].nome, "\n")] = 0;

        // 2. Cor do Exército
        printf("Cor do Exército (Ex: Vermelho): ");
        fgets(lista_territorios[i].cor, 10, stdin);
        lista_territorios[i].cor[strcspn(lista_territorios[i].cor, "\n")] = 0;

        // 3. Quantidade de Tropas
        printf("Quantidade de Tropas (inteiro): ");
        // Uso de scanf para ler o inteiro de forma simples.
        if (scanf("%d", &lista_territorios[i].tropas) != 1) {
             printf("Erro na leitura das tropas. Encerrando.\n");
             return 1;
        }
        
        // Limpa o buffer de entrada (stdin) após o scanf para evitar que o '\n' 
        // cause problemas no próximo fgets.
        while (getchar() != '\n'); 
    }

    // ---  EXIBIÇÃO DOS DADOS ---
    printf("\n\n===========================================\n");
    printf("      DADOS DOS TERRITÓRIOS CADASTRADOS      \n");
    printf("===========================================\n");

    
    // Documentação: Laço para iterar e exibir os dados de cada estrutura formatadamente.
    // Usabilidade/Desempenho: Exibição clara e imediata após o cadastro.
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("\n[%d°] Território: **%s**\n", i + 1, lista_territorios[i].nome);
        printf("    Cor do Exército: %s\n", lista_territorios[i].cor);
        printf("    Tropas: %d\n", lista_territorios[i].tropas);
        printf("-------------------------------------------\n");
    }

    printf("Fim do Cadastro e Exibição.\n");

    return 0;
}