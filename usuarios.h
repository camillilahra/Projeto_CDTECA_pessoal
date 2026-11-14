#ifndef USUARIOS_H
#define USUARIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario {
    int idUsuario;
    char nome[50];
    char email[50];
    int totalAlbunsCadastrados;
    int ativo;
};

struct Usuario listaUsuarios[50];
int totalUsuarios = 0;

void salvarUsuariosCSV() {
    int i;
    FILE *arq = fopen("usuarios.csv", "w");
    if (arq == NULL) return;
    for (i = 0; i < totalUsuarios; i++) {
        fprintf(arq, "%d;%s;%s;%d;%d\n",
                listaUsuarios[i].idUsuario,
                listaUsuarios[i].nome,
                listaUsuarios[i].email,
                listaUsuarios[i].totalAlbunsCadastrados,
                listaUsuarios[i].ativo);
    }
    fclose(arq);
}

void carregarUsuariosCSV() {
    FILE *arq = fopen("usuarios.csv", "r");
    if (arq == NULL) return;

    totalUsuarios = 0;
    while (fscanf(arq, "%d;%49[^;];%49[^;];%d;%d\n",
                  &listaUsuarios[totalUsuarios].idUsuario,
                  listaUsuarios[totalUsuarios].nome,
                  listaUsuarios[totalUsuarios].email,
                  &listaUsuarios[totalUsuarios].totalAlbunsCadastrados,
                  &listaUsuarios[totalUsuarios].ativo) == 5) {
        totalUsuarios++;
        if (totalUsuarios >= 50) break;
    }
    fclose(arq);
}

void cadastrarUsuario() {
    if (totalUsuarios >= 50) {
        printf("\n[ALERTA] Limite de usuarios atingido!\n");
        return;
    }
    printf("\n--- CADASTRAR NOVO USUARIO ---\n");
    printf("ID do Usuario: ");
    scanf("%d", &listaUsuarios[totalUsuarios].idUsuario);
    printf("Nome Completo: ");
    scanf(" %49[^\n]", listaUsuarios[totalUsuarios].nome);
    printf("E-mail: ");
    scanf(" %49[^\n]", listaUsuarios[totalUsuarios].email);

    listaUsuarios[totalUsuarios].totalAlbunsCadastrados = 0;
    listaUsuarios[totalUsuarios].ativo = 1;

    totalUsuarios++;
    salvarUsuariosCSV();
    printf("\n[SUCESSO] Usuario cadastrado e salvo em usuarios.csv!\n");
}

void listarOuBuscarUsuarios() {
    int tipoBusca;
    char termo[50];
    int achou = 0;
    int i;
    printf("\n1. Listar todos os ativos\n2. Buscar por nome\nEscolha: ");
    scanf("%d", &tipoBusca);

    if (tipoBusca == 2) {
        printf("Digite parte do nome: ");
        scanf(" %49[^\n]", termo);
    }

    printf("\n--- USUARIOS ENCONTRADOS ---\n");
    for (i = 0; i < totalUsuarios; i++) {
        if (listaUsuarios[i].ativo == 1) {
            if (tipoBusca == 1 || strstr(listaUsuarios[i].nome, termo) != NULL) {
                printf("ID: %d | Nome: %s | E-mail: %s | Albuns: %d\n",
                       listaUsuarios[i].idUsuario,
                       listaUsuarios[i].nome,
                       listaUsuarios[i].email,
                       listaUsuarios[i].totalAlbunsCadastrados);
                achou++;
            }
        }
    }
    if (!achou) printf("Nenhum usuario encontrado.\n");
}

void editarUsuario() {
    int id, achou = 0;
    int i;
    printf("\nDigite o ID do usuario para editar: ");
    scanf("%d", &id);

    for (i = 0; i < totalUsuarios; i++) {
        if (listaUsuarios[i].idUsuario == id && listaUsuarios[i].ativo == 1) {
            printf("Novo Nome (atual: %s): ", listaUsuarios[i].nome);
            scanf(" %49[^\n]", listaUsuarios[i].nome);
            printf("Novo E-mail (atual: %s): ", listaUsuarios[i].email);
            scanf(" %49[^\n]", listaUsuarios[i].email);

            salvarUsuariosCSV();
            printf("\n[SUCESSO] Dados atualizados!\n");
            achou = 1;
            break;
        }
    }
    if (!achou) printf("\n[ERRO] Usuario nao encontrado.\n");
}

void removerUsuario() {
    int id, achou = 0;
    int i;
    printf("\nDigite o ID do usuario para remover: ");
    scanf("%d", &id);

    for (i = 0; i < totalUsuarios; i++) {
        if (listaUsuarios[i].idUsuario == id && listaUsuarios[i].ativo == 1) {
            listaUsuarios[i].ativo = 0;
            salvarUsuariosCSV();
            printf("\n[SUCESSO] Usuario removido do sistema!\n");
            achou = 1;
            break;
        }
    }
    if (!achou) printf("\n[ERRO] Usuario nao encontrado.\n");
}

void moduloUsuarios() {
    int op;
    do {
        printf("\n=== MODULO 1: GESTAO DE USUARIOS ===\n");
        printf("1. Cadastrar Usuario\n");
        printf("2. Listar / Buscar Usuarios\n");
        printf("3. Editar Usuario\n");
        printf("4. Remover Usuario\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: cadastrarUsuario(); break;
            case 2: listarOuBuscarUsuarios(); break;
            case 3: editarUsuario(); break;
            case 4: removerUsuario(); break;
        }
    } while (op != 0);
}

#endif
