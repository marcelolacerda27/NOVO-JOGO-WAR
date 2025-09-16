#ifndef GAME_MAP_H
#define GAME_MAP_H

#define MAX_VIZINHOS 10

// Enum para facilitar a identificação dos continentes
typedef enum {
    AMERICA_DO_SUL,
    EUROPA
    // Outros continentes podem ser adicionados aqui
} Continente;

// Estrutura para representar um jogador
typedef struct Jogador {
    int id;
    char nome[50];
} Jogador;

// A estrutura fundamental: o Território
typedef struct Territorio {
    int id;
    char nome[50];
    Continente continente;
    int exercitos;
    Jogador* dono; // Ponteiro para o jogador que domina o território
    struct Territorio* vizinhos[MAX_VIZINHOS];
    int num_vizinhos;
} Territorio;

#endif // GAME_MAP_H