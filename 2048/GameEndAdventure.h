void gameEndAdvenchure(int** field, int* endGame, int* adventureModeLvl, int* adventureModeMaxLvl, int* countingMoves) {
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
						cout << "You complete first lvl and you unlocked second lvl in Adventure mode!!!" << endl;
					}
					*endGame = 1;
					return;
				}
			}
			if (*adventureModeLvl == 2) {
				if (maxCounter >= 128 && *countingMoves >= 100) {
					if (*adventureModeMaxLvl < 3) {
						cout << endl;
						*adventureModeMaxLvl = 3;
						cout << "You complete second lvl and you unlocked third lvl in Adventure mode!!!" << endl;
					}
					*endGame = 1;
					return;
				}
			}
			if (*adventureModeLvl == 3) {
				if (maxCounter >= 256 && *countingMoves >= 150) {
					if (*adventureModeMaxLvl < 4) {
						cout << endl;
						*adventureModeMaxLvl = 4;
						cout << "You complete third lvl and you unlocked fourth lvl in Adventure mode!!!" << endl;
					}
					*endGame = 1;
					return;
				}
			}
			if (*adventureModeLvl == 4) {
				if (maxCounter >= 512 && pointCounter >= 850) {
					if (*adventureModeMaxLvl < 5) {
						cout << endl;
						*adventureModeMaxLvl = 5;
						cout << "You complete fourth lvl and you unlocked sixth lvl in Adventure mode!!!" << endl;
					}
					*endGame = 1;
					return;
				}
			}
			if (*adventureModeLvl == 5) {
				if (maxCounter >= 1024 && *countingMoves >= 250) {
					if (*adventureModeMaxLvl < 6) {
						cout << endl;
						*adventureModeMaxLvl = 6;
						cout << "You complete sixth lvl and you unlocked seventh lvl in Adventure mode!!!" << endl;
					}
					*endGame = 1;
					return;
				}
			}
			if (*adventureModeLvl == 6) {
				if (maxCounter >= 2048) {
					if (*adventureModeMaxLvl < 7) {
						cout << endl;
						*adventureModeMaxLvl = 7;
						cout << "You complete seventh lvl in Adventure mode!!!" << endl;
					}
					*endGame = 1;
					return;
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
