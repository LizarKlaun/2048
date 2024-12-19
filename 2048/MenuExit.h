void exitMenu(char** menuExit, int* locationXmenuExit, int* exit) {
	char move;
	while (true) {
		system("cls");
		cout << "Are you sure?(" << endl << endl;
		for (int i = 0; i < 2; i++) {
			if (*locationXmenuExit == i) {
				cout << "-> ";
			}
			cout << menuExit[i] << " ";
		}
		move = _getch();
		if (move == 27) {
			system("cls");
			return;
		}
		if (move == 77 || move == 'd' || move == 'D') {
			if (*locationXmenuExit < 1) {
				system("cls");
				*locationXmenuExit += 1;
			}
		}
		if (move == 75 || move == 'a' || move == 'A') {
			if (*locationXmenuExit > 0) {
				system("cls");
				*locationXmenuExit -= 1;
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuExit == 0) {
				cout << endl;
				*exit = 1;
				return;
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuExit == 1) {
				return;
			}
		}
		if (move == 'y' || move == 'Y') {
			cout << endl;
			*exit = 1;
			return;
		}
		if (move == 'n' || move == 'N') {
			return;
		}
	}
}