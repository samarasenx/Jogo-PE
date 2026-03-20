#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#define MAX_ITENS 6
#define MAX_CAPITULOS 6
#define TAM_NOME 50

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
    int jogo_iniciado; // 0 = não iniciado, 1 = iniciado
} PERSONAGEM;

typedef struct {
    int defesa;
    int amor;
    int inteligencia;
} GABRIEL;

typedef struct {
    int estilo;
    int ataque;
    int amor;
} LUCAS;

GABRIEL heroi = {5, 0, 7};
LUCAS vilao = {8, 6, 0};

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
int final(PERSONAGEM *jogador);  
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

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");
    PERSONAGEM jogador;
    int opcao;
    
    srand(time(NULL));
    jogador.jogo_iniciado = 0;
    
    do {
        limpar_tela();
        opcao = imprimir_menu();
        
        switch (opcao) {
            case 1: 
                novo_jogo(&jogador);
                break;
            case 2:
                if (!continuar_jogo(&jogador)) {
                    pause();
                }
                break;
            case 3:
                status(&jogador);
                break;
            case 4:
                integrantes();
                pause();
                break;
            case 5:
                printf("Saindo do jogo...\n");
                exit(0);
                break;
            default:
                printf("Escolha inválida. Tente novamente.\n");
                pause();
        }
    } while (opcao != 5);
    
    return 0;
}

void limpar_tela() {
    system("cls");
}

int imprimir_menu() {
    int opcao;
    digitar("\n╔════════════════╗\n", 10);
    digitar("║ MENU PRINCIPAL ║\n", 15);
    digitar("╚════════════════╝\n", 10);
    digitar("1. Novo Jogo\n", 40);
    digitar("2. Continuar\n", 40);
    digitar("3. Status\n", 40);
    digitar("4. Integrantes\n", 40);
    digitar("5. Sair\n", 40);
    digitar("Escolha uma opção: ", 30);
    
    scanf("%d", &opcao);
    getchar();
    return opcao;
}

int digita_escolha() {
    int escolha;
    printf("\nEscolha: ");
    scanf("%d", &escolha);
    getchar(); 
    return escolha;
}

void pause() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void novo_jogo(PERSONAGEM *jogador) {
    limpar_tela();
    jogador->nome[0] = '\0';  // Inicializa o nome como string vazia
    jogador->sorte = (rand() % 6) + 1;
    jogador->carisma = 5;
    jogador->estilo = 5;
    jogador->inteligencia = 5;
    jogador->amorHeroi = 0;
    jogador->amorVilao = 0;
    jogador->num_itens = 0;
    jogador->capitulo_atual = 1;
    jogador->caminho = -1;
    jogador->quests = 0;
    jogador->jogo_iniciado = 0; // Jogo ainda não iniciado
    
        for(int i = 0; i < MAX_ITENS; i++) {
            jogador->itens[i] = 0;
        }
    cria_personagem(jogador);
    jogador->jogo_iniciado = 1; 
    
    printf("\nPronto! Você está pronta para começar suas férias em Baía Azul!\n");
    pause();
    
    Introducao();
    jogar_capitulo(jogador);
}

void Introducao() {
    limpar_tela();
    digitar("=== INTRODUÇÃO ===\n\n", 30);
    digitar("Você é uma jovem em busca de um verão de tranquilidade antes de começar a faculdade...\n", 30);
    digitar("Pelo visto, veio passar as suas férias de verão aqui na Baía Azul!\n", 30);
    digitar("Essa é uma cidade pitoresca, conhecida pelas suas praias douradas e pelo cheiro inconfundível de maresia...\n\n", 30);
    digitar("A brisa suave do mar entra pela janela do seu quarto...\n", 30);
    digitar("Trazendo o som distante das gaivotas e o murmúrio das ondas...\n\n", 30);
    digitar("Você desfez a mala sem pressa, sentindo o calor do sol beijar sua pele...\n", 30);
    digitar("O verão em Baía Azul seria diferente, você sente...\n", 30);
    digitar("Uma promessa de dias longos e ensolarados...\n\n", 30);
    pause();
}

