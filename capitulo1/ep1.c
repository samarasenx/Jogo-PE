#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include<locale.h>

void limpar_tela();
int imprimir_menu();
int digita_escolha();
void novo_jogo(PERSONAGEM *jogador); //Historia Principal 
int continuar_jogo(PERSONAGEM *jogador);
void Introducao(PERSONAGEM *jogador);
void pause();
void cria_personagem(PERSONAGEM *jogador);
void salvar_personagem(PERSONAGEM *jogador, const char *filename);
void final();
int dado(int *jogador.sorte);
void status(PERSONAGEM *jogador);
void combate();
void integrantes();



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
    int defesa;   
    int amor;     
    int estilo;
    int nerd;  

}GABRIEL;

typedef struct LUCAS_   //vilao
{
    int carisma;   
    int ataque;   
    int amor;    

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
                status(PERSONAGEM *jogador);
                break;

            case 5:
                integrantes();
                break;

            default:
                printf("Escolha uma das opções disponíveis.\n");
        }
    }while(opcao!=5)

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
    printf("5. Integrantes\n");
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

void Introducao(PERSONAGEM *jogador) // Escrever introducao da historia aqui
{
    setlocale(LC_ALL, "Portuguese"); 

    printf("Você é %s, uma jovem em busca de um verao de tranquilidade antes de comecar a faculdade.\n", jogador.nome);
    pause();
    printf("Pelo visto, veio passar as suas ferias de verao aqui na Baia Azul!\n");
    pause();
    printf("Essa e uma cidade pitoresca, conhecida pelas suas praias douradas e pelo cheiro inconfundivel de maresia.\n");
    pause();
    printf("Um verdadeiro refúgio, longe da rotina da cidade e da pressao dos estudos.\n");
    pause();
    printf("A brisa suave do mar entra pela janela do seu quarto, trazendo o som distante das gaivotas e o murmúrio das ondas.\n");
    pause();
    printf("Voce desfez a mala sem pressa, sentindo o calor do sol beijar sua pele.\n");
    pause();
    printf("O verao em Baia Azul seria diferente, voce sente. Uma promessa de dias longos e ensolarados.\n");
    pause();
    printf("O que este novo cenario guardaria para voce? Amizades? Aventuras? Talvez ate um romance de verao...\n");
    pause();
    printf("A vida em Baia Azul parecia sussurrar segredos, e voce esta pronta para ouvi-los.\n");
    pause();
    printf("Com a mochila da praia em uma mao e o coracao cheio de uma expectativa incerta na outra, voce desce as escadas.\n");
    pause();
    printf("O cafe da manha da sua avo te espera, e depois... bem, depois o dia e todo seu.\n");
    pause();
    printf("O que voce faz primeiro neste primeiro dia de verao em Baia Azul?\n");
    pause();
    //agora vai ir pro ep 1
}

void novo_jogo(PERSONAGEM *jogador) // NaO TERMINEI
{
    setlocale(LC_ALL, "Portuguese");
    cria_personagem(&jogador);
    salvar_personagem(&jogador, "personagem.txt");
    printf("\nPronto agora você é já pode ir aproveitar suas férias de verão em Baía Azul!\n");
    limpar_tela();
    Introducao();
    limpar_tela();
    int escolha;
    GABRIEL heroi;
    LUCAS vilao;

    // começo das quests

    //quest 1
    printf("Para passar o tempo %s decidiu que precisava explorar um pouco por Baía Azul, mas não sabia ao certo se iria para a Biblioteca local ou para Praça\n",jogador.nome);
    printf("Escolha uma das opções: \n");
    printf("1. Biblioteca\n");
    printf("2. Praça\n");
    escolha=digita_escolha();
    if(escolha==1){
        jogador.inteligencia=2;
        printf("Após chegar na Biblioteca %s sem querer esbarrou em um homem alto, moreno e dos olhos azuis mais apaixonantes que %s já viu, que estava carregando uma pilha de livros. Logo depois de se esbarrarem Gabriel se apaixonou, e então eles começaram a conversar e se conhecer.\n", jogador.nome, jogador.nome);
        jogador.amor=1;
        vilao.amor=1;
        printf("Gabriel já encantado por %s, deu o livro favorito dele para %s, tendo em vista que os dois compatilham do mesmo interese por literatura\n"jogador.nome,jogador.nome);
        jogador->itens+=1;
        jogador->quests+=1;
    }
    if else(escolha==2){
        printf("Após chegar na Praça %s sem querer esbarrou em um homem alto, ruivo e com várias tatuagens no braço, assim que se encontraram Lucas gritou resmungando que uma pessoa sonsa e desmiolada pisou no pé dele.\n",jogador.nome);




        jogador->quests+=1;
    }
    limpar_tela();

    //quest 2

    

    salvar_jogo(&jogador);
}

