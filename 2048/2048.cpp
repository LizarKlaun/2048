#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cctype>

using namespace std;

#include "Move.h"
#include "Output.h"
#include "ChoosingRandomNumber.h"
#include "MenuModeAdventure.h"
#include "MenuMode.h"
#include "MenuExit.h"
#include "MenuStart.h"
#include "GameEndLvl.h"
#include "GameEndClassic.h"

int*** addOneMoveLastField(int*** lastField, int* countingMoves, int** field) {
	int*** tempLastField = new int** [*countingMoves + 1];
	for (int k = 0; k < *countingMoves + 1; ++k) {
		tempLastField[k] = new int* [4];
		for (int i = 0; i < 4; ++i) {
			tempLastField[k][i] = new int[4];
		}
	}
	for (int k = 0; k < *countingMoves; ++k) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				tempLastField[k][i][j] = lastField[k][i][j];
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tempLastField[*countingMoves - 1][i][j] = field[i][j];
		}
	}
	for (int k = 0; k < *countingMoves; k++) {
		for (int i = 0; i < 4; i++) {
			delete[] lastField[k][i];
		}
		delete[] lastField[k];
	}
	delete[] lastField;

	return tempLastField;
}

void dataCheck(int** field, char move, int* countingMoves, int*** lastField, int* countingReturnedMoves, int* endGame) {
	while (true) {
		cout << "Make your " << *countingMoves << "st move: " << endl;
		move = _getch(); // даём возмонжость выбрать куда походить
		if (move == 0 || move == -32) {
			move = _getch();
		}
		playerMoveOutput(field, move);
		int similarityField = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (lastField[*countingMoves - 1][i][j] != field[i][j]) {
					similarityField = 1;
				}
			}
		}
		if (similarityField == 1) {
			system("cls");
			++*countingMoves; // прибавляем к числу ходов 1
			selectionRandomOutput(field); // вызываем рандом
			gameOutput(field); // и показываем пользователю что он сделал
			break;
		}
		else if (*countingMoves > 1 && move == 'b') {
			--*countingMoves;
			++*countingReturnedMoves;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					field[i][j] = lastField[*countingMoves - 1][i][j];
				}
			}
			gameOutput(field); // и показываем пользователю что он сделал
			break;
		}
		else if (move == 27) {
			*endGame = 2;
			break;
		}
		else {
			cout << "Error. Press A W S D" << endl;
		}
	}
}

