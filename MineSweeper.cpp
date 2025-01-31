#include <iostream>
using namespace std;

class bomb{
    public:
        bool isBomb = false;
        int bombNum = 0;
};

void generateGround (bomb ground[], int len, int bombNum, int iSafe, int jSafe) {
    int safeHome = iSafe * 5 + jSafe;

    for (int i = 0; i < len; i++) {
        if (i < bombNum)
            ground[i].isBomb = true;
    }

    int randomIndex = 0;
    bomb temp;

    for (int i = 0; i < len - 1; i++) {
        randomIndex = rand() % len - 1;
        temp = ground[i];
        ground[i] = ground[randomIndex];
        ground[randomIndex] = temp;
    }

    for (int i = len; i >= safeHome; i--) {
        if (i != safeHome)
            ground[i] = ground[i - 1];
        else
            ground[i].isBomb = false;
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
            if (d2[i][j].isBomb)
                cout << 'X' << "  ";
            else
                cout << d2[i][j].bombNum << "  ";
        }
        cout << "\n";
    }
}

void findBombNum(bomb matrix[5][5], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            // matrix[i][j].bombNum = 0;

            if (i == 0) {
                if (j == 0) {            // matrix[0][0]
                    if (matrix[i][j + 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j + 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j].isBomb)
                        matrix[i][j].bombNum ++;
                }


                else if (j != len - 1 && j != 0) {         // matrix[0][j]
                    if (matrix[i][j + 1].isBomb)
                        {matrix[i][j].bombNum ++;}
                    
                    if (matrix[i + 1][j + 1].isBomb)
                        {matrix[i][j].bombNum ++;}

                    if (matrix[i + 1][j].isBomb)
                        {matrix[i][j].bombNum ++;}

                    if (matrix[i + 1][j - 1].isBomb)
                        {matrix[i][j].bombNum ++;}

                    if (matrix[i][j - 1].isBomb)
                        {matrix[i][j].bombNum ++;}
                }


                else {     // matrix[0][len - 1]
                    if (matrix[i][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j].isBomb)
                        matrix[i][j].bombNum ++;
                }
            }

            else if (i != len - 1) {
                if (j == 0) {          // matrix[i][0]
                    if (matrix[i - 1][j].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i - 1][j + 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i][j + 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j + 1].isBomb)
                        matrix[i][j].bombNum ++;
                }

                else if (j != len - 1) {      // matrix[i][j]
                    if (matrix[i - 1][j].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i - 1][j + 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i][j + 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j + 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i - 1][j - 1].isBomb)
                        matrix[i][j].bombNum ++;
                }

                else {         // matrix[i][len - 1]
                    if (matrix[i - 1][j].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i - 1][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i][j - 1].isBomb)
                        matrix[i][j].bombNum ++;
                }
            }

            else {
                if (j == 0) {        // matrix[len - 1][0]
                    if (matrix[i - 1][j].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i - 1][j + 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i][j + 1].isBomb)
                        matrix[i][j].bombNum ++;
                }

                else if (j != len - 1) {       // matrix[len - 1][j]
                    if (matrix[i][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i - 1][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i - 1][j].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i - 1][j + 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i][j + 1].isBomb)
                        matrix[i][j].bombNum ++;
                }

                else {       // matrix[len - 1][len - 1]
                    if (matrix[i][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i - 1][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i - 1][j].isBomb)
                        matrix[i][j].bombNum ++;
                }
            }
        }
    }
}

main() {
    srand(time(NULL));

    int i, j;

    cout << "Enter i and j: ";
    cin >> i >> j;

    bomb x[25];
    generateGround(x, 25, 5, i, j);

    bomb y[5][5];
    placement(y, x, 5);

    printMatrix(y);

    cout << "\n\n";

    findBombNum(y, 5);

    printMatrix(y);
}