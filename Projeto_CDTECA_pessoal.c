#include <stdio.h>
#include <string.h>

// Structs globais do sistema
struct Usuario {
    int idUsuario;
    char nome[50];
    char email[50];
    int totalAlbunsCadastrados;
    int ativo; 
};
struct Usuario listaUsuarios[50];
int totalUsuarios = 0;

struct Album {
    int idAlbum;
    char titulo[50];
    char artista[40];
    int anoLancamento;
    float precoEstimado;
    int disponivel; 
};
struct Album catalogoAlbuns[50];
int totalAlbuns = 0;

struct Emprestimo {
    int idEmprestimo;
    int idAlbumEmprestado;
    char nomeAmigo[40];
    char dataEmprestimo[20];
    int devolvido; 
};
struct Emprestimo historicoEmprestimos[50];
int totalEmprestimos = 0;

struct Reproducao {
    int idReproducao;
    int idUsuarioOuvinte;
    int idAlbumOuvido;
    int vezesOuvidas;
    float avaliacaoEstrelas;
};
struct Reproducao historicoReproducoes[50];
int totalReproducoes = 0;

// Cabecalho visual do sistema
void exibirCabecalho() {
    printf("\n======================================================\n");
    printf("           SISTEMA CDTECA PESSOAL                     \n");
    printf("======================================================\n");
}

// Modulo 1 - Autora: Camilli Garcia Lahra (RGM: 46898689)
void moduloUsuarios() {
    int opcao;
    do {
        printf("\n--- MENU USUARIOS ---\n");
        printf("1. Cadastrar Usuario\n");
        printf("2. Listar Usuarios\n");
        printf("3. Editar Usuario\n");
        printf("4. Remover Usuario\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nFuncao de cadastrar usuario em desenvolvimento.\n");
                break;
            case 2:
                printf("\nFuncao de listar usuarios em desenvolvimento.\n");
                break;
            case 3:
                printf("\nFuncao de editar usuario em desenvolvimento.\n");
                break;
            case 4:
                printf("\nFuncao de remover usuario em desenvolvimento.\n");
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
}

// Modulo 2 - Autora: Viviana Alexandra Quijada Perez (RGM: 49339877)
void moduloAlbuns() {
    int opcao;
    do {
        printf("\n--- MENU ALBUNS ---\n");
        printf("1. Cadastrar Album\n");
        printf("2. Listar Albuns\n");
        printf("3. Editar Album\n");
        printf("4. Excluir Album\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nFuncao de cadastrar album em desenvolvimento.\n");
                break;
            case 2:
                printf("\nFuncao de listar albuns em desenvolvimento.\n");
                break;
            case 3:
                printf("\nFuncao de editar album em desenvolvimento.\n");
                break;
            case 4:
                printf("\nFuncao de excluir album em desenvolvimento.\n");
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
}

// Modulo 3 - Autora: Isabella Fragoso Harps (RGM: 8849798821)
void moduloEmprestimos() {
    int opcao;
    do {
        printf("\n--- MENU EMPRESTIMOS ---\n");
        printf("1. Registrar Emprestimo\n");
        printf("2. Listar Emprestimos\n");
        printf("3. Editar Emprestimo\n");
        printf("4. Registrar Devolucao\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nFuncao de registrar emprestimo em desenvolvimento.\n");
                break;
            case 2:
                printf("\nFuncao de listar emprestimos em desenvolvimento.\n");
                break;
            case 3:
                printf("\nFuncao de editar emprestimo em desenvolvimento.\n");
                break;
            case 4:
                printf("\nFuncao de registrar devolucao em desenvolvimento.\n");
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
}

// Modulo 4 - Relatorios e Reproducoes (Equipe)
void moduloReproducoesRelatorios() {
    int opcao;
    do {
        printf("\n--- MENU REPRODUCOES E RELATORIOS ---\n");
        printf("1. Registrar Reproducao\n");
        printf("2. Listar Reproducoes\n");
        printf("3. Cancelar Reproducao\n");
        printf("4. Relatorio: Album Mais Ouvido\n");
        printf("5. Relatorio: Usuario Mais Ativo\n");
        printf("6. Relatorio por Usuario\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nFuncao de registrar reproducao em desenvolvimento.\n");
                break;
            case 2:
                printf("\nFuncao de listar reproducoes em desenvolvimento.\n");
                break;
            case 3:
                printf("\nFuncao de cancelar reproducao em desenvolvimento.\n");
                break;
            case 4:
                printf("\nRelatorio de album mais ouvido em desenvolvimento.\n");
                break;
            case 5:
                printf("\nRelatorio de usuario mais ativo em desenvolvimento.\n");
                break;
            case 6:
                printf("\nRelatorio por usuario em desenvolvimento.\n");
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
}

int main() {
    int opcaoPrincipal;
    
    do {
        exibirCabecalho();
        printf("MENU PRINCIPAL:\n");
        printf("1. Modulo de Usuarios (Camilli)\n");
        printf("2. Modulo de Albuns (Viviana)\n");
        printf("3. Modulo de Emprestimos (Isabella)\n");
        printf("4. Modulo de Reproducoes e Relatorios (Equipe)\n");
        printf("0. Sair\n");
        printf("------------------------------------------------------\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcaoPrincipal);

        switch (opcaoPrincipal) {
            case 1:
                moduloUsuarios();
                break;
            case 2:
                moduloAlbuns();
                break;
            case 3:
                moduloEmprestimos();
                break;
            case 4:
                moduloReproducoesRelatorios();
                break;
            case 0:
                printf("\nSaindo do programa. Ate mais!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcaoPrincipal != 0);

    return 0;
}