#include <stdio.h>
#include <stdbool.h>

// Constantes do programa
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se uma posição é válida no tabuleiro
bool posicaoValida(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && 
            coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Função para verificar se é possível posicionar um navio
bool podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                         int linhaInicio, int colunaInicio, 
                         bool ehHorizontal) {
    
    // Verificar se todas as posições do navio estão dentro do tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linhaInicio;
        int coluna = colunaInicio;
        
        if (ehHorizontal) {
            coluna += i;  // Movimento horizontal
        } else {
            linha += i;   // Movimento vertical
        }
        
        // Verificar se a posição está dentro do tabuleiro
        if (!posicaoValida(linha, coluna)) {
            return false;
        }
        
        // Verificar se já existe um navio nesta posição
        if (tabuleiro[linha][coluna] == NAVIO) {
            return false;
        }
    }
    
    return true;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int linhaInicio, int colunaInicio, 
                     bool ehHorizontal) {
    
    // Posicionar o navio no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linhaInicio;
        int coluna = colunaInicio;
        
        if (ehHorizontal) {
            coluna += i;  // Movimento horizontal
        } else {
            linha += i;   // Movimento vertical
        }
        
        tabuleiro[linha][coluna] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    
    // Imprimir cabeçalho com números das colunas
    printf("   ");  // Espaço para alinhar com as linhas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    // Imprimir linhas separadoras
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("\n");
    
    // Imprimir o tabuleiro com números das linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d|", i);  // Número da linha
        
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função principal
int main() {
    // Declarar e inicializar o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    
    printf("=== POSICIONAMENTO DE NAVIOS - BATALHA NAVAL ===\n");
    printf("Tabuleiro: %dx%d | Tamanho dos navios: %d\n\n", 
           TAMANHO_TABULEIRO, TAMANHO_TABULEIRO, TAMANHO_NAVIO);
    
    // Coordenadas pré-definidas para os navios
    int navioHorizontal[] = {2, 3};  // Linha 2, Coluna 3 (horizontal)
    int navioVertical[] = {5, 7};    // Linha 5, Coluna 7 (vertical)
    
    // Posicionar navio horizontal
    printf("Posicionando navio horizontal...\n");
    printf("Posição inicial: Linha %d, Coluna %d\n", 
           navioHorizontal[0], navioHorizontal[1]);
    
    if (podePosicionarNavio(tabuleiro, navioHorizontal[0], navioHorizontal[1], true)) {
        posicionarNavio(tabuleiro, navioHorizontal[0], navioHorizontal[1], true);
        printf("Navio horizontal posicionado com sucesso!\n");
    } else {
        printf("ERRO: Não foi possível posicionar o navio horizontal!\n");
        printf("Posição inválida ou sobreposição com outro navio.\n");
        return 1;  // Encerrar o programa com erro
    }
    
    // Posicionar navio vertical
    printf("\nPosicionando navio vertical...\n");
    printf("Posição inicial: Linha %d, Coluna %d\n", 
           navioVertical[0], navioVertical[1]);
    
    if (podePosicionarNavio(tabuleiro, navioVertical[0], navioVertical[1], false)) {
        posicionarNavio(tabuleiro, navioVertical[0], navioVertical[1], false);
        printf("Navio vertical posicionado com sucesso!\n");
    } else {
        printf("ERRO: Não foi possível posicionar o navio vertical!\n");
        printf("Posição inválida ou sobreposição com outro navio.\n");
        return 1;  // Encerrar o programa com erro
    }
    
    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);
    
    // Resumo dos navios posicionados
    printf("\n=== RESUMO DOS NAVIOS POSICIONADOS ===\n");
    printf("Navio Horizontal: Posição (%d,%d) a (%d,%d)\n", 
           navioHorizontal[0], navioHorizontal[1],
           navioHorizontal[0], navioHorizontal[1] + TAMANHO_NAVIO - 1);
    printf("Navio Vertical:   Posição (%d,%d) a (%d,%d)\n", 
           navioVertical[0], navioVertical[1],
           navioVertical[0] + TAMANHO_NAVIO - 1, navioVertical[1]);
    
    printf("\nLegenda: 0 = Água | 3 = Navio\n");
    printf("=== POSICIONAMENTO CONCLUÍDO ===\n");
    
    return 0;
}