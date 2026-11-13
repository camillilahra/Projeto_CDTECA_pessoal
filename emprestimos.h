#ifndef EMPRESTIMOS_H
#define EMPRESTIMOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Emprestimo {
    int idEmprestimo;
    int idAlbumEmprestado;
    char nomeAmigo[40];
    char dataEmprestimo[20];
    int devolvido;
};

struct Emprestimo listaEmprestimos[50];
int totalEmprestimos = 0;

void salvarEmprestimosCSV() {
    FILE *arq = fopen("emprestimos.csv", "w");
    if (arq == NULL) return;
    for (int i = 0; i < totalEmprestimos; i++) {
        fprintf(arq, "%d;%d;%s;%s;%d\n",
                listaEmprestimos[i].idEmprestimo,
                listaEmprestimos[i].idAlbumEmprestado,
                listaEmprestimos[i].nomeAmigo,
                listaEmprestimos[i].dataEmprestimo,
                listaEmprestimos[i].devolvido);
    }
    fclose(arq);
}

void carregarEmprestimosCSV() {
    FILE *arq = fopen("emprestimos.csv", "r");
    if (arq == NULL) return;

    totalEmprestimos = 0;
    while (fscanf(arq, "%d;%d;%39[^;];%19[^;];%d\n",
                  &listaEmprestimos[totalEmprestimos].idEmprestimo,
                  &listaEmprestimos[totalEmprestimos].idAlbumEmprestado,
                  listaEmprestimos[totalEmprestimos].nomeAmigo,
                  listaEmprestimos[totalEmprestimos].dataEmprestimo,
                  &listaEmprestimos[totalEmprestimos].devolvido) == 5) {
        totalEmprestimos++;
        if (totalEmprestimos >= 50) break;
    }
    fclose(arq);
}

void registrarEmprestimo() {
    if (totalEmprestimos >= 50) {
        printf("\n[ALERTA] Limite de emprestimos atingido!\n");
        return;
    }
    printf("\n--- REGISTRAR EMPRESTIMO DE CD ---\n");
    printf("ID do Emprestimo: ");
    scanf("%d", &listaEmprestimos[totalEmprestimos].idEmprestimo);
    printf("ID do Album Emprestado: ");
    scanf("%d", &listaEmprestimos[totalEmprestimos].idAlbumEmprestado);
    printf("Nome do Amigo: ");
    scanf(" %39[^\n]", listaEmprestimos[totalEmprestimos].nomeAmigo);
    printf("Data (DD/MM/AAAA): ");
    scanf(" %19[^\n]", listaEmprestimos[totalEmprestimos].dataEmprestimo);

    listaEmprestimos[totalEmprestimos].devolvido = 0;

    totalEmprestimos++;
    salvarEmprestimosCSV();
    printf("\n[SUCESSO] Emprestimo registrado em emprestimos.csv!\n");
}

void listarEmprestimos() {
    printf("\n--- HISTORICO DE EMPRESTIMOS ---\n");
    if (totalEmprestimos == 0) {
        printf("Nenhum emprestimo registrado.\n");
        return;
    }
    for (int i = 0; i < totalEmprestimos; i++) {
        printf("ID: %d | Album ID: %d | Amigo: %s | Data: %s | Status: %s\n",
               listaEmprestimos[i].idEmprestimo,
               listaEmprestimos[i].idAlbumEmprestado,
               listaEmprestimos[i].nomeAmigo,
               listaEmprestimos[i].dataEmprestimo,
               listaEmprestimos[i].devolvido == 0 ? "EMPRESTADO" : "DEVOLVIDO");
    }
}

void editarEmprestimo() {
    int id, achou = 0;
    printf("\nDigite o ID do emprestimo para alterar o nome/data: ");
    scanf("%d", &id);

    for (int i = 0; i < totalEmprestimos; i++) {
        if (listaEmprestimos[i].idEmprestimo == id) {
            printf("Novo Nome do Amigo: ");
            scanf(" %39[^\n]", listaEmprestimos[i].nomeAmigo);
            printf("Nova Data: ");
            scanf(" %19[^\n]", listaEmprestimos[i].dataEmprestimo);

            salvarEmprestimosCSV();
            printf("\n[SUCESSO] Emprestimo atualizado!\n");
            achou = 1;
            break;
        }
    }
    if (!achou) printf("\n[ERRO] Emprestimo nao encontrado.\n");
}

void darBaixaDevolucao() {
    int id, achou = 0;
    printf("\nDigite o ID do emprestimo devolvido: ");
    scanf("%d", &id);

    for (int i = 0; i < totalEmprestimos; i++) {
        if (listaEmprestimos[i].idEmprestimo == id && listaEmprestimos[i].devolvido == 0) {
            listaEmprestimos[i].devolvido = 1;
            salvarEmprestimosCSV();
            printf("\n[SUCESSO] Devolucao confirmada!\n");
            achou = 1;
            break;
        }
    }
    if (!achou) printf("\n[ERRO] Emprestimo ativo nao encontrado.\n");
}

void moduloEmprestimos() {
    int op;
    do {
        printf("\n=== MODULO 3: EMPRESTIMOS DE CDS ===\n");
        printf("1. Registrar Emprestimo\n");
        printf("2. Listar Emprestimos\n");
        printf("3. Editar Emprestimo\n");
        printf("4. Registrar Devolucao (Baixa)\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: registrarEmprestimo(); break;
            case 2: listarEmprestimos(); break;
            case 3: editarEmprestimo(); break;
            case 4: darBaixaDevolucao(); break;
        }
    } while (op != 0);
}

#endif
