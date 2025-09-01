#include<stdio.h>
#define TAM  9

int verificaLinha(int m[TAM][TAM]);
int verificaColuna(int m[TAM][TAM]);
int verificaBloco(int m[TAM][TAM]);

int main(){
    int matriz[TAM][TAM]= {
        {8, 0, 9, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 2, 0},
        {0, 0, 5, 9, 0, 0, 3, 4, 0},
        {0, 0, 4, 0, 9, 0, 0, 0, 6},
        {3, 0, 0, 2, 0, 0, 0, 0, 8},
        {0, 0, 8, 0, 6, 0, 0, 0, 2},
        {0, 0, 2, 1, 0, 0, 6, 8, 0},
        {0, 0, 0, 0, 5, 0, 0, 9, 0},
        {4, 0, 7, 0, 0, 6, 0, 0, 0}
    };

    printf("%d",matriz[TAM][TAM]);

    printf("Adicione um numero ao sudoku:\n");
    char num;
    scanf("%c",&num);
    printf("Agora coçoque a linha e a coluna que deseja adicionar esse numero:\n");
    int linha ,coluna;
    scanf("%d %d",&linha,&coluna);

    if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
        printf("Posicao invalida. Por favor, escolha uma linha e coluna entre 0 e 8.\n");
    } else {
        if (matriz[linha][coluna] == ' ') {
            matriz[linha][coluna] = num;
            printf("Numero adicionado com sucesso!\n");
        } else {
            printf("Essa posicao ja esta ocupada. Escolha outra.\n");
        }
    }


    int a=verificaBloco(matriz);
    int b=verificaLinha(matriz);
    int c=verificaColuna(matriz);

    if(a==1 && b==1 && c==1){
        printf("Parabens!Voce acertou o sudoku.\n");
    }
    else{
        printf("GameOver!Voce perdeu.\n");
    }

    return 0;
}