void salvar_jogo(PERSONAGEM jogador)
{
    FILE *salvar= fopen("salvarjogo.txt", wt);

    if (salvar!= NULL)
    {
        fwrite(&progresso, sizeof(PROGRESSO), 1, salvar);
        fclose(salvar);
        printf("Seu progresso salvo com sucesso!\n");
    } 

    else
    {
        printf("Erro ao salvar o progresso.\n");
    }
}

int continuar_jogo(PERSONAGEM *jogador, PROGRESSO *progresso_salvo)
{    
    FILE *continuar = fopen("salvarjogo.txt", "rt");
    if(continuar != NULL) 
    {        
        int resultado = fread(progresso_salvo, sizeof(PROGRESSO), 1, continuar);        
        fclose(continuar);                
        if(resultado == 1) 
        {            
            printf("Progresso carregado!\n");            
            return 0;        
        }    
    }        
    printf("Nenhum progresso encontrado!\n");    
    return 1;
}

void criar_personagem(Personagem *jogador) // NAO TERMINEI
{
    setlocale(LC_ALL, "Portuguese");
    jogador.amor=0;
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
    printf("1. Ler, desenhar, estudar, tocar algum instrumento\n");
    printf("2. Mexer no celular, ficar o dia todo no Instagram ou não ter nenhum hobbie\n");
    if(digita_escolha()==1)
        jogador.inteligencia=2;
        printf("Vamos querer né! Não tem um hobbie legal, precisa mudar isso aí. Muito pouco repertório nota 3 para sua inteligência.\n");
    else
        jogador.inteligencia=5;
        printf("Isso aí diva estudiosa e esforçada, continue assim! A mais mais de toda Baía Azul nota 10 para a sua inteligência.\n");
    limpar_tela();
    
    printf("Qual dessas opções você mais se identifica?\n");
    pause();
    printf("1. Arrogante, mal educada, ignorante, sem noção.\n");
    printf("2. Comunicativa, empática, autentêntica e é uma pessoa amorosa.\n");
    if(digita_escolha()==1)
        jogador.carisma=3;
        printf("Você precisa melhorar como pessoa urgentemente. Ninguém te aguenta nota 3 de carisma para você.\n");
    else
        jogador.carisma=10;
        printf("Parabéns todos te amam você é a diva suprema, nota 10 para o seu carisma.\n");
    limpar_tela();

    printf("Rode um dado de 6 lados para ver o quanto de sorte você terá ao longo do seu verão.\n");
    pause();
    printf("Você vai começar com %d de sorte, mas ao longo do jogo isso pode mudar.\n", dado(jogador.sorte));
    limpar_tela();

    printf("Seu amor vai começar com zero, mas quem sabe ao longo do tempo que você vai passar em Baía Azul isso não mude...\n");
    limpar_tela();

}

void salvar_personagem(PERSONAGEM *jogador, const char *filename)
{



}

int dado(int *jogador.sorte)
{
    return *sorte = (rand()%6)+1;
}

void integrantes()
{
    printf("==============\n");
    printf("Samara Sena\n");
    printf("Raissa Barros\n");
    printf("Laura Silva\n");
    printf("==============\n");
}

void status(PERSONAGEM *jogador)
{    
   printf("\n=== ATRIBUTOS ATUAIS ===\n");    
   printf("Sorte: %d\n", jogador.sorte);    
   printf("Carisma: %d\n", jogador.carisma);    
   printf("Estilo: %d\n", jogador.estilo);    
   printf("Inteligência: %d\n", jogador.inteligencia);    
   printf("Amor: %d\n", jogador.amor);    
   printf("=======================\n\n");
}
