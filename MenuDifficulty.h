void difficultyMenu(char** menuDifficulty, int* locationXmenuDifficulty, int* dificulty) {
	char move;
	while (true) {
		system("cls");
		cout << "Select game mode: " << endl << endl;
		for (int i = 0; i < 5; i++) {
			if (*locationXmenuDifficulty == i) {
				cout << "-> ";
			}
			if (*dificulty == i) {
				cout << '!' << menuDifficulty[i] << " | ";
			}
			else {
				cout << menuDifficulty[i] << " | ";
			}
		}

		cout << endl;
		move = _getch();
		if (move == 0 || move == -32) {
			move = _getch();
		}
		if (move == 27) {
			system("cls");
			return;
		}
		if (move == 77 || move == 'd' || move == 'D') {
			if (*locationXmenuDifficulty < 4) {
				system("cls");
				*locationXmenuDifficulty += 1;
			}
		}
		if (move == 75 || move == 'a' || move == 'A') {
			if (*locationXmenuDifficulty > 0) {
				system("cls");
				*locationXmenuDifficulty -= 1;
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuDifficulty == 0) {
				system("cls");
				*dificulty = 0;
			}
			if (*locationXmenuDifficulty == 1) {
				system("cls");
				*dificulty = 1;
			}
			if (*locationXmenuDifficulty == 2) {
				system("cls");
				*dificulty = 2;
			}
			if (*locationXmenuDifficulty == 3) {
				system("cls");
				*dificulty = 3;
			}
			if (*locationXmenuDifficulty == 4) {
				system("cls");
				return;
			}
		}
	}
}