void startMenu(char** menuStart, int* locationXmenuStart, int topCountingMoves, int topCountingReturnedMoves, int topPointCounter, int topMaxCounter, char** menuMode, int* mode,  int* locationXmenuMode, char** menuModeAdventure, int* locationXmenuModeAdventure, int* adventureModeLvl, int* adventureModeMaxLvl, char** menuExit, int* locationXmenuExit, int* exit, char** menuDifficulty, int* locationXmenuDifficulty, int* dificulty, int** field, int* randOnBlock) {
	char move;
	while (true) {
		system("cls");
		cout << "\t\t    22222     0000    4    4    8888  \n";
		cout << "\t\t   2     2   0    0   4    4   8    8 \n";
		cout << "\t\t        2    0    0   4    4   8    8 \n";
		cout << "\t\t       2     0    0   444444    8888  \n";
		cout << "\t\t      2      0    0        4   8    8 \n";
		cout << "\t\t    2        0    0        4   8    8 \n";
		cout << "\t\t   2222222    0000         4    8888  \n";
		cout << endl;

		for (int i = 0; i < 6; i++) {
			if (*locationXmenuStart == i) {
				cout << "-> ";
			}
			cout << menuStart[i] << " ";
		}
		cout << endl;
		move = _getch();
		if (move == 0 || move == -32) {
			move = _getch();
		}
		if (move == 27) {
			system("cls");
			exitMenu(menuExit, locationXmenuExit, exit);
		}
		if (move == 77 || move == 'd' || move == 'D') {
			if (*locationXmenuStart < 5) {
				system("cls");
				*locationXmenuStart += 1;
			}
		}
		if (move == 75 || move == 'a' || move == 'A') {
			if (*locationXmenuStart > 0) {
				system("cls");
				*locationXmenuStart -= 1;
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuStart == 0) {
				system("cls");
				return;
			}
			if (*locationXmenuStart == 1) {
				system("cls");
				cout << "Info" << endl << endl;
				cout << "Your top account: " << topPointCounter << endl
					<< "Your top number: " << topMaxCounter << endl
					<< "Your top number of moves: " << topCountingMoves << endl
					<< "Your top number of returned moves: " << topCountingReturnedMoves << endl;
				cout << endl;
				cout << "Press any key to back..." << endl;
				move = _getch();
			}
			if (*locationXmenuStart == 2) {
				system("cls");
				modeMenu(menuMode, mode, locationXmenuMode, menuModeAdventure, locationXmenuModeAdventure, adventureModeLvl, adventureModeMaxLvl, topPointCounter, topMaxCounter, topCountingMoves, topCountingReturnedMoves);
			}
			if (*locationXmenuStart == 3) {
				system("cls");
				difficultyMenu(menuDifficulty, locationXmenuDifficulty, dificulty);
			}
			if (*locationXmenuStart == 4) {
				system("cls");
				tutorial(field, move, randOnBlock);
			}
			if (*locationXmenuStart == 5) {
				system("cls");
				exitMenu(menuExit, locationXmenuExit, exit);
			}
		}
		if (*exit == 1) {
			return;
		}
	}
}