#include <iostream>
using namespace std;

struct bomb{
    bool isBomb = false;
    int n;
};

void generateGround (bomb ground[], int len, int bombNum) {
    for (int i = 0; i < len; i++) {
        if (i < bombNum)
            ground[i].isBomb = true;
    }

    int randomIndex = 0;
    bomb temp;

    for (int i = 0; i < len; i++) {
        randomIndex = rand() % len;
        temp = ground[i];
        ground[i] = ground[randomIndex];
        ground[randomIndex] = temp;
    }
}

void placement(bomb d2[5][5] , bomb d1[], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            d2[i][j] = d1[5 * i + j];
        }
    }
}

void printMatrix (bomb d2[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << d2[i][j].isBomb << "  ";
        }
        cout << "\n";
    }
}

main() {
    srand(time(NULL));

    bomb x[25];
    generateGround(x, 25, 5);

    bomb y[5][5];
    placement(y, x, 5);

    printMatrix(y);
}
