void exitMenu(char** menuExit, int* locationXmenuExit) {
	char move;
	while (true) {
		system("cls");
		cout << "Are you sure?(" << endl << endl;
		for (int i = 0; i < 3; i++) {
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
				char* tempArrow = menuExit[*locationXmenuExit];
				menuExit[*locationXmenuExit] = menuExit[*locationXmenuExit + 1];
				menuExit[*locationXmenuExit + 1] = tempArrow;
				*locationXmenuExit += 1;
			}
		}
		if (move == 75 || move == 'a' || move == 'A') {
			if (*locationXmenuExit > 0) {
				system("cls");
				char* tempArrow = menuExit[*locationXmenuExit];
				menuExit[*locationXmenuExit] = menuExit[*locationXmenuExit - 1];
				menuExit[*locationXmenuExit - 1] = tempArrow;
				*locationXmenuExit -= 1;
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuExit == 0) {
				cout << endl;
				exit(0);
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuExit == 1) {
				return;
			}
		}
	}
}