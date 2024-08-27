/*
ALUNO...: LUCAS ANTONIO GUANDALIN
DATA....: 23/08/24
OBJETIVO: Simula jogo da megasena
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main() {
    int sorteados[6];
    int palpites[6];
    int palpite;
    int num_aleatorio;
    int acertos;
    char grava;
    int i;
    int j;

    system("cls");

    palpite = 0;
    for (i = 0; i < 6; i++) {
        printf("Digite o palpite %d: ", i + 1);
        scanf("%d", &palpite);
        grava = 's';
        // verifica se o palpite esta entre 1 e 60
        if (palpite < 1 || palpite > 60) {
            printf("Digite um numero entre 1 e 60 !!\n");
            getch();
            grava = 'n';
            i--;
        }
        
        // verifica se o numero esta duplicado
        for (j = 0; j < 6; j++) {
            if (palpite == palpites[j]) {
                printf("Numero repetido, digite outro numero!!\n");
                getch();
                grava = 'n';
                i--;
            }
        }

        if (grava == 's') {
            palpites[i] = palpite;
        }

        system("cls");
    }
    
    srand(time(NULL));

    for (i = 0; i < 6; i++) {
        num_aleatorio = rand() % 60 + 1;
        for (j = 0; j < 6; j++) {
            if (num_aleatorio == sorteados [j]) {
                num_aleatorio = rand() % 60 + 1;
                j = -1;                
            }
        }
        sorteados[i] = num_aleatorio;

        printf("Sorteado: %d\tPalpite: %d\n", sorteados[i], palpites[i]);
    }   

    acertos = 0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (palpites[i] == sorteados[j]) {
                acertos++;
            }
        }
    }

    printf("\nVoce acertou: %d numeros", acertos);
    if (acertos == 6) {
        printf("\nParabens voce ganhou !!");
    }
    
}
