#include <stdio.h>

#define boardN 8  // brætstørrelse

// Prototyper
int isValid(int x, int y);
int possibleMoves(int x, int y);
int warnsdorffKnight(int startX, int startY);
void boardReset(void);
void boardPrintR(void);

// Bræt: [række][kolonne] = [y][x]
int boardM[boardN][boardN]; // besøgsrækkefølge (0 = ikke besøgt)
int boardR[boardN][boardN]; // resultat: antal besøgte fra startfelt

// Ridderens 8 træk
static const int moveX[8] = { 2, 1, -1, -2, -2, -1, 1,  2 };
static const int moveY[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

void boardReset(void) {
    for (int r = 0; r < boardN; r++)
        for (int c = 0; c < boardN; c++)
            boardM[r][c] = 0;
}

int isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < boardN && y < boardN && boardM[y][x] == 0);
}

int possibleMoves(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + moveX[i];
        int ny = y + moveY[i];
        if (isValid(nx, ny)) cnt++;
    }
    return cnt;
}

// Warnsdorff: vælg næste felt med færrest fremtidige muligheder
int warnsdorffKnight(int startX, int startY) {
    int moveCount = 1;
    int x = startX, y = startY;
    boardM[y][x] = moveCount;

    while (1) {
        int nextX = -1, nextY = -1;
        int minDegree = 9;

        for (int i = 0; i < 8; i++) {
            int nx = x + moveX[i];
            int ny = y + moveY[i];
            if (!isValid(nx, ny)) continue;

            int deg = possibleMoves(nx, ny);
            if (deg < minDegree) {
                minDegree = deg;
                nextX = nx; nextY = ny;
            }
        }

        if (nextX == -1) break; // ingen videre træk

        x = nextX; y = nextY;
        boardM[y][x] = ++moveCount;
    }
    return moveCount;
}

// Vælg blot den FØRSTE gyldige af de 8 riddertræk (ingen min-degree)
int greedyFirstKnight(int startX, int startY) {
    int moveCount = 1;
    int x = startX, y = startY;
    boardM[y][x] = moveCount;

    while (1) {
        int nextX = -1, nextY = -1;

        // gennemgå træk i fast rækkefølge og tag den første der er valid
        for (int i = 0; i < 8; i++) {
            int nx = x + moveX[i];
            int ny = y + moveY[i];
            if (isValid(nx, ny)) { nextX = nx; nextY = ny; break; }
        }

        if (nextX == -1) break;      // ingen flere træk
        x = nextX; y = nextY;
        boardM[y][x] = ++moveCount;  // marker feltet
    }
    return moveCount;
}

void boardPrintR(void) {
    for (int r = 0; r < boardN; r++) {
        for (int c = 0; c < boardN; c++)
            printf("%2d ", boardR[r][c]);
        printf("\n");
    }
}

int main(void) {
    // --- WARNDORFF (smart version) ---
    for (int r = 0; r < boardN; r++) {
        for (int c = 0; c < boardN; c++) {
            boardReset();
            boardR[r][c] = warnsdorffKnight(c, r);
        }
    }
    printf("warnsdorff:\n");
    boardPrintR();

    // --- GREEDY (første mulige træk) ---
    for (int r = 0; r < boardN; r++) {
        for (int c = 0; c < boardN; c++) {
            boardReset();
            boardR[r][c] = greedyFirstKnight(c, r);
        }
    }
    printf("greedy:\n");
    boardPrintR();

    return 0;
}