int main()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем хэндл консоли
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo); // Получаем информацию о курсоре
	cursorInfo.bVisible = false; // Скрываем курсор
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);

	int* endGame = new int(0);
	char move = 'f'; // создаём переменную отвечающию за выбраный ход игрока
	int* сountingMoves = new int(1); // число его ходов
	int* countingReturnedMoves = new int(0);

	//Статистика{
	int pointCounter = 0;
	int maxCounter = 0;
	int topCountingMoves = 0;
	int topCountingReturnedMoves = 0;
	int topPointCounter = 0;
	int topMaxCounter = 0;
	//}

	char** menuStart = new char* [6];
	int* locationXmenuStart = new int(0);
	menuStart[*locationXmenuStart] = new char[3] {'-', '>', '\0'};
	menuStart[1] = new char[11] {'1', '.', ' ', 'S', 't', 'a', 'r', 't', ' ', '|', '\0'};
	menuStart[2] = new char[10] {'2', '.', ' ', 'I', 'n', 'f', 'o', ' ', '|', '\0'};
	menuStart[3] = new char[15] {'3', '.', ' ', 'G', 'a', 'm', 'e', ' ', 'm', 'o', 'd', 'e', ' ', '|', '\0'};
	menuStart[4] = new char[16] {'4', '.', ' ', 'D', 'i', 'f', 'f', 'i', 'c', 'u', 'l', 't', 'i', ' ', '|', '\0'};
	menuStart[5] = new char[9] {'5', '.', ' ', 'E', 'x', 'i', 't', '\0'};

	char** menuExit = new char* [3];
	int* locationXmenuExit = new int(1);
	menuExit[0] = new char[9] {'1', '.', ' ', 'Y', 'e', 's', ' ', '|', '\0'};
	menuExit[*locationXmenuExit] = new char[3] {'-', '>', '\0'};
	menuExit[2] = new char[6] {'2', '.', ' ', 'N', 'o', '\0'};

	int* mode = new int(0);

	char** menuMode = new char* [6];
	int* locationXmenuMode = new int(0);
	menuMode[*locationXmenuMode] = new char[3] {'-', '>', '\0'};
	menuMode[1] = new char[13] {'1', '.', ' ', 'C', 'l', 'a', 's', 's', 'i', 'c', ' ', '|', '\0'};
	menuMode[2] = new char[15] {'2', '.', ' ', 'A', 'd', 'v', 'e', 'n', 't', 'u', 'r', 'e', ' ', '|', '\0'};
	menuMode[3] = new char[13] {'3', '.', ' ', 'E', 'n', 'd', 'l', 'e', 's', 's', ' ', '|', '\0'};
	menuMode[4] = new char[13] {'4', '.', ' ', 'D', 'r', 'i', 'v', 'i', 'n', 'g', ' ', '|', '\0'};
	menuMode[5] = new char[8] {'5', '.', ' ', 'B', 'a', 'c', 'k', '\0'};

	int* adventureModeLvl = new int(1);
	int* adventureModeMaxLvl = new int(1);

	char** menuModeAdventure = new char* [8];
	int* locationXmenuModeAdventure = new int(0);
	menuModeAdventure[*locationXmenuModeAdventure] = new char[3] {'-', '>', '\0'};
	menuModeAdventure[1] = new char[13] {'1', '.', ' ', 'F', 'i', 'r', 's', 't', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[2] = new char[14] {'2', '.', ' ', 'S', 'e', 'c', 'o', 'n', 'd', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[3] = new char[13] {'3', '.', ' ', 'T', 'h', 'i', 'r', 'd', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[4] = new char[14] {'4', '.', ' ', 'F', 'o', 'u', 'r', 't', 'h', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[5] = new char[13] {'5', '.', ' ', 'F', 'i', 'f', 't', 'h', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[6] = new char[13] {'6', '.', ' ', 'S', 'i', 'x', 't', 'h', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[7] = new char[8] {'7', '.', ' ', 'B', 'a', 'c', 'k', '\0'};

	while (true) {
		*сountingMoves = 1;
		*countingReturnedMoves = 0;
		*endGame = 0;
		pointCounter = 0;
		maxCounter = 0;

		int** field = new int* [4]; // cоздаём массив массивов
		for (int i = 0; i < 4; i++) { // заполняем его массивами
			field[i] = new int[4];
		}
		for (int i = 0; i < 4; i++) { // заполняем массив чисел 
			for (int j = 0; j < 4; j++) {
				field[i][j] = 0;
			}
		}

		int*** lastField = new int** [1];
		for (int k = 0; k < 1; k++) {
			lastField[k] = new int* [4];
			for (int i = 0; i < 4; i++) {
				lastField[k][i] = new int[4];
			}
		}
		for (int k = 0; k < 1; k++) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					lastField[k][i][j] = 0;
				}
			}
		}

		startMenu(menuStart, locationXmenuStart, topCountingMoves, topCountingReturnedMoves, topPointCounter, topMaxCounter, menuMode, mode, locationXmenuMode, menuModeAdventure, locationXmenuModeAdventure, adventureModeLvl, adventureModeMaxLvl, menuExit, locationXmenuExit);
		//modeAdventureMenu();

		//field[0][0] = 1;
		//field[1][0] = 2;
		//field[2][0] = 3;
		//field[3][0] = 4;
		//
		//field[0][1] = 2;
		//field[1][1] = 3;
		//field[2][1] = 4;
		//field[3][1] = 5;
		//
		//field[0][2] = 3;
		//field[1][2] = 4;
		//field[2][2] = 5;
		//field[3][2] = 6;
		//
		//field[0][3] = 0;
		//field[1][3] = 4;
		//field[2][3] = 5;
		//field[3][3] = 6;

		selectionRandomOutput(field); // по игре сразу 2 создают числа а не 1
		selectionRandomOutput(field); // а вот и 2
		gameOutput(field);
		do { // бесконечность не предел
			lastField = addOneMoveLastField(lastField, сountingMoves, field);
			dataCheck(field, move, сountingMoves, lastField, countingReturnedMoves, endGame);
			if (*mode == 0) {
				gameEndClassic(field, endGame);
			}
			else if (*mode == 1) {
				if (*adventureModeLvl == 1) {
					gameEndLvl(field, endGame, adventureModeLvl, adventureModeMaxLvl);
				}
			}
		} while (*endGame == 0);
		if (*endGame == 1) {
			cout << endl << "You WIN!!!" << endl << endl;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					pointCounter += field[i][j];
				}
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (field[i][j] > maxCounter) {
						maxCounter = field[i][j];
					}
				}
			}
			if (topCountingMoves < *сountingMoves) {
				topCountingMoves = *сountingMoves;
			}
			if (topCountingReturnedMoves < *countingReturnedMoves) {
				topCountingReturnedMoves = *countingReturnedMoves;
			}
			if (topPointCounter < pointCounter) {
				topPointCounter = pointCounter;
			}
			if (topMaxCounter < maxCounter) {
				topMaxCounter = maxCounter;
			}
			cout << "Your account: " << pointCounter << '!' << endl
				<< "Your max number: " << maxCounter << endl
				<< "Your number of moves: " << *сountingMoves << endl
				<< "Your number of returned moves: " << *countingReturnedMoves << endl;
			cout << endl;
			cout << "Press any key to back..." << endl;
			move = _getch();
		}
		else if (*endGame == 2) {
			cout << endl << "You lose(" << endl << endl;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					pointCounter += field[i][j];
				}
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (field[i][j] > maxCounter) {
						maxCounter = field[i][j];
					}
				}
			}
			if (topCountingMoves < *сountingMoves) {
				topCountingMoves = *сountingMoves;
			}
			if (topCountingReturnedMoves < *countingReturnedMoves) {
				topCountingReturnedMoves = *countingReturnedMoves;
			}
			if (topPointCounter < pointCounter) {
				topPointCounter = pointCounter;
			}
			if (topMaxCounter < maxCounter) {
				topMaxCounter = maxCounter;
			}
			cout << "Your account: " << pointCounter << '!' << endl
				<< "Your max number: " << maxCounter << endl
				<< "Your number of moves: " << *сountingMoves << endl
				<< "Your number of returned moves: " << *countingReturnedMoves << endl;
			cout << endl;
			cout << "Press any key to back..." << endl;
			move = _getch();
		}

		for (int i = 0; i < 4; i++) {
			delete[] field[i];
		}
		delete[] field;
		field = nullptr;

		for (int k = 0; k < *сountingMoves; ++k) {
			for (int i = 0; i < 4; ++i) {
				delete[] lastField[k][i];
			}
			delete[] lastField[k];
		}
		delete[] lastField;
		lastField = nullptr;
	}

	delete locationXmenuModeAdventure;
	locationXmenuModeAdventure = nullptr;

	delete locationXmenuMode;
	locationXmenuMode = nullptr;

	delete locationXmenuStart;
	locationXmenuStart = nullptr;

	delete mode;
	mode = nullptr;

	delete endGame;
	endGame = nullptr;

	delete сountingMoves;
	сountingMoves = nullptr;

	delete countingReturnedMoves;
	countingReturnedMoves = nullptr;

	delete adventureModeLvl;
	adventureModeLvl = nullptr;

	delete adventureModeMaxLvl;
	adventureModeLvl = nullptr;

	for (int i = 0; i < 4; i++) {
		delete[] menuModeAdventure[i];
	}
	delete[] menuModeAdventure;
	menuModeAdventure = nullptr;

	for (int i = 0; i < 4; i++) {
		delete[] menuMode[i];
	}
	delete[] menuMode;
	menuMode = nullptr;

	for (int i = 0; i < 4; i++) {
		delete[] menuStart[i];
	}
	delete[] menuStart;
	menuStart = nullptr;

	return 0;
}