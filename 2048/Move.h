#pragma once
int** playesMoveOutput(int** field, int countingMoves, char move) {
    cout << "Make your " << countingMoves << "st move: ";
    cin >> move;
    if (move == 'w' || move == 'W') {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (field[i][j] != 0) {
                    if (field[0][j] == field[i][j] && i != 0) {
                        cout << "plus" << endl;
                        field[0][j] += field[i][j];
                        field[i][j] = 0;
                    }
                    else if (field[1][j] == field[i][j] && i != 1) {
                        cout << "plus" << endl;
                        field[1][j] += field[i][j];
                        field[i][j] = 0;
                    }
                    else if (field[2][j] == field[i][j] && i != 2) {
                        cout << "plus" << endl;
                        field[2][j] += field[i][j];
                        field[i][j] = 0;
                    }
                    else if (field[0][j] == 0) {
                        cout << "reverse" << endl;
                        field[0][j] = field[i][j];
                        field[i][j] = 0;
                    }
                    else if (field[1][j] == 0) {
                        cout << "reverse" << endl;
                        field[1][j] = field[i][j];
                        field[i][j] = 0;
                    }
                    else if (field[2][j] == 0) {
                        cout << "reverse" << endl;
                        field[2][j] = field[i][j];
                        field[i][j] = 0;
                    }
                }
            }
        }
    }
    else if (move == 'a' || move == 'A') {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (field[i][j] != 0) {
                    if (field[i][0] == field[i][j] && j != 0) {
                        cout << "plus" << endl;
                        field[i][0] += field[i][j];
                        field[i][j] = 0;
                    }
                    else if (field[i][1] == field[i][j] && j != 1) {
                        cout << "plus" << endl;
                        field[i][1] += field[i][j];
                        field[i][j] = 0;
                    }
                    else if (field[i][2] == field[i][j] && j != 2) {
                        cout << "plus" << endl;
                        field[i][2] += field[i][j];
                        field[i][j] = 0;
                    }
                    else if (field[i][0] == 0) {
                        cout << "reverse" << endl;
                        field[i][0] = field[i][j];
                        field[i][j] = 0;
                    }
                    else if (field[i][1] == 0) {
                        cout << "reverse" << endl;
                        field[i][1] = field[i][j];
                        field[i][j] = 0;
                    }
                    else if (field[i][2] == 0) {
                        cout << "reverse" << endl;
                        field[i][2] = field[i][j];
                        field[i][j] = 0;
                    }
                }
            }
        }
    }
    selectionRandomOutput(field);
    gameOutput(field);
    return field;
}