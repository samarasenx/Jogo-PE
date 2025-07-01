#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include<locale.h>

void limpar_tela();
int imprimir_menu();
int digita_escolha();
void novo_jogo(PERSONAGEM *jogador);
void continuar_jogo(PERSONAGEM *jogador);
void Introducao();
void pause();
void cria_personagem(PERSONAGEM *jogador);
void salvar_personagem(PERSONAGEM *jogador, const char *filename);
void final();


typedef struct PERSONAGEM_
{
    char nome[20];
    int sorte;
    int carisma;
    int estilo;
    int inteligencia;
    int amor;
    int itens[20]; //usar para guardar os presentes romanticos do gabriel
    int quests[20];

}PERSONAGEM;

typedef struct GABRIEL_   //heroi
{
    int sorte;      
    int carisma;   //carisma alto
    int amor;     //amor=0
    int estilo;  //estilo alto

}GABRIEL;

typedef struct LUCAS_   //vilao
{
    int sorte;
    int carisma;   //carisma baixo
    int estilo;   //estilo baixo
    int amor;    //amor=0

}LUCAS;


int main()
{
    setlocale(LC_ALL,"Portuguese");
    PERSONAGEM jogador;

    int opcao=imprimir_menu();
    
    srand(time(NULL)); //usar aleatoriedade no jogo(usar na variavel sorte)

    do{
        switch (opcao){
            case 1: 
                novo_jogo(&jogador);
                break;

            case 2:
                continuar_jogo(&jogador);
                break;

            case 3:
                printf("Saindo do jogo...\n");
                exit(0);
                break;

            case 4:



            default:
                printf("Escolha uma das opções disponíveis.\n");
        }
    }while(opcao!=4)

    return 0;
}



void limpar_tela()
{
    system("clear"); //no windows
	//syste("clear"); //no linux
}


int imprimir_menu()
{
    setlocale(LC_ALL,"Portuguese");
    int opcao;
    printf("================\n");
    printf("      MENU      \n");
    printf("================\n");
    printf("1. Novo Jogo\n");
    printf("2. Continuar\n");
    printf("3. Sair\n");
    printf("4. Status\n");
    printf("Escolha uma opção: ");
    scanf("%d",&opcao);
    limpar_tela();
    return opcao;
}

int digita_escolha() // usar nas escolhas do jogador
{
	int escolha;
	scanf("%d", &escolha);
	return escolha;
}

void final()
{


}

// Função para pausar e esperar que o usuário pressione Enter
void pause()
{
    printf("\nPressione ENTER para continuar...");
    getchar(); // Captura o newline deixado pelo scanf
    getchar(); // Espera o ENTER do usuário
}

void Introducao() // escrever introducao da historia aqui FAZER
{
    setlocale(LC_ALL, "Portuguese");
    
    printf("Voce eh %s, ......", jogador.nome);
    pause();
}

void novo_jogo(PERSONAGEM *jogador) // NaO TERMINEI
{
    setlocale(LC_ALL, "Portuguese");
    cria_personagem(&jogador);
    salvar_personagem(&jogador, "personagem.txt");
    printf("\nPronto agora você é já pode ir aproveitar suas férias de verão em Baía Azul!\n");
    


}

void continuar_jogo(PERSONAGEM *jogador)
{



}

void criar_personagem(Personagem *jogador) // NAO TERMINEI
{
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o nome do seu personagem: ");
    fgets(jogador->nome, 20, stdin); //usar seta pois é ponteiro
    limpar_tela()
    printf("Para começar o verão arrasando escolha quais roupas você vai querer disfilar pela cidade de Baía Azul.\n");
    pause();
    printf("Qual desses looks você vai querer usar no seu primeiro dia de verão?\n");
    printf("1. Sapatênis, calça cargo e um casaco de capuz.\n");
    printf("2. Óculos de sol, vestido e sandália.\n");
    if(digita_escolha()==1)
        jogador.estilo=3;
        printf("Nossa muito fubanga, melhore seu estilo agora!!! Infelizmente você não é estilosa nota 3 para seu estilo.\n");
    else
        jogador.estilo=10;
        printf("Arrasouuuu!!! A mais estilosa que Baía Azul jáviu!! Com os seus incríveis 10 no quesito estilo.\n");
    limpar_tela();
    printf("Agora conte mais sobre seus hobbies favoritos\n");
    pause();
    printf("O que você mais gosta de fazer no seu tempo livre?\n");
    printf("1. Ler, desenhar, estudar, tocar algum instrumento\n\n");
    printf("2. Mexer no celular, ficar o dia todo no Instagram ou não ter nenhum hobbie\n");
    if(digita_escolha()==1)
        jogador.inteligencia=3;
        printf("Vamos querer né! Não tem um hobbie legal, precisa mudar isso aí. Muito pouco repertório nota 3 para sua inteligência.\n");
    else
        jogador.inteligencia=10;
        printf("Isso aí diva estudiosa e esforçada, continue assim! A mais mais de toda Baía Azul nota 10 para a sua inteligência.\n");
        limpar_tela();
}

void salvar_personagem(PERSONAGEM *jogador, const char *filename)
{



}