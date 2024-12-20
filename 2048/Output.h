void gameOutput(int** field) { // здесь создаём мы функцию которая выводит всю игру
	int maxNumber = 0; // нужно чтобы узнать максимальное число в массиве
	int minNumber = 0;
	int numberOfDigitsMax = 0;
	int minNumberOfDigitsMax = 0;
	for (int i = 0; i < 4; i++) { // перебераем все числа во всех масивах
		for (int j = 0; j < 4; j++) {
			if (field[i][j] > maxNumber) { // cмотрим является ли оно меньше прошлой проверки
				maxNumber = field[i][j];
			}
		}
	}
	do {
		numberOfDigitsMax++;
		maxNumber /= 10; // Уменьшаем число, деля на 10
	} while (maxNumber > 0);
	for (int i = 0; i < 4; i++) { // перебераем все числа во всех масивах
		for (int j = 0; j < 4; j++) {
			if (field[i][j] < minNumber && field[i][j] < 0) { // cмотрим является ли оно меньше прошлой проверки
				minNumber = field[i][j];
			}
		}
	}
	if (minNumber != 0 && numberOfDigitsMax < 3) {
		numberOfDigitsMax = 3;
	}
	for (int i = 0; i < 4; i++) { // снова перебераем всё
		for (int j = 0; j < 4; j++) {
			int index = field[i][j];
			int numberOfDigitsElement = 0;
			do {
				numberOfDigitsElement++;
				index /= 10; // Уменьшаем число, деля на 10
			} while (index > 0);
			if (numberOfDigitsElement == 1) {
				for (int k = 0; k < (numberOfDigitsMax / 2); k++) {
					if (field[i][j] >= 0 || k != (numberOfDigitsMax / 2 - 1)) {
						cout << " ";
					}
					else {
						cout << "[";
					}
				}
			}
			else if (numberOfDigitsMax % 2 != 0) {
				for (int k = 0; k < (numberOfDigitsMax / 2 - numberOfDigitsElement / 2); k++) {
					if (field[i][j] >= 0 || k != (numberOfDigitsMax / 2 - numberOfDigitsElement / 2 - 1)) {
						cout << " ";
					}
					else {
						cout << "[";
					}
				}
			}
			else {
				for (int k = 0; k < ((numberOfDigitsMax / 2 + 1) - numberOfDigitsElement); k++) {
					if (field[i][j] >= 0 || k != ((numberOfDigitsMax / 2 + 1) - numberOfDigitsElement - 1)) {
						cout << " ";
					}
					else {
						cout << "[";
					}
				}
			}
			if (field[i][j] >= 0) {
				cout << field[i][j];
			}
			else {
				cout << abs(field[i][j] % 10);
			}
			if (numberOfDigitsMax % 2 != 0) {
				if (numberOfDigitsElement == 1) {
					int a = 0;
					for (int k = 0; k < ((numberOfDigitsMax / 2 + 1) - (numberOfDigitsElement / 2)); k++) {
						if (field[i][j] >= 0 || a != 0) {
							cout << " ";
						}
						else {
							a++;
							cout << "]";
						}
					}
				}
				else if (numberOfDigitsElement % 2 == 0) {
					int a = 0;
					for (int k = 0; k < ((numberOfDigitsMax/2 + 2) - (numberOfDigitsElement/2)); k++) {
						if (field[i][j] >= 0 || a != 0) {
							cout << " ";
						}
						else {
							a++;
							cout << "]";
						}
					}
				}
				else {
					int a = 0;
					for (int k = 0; k < ((numberOfDigitsMax / 2 + 1) - (numberOfDigitsElement / 2)); k++) {
						if (field[i][j] >= 0 || a != 0) {
							cout << " ";
						}
						else {
							a++;
							cout << "]";
						}
					}
				}
			}
			else if (numberOfDigitsElement == 1) {
				int a = 0;
				for (int k = 0; k < (numberOfDigitsMax / 2); k++) {
					if (field[i][j] >= 0 || a != 0) {
						cout << " ";
					}
					else {
						a++;
						cout << "]";
					}
				}
			}
			else {
				if (numberOfDigitsElement % 2 == 0) {
					int a = 0;
					for (int k = 0; k < ((numberOfDigitsMax/2 + 1) - (numberOfDigitsElement/2)); k++) {
						if (field[i][j] >= 0 || a != 0) {
							cout << " ";
						}
						else {
							a++;
							cout << "]";
						}
					}
				}
				else {
					int a = 0;
					for (int k = 0; k < ((numberOfDigitsMax / 2 + 1) - (numberOfDigitsElement / 2)); k++) {
						if (field[i][j] >= 0 || a != 0) {
							cout << " ";
						}
						else {
							a++;
							cout << "]";
						}
					}
				}
			}
		}
		for (int j = 0; j < ((numberOfDigitsMax +1)/2); j++) {
			cout << endl;
		}
	}
}
