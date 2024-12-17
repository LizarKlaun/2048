void selectionRandomOutput(int** field) { // функция для создания рандомного число в рандомном месте после хода пользователя
	srand(time(NULL));
	int randomNumber = rand() % 12;
	int counterZero = 0;
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
					indexZero++;
				}
			}
		}
	}
}