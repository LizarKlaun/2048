void modeAdventureMenu(char** menuModeAdventure, int* locationXmenuModeAdventure, int* adventureModeLvl, int* adventureModeMaxLvl, int topCountingMoves, int topCountingReturnedMoves, int topPointCounter, int topMaxCounter) {
	char move;
	while (true) {
		system("cls");
		cout << "Select lvl game: " << endl << endl;
		for (int i = 0; i < 6; i++) {
			if (*locationXmenuModeAdventure == i) {
				cout << "-> ";
			}
			if (*adventureModeLvl-1 == i) {
				cout << '!' << menuModeAdventure[i] << " | ";
			}
			else {
				if (*adventureModeMaxLvl <= i) {
					cout << '#' << menuModeAdventure[i] << "# | ";
				}
				else {
					cout << menuModeAdventure[i] << " | ";
				}
			}
		}
		cout << menuModeAdventure[6];
		cout << endl;
		move = _getch();
		if (move == 27) {
			system("cls");
			return;
		}
		if (move == 77 || move == 'd' || move == 'D') {
			if (*locationXmenuModeAdventure < 6) {
				system("cls");
				*locationXmenuModeAdventure += 1;
			}
		}
		if (move == 75 || move == 'a' || move == 'A') {
			if (*locationXmenuModeAdventure > 0) {
				system("cls");
				*locationXmenuModeAdventure -= 1;
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuModeAdventure == 0) {
				if (*adventureModeMaxLvl >= 1) {
					*adventureModeLvl = 1;
					if (*adventureModeMaxLvl == 1) {
						system("cls");
						cout << "First lvl" << endl << endl;
						cout << "This level is not complete." << endl << endl << "To complete this level you need: " << endl;
						cout << "Top account: 90 >> Your top account: " << topPointCounter << endl;
						cout << "Top number: 64 >> Your top number: " << topMaxCounter << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
						system("cls");
					}
					else {
						system("cls");
						cout << "First lvl" << endl << endl;
						cout << "You complete this lvl!" << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
					}
				}
			}
			if (*locationXmenuModeAdventure == 1) {
				if (*adventureModeMaxLvl >= 2) {
					*adventureModeLvl = 2;
					if (*adventureModeMaxLvl == 2) {
						system("cls");
						cout << "Second lvl" << endl << endl;
						cout << "This level is not complete." << endl << endl << "To complete this level you need: " << endl;
						cout << "Top number of moves: 100 >> Your top number of moves: " << topCountingMoves << endl;
						cout << "Top number: 128 >> Your top number: " << topMaxCounter << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
						system("cls");
					}
					else {
						system("cls");
						cout << "Second lvl" << endl << endl;
						cout << "You complete this lvl!" << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
					}
				}
				else {
					system("cls");
					cout << "Second lvl" << endl << endl;
					cout << "This level is locked." << endl << endl << "To unlock it you need to earn in the first lvl: " << endl;
					cout << "Top account: 90 >> Your top account: " << topPointCounter << endl;
					cout << "Top number: 64 >> Your top number: " << topMaxCounter << endl;
					cout << endl;
					cout << "Press any key to back... " << endl;
					move = _getch();
					system("cls");
				}
			}
			if (*locationXmenuModeAdventure == 2) {
				if (*adventureModeMaxLvl >= 3) {
					*adventureModeLvl = 3;
					if (*adventureModeMaxLvl == 3) {
						system("cls");
						cout << "Third lvl" << endl << endl;
						cout << "This level is not complete." << endl << endl << "To complete this level you need: " << endl;
						cout << "Top number of moves: 150 >> Your top number of moves: " << topCountingMoves << endl;
						cout << "Top number: 256 >> Your top number: " << topMaxCounter << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
						system("cls");
					}
					else {
						system("cls");
						cout << "Third lvl" << endl << endl;
						cout << "You complete this lvl!" << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
					}
				}
				else {
					system("cls");
					cout << "Third lvl" << endl << endl;
					cout << "This level is locked." << endl << endl << "To unlock it you need to earn in the second lvl: " << endl;
					cout << "Top number of moves: 100 >> Your top number of moves: " << topCountingMoves << endl;
					cout << "Top number: 128 >> Your top number: " << topMaxCounter << endl;
					cout << endl;
					cout << "Press any key to back... " << endl;
					move = _getch();
					system("cls");
				}
			}
			if (*locationXmenuModeAdventure == 3) {
				if (*adventureModeMaxLvl >= 4) {
					*adventureModeLvl = 4;
					if (*adventureModeMaxLvl == 4) {
						system("cls");
						cout << "Fourth lvl" << endl << endl;
						cout << "This level is not complete." << endl << endl << "To complete this level you need: " << endl;
						cout << "Top number of moves: 850 >> Your top number of moves: " << topPointCounter << endl;
						cout << "Top number: 512 >> Your top number: " << topMaxCounter << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
						system("cls");
					}
					else {
						system("cls");
						cout << "Fourth lvl" << endl << endl;
						cout << "You complete this lvl!" << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
					}
				}
				else {
					system("cls");
					cout << "Fourth lvl" << endl << endl;
					cout << "This level is locked." << endl << endl << "To unlock it you need to earn in the second lvl: " << endl;
					cout << "Top number of moves: 150 >> Your top number of moves: " << topCountingMoves << endl;
					cout << "Top number: 256 >> Your top number: " << topMaxCounter << endl;
					cout << endl;
					cout << "Press any key to back... " << endl;
					move = _getch();
					system("cls");
				}
			}
			if (*locationXmenuModeAdventure == 4) {
				if (*adventureModeMaxLvl >= 5) {
					*adventureModeLvl = 5;
					if (*adventureModeMaxLvl == 5) {
						system("cls");
						cout << "Fifth lvl" << endl << endl;
						cout << "This level is not complete." << endl << endl << "To complete this level you need: " << endl;
						cout << "Top number of moves: 250 >> Your top number of moves: " << topCountingMoves << endl;
						cout << "Top number: 1024 >> Your top number: " << topMaxCounter << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
						system("cls");
					}
					else {
						system("cls");
						cout << "Fifth lvl" << endl << endl;
						cout << "You complete this lvl!" << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
					}
				}
				else {
					system("cls");
					cout << "Fifth lvl" << endl << endl;
					cout << "This level is locked." << endl << endl << "To unlock it you need to earn in the second lvl: " << endl;
					cout << "Top number of moves: 850 >> Your top number of moves: " << topPointCounter << endl;
					cout << "Top number: 512 >> Your top number: " << topMaxCounter << endl;
					cout << endl;
					cout << "Press any key to back... " << endl;
					move = _getch();
					system("cls");
				}
			}
			if (*locationXmenuModeAdventure == 5) {
				if (*adventureModeMaxLvl >= 6) {
					*adventureModeLvl = 6;
					if (*adventureModeMaxLvl == 6) {
						system("cls");
						cout << "Sixth lvl" << endl << endl;
						cout << "This level is not complete." << endl << endl << "To complete this level you need: " << endl;
						cout << "Top number: 2024 >> Your top number: " << topMaxCounter << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
						system("cls");
					}
					else {
						system("cls");
						cout << "Sixth lvl" << endl << endl;
						cout << "You complete this lvl!" << endl;
						cout << endl;
						cout << "Press any key to back... " << endl;
						move = _getch();
					}
				}
				else {
					system("cls");
					cout << "Sixth lvl" << endl << endl;
					cout << "This level is locked." << endl << endl << "To unlock it you need to earn in the second lvl: " << endl;
					cout << "Top number of moves: 250 >> Your top number of moves: " << topCountingMoves << endl;
					cout << "Top number: 1024 >> Your top number: " << topMaxCounter << endl;
					cout << endl;
					cout << "Press any key to back... " << endl;
					move = _getch();
					system("cls");
				}
			}
			if (*locationXmenuModeAdventure == 6) {
				system("cls");
				return;
			}
		}
	}

}