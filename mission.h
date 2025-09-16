#ifndef MISSION_H
#define MISSION_H

#include "map_adt.h"
#include <stdbool.h>

// A estrutura da Missão
typedef struct Missao {
    char descricao[200];
    // Ponteiro de função que verifica se a missão foi cumprida
    bool (*verificar_condicao)(const Jogador* jogador, const GameMap* mapa);
} Missao;

// Exemplo de uma condição de vitória
bool vitoria_conquistar_america_do_sul(const Jogador* jogador, const GameMap* mapa);

#endif // MISSION_H