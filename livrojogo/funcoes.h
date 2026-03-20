#ifndef FUNCOES_H 
#define FUNCOES_H 

void limpar_tela();
int imprimir_menu();
int digita_escolha();
void novo_jogo(PERSONAGEM *jogador);
int continuar_jogo(PERSONAGEM *jogador);
void Introducao();
void pause();
void cria_personagem(PERSONAGEM *jogador);
void salvar_jogo(PERSONAGEM *jogador);
void salvar_personagem(PERSONAGEM *jogador, const char *filename);
int carregar_jogo(PERSONAGEM *jogador);
void final(PERSONAGEM *jogador);  
void status(PERSONAGEM *jogador);
void integrantes();
void digitar(const char *texto, int velocidade);
void jogar_capitulo(PERSONAGEM *jogador);
void mostrar_escolhas(int capitulo);
void processar_escolha(PERSONAGEM *jogador, int escolha);
void combate(PERSONAGEM *jogador, GABRIEL *heroi, LUCAS *vilao);

void capitulo1(PERSONAGEM *jogador);
void capitulo2(PERSONAGEM *jogador);
void capitulo3(PERSONAGEM *jogador);
void capitulo4(PERSONAGEM *jogador);
void capitulo5(PERSONAGEM *jogador);
void capitulo6(PERSONAGEM *jogador);

#endif
