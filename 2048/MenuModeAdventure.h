void modeAdventureMenu(char** menuModeAdventure, int* locationXmenuModeAdventure, int* adventureModeLvl, int* adventureModeMaxLvl, int topCountingMoves, int topCountingReturnedMoves, int topPointCounter, int topMaxCounter) {
	char move;
	while (true) {
		system("cls");
		cout << "Select lvl game: " << endl;
		for (int i = 0; i < 7; i++) {
			if (i == *locationXmenuModeAdventure) {
				if (i == *adventureModeLvl - 1) {
					cout << menuModeAdventure[i] << " !";
				}
				else {
					cout << menuModeAdventure[i] << " ";
				}
			}
			else if (*adventureModeMaxLvl >= *locationXmenuModeAdventure) {
				if (i > *adventureModeMaxLvl) {
					cout << "X" << menuModeAdventure[i] << "X | ";
				}
				else {
					if (i == *adventureModeLvl - 1) {
						if (*locationXmenuModeAdventure <= *adventureModeLvl - 1) {
							cout << menuModeAdventure[i] << " | ";
							cout << "!" << menuModeAdventure[i + 1] << " | ";
							i++;
						}
						else if (*locationXmenuModeAdventure > *adventureModeLvl - 1) {
							cout << "!" << menuModeAdventure[i] << " | ";
						}
						else {
							cout << menuModeAdventure[i] << " | ";
						}
					}
					else {
						cout << menuModeAdventure[i] << " | ";
					}
				}
			}
			else if (*adventureModeMaxLvl < *locationXmenuModeAdventure) {
				if (i >= *adventureModeMaxLvl) {
					cout << "X" << menuModeAdventure[i] << "X | ";
				}
				else {
					if (i == *adventureModeLvl-1) {
						if (*locationXmenuModeAdventure <= *adventureModeLvl - 1) {
							cout << menuModeAdventure[i] << " | ";
							cout << "!" << menuModeAdventure[i+1] << " | ";
							i++;
						}
						else if (*locationXmenuModeAdventure > *adventureModeLvl - 1) {
							cout << "!" << menuModeAdventure[i] << " | ";
						}
						else {
							cout << menuModeAdventure[i] << " | ";
						}
					}
					else {
						cout << menuModeAdventure[i] << " | ";
					}
				}
			}
		}
		cout << endl;
		cout << menuModeAdventure[7];
		move = _getch();
		if (move == 27) {
			system("cls");
			return;
		}
		if (move == 77 || move == 'd' || move == 'D') {
			if (*locationXmenuModeAdventure < 6) {
				system("cls");
				char* tempArrow = menuModeAdventure[*locationXmenuModeAdventure];
				menuModeAdventure[*locationXmenuModeAdventure] = menuModeAdventure[*locationXmenuModeAdventure + 1];
				menuModeAdventure[*locationXmenuModeAdventure + 1] = tempArrow;
				*locationXmenuModeAdventure += 1;
			}
		}
		if (move == 75 || move == 'a' || move == 'A') {
			if (*locationXmenuModeAdventure > 0) {
				system("cls");
				char* tempArrow = menuModeAdventure[*locationXmenuModeAdventure];
				menuModeAdventure[*locationXmenuModeAdventure] = menuModeAdventure[*locationXmenuModeAdventure - 1];
				menuModeAdventure[*locationXmenuModeAdventure - 1] = tempArrow;
				*locationXmenuModeAdventure -= 1;
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuModeAdventure == 0) {
				if (*adventureModeMaxLvl >= 1) {
					*adventureModeLvl = 1;
					return;
				}
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuModeAdventure == 1) {
				if (*adventureModeMaxLvl >= 2) {
					*adventureModeLvl = 2;
					return;
				}
				else {
					system("cls");
					cout << "This level is locked." << endl << endl << "To unlock it you need to earn in the first lvl: " << endl;
					cout << "Top number of moves: 90 >> Your top number of moves: " << topCountingMoves << endl;
					cout << "Top number: 64 >> Your top number: " << topMaxCounter << endl;
					cout << endl;
					cout << "Press any key to back... " << endl;
					move = _getch();
					system("cls");
				}
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuModeAdventure == 2) {
				if (*adventureModeMaxLvl >= 3) {
					*adventureModeLvl = 3;
					return;
				}
				else {
					system("cls");
					cout << "This level is locked." << endl << endl << "To unlock it you need to earn in the second lvl: " << endl;
					cout << "Top number of moves: 100 >> Your top number of moves: " << topCountingMoves << endl;
					cout << "Top number: 128 >> Your top number: " << topMaxCounter << endl;
					cout << endl;
					cout << "Press any key to back... " << endl;
					move = _getch();
					system("cls");
				}
			}
		}
		if (move == 13 || move == 32) {
			if (*locationXmenuModeAdventure == 6) {
				system("cls");
				return;
			}
		}
	}

}