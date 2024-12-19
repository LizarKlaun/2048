void gameOutput(int** field) { // здесь создаём мы функцию которая выводит всю игру
	int a = 0; // нужно чтобы узнать максимальное число в массиве
	int numberOfDigits = 0;
	for (int i = 0; i < 4; i++) { // перебераем все числа во всех масивах
		for (int j = 0; j < 4; j++) {
			if (field[i][j] > a) { // cмотрим является ли оно меньше прошлой проверки
				a = field[i][j];
			}
		}
	}
	do {
		numberOfDigits++;
		a /= 10; // Уменьшаем число, деля на 10
	} while (a > 0);
	for (int i = 0; i < 4; i++) { // снова перебераем всё
		for (int j = 0; j < 4; j++) {
			cout << field[i][j];
			a = field[i][j];
			int numberOfDigitsElement = 0;
			do {
				numberOfDigitsElement++;
				a /= 10; // Уменьшаем число, деля на 10
			} while (a > 0);
			for (int k = 0; k < (numberOfDigits-(numberOfDigitsElement-1)); k++) {
				cout << " ";
			}
		}
		for (int j = 0; j < ((numberOfDigits+1)/2); j++) {
			cout << endl;
		}
	}
}
