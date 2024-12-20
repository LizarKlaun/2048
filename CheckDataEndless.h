void dataCheckEndless(int** field, char move, int* countingMoves, int*** lastField, int* countingReturnedMoves, int* endGame, int* dificulty, int* randOnBlock, char** menuDifficulty, int* countingOfLegalReturnedMoves) {
	while (true) {
		if (*countingOfLegalReturnedMoves != 0 && *dificulty != 0) {
			cout << "You can go back " << *countingOfLegalReturnedMoves << " times" << endl;
		}
		else if (*dificulty == 0) {
			cout << "You can go back forever" << endl;
		}
		else {
			cout << "You can't go back" << endl;
		}
		cout << "Make your " << *countingMoves << "st move: ";
		move = _getche(); // даём возмонжость выбрать куда походить
		if (move == 0 || move == -32) {
			move = _getche();
		}
		cout << endl;
		playerMoveOutput(field, move);
		int similarityField = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (lastField[*countingMoves - 1][i][j] != field[i][j]) {
					similarityField = 1;
				}
			}
		}
		if (similarityField == 1) {
			system("cls");
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (field[i][j] < 0) {
						field[i][j] += 1;
					}
					if (abs(field[i][j] % 10) <= 0) {
						field[i][j] /= -10;
						if (field[i][j] == 3) {
							field[i][j] = 0;
						}
					}
				}
			}
			cout << "Endless mode" << endl << endl;
			cout << "Dificulty " << menuDifficulty[*dificulty] << endl << endl;
			++*countingMoves; // прибавляем к числу ходов 1
			selectionRandomOutput(field, dificulty, randOnBlock); // вызываем рандом
			break;
		}
		else if (*countingMoves > 1 && move == 'b' && *countingOfLegalReturnedMoves != 0) {
			--*countingMoves;
			--*countingOfLegalReturnedMoves;
			++*countingReturnedMoves;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					field[i][j] = lastField[*countingMoves - 1][i][j];
				}
			}
			cout << endl;
			break;
		}
		else if (move == 27) {
			system("cls");
			*endGame = 2;
			break;
		}
		else {
			cout << "Error. Press A W S D" << endl;
		}
	}
}