void cria_personagem(PERSONAGEM *jogador) {
    limpar_tela();
    digitar("=== CRIAR PERSONAGEM ===\n\n", 30);
    digitar("Digite o nome da sua personagem: ", 30); 
    fgets(jogador->nome, TAM_NOME, stdin);
        for(int i = 0; i < TAM_NOME; i++) {
            if(jogador->nome[i] == '\n') {
                jogador->nome[i] = '\0';
                break;
            }
        }
    srand(time(NULL)); 
    jogador->sorte = (rand() % 6) + 1;  // Gera número aleatório entre 1 e 6
    

    digitar("\nPersonagem criada com sucesso!\n", 30);
    printf("Nome: %s\n", jogador->nome);
    printf("Sorte inicial: %d\n", jogador->sorte);
    
    digitar("\nAtributos iniciais:\n", 30);
    printf("- Carisma: %d\n", jogador->carisma);
    printf("- Estilo: %d\n", jogador->estilo);
    printf("- Inteligência: %d\n", jogador->inteligencia);
    
    pause();
}

void jogar_capitulo(PERSONAGEM *jogador) {
    while (jogador->capitulo_atual <= MAX_CAPITULOS) {
        limpar_tela();
        printf("=== CAPÍTULO %d ===\n\n", jogador->capitulo_atual);
        
        switch(jogador->capitulo_atual) {
            case 1: capitulo1(jogador); break;
            case 2: capitulo2(jogador); break;
            case 3: capitulo3(jogador); break;
            case 4: capitulo4(jogador); break;
            case 5: capitulo5(jogador); break;
            case 6: 
                capitulo6(jogador); 
                return; // Retorna ao menu principal após o capítulo 6
        }
        
        if (jogador->capitulo_atual < MAX_CAPITULOS) {
            printf("\n\nO que deseja fazer?\n");
            printf("1. Continuar para o próximo capítulo\n");
            printf("2. Salvar e sair\n");
            
            int escolha = digita_escolha();
            if (escolha == 2) {
                salvar_jogo(jogador);
                return;
            }
            
            jogador->capitulo_atual++;
        } else {
            jogador->capitulo_atual++; // Marca como terminado
        }
    }
}

void capitulo1(PERSONAGEM *jogador) {
    limpar_tela();
    digitar("=== CAPÍTULO 1 ===\n\n", 30);
    digitar("Para passar o tempo, você decidiu que precisava explorar um pouco Baía Azul, mas não sabia ao certo se iria para a Biblioteca local ou para Praça.\n", 30);
    digitar("Escolha uma das opções: \n", 30);
    digitar("1. Biblioteca\n", 30);
    digitar("2. Praça\n", 30);
    
    int escolha = digita_escolha();
    
    if (escolha == 1) {
        jogador->caminho = 0;
        jogador->inteligencia += 2;
        jogador->amorHeroi += 1;
        heroi.amor += 1;
        digitar("\n", 30);
        digitar("Após chegar na Biblioteca, você sem querer esbarrou em um homem alto, moreno e dos olhos azuis mais apaixonantes que você já viu, que estava carregando uma pilha de livros. Ele se apresentou, disse que seu nome era Gabriel, e assim que os olhos dele encontraram os seus, ele se apaixonou secretamente, então começaram a conversar e se conhecer.\n\n", 30);
        digitar("Gabriel, já encantado por você, lhe deu o livro favorito dele, tendo em vista que vocês dois compartilham do mesmo interesse por literatura. Guarde na sua bolsa.\n\n", 30);
        digitar("Adicionou 1 item a sua bolsa. A capacidade total da bolsa é de 10 itens.\n", 30);
        
        if (jogador->num_itens < MAX_ITENS) {
            jogador->itens[jogador->num_itens] = 1; // Livro
            jogador->num_itens++;
        }
        jogador->quests++;
    } 
    else {
        jogador->caminho = 1;
        jogador->estilo += 1;
        jogador->amorVilao += 1;
        vilao.amor += 1;
        digitar("\n", 30);
        digitar("Após chegar na Praça você sem querer esbarrou em um homem alto, ruivo e com várias tatuagens no braço. Assim que se encontraram, ele, que estava sendo chamado de Lucas pelos outros, gritou resmungando que uma pessoa sonsa e desmiolada pisou no pé dele. Logo depois, quando ele virou para te olhar e viu o quanto você é boa de aparência, falou que até que não é tão sonsa assim... Ele se apresentou e disse que seu nome era Lucas.\n\n", 30);
        digitar("Lucas tinha um jeito esquisito de demonstrar as emoções, o que te confundiu muito, pois ele falou que tinha achado a sua roupa muito feia e começou a implicar contigo.\n\n", 30);
        digitar("Mas Lucas estava começando a se apaixonar por você secretamente...\n\n", 30);
        digitar("Lucas te deu uma flor que pegou do jardim da praça e falou que nunca tinha visto alguém tão chato ficar bem com uma flor no cabelo.\n", 30);
        
        if (jogador->num_itens < MAX_ITENS) {
            jogador->itens[jogador->num_itens] = 2; // Flor
            jogador->num_itens++;
        }
        jogador->quests++;
    }
    pause();
}

