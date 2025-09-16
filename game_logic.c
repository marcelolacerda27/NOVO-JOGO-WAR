#include "game_logic.h"
#include <stdio.h>
#include <stdlib.h>

int rolagem_dados_padrao(int num_exercitos) {
    if (num_exercitos <= 0) return 0;
    int forca_total = 0;
    // Simula rolar um dado para cada exército (simplificado)
    for(int i = 0; i < num_exercitos; ++i) {
        forca_total += (rand() % 6 + 1);
    }
    return forca_total;
}

bool realizar_ataque(Territorio* atacante, Territorio* defensor, EstrategiaDeDados estrategia) {
    printf("\n--- BATALHA: %s ataca %s! ---\n", atacante->nome, defensor->nome);

    if (atacante->dono == defensor->dono) {
        printf("Ataque inválido: Territórios do mesmo jogador.\n");
        return false;
    }
    if (atacante->exercitos < 2) {
        printf("Ataque falhou: %s precisa de no mínimo 2 exércitos para atacar.\n", atacante->nome);
        return false;
    }

    int forca_ataque = estrategia(atacante->exercitos - 1); // Deixa 1 de guarnição
    int forca_defesa = estrategia(defensor->exercitos);

    printf("Força de Ataque de %s: %d\n", atacante->dono->nome, forca_ataque);
    printf("Força de Defesa de %s: %d\n", defensor->dono->nome, forca_defesa);

    if (forca_ataque > forca_defesa) {
        printf(">> VITÓRIA DO ATACANTE! %s conquistou %s.\n", atacante->dono->nome, defensor->nome);
        defensor->dono = atacante->dono;
        defensor->exercitos = 1;
        atacante->exercitos -= 1;
        return true;
    } else {
        printf(">> VITÓRIA DO DEFENSOR! %s repeliu o ataque.\n", defensor->dono->nome);
        atacante->exercitos = 1; // Perde todos os exércitos menos um
        return false;
    }
}