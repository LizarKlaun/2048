void modeMenu(char** menuMode, int* mode, int* locationXmenuMode, char** menuModeAdventure, int* locationXmenuModeAdventure, int* adventureModeLvl, int* adventureModeMaxLvl, int topCountingMoves, int topCountingReturnedMoves, int topPointCounter, int topMaxCounter) {
	char move;
	while (true) {
		system("cls");
		cout << "Select game mode: " << endl << endl;
		for (int i = 0; i < 5; i++) {
			if (*locationXmenuMode == i) {
				cout << "-> ";
			}
			if (*mode == i) {
				cout << '!' << menuMode[i] << " ";
			}
			else {
				cout << menuMode[i] << " ";
			}
		}
		cout << endl;
		move = _getch();
		if (move == 27) {
			system("cls");
			return;
		}
		if (move == 77 || move == 'd' || move == 'D') {
			if (*locationXmenuMode < 4) {
				system("cls");
				*locationXmenuMode += 1;
			}
		}
		if (move == 75 || move == 'a' || move == 'A') {
			if (*locationXmenuMode > 0) {
				system("cls");
				*locationXmenuMode -= 1;
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuMode == 0) {
				*mode = 0;
				system("cls");
			}
			if (*locationXmenuMode == 1) {
				system("cls");
				modeAdventureMenu(menuModeAdventure, locationXmenuModeAdventure, adventureModeLvl, adventureModeMaxLvl, topPointCounter, topMaxCounter, topCountingMoves, topCountingReturnedMoves, mode);
			}
			if (*locationXmenuMode == 2) {
				*mode = 2;
				system("cls");
			}
			if (*locationXmenuMode == 3) {
				*mode = 3;
				system("cls");
			}
			if (*locationXmenuMode == 4) {
				system("cls");
				return;
			}
		}
	}
}