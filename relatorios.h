#ifndef RELATORIOS_H
#define RELATORIOS_H

#include <stdio.h>
#include "albuns.h"
#include "emprestimos.h"

void relatorioCruzadoMaisEmprestado() {
    int maxEmprestimos = -1;
    int indiceMaisEmprestado = -1;
    int i;
    int j;
    int contagem;

    printf("\n--- [RELATORIO ANALITICO] ALBUM MAIS EMPRESTADO ---\n");
    if (totalAlbuns == 0 || totalEmprestimos == 0) {
        printf("Dados insuficientes para cruzamento.\n");
        return;
    }

    for (i = 0; i < totalAlbuns; i++) {
        if (catalogoAlbuns[i].disponivel == 1) {
            contagem = 0;
            for (j = 0; j < totalEmprestimos; j++) {
                if (listaEmprestimos[j].idAlbumEmprestado == catalogoAlbuns[i].idAlbum) {
                    contagem++;
                }
            }
            if (contagem > maxEmprestimos) {
                maxEmprestimos = contagem;
                indiceMaisEmprestado = i;
            }
        }
    }

    if (indiceMaisEmprestado != -1 && maxEmprestimos > 0) {
        printf("Album Destaque: %s (%s)\n",
               catalogoAlbuns[indiceMaisEmprestado].titulo,
               catalogoAlbuns[indiceMaisEmprestado].artista);
        printf("Total de vezes emprestado: %d\n", maxEmprestimos);
    } else {
        printf("Nenhum album ativo possui emprestimos registrados.\n");
    }
}

void relatorioValorTotalAcervo() {
    float soma = 0;
    int ativos = 0;
    int i;
    for (i = 0; i < totalAlbuns; i++) {
        if (catalogoAlbuns[i].disponivel == 1) {
            soma += catalogoAlbuns[i].precoEstimado;
            ativos++;
        }
    }
    printf("\n--- [RELATORIO FINANCEIRO] VALOR DO ACERVO ---\n");
    printf("Total de CDs Ativos: %d\n", ativos);
    printf("Patrimonio Estimado da CDteca: R$ %.2f\n", soma);
}

void exibirMatrizEstante() {
    int estante[3][4] = {0};
    int k = 0;
    int lin;
    int col;

    for (lin = 0; lin < 3; lin++) {
        for (col = 0; col < 4; col++) {
            while (k < totalAlbuns && catalogoAlbuns[k].disponivel == 0) {
                k++;
            }
            if (k < totalAlbuns) {
                estante[lin][col] = catalogoAlbuns[k].idAlbum;
                k++;
            }
        }
    }

    printf("\n--- [MATRIZ 2D] MAPA FISICO DA ESTANTE DE CDS ---\n");
    for (lin = 0; lin < 3; lin++) {
        printf("Prateleira %d: ", lin + 1);
        for (col = 0; col < 4; col++) {
            if (estante[lin][col] != 0)
                printf("[CD #%02d] ", estante[lin][col]);
            else
                printf("[ VAZIO ] ");
        }
        printf("\n");
    }
}

void moduloRelatorios() {
    int op;
    do {
        printf("\n=== MODULO 4: RELATORIOS E ESTANTE 2D ===\n");
        printf("1. Album Mais Emprestado\n");
        printf("2. Valor Total do Acervo\n");
        printf("3. Mapa Fisico da Estante (Matriz 2D)\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: relatorioCruzadoMaisEmprestado(); break;
            case 2: relatorioValorTotalAcervo(); break;
            case 3: exibirMatrizEstante(); break;
        }
    } while (op != 0);
}

#endif
