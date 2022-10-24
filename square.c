#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ms[3][3];

int isMagicSquare(int ms[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (ms[i][0] + ms[i][1] + ms[i][2] != 15 
                || ms[0][i] + ms[1][i] + ms[2][i] != 15) {
            return 0;
        }
    }
    return ms[0][0] + ms[1][1] + ms[2][2] == 15 
            && ms[0][2] + ms[1][1] + ms[2][0] == 15;
}

int main() {
    srand(time(NULL));
    int count = 0;
    do {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                ms[row][col] = 0;
            }
        }
        for (int i = 1; i <= 9; i++) {
            int row, col;
            do {
                row = rand() % 3;
                col = rand() % 3;
            } while (ms[row][col] != 0);
            ms[row][col] = i;
        }
        count++;
    } while (isMagicSquare(ms) == 0);
    printf("%d squares generated before a magic square was found\n", count);
    for (int row = 0; row < 3; row++) {
        printf("[%d %d %d]\n", ms[row][0], ms[row][1], ms[row][2]);
    }
    return 0;
}