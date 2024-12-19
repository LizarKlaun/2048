void dataCheckClassic(int** field, char move, int* countingMoves, int*** lastField, int* countingReturnedMoves, int* endGame) {
	while (true) {
		cout << "Make your " << *countingMoves << "st move: " << endl;
		move = _getch(); // даём возмонжость выбрать куда походить
		if (move == 0 || move == -32) {
			move = _getch();
		}
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
			++*countingMoves; // прибавляем к числу ходов 1
			selectionRandomOutput(field); // вызываем рандом
			break;
		}
		else if (*countingMoves > 1 && move == 'b') {
			--*countingMoves;
			++*countingReturnedMoves;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					field[i][j] = lastField[*countingMoves - 1][i][j];
				}
			}
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
