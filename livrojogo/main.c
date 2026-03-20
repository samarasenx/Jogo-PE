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
