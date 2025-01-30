#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da cidade
struct CartaCidade {
    char estado;
    char codigo[4]; // Ex: "A01", "B02"
    char nome[30];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
};

void limparBufferEntrada() {
    while (getchar() != '\n'); // Limpa qualquer resíduo no buffer
}

void cadastrarCarta(struct CartaCidade *carta) {
    printf("\nVamos cadastrar uma nova carta!\n");
    
    printf("Digite a letra do Estado (A-H): ");
    scanf(" %c", &carta->estado);
    limparBufferEntrada(); // Evita problemas no próximo scanf
    
    printf("Digite o Código da Carta (Ex: A01, B02): ");
    scanf(" %3s", carta->codigo);
    limparBufferEntrada(); 
    
    printf("Digite o Nome da Cidade: ");
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = 0; // Remove a nova linha
    
    printf("Digite a População: ");
    scanf("%d", &carta->populacao);
    limparBufferEntrada();

    printf("Digite a Área da Cidade (km²): ");
    scanf("%f", &carta->area);
    limparBufferEntrada();

    printf("Digite o PIB da Cidade: ");
    scanf("%f", &carta->pib);
    limparBufferEntrada();

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta->num_pontos_turisticos);
    limparBufferEntrada();

    printf("\nCarta cadastrada com sucesso!\n");
}

void exibirCarta(struct CartaCidade carta) {
    printf("\n======= DADOS DA CIDADE =======\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.num_pontos_turisticos);
    printf("=================================\n");
}

int main() {
    struct CartaCidade carta;
    char continuar;
    
    do {
        cadastrarCarta(&carta);
        exibirCarta(carta);
        
        printf("\nDeseja cadastrar outra carta? (S/N): ");
        scanf(" %c", &continuar);
        limparBufferEntrada(); // Evita problemas na repetição do loop
    } while (continuar == 'S' || continuar == 's');
    
    printf("\nCadastro finalizado. Obrigado por utilizar o sistema!\n");
    return 0;
}