void capitulo2(PERSONAGEM *jogador) {
    limpar_tela();
    digitar("=== CAPÍTULO 2 ===\n\n", 30);
    
    if (jogador->caminho == 0) {
        digitar("Voltando para casa de sua avó, você recebeu uma ligação de um número desconhecido...\n\n", 30);
        digitar("Você atende o telefone e escuta a voz de Gabriel do outro lado...\n\n", 30);
        digitar("Gabriel te chamou para um encontro no restaurante.\n\n", 30);
        digitar("Escolha uma dessas opções:\n", 30);
        digitar("1. Sair com Gabriel\n", 30);
        digitar("2. Não sair com Gabriel\n", 30);
        
        int escolha = digita_escolha();
        
        if (escolha == 1) {
            jogador->amorHeroi += 2;
            heroi.amor += 2;
            digitar("\nGabriel chegou no encontro com um buque de flores para te dar.\n\n", 30);
            digitar("Foi adicionado 1 item a sua bolsa e a capacidade da bolsa agorra é de 8 itens.\n\n", 30);
            digitar("Vocês tiveram um ótimo encontro, ele foi super carinhoso e amoroso contigo, e aos poucos você vai se apaixonando cada vez mais por Gabriel.\n", 30);
            
            if (jogador->num_itens < MAX_ITENS) {
                jogador->itens[jogador->num_itens] = 3; // Buquê
                jogador->num_itens++;
            }
        }
        jogador->quests++;
    } 
    else if (jogador->caminho == 1) 
    {
        digitar("Voltando para casa, você encontra um bilhete estranho deixado por Lucas...\n\n", 30);
        digitar("O bilhete dizia: Ainda quero te ver usando aquela flor, mesmo com você sendo meio esquisita...\n\n", 30);
        digitar("Você sentiu um mix de emoções naquele momento, mas gostou do bilhete.\n\n", 30);
        digitar("Depois, quando foi olhar o verso do bilhete, viu que tinha escrito algo. Estava escrito: você gostaria de sair comigo para andar de moto um pouco?\n\n", 30);
        digitar("Escolha uma das opções:\n", 30);
        digitar("1. Sair com Lucas\n", 30);
        digitar("2. Não sair com Lucas\n", 30);
        
        int escolha = digita_escolha();
        limpar_tela();
        
        if (escolha == 1) {
            jogador->amorVilao += 2;
            vilao.amor += 2;
            digitar("\nVocês tiveram um encontro meio estranho, mas bom, com Lucas passando o caminho todo implicando com você e zombando do seu estilo.\n\n", 30);
            digitar("Lucas deu sua jaqueta de couro para você ficar, já que estava fazendo muito frio a noite naquele momento.\n", 30);
            
            if (jogador->num_itens < MAX_ITENS) {
                jogador->itens[jogador->num_itens] = 4; // Jaqueta
                jogador->num_itens++;
            }
        }
        jogador->quests++;
    }
    pause();
}

