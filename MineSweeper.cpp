#include <iostream>
using namespace std;

class bomb{
    public:
        bool isBomb = false;
        bool isChoice = false;
        bool hasFlag = false;
        int bombNum = 0;
};

void expansion (bomb matrix[20][20], int row, int i, int j) {
    if (matrix[i][j].bombNum != 0 && !matrix[i][j].isChoice && !matrix[i][j].isBomb)
        matrix[i][j].isChoice = true;

    if (matrix[i][j].bombNum == 0 && !matrix[i][j].isChoice) {
        matrix[i][j].isChoice = true;
        if (i == 0) {
            if (j == 0) {            // matrix[0][0]
                expansion(matrix, row, i, j + 1);

                expansion(matrix, row, i + 1, j + 1);

                expansion(matrix, row, i + 1, j);
            }


            else if (j != row - 1 && j != 0) {         // matrix[0][j]
                expansion(matrix, row, i, j + 1);
                    
                expansion(matrix, row, i + 1, j + 1);

                expansion(matrix, row, i + 1, j);

                expansion(matrix, row, i + 1, j - 1);

                expansion(matrix, row, i, j - 1);
            }


            else {     // matrix[0][row - 1]
                expansion(matrix, row, i, j - 1);

                expansion(matrix, row, i + 1, j - 1);

                expansion(matrix, row, i + 1, j);
            }
        }

        else if (i != row - 1) {
            if (j == 0) {          // matrix[i][0]
                expansion(matrix, row, i - 1, j);

                expansion(matrix, row, i - 1, j + 1);

                expansion(matrix, row, i + 1, j);

                expansion(matrix, row, i, j + 1);

                expansion(matrix, row, i + 1, j + 1);
            }

            else if (j != row - 1) {      // matrix[i][j]
                expansion(matrix, row, i - 1, j);

                expansion(matrix, row, i - 1, j + 1);

                expansion(matrix, row, i, j + 1);

                expansion(matrix, row, i + 1, j + 1);

                expansion(matrix, row, i + 1, j);

                expansion(matrix, row, i + 1, j - 1);

                expansion(matrix, row, i, j - 1);

                expansion(matrix, row, i - 1, j - 1);
            }

            else {         // matrix[i][row - 1]
                expansion(matrix, row, i - 1, j);

                expansion(matrix, row, i - 1, j - 1);

                expansion(matrix, row, i + 1, j);

                expansion(matrix, row, i + 1, j - 1);

                expansion(matrix, row, i, j - 1);
            }
        }

        else {
            if (j == 0) {        // matrix[row - 1][0]
                expansion(matrix, row, i - 1, j);

                expansion(matrix, row, i - 1, j + 1);

                expansion(matrix, row, i, j + 1);
            }

            else if (j != row - 1) {       // matrix[row - 1][j]
                expansion(matrix, row, i, j - 1);

                expansion(matrix, row, i - 1, j - 1);

                expansion(matrix, row, i - 1, j);

                expansion(matrix, row, i - 1, j + 1);

                expansion(matrix, row, i, j + 1);
            }

            else {       // matrix[row - 1][row - 1]
                expansion(matrix, row, i, j - 1);

                expansion(matrix, row, i - 1, j - 1);

                expansion(matrix, row, i - 1, j);
            }
        }
    }





}

void generateGround (bomb ground[], int size, int bombNum, int iSafe, int jSafe) {
    int safeHome = iSafe * 5 + jSafe;

    for (int i = 0; i < size; i++) {
        if (i < bombNum)
            ground[i].isBomb = true;
    }

    int randomIndex = 0;
    bomb temp;

    for (int i = 0; i < size - 1; i++) {
        randomIndex = rand() % size - 1;
        temp = ground[i];
        ground[i] = ground[randomIndex];
        ground[randomIndex] = temp;
    }

    for (int i = size; i >= safeHome; i--) {
        if (i != safeHome)
            ground[i] = ground[i - 1];
        else
            ground[i].isBomb = false;
    }
}

void placement(bomb d2[20][20] , bomb d1[], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            d2[i][j] = d1[5 * i + j];
        }
    }
}

void printMatrix (bomb d2[20][20], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (!d2[i][j].isChoice)
                cout << 'X' << "  ";
            
            else if (!d2[i][j].isBomb)
                cout << d2[i][j].bombNum << "  ";
            
            else
                cout << 'M' << "  ";
        } 
        cout << "\n";
    }
}

void findBombNum(bomb matrix[20][20], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
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


                else if (j != row - 1 && j != 0) {         // matrix[0][j]
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


                else {     // matrix[0][row - 1]
                    if (matrix[i][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j - 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i + 1][j].isBomb)
                        matrix[i][j].bombNum ++;
                }
            }

            else if (i != row - 1) {
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

                else if (j != row - 1) {      // matrix[i][j]
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

                else {         // matrix[i][row - 1]
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
                if (j == 0) {        // matrix[row - 1][0]
                    if (matrix[i - 1][j].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i - 1][j + 1].isBomb)
                        matrix[i][j].bombNum ++;

                    if (matrix[i][j + 1].isBomb)
                        matrix[i][j].bombNum ++;
                }

                else if (j != row - 1) {       // matrix[row - 1][j]
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

                else {       // matrix[row - 1][row - 1]
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

void printAll (bomb d2[20][20], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (!d2[i][j].isBomb)
                cout << d2[i][j].bombNum << "  ";
            
            else
                cout << 'M' << "  ";
        } 
        cout << "\n";
    }
}

bool isWin(bomb matrix[20][20], int row, int numOfBomb) {
    bool win = false;
    int counter = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (!matrix[i][j].isChoice)
                counter++;
        }
    }

    if (counter == numOfBomb)
        win = true;

    return win;
}

main() {
    srand(time(NULL));
    int i, j, len, NumOfBomb, choice;
    bomb tempList[400];
    bomb ground[20][20];

    cout << "========== MineSweeper ==========\n\n"
        << "Enter the =lengh= of ground and =number of bombs/mines= (lengh < 20): ";
    cin >> len >> NumOfBomb;

    cout << "Enter i and j: ";
    cin >> i >> j;
    generateGround (tempList, len*len, NumOfBomb, i, j);
    placement(ground, tempList, len);
    findBombNum (ground, len);
    expansion (ground, len, i, j);

    do {
        choice = 0;
        printMatrix(ground, len);

        cout << "\nEnter i and j: ";
        cin >> i >> j;

        if (ground[i][j].isBomb) {
            cout << "\n====== YOU LOSE ======\n\n"
            << "== ground:\n";
            printAll (ground, len);
            return 0;
        }
        expansion (ground, len, i, j);
        
    } while (!isWin(ground, len, NumOfBomb));

    if (isWin(ground, len, NumOfBomb))
        cout << "\n====== YOU WIN ======\n";
}