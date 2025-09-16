#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "map_adt.h"
#include "game_logic.h"
#include "mission.h"

#define NUM_TERRITORIOS 4 // 2 para cada continente, para simplificar
#define NUM_JOGADORES 2

// Função auxiliar para configurar o estado inicial do jogo
void inicializar_jogo(GameMap* mapa, Jogador jogadores[]) {
    // Definir jogadores
    strcpy(jogadores[0].nome, "Napoleao");
    jogadores[0].id = 1;
    strcpy(jogadores[1].nome, "Alexandre");
    jogadores[1].id = 2;

    // Obter ponteiros para territórios
    Territorio* brasil = obter_territorio_por_id(mapa, 0);
    Territorio* argentina = obter_territorio_por_id(mapa, 1);
    Territorio* franca = obter_territorio_por_id(mapa, 2);
    Territorio* inglaterra = obter_territorio_por_id(mapa, 3);
    
    // Configurar territórios da América do Sul
    *brasil = (Territorio){0, "Brasil", AMERICA_DO_SUL, 10, &jogadores[0]};
    *argentina = (Territorio){1, "Argentina", AMERICA_DO_SUL, 3, &jogadores[1]};
    
    // Configurar territórios da Europa
    *franca = (Territorio){2, "Franca", EUROPA, 8, &jogadores[0]};
    *inglaterra = (Territorio){3, "Inglaterra", EUROPA, 5, &jogadores[1]};

    // Conectar fronteiras
    conectar_territorios_por_id(mapa, 0, 1); // Brasil-Argentina
    conectar_territorios_por_id(mapa, 2, 3); // Franca-Inglaterra
}

int main() {
    // Semente para números aleatórios
    srand(time(NULL));

    // --- FASE 1: CRIAÇÃO DO MUNDO ---
    GameMap* mapa = criar_mapa(NUM_TERRITORIOS);
    if (!mapa) return 1;

    Jogador jogadores[NUM_JOGADORES];
    inicializar_jogo(mapa, jogadores);

    // --- FASE 3: DEFINIÇÃO DAS MISSÕES ---
    Missao missao_napoleao = {
        "Conquistar a America do Sul",
        vitoria_conquistar_america_do_sul
    };
    // (Poderíamos ter uma missão diferente para Alexandre)

    printf("Iniciando Jogo de War - TechNova Edition!\n");
    printf("Missão de Napoleão: %s\n", missao_napoleao.descricao);
    
    imprimir_mapa(mapa);
    
    // --- FASE 2: LÓGICA DE ATAQUE (Simulação de uma rodada) ---
    Territorio* brasil = obter_territorio_por_id(mapa, 0);
    Territorio* argentina = obter_territorio_por_id(mapa, 1);

    // Napoleão (dono do Brasil) ataca a Argentina
    realizar_ataque(brasil, argentina, rolagem_dados_padrao);
    
    imprimir_mapa(mapa);
    
    // --- FASE 3: VERIFICAÇÃO DE VITÓRIA ---
    printf("\nVerificando condição de vitória para Napoleão...\n");
    if (missao_napoleao.verificar_condicao(&jogadores[0], mapa)) {
        printf("VITÓRIA! Napoleão cumpriu sua missão!\n");
    } else {
        printf("Napoleão ainda não cumpriu sua missão.\n");
    }

    // --- LIMPEZA ---
    destruir_mapa(mapa);

    return 0;
}