void capitulo3(PERSONAGEM *jogador) {
    limpar_tela();
    digitar("=== CAPÍTULO 3 ===\n\n", 30);
    
    if (jogador->caminho == 0) {
        digitar("No outro dia de manhã, você decidiu ir a Praia ver o mar e pegar um pouco de sol.\n\n", 30);
        digitar("Enquanto estava observando o mar, surgiu no meio do nada um homem alto, ruivo e com várias tatuagens no braço, e esbarrou em você.\n", 30);
        digitar("Assim que Lucas esbarrou, ele gritou resmungando que uma pessoa sonsa e desmiolada pisou no pé dele. Logo depois, quando ele te olhou e viu o quanto você é bem de aparência, falou que até que não é tão sonsa assim...\n\n", 30);
        digitar("\"Você é nova por aqui né, sou a primeira pessoa que você conheceu por aqui? Com certeza sou o mais bonito né, pode falar.\" diz Lucas.\n\n", 30);
        digitar("Você diz que não, a primeira pessoa que conheceu foi Gabriel.\n\n", 30);
        digitar("\"O QUE??? O GABRIEL?? Aquele nerd esquisito! Você precisa urgentemente trocar esse seu ciclo de amizade. Vamos começar assim, primeiro eu viro seu amigo, você para de falar com o Gabriel e nós namoramos! Uma linda história, você não acha?\" diz Lucas.\n\n", 30);
        digitar("Escolha uma opção:\n", 30);
        digitar("1. Perguntar o por que de o Lucas e o Gabriel se odiarem\n", 30);
        digitar("2. Se tornar amiga de Lucas\n", 30);
    } 
    else if(jogador->caminho == 1){
        digitar("No outro dia de manhã, você decidiu ir a Praia ver o mar e pegar um pouco de sol.\n\n", 30);
        digitar("Enquanto você estava observando o mar, surgiu no meio do nada um homem alto, moreno e dos olhos azuis mais apaixonantes que você já viu, e que esbarrou em ti sem querer.\"\n\n", 30);
        digitar("Assim que ele esbarrou em você, ele te pediu desculpas e foi muito educado perguntando se você se machucou e precisava de ajuda. Você se encantou com isso.\n\n", 30);
        digitar("\"Você é nova por aqui né, sou a primeira pessoa que você conheceu? Eu me chamo Gabriel.\" diz Gabriel.\n\n", 30);
        digitar("Você diz que não, a primeira pessoa que conheceu foi Lucas, mas que era um prazer.\n\n", 30);
        limpar_tela();
        digitar("\"O QUE??? O LUCAS?? Aquele motoqueiro desmiolado! - Ele percebeu que elevou a voz - Me desculpe por ter me alterado desse jeito, é que o Lucas é um completo imbecil. Você precisa urgentemente trocar esse seu ciclo de amizade. Vamos começar assim, primeiro eu viro seu amigo, depois você para de falar com o Lucas e nós podemos sair, que tal?\" diz Gabriel.\n\n", 30);
        digitar("Escolha uma opção:\n", 30);
        digitar("1. Perguntar o por que de o Lucas e o Gabriel se odiarem\n", 30);
        digitar("2. Se tornar amiga de Gabriel\n", 30);
    }

    int escolha = digita_escolha();
    limpar_tela();
    
    if (jogador->caminho == 0) {
        if (escolha == 1) {
            digitar("\nSeu sorriso sumiu, substituído por uma expressão sombria. 'Você fala de Gabriel?', ele sussurrou, e o nome dele parecia amargo em sua boca. 'Ele é o queridinho da Baía Azul, não é? O salva-vidas perfeito.' Lucas desviou o olhar para o mar e um arrepio subiu pela sua espinha. 'Mas a verdade é que Gabriel não é quem parece ser. Ele... ele assassinou Melissa.' O ar ficou pesado. 'Melissa era uma menina daqui e a cidade sabe a verdade. Ninguém fala abertamente, mas todos sabem que foi ele.'\n", 30);
            jogador->quests++;
        } else {
            jogador->amorVilao += 1;
            vilao.amor += 1;
            digitar("\nVocê se tornou amiga de Lucas!\n", 30);
            digitar("+1 Amor com Lucas\n", 30);
            jogador->quests++;
        }
        
    } else if (jogador->caminho == 1){
        if (escolha == 1) {
            digitar("\nO sorriso de Gabriel vacilou e ele olhou ao redor, como se verificasse se alguém mais estava ouvindo. A leveza que o cercava desapareceu, substituída por uma expressão séria e um tanto apreensiva. 'Você se interessa pelo Lucas, não é?', ele perguntou, e havia uma ponta de amargura em sua voz. 'Ele se vende como o artista sensível e misterioso da Baía Azul, mas eu preciso te alertar.' O olhar dele se fixou no seu de uma forma intensa. 'Não confie nele. Lucas... ele matou a Melissa. Sim, a Melissa que desapareceu há alguns anos.' Gabriel abaixou a voz. 'A cidade tem seus segredos e o maior deles é sobre ele. Ninguém fala abertamente, mas eu sei que foi ele.\n", 30);
            jogador->quests++;
        } else {
            jogador->amorHeroi += 1;
            heroi.amor += 1;
            digitar("\nVocê se tornou amiga de Gabriel!\n", 30);
            digitar("+1 Amor com Gabriel\n", 30);
            jogador->quests++;
        }
    }
    pause();
}

