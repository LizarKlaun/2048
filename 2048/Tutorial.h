void tutorial(int** field, char move, int* randOnBlock) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			field[i][j] = 0;
		}
	}
	int step = 0;
	while (step < 7) {
		while (step < 7) {
			cout << "Tutorial" << endl;
			cout << "Step: " << step << endl << endl;
			if (step == 0) {
				cout << "To exit the tutorial you can press ESC at any time" << endl;
				cout << "And press space if you need to next step";
			}
			if (step == 1) {
				cout << "Welcome to the 2048 game tutorial! In this simple yet addictive puzzle game," << endl << "your goal is to combine numbered tiles on a 4x4 grid to create a tile with the number 2048.";
			}
			if (step == 2) {
				cout << "In 2048, after each move, a number spawns in a random position on the grid." << endl << "The value of this number depends on the game's difficulty level.";
			}
			if (step == 3) {
				cout << "You can move up, down, left, or right, and this will shift all the tiles in the chosen direction." << endl << "For example:" << endl << endl;
				field[1][2] = 2;
				field[2][0] = 2;
				gameOutput(field);
				cout << endl << "If you press W or the up arrow, all the tiles will shift upward." << endl;
				cout << "Press W or UP_ARROW to move...";
				move = _getche();
				if (move == 0 || move == -32) {
					move = _getche();
				}
				if (move == 27) {
					system("cls");
					return;
				}
				else if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				while (move != 'W' && move != 'w' && move != 72 && move != 32) {
					cout << "Press only W or UP_ARROW... " << move;
					move = _getche();
					if (move == 0 || move == -32) {
						move = _getche();
					}
					if (move == 27) {
						system("cls");
						return;
					}
					cout << endl;
				}
				if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				playerMoveOutput(field, move);
				gameOutput(field);
				cout << endl << "You can see that all the tiles on the grid have shifted upward in the direction you pressed." << endl;
				cout << "But if you press down" << endl;
				cout << "Press S or DOWN_ARROW to move...";
				move = _getche();
				if (move == 0 || move == -32) {
					move = _getche();
				}
				if (move == 27) {
					system("cls");
					return;
				}
				else if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				while (move != 'S' && move != 's' && move != 80 && move != 32) {
					cout << "Press only W or DOWN_ARROW... " << move;
					move = _getche();
					if (move == 0 || move == -32) {
						move = _getche();
					}
					if (move == 27) {
						system("cls");
						return;
					}
					cout << endl;
				}
				if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				playerMoveOutput(field, move);
				gameOutput(field);
				cout << endl << "Then you can see that all the tiles have shifted downward because you pressed in that direction." << endl << endl;
				cout << "But there are one important rules. If the tile that is moving encounters another tile that is different from it," << endl
					<< "the moving tile cannot merge or combine with the other one. Instead, it will stop right before the other tile," << endl
					<< "and both tiles will shift in the direction you specified." << endl << endl;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						field[i][j] = 0;
					}
				}
				field[1][2] = 4;
				field[2][2] = 2;
				field[2][0] = 2;
				field[3][0] = 4;
				gameOutput(field);
				cout << "Press W or UP_ARROW to move...";
				move = _getche();
				if (move == 0 || move == -32) {
					move = _getche();
				}
				if (move == 27) {
					system("cls");
					return;
				}
				else if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				while (move != 'W' && move != 'w' && move != 72 && move != 32) {
					cout << "Press only W or UP_ARROW... " << move;
					move = _getche();
					if (move == 0 || move == -32) {
						move = _getche();
					}
					if (move == 27) {
						system("cls");
						return;
					}
					cout << endl;
				}
				if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				playerMoveOutput(field, move);
				gameOutput(field);

				cout << "All the tiles on the grid did not merge but moved closer to each other.";
			}
			if (step == 4) {
				cout << "If you merge tiles with the same values together, they will combine and sum up." << endl << "For example:" << endl << endl;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						field[i][j] = 0;
					}
				}
				field[1][2] = 2;
				field[3][2] = 2;
				field[2][0] = 4;
				field[3][0] = 4;
				field[0][3] = 8;
				field[3][3] = 8;
				gameOutput(field);
				cout << "Press W or UP_ARROW or S or DOWN_ARROW to move...";
				move = _getche();
				if (move == 0 || move == -32) {
					move = _getche();
				}
				if (move == 27) {
					system("cls");
					return;
				}
				else if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				while (move != 'W' && move != 'w' && move != 72 && move != 'S' && move != 's' && move != 80 && move != 32) {
					cout << "Press only W or UP_ARROW or S or DOWN_ARROW... " << move;
					move = _getche();
					if (move == 0 || move == -32) {
						move = _getche();
					}
					if (move == 27) {
						system("cls");
						return;
					}
					cout << endl;
				}
				if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				playerMoveOutput(field, move);
				gameOutput(field);
				if (move == 'W' || move == 'w' || move == 72) {
					cout << "You can see that all the tiles have added up and moved to the top.";
				}
				else {
					cout << "You can see that all the tiles have added up and moved to the down.";
				}
			}
			if (step == 5) {
				cout << "In 2048, there are 4 game modes:" << endl << endl;
				cout << "1. Classic Mode: This is the standard 2048 game where you play until you reach the tile 2048." << endl;
				cout << "2. Adventure Mode: A journey-based mode where you progress through different levels." << endl;
				cout << "3. Endless Mode: Similar to Classic Mode, but with no winning condition. You can keep playing indefinitely." << endl;
				cout << "4. Driving Mode: A more challenging version of Classic Mode where you have a limited number of moves." << endl << "Each successful tile merge increases the number of available moves by 1, up to a maximum of 10.";
			}
			if (step == 6) {
				cout << "In 2048, you can also undo moves by pressing B," << endl << "and the number of undos may be limited depending on the game mode. For example:" << endl << endl;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						field[i][j] = 0;
					}
				}
				int* dificulty = new int(0);
				selectionRandomOutput(field, dificulty, randOnBlock);
				selectionRandomOutput(field, dificulty, randOnBlock);
				int** lastField = new int* [4]; // cоздаём массив массивов
				for (int i = 0; i < 4; i++) { // заполняем его массивами
					lastField[i] = new int[4];
				}
				for (int i = 0; i < 4; i++) { // заполняем массив чисел 
					for (int j = 0; j < 4; j++) {
						lastField[i][j] = field[i][j];
					}
				}
				gameOutput(field);
				cout << "You can go back " << 10 << " times" << endl;
				cout << "Make your " << 1 << "st move: ";
				move = _getche();
				if (move == 0 || move == -32) {
					move = _getche();
				}
				if (move == 27) {
					system("cls");
					return;
				}
				if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				while (move != 'W' && move != 'w' && move != 72 && move != 'S' && move != 's' && move != 80 && move != 'A' && move != 'a' && move != 75 && move != 'D' && move != 'd' && move != 77 && move!= 32) {
					cout << "Press only W or UP_ARROW or S or DOWN_ARROW or A or LEFT_ARROW or D or RIGHT_ARROW... " << move;
					move = _getche();
					if (move == 0 || move == -32) {
						move = _getche();
					}
					if (move == 27) {
						system("cls");
						return;
					}
					cout << endl;
				}
				if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				playerMoveOutput(field, move);
				gameOutput(field);
				cout << "Press B to go back a step" << endl;
				cout << "You can go back " << 10 << " times" << endl;
				cout << "Make your " << 2 << "st move: ";
				move = _getche();
				if (move == 0 || move == -32) {
					move = _getche();
				}
				if (move == 27) {
					system("cls");
					return;
				}
				else if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				while (move != 'b' && move != 'B' && move != 32) {
					cout << "Press only B... " << move;
					move = _getche();
					if (move == 0 || move == -32) {
						move = _getche();
					}
					if (move == 27) {
						system("cls");
						return;
					}
					cout << endl;
				}
				if (move == 32) {
					step++;
					system("cls");
					break;
				}
				cout << endl;
				gameOutput(lastField);

				for (int i = 0; i < 4; i++) {
					delete[] lastField[i];
				}
				delete[] lastField;
				lastField = nullptr;

				delete dificulty;
				dificulty = nullptr;
			}
			cout << endl << endl << "Press any key to continue... ";
			move = _getch();
			if (move == 0 || move == -32) {
				move = _getch();
			}
			if (move == 27) {
				system("cls");
				return;
			}
			system("cls");
			step++;
		}
	}
}