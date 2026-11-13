#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "usuarios.h"
#include "albuns.h"
#include "emprestimos.h"
#include "relatorios.h"

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausarTela() {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

int main() {
    setlocale(LC_CTYPE, "Portuguese");

    carregarUsuariosCSV();
    carregarAlbunsCSV();
    carregarEmprestimosCSV();

    int opcaoPrincipal;
    do {
        limparTela();
        printf("======================================================\n");
        printf("       CDTECA PESSOAL - SISTEMA MODULAR (v2.0)        \n");
        printf("======================================================\n");
        printf("1. Modulo de Usuarios (usuarios.h)\n");
        printf("2. Modulo de Albuns (albuns.h)\n");
        printf("3. Modulo de Emprestimos (emprestimos.h)\n");
        printf("4. Modulo de Relatorios e Estante (relatorios.h)\n");
        printf("0. Salvar e Encerrar Sistema\n");
        printf("------------------------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoPrincipal);

        switch (opcaoPrincipal) {
            case 1:
                limparTela();
                moduloUsuarios();
                break;
            case 2:
                limparTela();
                moduloAlbuns();
                break;
            case 3:
                limparTela();
                moduloEmprestimos();
                break;
            case 4:
                limparTela();
                moduloRelatorios();
                break;
            case 0:
                printf("\nEncerrando CDteca Pessoal. Dados salvos!\n");
                break;
            default:
                printf("\n[ERRO] Opcao invalida!\n");
                pausarTela();
        }
    } while (opcaoPrincipal != 0);

    return 0;
}
