#ifndef PERSONAGEM_H
#define PERSONAGEM_H

typedef struct {
    char nome[TAM_NOME];
    int sorte;
    int carisma;
    int estilo;
    int inteligencia;
    int amorHeroi;
    int amorVilao;
    int itens[MAX_ITENS];
    int num_itens;
    int capitulo_atual;
    int caminho; // 0 = Gabriel, 1 = Lucas
    int quests;
} PERSONAGEM;

#endif