void capitulo4(PERSONAGEM *jogador) {
    limpar_tela();
    combate(jogador, &heroi, &vilao);
    digitar("Qual lado você escolhe? \n", 30);
    digitar("0. Gabriel\n", 30);
    digitar("1. Lucas\n\n", 30);
    int escolha;
    scanf("%d", &escolha);
    limpar_tela();
    if(escolha==0){
        jogador->amorHeroi += 1;
        heroi.amor += 1;
        digitar("Você tira Gabriel de lá e vão para uma área deserta da praia. Você fica furiosa mas não adianta nada. Gabriel te puxou para perto na areia, o barulho das ondas abafando um pouco as batidas aceleradas do seu coração. Seus olhos azuis, sempre cheios de luz, estavam agora mais sérios, mas carregados de uma ternura profunda. Ele segurou suas mãos com um sorriso tímido surgindo em seus lábios. Então, ele diz: Este verão com você tem sido... tudo. Eu nunca pensei que encontraria algo assim aqui, ou em qualquer lugar. Eu... eu estou apaixonado por você. Você aceita ser minha namorada?\n", 30);
        digitar("Seu coração deu um salto. Não haviam dúvidas na sua cabeça, você o amava. Com um sorriso radiante, você aceitou. 'Sim, Gabriel! Sim!'\n", 30);
        digitar("Seu coração transborda de alegria e alivio ao aceitar o pedido de Gabriel. Os beijos salgados do mar, as risadas descontraídas e a paixão que ele inspira confirmam sua escolha. Não há mais duvidas. Vocês estão juntos, prontos para viver o que o futuro reserva, além dos limites deste verão. E vivem felizes para sempre!\n", 30);
        digitar("Enquanto os braços de Gabriel me envolviam, uma ultima sombra, um sussurro persistente da Baia Azul, se dissipou da minha mente. Não era sobre o que eu deixava para trás, mas sim sobre o que eu havia descoberto e evitado. Lucas, o badboy enigmático que parecia tão vulnerável e profundo, não era o que aparentava ser. As memorias de Melissa, o mistério que pairava sobre a cidade, agora faziam sentido. Eu me lembrei das suas próprias suspeitas, das suas investigações discretas, ou talvez das confissões sussurradas por outros. Ele era o lobo em pele de cordeiro, o verdadeiro segredo sombrio da Baia Azul, um predador a espreita nas sombras da cidade costeira. Eu fiz a escolha certa, protegendo meu coração e, talvez, a própria Baia Azul. O verão com Gabriel e a luz que dissipa qualquer vestígio da escuridão de Lucas.\n", 30);
        jogador->quests++;
    }
    if(escolha==1){
        jogador->amorVilao += 1;
        vilao.amor += 1;
        digitar("Você tira Lucas de lá e vão para uma área deserta da praia. Você fica furiosa mas não adianta nada. Ele segura suas mãos com seus olhos profundos e enigmáticos se fixando nos seus. Havia uma intensidade neles que te hipnotizava, e a sensação de que você estava prestes a descobrir um novo universo em seus braços era mais legal ainda. Então, ele diz: Você me fez enxergar a beleza onde eu via apenas escuridão. Eu... eu te amo. Você aceita ser minha namorada?\n", 30);
        digitar("Seu coração disparou, não de medo, mas de uma vertigem de amor e aventura. Sim, você o queria. 'Sim, Lucas! Sim!'. Suas palavras mal saíram em um sussurro antes que ele te puxasse para um abraço. No instante seguinte, a suavidade de seus braços se transformou em algo gélido, uma pressão insuportável. Uma dor aguda e fria, que rasgou o seu peito. Seus olhos se arregalaram e a última coisa que viu no olhar de Lucas não foi amor, mas um vazio assustador, um brilho de vitória cruel. No entanto, você acha que foi apenas coisa da sua cabeça e fica ali, curtindo o momento.\n\n", 30);
        jogador->quests++;
    }
}

