#include "map_adt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição real e privada da estrutura
struct GameMap {
    Territorio* territorios;
    int num_total_territorios;
};

GameMap* criar_mapa(int num_territorios) {
    GameMap* mapa = (GameMap*) malloc(sizeof(GameMap));
    if (!mapa) {
        perror("Falha ao alocar mapa");
        return NULL;
    }
    
    mapa->num_total_territorios = num_territorios;
    mapa->territorios = (Territorio*) calloc(num_territorios, sizeof(Territorio));
    if (!mapa->territorios) {
        perror("Falha ao alocar territórios");
        free(mapa);
        return NULL;
    }
    
    printf("Mapa criado com sucesso para %d territórios.\n", num_territorios);
    return mapa;
}

void destruir_mapa(GameMap* mapa) {
    if (mapa) {
        free(mapa->territorios);
        free(mapa);
        printf("Mapa destruído e memória liberada.\n");
    }
}

Territorio* obter_territorio_por_id(GameMap* mapa, int id) {
    if (mapa && id >= 0 && id < mapa->num_total_territorios) {
        return &mapa->territorios[id];
    }
    return NULL;
}

void conectar_territorios_por_id(GameMap* mapa, int id1, int id2) {
    Territorio* t1 = obter_territorio_por_id(mapa, id1);
    Territorio* t2 = obter_territorio_por_id(mapa, id2);

    if (t1 && t2) {
        if (t1->num_vizinhos < MAX_VIZINHOS) {
            t1->vizinhos[t1->num_vizinhos++] = t2;
        }
        if (t2->num_vizinhos < MAX_VIZINHOS) {
            t2->vizinhos[t2->num_vizinhos++] = t1;
        }
    }
}

void imprimir_mapa(const GameMap* mapa) {
    printf("\n==================== ESTADO ATUAL DO MAPA ====================\n");
    for (int i = 0; i < mapa->num_total_territorios; ++i) {
        Territorio* t = &mapa->territorios[i];
        printf("ID: %d | Território: %-10s | Dono: %-10s | Exércitos: %2d\n",
               t->id, t->nome, t->dono ? t->dono->nome : "Nenhum", t->exercitos);
    }
    printf("==============================================================\n");
}

int contar_territorios_do_jogador_no_continente(const GameMap* mapa, const Jogador* jogador, Continente c) {
    int count = 0;
    for (int i = 0; i < mapa->num_total_territorios; i++) {
        Territorio* t = &mapa->territorios[i];
        if (t->continente == c && t->dono->id == jogador->id) {
            count++;
        }
    }
    return count;
}

int total_territorios_no_continente(const GameMap* mapa, Continente c) {
    int count = 0;
    for (int i = 0; i < mapa->num_total_territorios; i++) {
        if (mapa->territorios[i].continente == c) {
            count++;
        }
    }
    return count;
}