#ifndef MAP_ADT_H
#define MAP_ADT_H

#include "game_map.h"
#include <stdbool.h>

// Declaração opaca do nosso TAD. A implementação fica escondida no .c
typedef struct GameMap GameMap;

// --- Funções da Interface ---

// Aloca e inicializa a estrutura do mapa
GameMap* criar_mapa(int num_territorios);

// Libera toda a memória associada ao mapa
void destruir_mapa(GameMap* mapa);

// Obtém um ponteiro para um território específico pelo seu ID
Territorio* obter_territorio_por_id(GameMap* mapa, int id);

// Conecta dois territórios, tornando-os vizinhos
void conectar_territorios_por_id(GameMap* mapa, int id1, int id2);

// Imprime o estado atual de todos os territórios no mapa
void imprimir_mapa(const GameMap* mapa);

// Conta quantos territórios um jogador possui em um continente
int contar_territorios_do_jogador_no_continente(const GameMap* mapa, const Jogador* jogador, Continente c);

// Retorna o número total de territórios em um continente específico
int total_territorios_no_continente(const GameMap* mapa, Continente c);

#endif // MAP_ADT_H