void capitulo5(PERSONAGEM *jogador) {
    limpar_tela();
    digitar("=== CAPÍTULO 5 ===\n\n", 30);
    
    if (jogador->caminho == 1) {
        digitar("No dia seguinte, Gabriel te encontra na praia:\n", 30);
        digitar("\"Você precisa se afastar do Lucas. Ele é perigoso.\"\n\n", 30);
        digitar("Ele te mostra fotos antigas que sugerem algo terrível...\n", 30);
    }
    else if(jogador->caminho == 0) {
        digitar("No dia seguinte, Lucas aparece inesperadamente:\n", 30);
        digitar("\"Cai fora desse Gabriel. Ele não é quem diz ser.\"\n\n", 30);
        digitar("Ele te mostra fotos antigas que sugerem algo terrível...\n", 30);
    }
    digitar("Agora você precisa tomar uma decisão crucial...\n\n", 30);
    digitar("1. Acreditar na revelação e se afastar\n", 30);
    digitar("2. Duvidar da revelação e continuar os dois relacionamentos\n", 30);
    
    int escolha = digita_escolha();
    
    if (escolha == 1) {
        if (jogador->caminho == 0) {
            jogador->amorVilao = 3;
            digitar("\nVocê decidiu se afastar de Gabriel!\n", 30);
            jogador->quests++;
        } 
        else if (jogador->caminho == 1) {
            jogador->amorHeroi = 3;
            digitar("\nVocê decidiu se afastar de Lucas\n", 30);
            jogador->quests++;
        }
    }
    else {
        digitar("\nVocê decidiu manter os dois relacionamentos!\n", 30);
        jogador->quests++;
    }
    pause();
}

void capitulo6(PERSONAGEM *jogador) {
    limpar_tela();
    digitar("=== CAPÍTULO 6 ===\n\n", 30);
    
    if (jogador->caminho == 0) {
        digitar("Você chega na praça e vê Gabriel lá. Você discute tudo o que viu nas fotos com ele.\n", 30);
        digitar("Gabriel te encara com intensidade:\n", 30);
        digitar("\"Você realmente acredita nele? Ou sequer pensou em acreditar? Depois de tudo que vivemos e de como ele agiu na festa?\"\n\n", 30);
        digitar("Sua voz se transforma em um sussurro gelado:\n", 30);
        digitar("\"O Lucas matou a Melissa. A cidade inteira sabe, mas tem medo de falar.\"\n\n", 30);
        digitar("Ele abre uma velha foto amassada mostrando Lucas e uma garota desaparecida... você já não sabe em quem acreditar.\n", 30);
    } 
    else if (jogador->caminho == 1) {
        digitar("Você chega na praça e vê Lucas lá. Você discute tudo o que viu nas fotos com ele.\n", 30);
        digitar("Lucas te encara com intensidade:\n", 30);
        digitar("\"Você realmente acredita nele? Ou sequer pensou em acreditar? Depois de tudo que vivemos e de como ele agiu na festa?\"\n\n", 30);
        digitar("Lucas segura suas mãos com urgência:\n", 30);
        digitar("\"Por favor, você precisa me ouvir... Gabriel não é quem diz ser.\"\n\n", 30);
        digitar("Ele abre um jornal antigo com a foto de Gabriel e a manchete:\n", 30);
        digitar("\'Suspeito de desaparecimento de jovem nunca foi preso\'\n\n", 30);
    }
    pause();
    
    // Mostra o final e marca o jogo como concluído
    final(jogador);
    jogador->capitulo_atual = MAX_CAPITULOS + 1;
    salvar_jogo(jogador);
}

void salvar_jogo(PERSONAGEM *jogador) {
    salvar_personagem(jogador, "jogo_salvo.dat");
}

void salvar_personagem(PERSONAGEM *jogador, const char *filename) {
    FILE *arquivo = fopen(filename, "wb");
    if (arquivo) {
        fwrite(jogador, sizeof(PERSONAGEM), 1, arquivo);
        fclose(arquivo);
        printf("\nProgresso salvo com sucesso!\n");
    } else {
        printf("\nErro ao salvar o progresso!\n");
    }
    pause();
}

int carregar_jogo(PERSONAGEM *jogador) {
    FILE *arquivo = fopen("jogo_salvo.dat", "rb");
    if (arquivo) {
        fread(jogador, sizeof(PERSONAGEM), 1, arquivo);
        fclose(arquivo);
        
        if(jogador->capitulo_atual > 0) {
            jogador->jogo_iniciado = 1;
        }
        
        printf("\nJogo carregado com sucesso!\n");
        printf("Continuando do Capítulo %d\n", jogador->capitulo_atual);
        pause();
        
        if (jogador->capitulo_atual > MAX_CAPITULOS) {
            printf("\nEste jogo já foi concluído. Inicie um novo jogo.\n");
            return 0;
        }
        
        jogar_capitulo(jogador);
        return 1;
    } 
    else {
        printf("\nNenhum jogo salvo encontrado!\n");
        return 0;
    }
}

