#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

void separator() {
    printf("----------------------------\n");
}

struct movementsStruct {
    char UP[3];
    char DOWN[5];
    char LEFT[5];
    char RIGHT[6];
};

const struct movementsStruct MOVEMENTS = {
    "UP",
    "DOWN",
    "LEFT",
    "RIGHT"
};

void bishopMovement() {
    for (int up = 3, right = 2; up > 0 || right > 0; up--, right--) {
        printf("%s \n", MOVEMENTS.UP);

        if (right > 0) {
            printf("%s \n", MOVEMENTS.RIGHT);
        }
    }
}

void bishopRecursiveMovement(int up, int right) {
    if (up > 0) {
        printf("%s \n", MOVEMENTS.UP);
        up--;

        if (right > 0) {
            printf("%s \n", MOVEMENTS.RIGHT);
            right--;
        }

        bishopRecursiveMovement(up, right);
    }
}

void queenMovement() {
    int left = 8;

    while (left > 0) {
        printf("%s \n", MOVEMENTS.LEFT);
        left--;
    }
}

void rookMovement() {
    int right = 5;

    do {
        printf("%s \n", MOVEMENTS.RIGHT);
        right--;
    } while (right > 0);
}

void horseMovement() {
    for (int down = 2, left = 1; down > 0 || left > 0; down--) {
        printf("%s \n", MOVEMENTS.DOWN);

        while (left > 0 && down == 1) {
            printf("%s \n", MOVEMENTS.LEFT);
            left--;
        }
    }
}

void horseRecursiveMovement(int down, int left) {
    if (down > 0 || left > 0) {
        printf("%s \n", MOVEMENTS.DOWN);

        if (left > 0 && down == 1) {
            printf("%s \n", MOVEMENTS.LEFT);
            left--;
        }

        down--;
        horseRecursiveMovement(down, left);
    }
}

int main() {
    printf("##### BISHOP MOVEMENT: \n");
    bishopMovement();
    separator();

    printf("##### RECURSIVE BISHOP MOVEMENT: \n");
    bishopRecursiveMovement(3, 2);
    separator();

    printf("##### ROOK MOVEMENT: \n");
    rookMovement();
    separator();

    printf("##### QUEEN MOVEMENT: \n");
    queenMovement();
    separator();

    printf("##### HORSE MOVEMENT: \n");
    horseMovement();
    separator();

    printf("##### HORSE RECURSIVE MOVEMENT: \n");
    horseRecursiveMovement(2, 1);
    separator();

    return 0;
}
