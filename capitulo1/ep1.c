#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include<locale.h>
#include<windows.h>

void limpar_tela();
int imprimir_menu();
int digita_escolha();
void novo_jogo(PERSONAGEM *jogador); //Historia Principal 
int continuar_jogo(PERSONAGEM *jogador);
void Introducao(PERSONAGEM *jogador);
void pause();
void cria_personagem(PERSONAGEM *jogador);
void salvar_personagem(PERSONAGEM *jogador, const char *filename);
void final(PERSONAGEM *jogador, GABRIEL *heroi, LUCAS *vilao);
int dado(int *jogador.sorte);
void status(PERSONAGEM *jogador);
void combate(PERSONAGEM *jogador, GABRIEL *heroi, LUCAS *vilao);
void integrantes();
void lerCapitulo(const char *chap);



typedef struct PERSONAGEM_
{
    char nome[20];
    int sorte;
    int carisma;
    int estilo;
    int inteligencia;
    int amorHeroi;
    int amorVilao;
    int itens[10]; //usar para guardar os presentes romanticos do gabriel e lucas
    int quests[5];

}PERSONAGEM;

typedef struct GABRIEL_   //heroi
{     
    int defesa;   
    int amor;     
    int estilo;
    int nerd;  

}GABRIEL;

typedef struct LUCAS_   //vilao carismatico que vai tentar roubar a PERSONAGEM do heroi
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