void status(PERSONAGEM *jogador) {
    printf("\n=== STATUS ===\n");
    
    if(jogador->jogo_iniciado == 0) {
        printf("Jogo ainda não iniciado\n");
        printf("Todos os valores serão zerados até que um novo jogo comece\n\n");
        
        printf("Nome: (Não definido)\n");
        printf("Capítulo: 0\n");
        printf("Amor (Gabriel): 0\n");
        printf("Amor (Lucas): 0\n");
        printf("Missões completas: 0\n");
        printf("Itens: 0/10\n");
        
        printf("\nAtributos:\n");
        printf("- Sorte: 0\n");
        printf("- Carisma: 0\n");
        printf("- Estilo: 0\n");
        printf("- Inteligência: 0\n");
    } else {
        printf("Nome: %s\n", jogador->nome);
        printf("Capítulo: %d\n", jogador->capitulo_atual);
        printf("Amor (Gabriel): %d\n", jogador->amorHeroi);
        printf("Amor (Lucas): %d\n", jogador->amorVilao);
        printf("Missões completas: %d\n", jogador->quests);
        printf("Itens: %d/10\n", jogador->num_itens);
        
        printf("\nAtributos:\n");
        printf("- Sorte: %d\n", jogador->sorte);
        printf("- Carisma: %d\n", jogador->carisma);
        printf("- Estilo: %d\n", jogador->estilo);
        printf("- Inteligência: %d\n", jogador->inteligencia);
    }
    
    pause();
}
void integrantes() {
    limpar_tela();
    printf("=== INTEGRANTES ===\n\n");
    printf("Desenvolvido por:\n\n");
    printf("- Samara Sena\n");
    printf("- Laura Silva\n");
    printf("- Raissa Barros\n\n");
}

void digitar(const char *texto, int velocidade) {
    for (; *texto; texto++) {
        putchar(*texto);        //caractere por caractere
        fflush(stdout);         //limpa o buffer pra garantir que os textos saiam
        Sleep(velocidade);       //velocidade da animação
    }
}
void combate(PERSONAGEM *jogador, GABRIEL *heroi, LUCAS *vilao) {
    limpar_tela();
    digitar("=== CONFRONTO NO BAR ===\n\n", 30);
    
    digitar("Em uma noite animada, você decide ir ao bar da cidade...\n", 30);
    digitar("Para sua surpresa, ambos Gabriel e Lucas estão lá!\n\n", 30);
    
    digitar("Os dois começam a discutir quando percebem sua presença...\n", 30);
    digitar("Gabriel: \"Lucas, você não deveria estar aqui depois do que fez!\"\n", 30);
    digitar("Lucas: \"Você que deveria sumir, seu falsário! Todo mundo sabe que foi você!\"\n\n", 30);
    
    digitar("Eles começam a brigar por sua atenção, acusando um ao outro...\n", 30);
    digitar("Gabriel diz que Lucas está envolvido no desaparecimento de uma menina!\n", 30);
    digitar("Lucas contra-ataca dizendo que Gabriel é quem esconde segredos obscuros!\n\n", 30);
    
    pause();
    limpar_tela();
    
    int defesaGabriel = heroi->defesa + heroi->inteligencia;
    int ataqueLucas = vilao->ataque + vilao->estilo;

    digitar("\n=== RESULTADO ===\n", 30);

    if (ataqueLucas > defesaGabriel) {
        digitar("Lucas venceu essa disputa! Ele conseguiu chamar mais atenção de você...\n", 30);
        jogador->amorVilao += 2;
        jogador->quests++;
        
        if (jogador->amorHeroi > 0) {
            jogador->amorHeroi -= 1;
        } else {
            jogador->amorHeroi = 0;
        }
        
        vilao->amor++;
        digitar("\n+2 Amor com Lucas\n", 30);
        digitar("-1 Amor com Gabriel\n", 30);
    } 
    else if (defesaGabriel > ataqueLucas) {
        digitar("Gabriel encantou você ainda mais com sua inteligência e carinho!\n", 30);
        jogador->amorHeroi += 2;
        jogador->quests++;
        
        if (jogador->amorVilao > 0) {
            jogador->amorVilao -= 1;
        } else {
            jogador->amorVilao = 0;
        }
        
        heroi->amor++;
        digitar("\n+2 Amor com Gabriel\n", 30);
        digitar("-1 Amor com Lucas\n", 30);
    } 
    else {
        digitar("Empate! Você ficou indecisa com o charme dos dois...\n", 30);
        jogador->quests++;
        jogador->amorHeroi += 1;
        jogador->amorVilao += 1;
        digitar("\n+1 Amor com ambos\n", 30);
    }

    pause();
}

