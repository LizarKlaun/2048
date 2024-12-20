void gameEndClassic(int** field, int* endGame) {
	int similarityСells = 0;
	for (int i = 0; i < 4; i++) { // проверка на конец игры
		for (int j = 0; j < 4; j++) {
			if (field[i][j] == 2048) {
				*endGame = 1;
				return;
			}
			if (i != 3) {
				if (field[i][j] == field[i + 1][j]) {
					similarityСells += 1;
				}
			}
			if (j != 3) {
				if (field[i][j] == field[i][j + 1]) {
					similarityСells += 1;
				}
			}
			if (field[i][j] == 0) {
				similarityСells += 1;
			}
		}
	}
	if (similarityСells == 0) {
		*endGame = 2;
	}
}