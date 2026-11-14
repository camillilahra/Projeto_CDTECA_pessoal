#ifndef ALBUNS_H
#define ALBUNS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void salvarAlbunsCSV() {
    int i;
    FILE *arq = fopen("albuns.csv", "w");
    if (arq == NULL) return;
    for (i = 0; i < totalAlbuns; i++) {
        fprintf(arq, "%d;%s;%s;%d;%.2f;%d\n",
                catalogoAlbuns[i].idAlbum,
                catalogoAlbuns[i].titulo,
                catalogoAlbuns[i].artista,
                catalogoAlbuns[i].anoLancamento,
                catalogoAlbuns[i].precoEstimado,
                catalogoAlbuns[i].disponivel);
    }
    fclose(arq);
}

void carregarAlbunsCSV() {
    FILE *arq = fopen("albuns.csv", "r");
    if (arq == NULL) return;

    totalAlbuns = 0;
    while (fscanf(arq, "%d;%49[^;];%39[^;];%d;%f;%d\n",
                  &catalogoAlbuns[totalAlbuns].idAlbum,
                  catalogoAlbuns[totalAlbuns].titulo,
                  catalogoAlbuns[totalAlbuns].artista,
                  &catalogoAlbuns[totalAlbuns].anoLancamento,
                  &catalogoAlbuns[totalAlbuns].precoEstimado,
                  &catalogoAlbuns[totalAlbuns].disponivel) == 6) {
        totalAlbuns++;
        if (totalAlbuns >= 50) break;
    }
    fclose(arq);
}

void cadastrarAlbum() {
    if (totalAlbuns >= 50) {
        printf("\n[ALERTA] Catalogo cheio!\n");
        return;
    }
    printf("\n--- CADASTRAR NOVO ALBUM ---\n");
    printf("ID do Album: ");
    scanf("%d", &catalogoAlbuns[totalAlbuns].idAlbum);
    printf("Titulo do CD: ");
    scanf(" %49[^\n]", catalogoAlbuns[totalAlbuns].titulo);
    printf("Artista / Banda: ");
    scanf(" %39[^\n]", catalogoAlbuns[totalAlbuns].artista);
    printf("Ano de Lancamento: ");
    scanf("%d", &catalogoAlbuns[totalAlbuns].anoLancamento);
    printf("Preco Estimado (R$): ");
    scanf("%f", &catalogoAlbuns[totalAlbuns].precoEstimado);

    catalogoAlbuns[totalAlbuns].disponivel = 1;

    totalAlbuns++;
    salvarAlbunsCSV();
    printf("\n[SUCESSO] Album salvo em albuns.csv!\n");
}

void listarOuBuscarAlbuns() {
    int op;
    char termo[50] = "";
    int achou = 0;
    int i;
    printf("\n1. Listar todos os albuns\n2. Buscar por titulo ou artista\nEscolha: ");
    scanf("%d", &op);

    if (op == 2) {
        printf("Digite o termo de busca: ");
        scanf(" %49[^\n]", termo);
    }

    printf("\n--- CATALOGO DE ALBUNS ---\n");
    for (i = 0; i < totalAlbuns; i++) {
        if (catalogoAlbuns[i].disponivel == 1) {
            if (op == 1 || (strlen(termo) > 0 && (strstr(catalogoAlbuns[i].titulo, termo) != NULL || strstr(catalogoAlbuns[i].artista, termo) != NULL))) {
                printf("ID: %d | %s - %s (%d) | Valor: R$ %.2f\n",
                       catalogoAlbuns[i].idAlbum,
                       catalogoAlbuns[i].titulo,
                       catalogoAlbuns[i].artista,
                       catalogoAlbuns[i].anoLancamento,
                       catalogoAlbuns[i].precoEstimado);
                achou++;
            }
        }
    }
    if (!achou) printf("Nenhum album encontrado.\n");
    
    printf("\nPressione ENTER para continuar...");
    getchar(); 
    getchar(); 
}

void editarAlbum() {
    int id, achou = 0;
    int i;
    printf("\nDigite o ID do album para editar: ");
    scanf("%d", &id);

    for (i = 0; i < totalAlbuns; i++) {
        if (catalogoAlbuns[i].idAlbum == id && catalogoAlbuns[i].disponivel == 1) {
            printf("Novo Titulo (atual: %s): ", catalogoAlbuns[i].titulo);
            scanf(" %49[^\n]", catalogoAlbuns[i].titulo);
            printf("Novo Preco (atual: %.2f): ", catalogoAlbuns[i].precoEstimado);
            scanf("%f", &catalogoAlbuns[i].precoEstimado);

            salvarAlbunsCSV();
            printf("\n[SUCESSO] Album atualizado!\n");
            achou = 1;
            break;
        }
    }
    if (!achou) printf("\n[ERRO] Album nao encontrado.\n");
}

void removerAlbum() {
    int id, achou = 0;
    int i;
    printf("\nDigite o ID do album para excluir: ");
    scanf("%d", &id);

    for (i = 0; i < totalAlbuns; i++) {
        if (catalogoAlbuns[i].idAlbum == id && catalogoAlbuns[i].disponivel == 1) {
            catalogoAlbuns[i].disponivel = 0;
            salvarAlbunsCSV();
            printf("\n[SUCESSO] Album excluido!\n");
            achou = 1;
            break;
        }
    }
    if (!achou) printf("\n[ERRO] Album nao encontrado.\n");
}

void moduloAlbuns() {
    int op;
    do {
        printf("\n=== MODULO 2: CATALOGO DE ALBUNS ===\n");
        printf("1. Cadastrar Album\n");
        printf("2. Listar / Buscar Albuns\n");
        printf("3. Editar Album\n");
        printf("4. Excluir Album\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: cadastrarAlbum(); break;
            case 2: listarOuBuscarAlbuns(); break;
            case 3: editarAlbum(); break;
            case 4: removerAlbum(); break;
        }
    } while (op != 0);
}

#endif
