#include "mission.h"

// Verifica se o jogador conquistou todos os territórios da América do Sul
bool vitoria_conquistar_america_do_sul(const Jogador* jogador, const GameMap* mapa) {
    int total_as = total_territorios_no_continente(mapa, AMERICA_DO_SUL);
    int jogador_tem_as = contar_territorios_do_jogador_no_continente(mapa, jogador, AMERICA_DO_SUL);
    
    return total_as > 0 && total_as == jogador_tem_as;
}