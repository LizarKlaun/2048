void selectionRandomOutput(int** field, int* dificulty, int* randOnBlock) { // функция для создания рандомного число в рандомном месте после хода пользователя
	srand(time(NULL));
	int randomNumber = rand() % 12;
	int counterZero = 0;
	bool exitFlag = false;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (field[i][j] == 0) {
				counterZero++;
			}
		}
	}
	int randZero = rand() % counterZero;
	int indexZero = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (field[i][j] == 0) {
				if (indexZero == randZero) {
					if (*dificulty == 0 || *dificulty == 1) {
						field[i][j] = 2;
						return;
					}
					else if (*dificulty == 2) {
						if (randomNumber < 8) {
							field[i][j] = 2;
							return;
						}
						else if (randomNumber < 11) {
							field[i][j] = 4;
							return;
						}
						else if (randomNumber == 11) {
							field[i][j] = 8;
							return;
						}
					}
					else {
						if (randomNumber < 8) {
							field[i][j] = 2;
							exitFlag = true;
							break;
						}
						else if (randomNumber < 11) {
							field[i][j] = 4;
							exitFlag = true;
							break;
						}
						else if (randomNumber == 11) {
							field[i][j] = 8;
							exitFlag = true;
							break;
						}
					}
				}
				else {
					indexZero++;
				}
			}
		}
		if (exitFlag) break;
	}

	if (*dificulty == 3) {
		if (*randOnBlock != 4) {
			*randOnBlock = rand() % 5;
		}
		if (*randOnBlock == 4) {
			int randSetBlock = rand() % 17;
			int index = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (index == randSetBlock && field[i][j] >= 0) {
						if (field[i][j] != 0) {
							field[i][j] *= -10;
							field[i][j] -= rand() % 9 + 1;
							return;
						}
						else {
							field[i][j] = 30;
							field[i][j] *= -1;
							field[i][j] -= rand() % 9 + 1;
							return;
						}
					}
					else {
						index++;
					}
				}
			}
		}
	}
}