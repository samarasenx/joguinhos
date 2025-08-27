#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    srand(time(NULL));


    printf("| PEDRA PAPEL E TESOURA |\n");

    int computador = rand() % 3 + 1;

    int jogador;
    printf("Escolha uma das opcoes: \n");
    printf("1) Pedra\n");
    printf("2) Papel\n");
    printf("3) Tesoura\n");

    scanf("%d", &jogador);

    if(computador==jogador){
        printf("Empate!\n");
    }
    else if(computador==1 && jogador==2 || computador==2 && jogador==3 || computador==3 && jogador==1){
        printf("Voce ganhou parabens!\n");
    }
    else{
        printf("Voce perdeu!\n");
    }


    return 0;
}