int final(PERSONAGEM *jogador) {
    limpar_tela();
    digitar("=== FINAL DO JOGO ===\n\n", 30);
    
    if(jogador->amorHeroi > jogador->amorVilao){
        digitar("Você estava em choque, mas decide dar um último voto de confiança e diz: tudo bem, eu vou acreditar em você!", 30);
        digitar("Gabriel se ajoelha e abre uma caixinha com um anel...\n", 30);
        digitar("Gabriel: \"Depois de tudo que passamos, percebi que não quero viver sem você\"\n", 30);
        digitar("Você aceita o pedido de namoro de Gabriel!\n\n", 30);
        digitar("E vivem felizes para sempre!\n\n", 30);
        digitar("Anos depois, você descobre a verdade sobre Lucas...\n", 30);
        digitar("Ele era um serial killer que assombrava Baía Azul!\n", 30);
        digitar("Gabriel estava tentando protegê-la o tempo todo!\n", 30);
        jogador->quests++;
    }
    else if(jogador->amorHeroi < jogador->amorVilao) {
        digitar("Você estava em choque, mas decide dar um último voto de confiança e diz: tudo bem, eu vou acreditar em você!\n", 30);
        digitar("Lucas te leva para um lugar isolado na praia...\n", 30);
        digitar("Lucas: \"Você é a única que realmente me entende...\"\n", 30);
        digitar("Lucas: \"Provavelmente era isso que você queria ouvir.\"\n\n", 30);
        digitar("A verdade, fria e brutal, desceu como uma avalanche. Lucas, o badboy, o homem de olhos profundos e misteriosos, não era um refúgio. Ele era a escuridão. Os sussurros da Baia Azul sobre Melissa, a menina desaparecida há anos, agora se tornaram um grito ensurdecedor em sua mente moribunda. Ele era o verdadeiro monstro, o serial killer por trás dos panos da cidade costeira, alimentando-se da inocência e da beleza que ele supostamente 'apreciava'. Você havia sido a última vítima a cair em sua teia, atraída pela sua beleza e sua fachada. O verão de Baia Azul, tão cheio de promessas, terminou em um pesadelo silencioso, com uma última lembrança sendo do sorriso vazio de um assassino.", 30);
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
        WORD attributes = BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY; //fundo vermelho + texto branco 
        SetConsoleTextAttribute(hConsole, attributes); //põe a cor
        digitar("\nVOCÊ ACABOU DE MORRER!!!!\n\n", 30);
        system("pause");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //reseta pra cor normal
        digitar("\nVocê se tornou mais uma vítima do serial killer de Baía Azul!\n", 30);
        digitar("Gabriel tentou avisá-la, mas você não quis ouvir...\n", 30);
        jogador->quests++;
    }
    
    digitar("\nFim da jornada...\n", 30);
    pause();
    
    return 1; // Indica que o jogo terminou
}

int continuar_jogo(PERSONAGEM *jogador) {
    FILE *arquivo = fopen("jogo_salvo.dat", "rb");
    if (arquivo) {
        fread(jogador, sizeof(PERSONAGEM), 1, arquivo);
        fclose(arquivo);
        
        printf("\nJogo carregado com sucesso!\n");
        printf("Continuando do Capítulo %d\n", jogador->capitulo_atual);
        pause();
        
        if (jogador->capitulo_atual > MAX_CAPITULOS) {
            printf("\nEste jogo já foi concluído. Inicie um novo jogo.\n");
            return 0;
        }
        
        jogar_capitulo(jogador);
        return 1;
    } else {
        printf("\nNenhum jogo salvo encontrado!\n");
        return 0;
    }
}
