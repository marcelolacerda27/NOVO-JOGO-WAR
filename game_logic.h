#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "map_adt.h"
#include <stdbool.h>

// Ponteiro de função para uma estratégia de rolagem de dados
typedef int (*EstrategiaDeDados)(int num_exercitos);

// Função principal de ataque
bool realizar_ataque(Territorio* atacante, Territorio* defensor, EstrategiaDeDados estrategia);

// Estratégia de rolagem de dados padrão
int rolagem_dados_padrao(int num_exercitos);

#endif // GAME_LOGIC_H