void final(PERSONAGEM *jogador, GABRIEL *heroi, LUCAS *vilao)
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
    jogador.amorHeroi=0;
    jogador.amorVilao=0;
    heroi.amor=0;
    vilao.amor=0;
    // começo das quests

    //quest 1
    printf("Para passar o tempo %s decidiu que precisava explorar um pouco por Baía Azul, mas não sabia ao certo se iria para a Biblioteca local ou para Praça\n",jogador.nome);
    printf("Escolha uma das opções: \n");
    printf("1. Biblioteca\n");
    printf("2. Praça\n");
    escolha=digita_escolha();
    if(escolha==1){
        jogador.inteligencia+=2;
        printf("Após chegar na Biblioteca %s sem querer esbarrou em um homem alto, moreno e dos olhos azuis mais apaixonantes que %s já viu, que estava carregando uma pilha de livros. Logo depois de se esbarrarem Gabriel se apaixonou, e então eles começaram a conversar e se conhecer.\n", jogador.nome, jogador.nome);
        jogador.amorHeroi+=1;
        heroi.amor+=1;
        heroi.inteligencia+=2;
        printf("Gabriel já encantado por %s, deu o livro favorito dele para %s, tendo em vista que os dois compatilham do mesmo interese por literatura. Guarde na sua bolsa.\n",jogador.nome,jogador.nome);
        jogador->itens+=1;
        printf("Adicionou 1 item a sua bolsa, e a capacidade total da bolsa é de 10 itens.\n");
        if(jogador.sorte>3){
            printf("A sorte está a seu favor! Gabriel gostou muito de você e para mostrar essa adimiração te deu um colar de ondas, para você sempre lembrar dele ao ver o mar. Guarde na sua bolsa.\n");
            printf("Adicionou 1 item a sua bolsa, e a capacidade total da bolsa é de 10 itens.\n");
            jogador->itens+=1;
            jogador.amorHeroi+=1;
            heroi.amor+=1;
        }
        jogador->quests+=1;
    }
    else if(escolha==2){
        printf("Após chegar na Praça %s sem querer esbarrou em um homem alto, ruivo e com várias tatuagens no braço, assim que se encontraram Lucas gritou resmungando que uma pessoa sonsa e desmiolada pisou no pé dele. Logo depois quando ele olhou para %s, e viu o quanto %s é bem de aparência, falou que até que não é tão sonsa assim...\n",jogador.nome,jogador.nome,jogador.nome);
        vilao.amor+=1;
        printf("Lucas tinha um jeito esquisito de demonstrar as emoções. O que confundiu muito %s, pois ele falou que tinha achado a roupa de %s muito feia e começou a implicar com %s.\n",jogador.nome,jogador.nome,jogador.nome);
        pause();
        printf("Mal sabia %s que Lucas estava começando a se apaixonar...",jogador.nome);
        pause();
        printf("Lucas deu uma flor que pegou do jardim da praça para %s, e falou que nunca tinha visto alguém tão chato ficar bem com uma flor no cabelo.\n",jogador.nome);
        printf("Escolha agora o que fazer com essa flor. Lembrando que a capacidade total da bolsa é de 10 itens.\n");
        printf("1. Guardar\n");
        printf("2. Não guardar\n");
        int subescolha = digita_escolha();
        if(subescolha==1){
            printf("Adicionou 1 item a sua bolsa, e a capacidade total da bolsa é de 10 itens.\n");
            jogador.amorVilao+=1;
            jogador.estilo+=1;
            jogador->itenss+=1;
            vilao.amor+=1;
        }
        else if(subescolha==2)
            continue;
        else
            printf("Escolha errada, tentar novamente.");
        jogador->quests+=1;
    }
    else
        printf("Escolha errada, tentar novamente.");


    limpar_tela();

    //quest 2
    if (escolha == 1) 
    {
    printf("Voltando para casa de sua avó, %s recebeu uma ligação de um número desconhecido...\n", jogador.nome);
    
        while (escolha == 1) {
            //continuação da história se o jogador foi para a BIBLIOTECA
            printf("Você atende o telefone e escuta a voz de Gabriel do outro lado...\n");
            pause();
            printf("Gabriel chamou %s para um encontro no restaurante.\n",jogador.nome);
            printf("Escolha uma dessas opções: \n");
            printf("1. Sair com Gabriel\n");
            printf("2. Não sair com Gabriel\n");
            subescolha=digita_escolha();
            if(subescolha==1){
                jogador.amorHeroi+=1;
                heroi.amor+=1;
                printf("Gabriel chegou no encontro com um buque de flores para te dar.\n");
                jogador->itenss+=1;
                printf("Adicionou 1 item a sua bolsa, e a capacidade total da bolsa é de 10 itens.\n");
                pause();
                printf("Vocês tiveram um ótimo encontro, ele foi super carinhoso e amoroso com você, aos poucos %s vai se apaixonando cada vez mais por Gabriel.\n");
            }
            else if(subescolha==2)
                continue;
            else
                printf("Escolha errada, tentar novamente.");
            limpar_tela();
            break; // se não quiser loop infinito, use break ou alguma condição de saída
        }
        jogador->quests+=1;
    } else if (escolha == 2) {
        printf("Voltando para casa, %s encontra um bilhete estranho deixado por Lucas...\n", jogador.nome);

        while (escolha == 2) {
            // Continuação da história se o jogador foi para a PRAÇA
            printf("O bilhete dizia: Ainda quero te ver usando aquela flor mesmo você sendo meio esquisita...\n");
            jogador.amorVilao+=1;
            pause();
            printf("%s sentiu um mix de emoções naquele momento,mas gostou do bilhete.\n",jogador.nome);
            printf("Depois quando foi olhar o verso do bilhete viu que tinha escrito algo. Estava escrito: %s, você gostaria de sair comigo para andar de moto um pouco?\n",jogador.nome);
            printf("Escolha uma das opções: ");
            printf("1. Sair com Lucas\n");
            printf("2. Não sair com Lucas\n");
            subescolha=digita_escolha();
            if(subescolha==1){
                jogador.amorVilao+=1;
                vilao.amor+=1;
                printf("Vocês tiveram um encontro meio estranho mas bom, Lucas passou o caminho todo implicando com você e zombando do seu estilo.\n");
                printf("Lucas deu sua jaqueta de couro para %s ficar, já que estava fazendo muito frio a noite naquele momento.\n",jogador.nome);
                jogador->itenss+=1;
                vilao.estilo+=2;
                jogador.estilo+=2;
            }
            else if(subescolha==2)
                continue;
            else
                printf("Escolha errada, tentar novamente.");
            limpar_tela();
            break; // ou outro critério de saída
        }
        jogador->quests+=1;
    }
    else
        printf("Escolha errada, tentar novamente.");


    limpar_tela();

    //quest 3
    
    printf("No outro dia de manhã, você decidiu ir a Praia ver o mar e pegar um pouco de sol.\n");
    if(escolha==1)
    {  //conhecer lucas na praia
        printf("Enquanto %s estava observando o mar, surgiu no meio do nada um homem alto, ruivo e com várias tatuagens no braço, e esbarrou em %s.\n", jogador.nome,jogador.nome);
        printf("Assim que Lucas esbarrou ele gritou resmungando que uma pessoa sonsa e desmiolada pisou no pé dele. Logo depois quando ele olhou para %s, e viu o quanto %s é bem de aparência, falou que até que não é tão sonsa assim...\n",jogador.nome,jogador.nome);
        pause();
        printf("Você é nova por aqui né, sou a primeira pessoa que você conheceu por aqui? Com certeza sou a mais bonita né pode falar.\n");
        pause();
        printf("%s diz que não, a primeira pessoa que %s conheceu foi Gabriel.",jogador.nome,jogador.nome);
        printf("O QUE??? O GABRIEL?? Aquele nerd esquisito! Você precisa urgentemente trocar esse seu ciclo de amizade. Vamos começar assim, primeiro eu viro seu amigo, você para de falar com o Gabriel e nós namoramos! Uma linda história você não achar?\n");
        printf("Escolha uma opção: ");
        printf("1. Perguntar o por que de o Lucas e o Gabriel se odiarem\n");
        printf("2. Se tornar amiga de Lucas\n");
        subescolha=digita_escolha();
        if(subescolha==1)
        {
           printf("(Acusar de assasinato)");
            pause();
            if(jogador.inteligencia<4){
                printf("(falar que o jogador acredita nisso)");

            }
            else{
                printf("(falar que o jogador nao acredita nisso)");
            }
        }
        else if(subescolha==2){
            vilao.amor+=1;
            jogador.amorVilao+=1;
            // ganhar item

        }
        else
           printf("Escolha errada, tentar novamente."); 

       jogador->quests+=1; 
    }
    else if(escolha==2){ //  conhecer gabriel na praia
        printf("Enquanto %s estava observando o mar, surgiu no meio do nada um homem alto, oreno e dos olhos azuis mais apaixonantes que %s já viu, e esbarrou em %s sem querer.\n", jogador.nome,jogador.nome);
        printf("Assim que Gabriel esbarrou (falar coisas boa e que ele é educado e carinhoso).\n",jogador.nome,jogador.nome);
        pause();
        printf("Você é nova por aqui né, sou a primeira pessoa que você conheceu por aqui?\n");
        pause();
        printf("%s diz que não, a primeira pessoa que %s conheceu foi Lucas.",jogador.nome,jogador.nome);
        printf("O QUE??? O LUCAS?? Aquele motoqueiro desmiolado! Me desculpe por ter me alterado desse é que o Lucas é um completo imbecil. Você precisa urgentemente trocar esse seu ciclo de amizade. Vamos começar assim, primeiro eu viro seu amigo, você para de falar com o Lucas e nós podemos sair que tal?\n");
        printf("Escolha uma opção: ");
        printf("1. Perguntar o por que de o Lucas e o Gabriel se odiarem\n");
        printf("2. Se tornar amiga de Gabriel\n");
        subescolha=digita_escolha();
        if(subescolha==1){
            printf("(Acusar de assasinato)");
            pause();
            if(jogador.inteligencia>4){
                printf("(falar que o jogador acredita nisso)");

            }
            else{
                printf("(falar que o jogador nao acredita nisso)");
            }

        }
        else if(subescolha==2){
            heroi.amor+=1;
            jogador.amorHeroi+=1;
            // ganhar item

        }
        else
           printf("Escolha errada, tentar novamente."); 

        jogador->quests+=1;
    }
    else
        printf("Escolha errada, tentar novamente.");


    limpar_tela();

    //quest 4   Combate

    combate(jogador,heroi,perdonagem);
    jogador->quests+=1;

    limpar_tela();

    //quest 5   final
    final(jogador,heroi,vilao);
    jogador->quests+=1;

    limpar_tela();


    salvar_jogo(&jogador);
    salvar_personagem(PERSONAGEM *jogador, const char *filaname);
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
            printf("Seu progresso carregado!\n");            
            return 0;        
        }    
    }        
    printf("Nenhum progresso encontrado!\n");    
    return 1;
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
        jogador.estilo=2;
        printf("Nossa muito fubanga, melhore seu estilo agora!!! Infelizmente você não é estilosa nota 3 para seu estilo.\n");
    else
        jogador.estilo=5;
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
    printf("Você vai começar com %d de sorte, mas ao longo do jogo isso pode mudar.\n", jogador.sorte=dado(jogador.sorte));
    limpar_tela();

    printf("Seu amor vai começar com zero, mas quem sabe ao longo do tempo que você vai passar em Baía Azul isso não mude...\n");
    limpar_tela();

}

void salvar_personagem(PERSONAGEM *jogador, const char *filename)
{
    FILE *fp;
    fp=fopen(filename,"wb");
    if(fp==NULL){
        printf("Erro");
    }
    else{
        fwrite(jogador,sizeof(PERSONAGEM),1,fp);
    }
    fclose(fp);

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

void lerCapitulo(const char *chap)
{
    FILE *cap = fopen(chap, "rt"); // abre o arquivo de texto    
    if (!cap) {        
        printf("Erro ao abrir o arquivo %s\n", chap);    
    }
    char linha[256];    
    while (fgets(linha, sizeof(linha), cap)) {        
        digitar(linha,  30); // imprime com efeito de digitação    
    }
    fclose(cap);

}

void combate(PERSONAGEM *jogador, GABRIEL *heroi, LUCAS *vilao)
{






}