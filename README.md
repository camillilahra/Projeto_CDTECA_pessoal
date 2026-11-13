# CDteca Pessoal - Checkpoint 2

Projeto desenvolvido para a disciplina de Programação / Engenharia de Software (Universidade Positivo).

## Integrantes do Grupo
* Camilli Garcia Lahra (RGM: 46898689)
* Viviana Alexandra Quijada Perez (RGM: 49339877)
* Isabella (RGM: [Inserir RGM])

## Sobre o Projeto
Segunda entrega do sistema de gerenciamento de CDs pessoal em linguagem C. Nesta etapa, o código foi dividido em módulos (arquivos `.h`), passou a salvar os dados em arquivos `.csv` e ganhou relatórios utilizando matriz bidimensional para representar a estante.

## Estrutura dos Arquivos
* `main.c`: Menu principal e chamada dos módulos.
* `usuarios.h`: Cadastro, busca, edição e remoção de usuários (`usuarios.csv`).
* `albuns.h`: Controle do catálogo de CDs (`albuns.csv`).
* `emprestimos.h`: Registro de empréstimos e devoluções (`emprestimos.csv`).
* `relatorios.h`: Relatório de álbum mais emprestado, valor total do acervo e mapa da estante em matriz 3x4.
