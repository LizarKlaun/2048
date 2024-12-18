void gameEndLvl(int** field, int* endGame, int* adventureModeLvl, int* adventureModeMaxLvl) {
	int similarityСells = 0;
	int pointCounter = 0;
	int maxCounter = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			pointCounter += field[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (field[i][j] > maxCounter) {
				maxCounter = field[i][j];
			}
		}
	}
	for (int i = 0; i < 4; i++) { // проверка на конец игры
		for (int j = 0; j < 4; j++) {
			if (*adventureModeLvl == 1) {
				if (maxCounter >= 64 && pointCounter >= 90) {
					if (*adventureModeMaxLvl < 2) {
						cout << endl;
						*adventureModeMaxLvl = 2;
						cout << "You unlocked the first lvl in Adventure mode!!!" << endl;
					}
					*endGame = 1;
				}
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
