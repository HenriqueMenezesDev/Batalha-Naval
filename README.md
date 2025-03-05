# Jogo de Batalha Naval com Habilidades

Este repositório contém a implementação de um jogo de batalha naval simples, utilizando um tabuleiro de 10x10. O jogo permite o posicionamento de navios de diferentes formas (horizontais, verticais e diagonais) e a aplicação de habilidades em áreas do tabuleiro, afetando os navios de formas específicas.

## Funcionalidades

- **Inicialização do Tabuleiro:** O tabuleiro é preenchido com água (representada por pontos).
- **Posicionamento de Navios:** Os navios são posicionados de maneira fixa no tabuleiro (tanto horizontais, verticais quanto diagonais).
- **Habilidades Especiais:** O jogo permite a aplicação de três tipos de habilidades:
  - **Cruz (C):** Afeta uma linha horizontal e vertical centralizadas na posição escolhida.
  - **Octaedro (O):** Afeta um padrão em forma de octaedro ao redor da posição escolhida.
  - **Cone (N):** Afeta uma área em forma de cone centralizada na posição escolhida.
- **Exibição do Tabuleiro:** O estado do tabuleiro é exibido no console com símbolos representando diferentes entidades:
  - `.` para água.
  - `N` para navios.
  - `*` para áreas afetadas pela habilidade.

## Estrutura do Código

- **Função `inicializarTabuleiro`:** Inicializa o tabuleiro com água.
- **Função `posicionarNavios`:** Posiciona os navios no tabuleiro.
- **Função `aplicarHabilidade`:** Aplica as habilidades no tabuleiro de acordo com o tipo de habilidade e a posição fornecida.
- **Função `exibirTabuleiro`:** Exibe o estado atual do tabuleiro no console.

## Como Usar

1. Clone este repositório para o seu computador.
2. Compile o código usando um compilador C, por exemplo:
   ```bash
   gcc -o batalha_navals batalha_navals.c
Exemplo de Execução
Ao executar o programa, o tabuleiro será exibido no console, mostrando a disposição dos navios e os efeitos das habilidades aplicadas.

Exemplo de saída:

Copiar
Editar
. . . . . . . . . . 
. N N N . . . . . . 
. . * . . . . . . . 
. . * N . . . . . . 
* * * N . . . . . . 
. N * N . . . . . . 
* * * N . . . . . . 
* N * N * * * * * * 
. . * N . . . . . . 
. . * N . . . . . . 
