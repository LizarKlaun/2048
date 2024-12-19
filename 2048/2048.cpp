﻿#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cctype>

using namespace std;

#include "Move.h" // просчитывает ходы игрока
#include "Output.h" // выводит поле 2024
#include "ChoosingRandomNumber.h" // выбирает рандомной число для вставки в рандомное место на поле 2024
#include "MenuModeAdventure.h" // менюшка адвенчура
#include "MenuMode.h" // менюшка режимов
#include "MenuExit.h" // менюшка выйти
#include "MenuStart.h" // главная менюшка
#include "GameEndAdventure.h" // проверка на окончание игры для адвенчура
#include "GameEndEndless.h" // проверка на окончание игры для бесконечного
#include "GameEndClassic.h" // проверка на окончание игры для классика
#include "CheckDataAdventure.h" // проверка на ход игрока для адвенчура
#include "CheckDataClassic.h" // проверка на ход игрока для классика

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
	menuStart[0] = new char[11] {'1', '.', ' ', 'S', 't', 'a', 'r', 't', ' ', '|', '\0'};
	menuStart[1] = new char[10] {'2', '.', ' ', 'I', 'n', 'f', 'o', ' ', '|', '\0'};
	menuStart[2] = new char[15] {'3', '.', ' ', 'G', 'a', 'm', 'e', ' ', 'm', 'o', 'd', 'e', ' ', '|', '\0'};
	menuStart[3] = new char[16] {'4', '.', ' ', 'D', 'i', 'f', 'f', 'i', 'c', 'u', 'l', 't', 'y', ' ', '|', '\0'};
	menuStart[4] = new char[14] {'5', '.', ' ', 'T', 'u', 't', 'o', 'r', 'i', 'a', 'l', ' ', '|', '\0'};
	menuStart[5] = new char[9] {'6', '.', ' ', 'E', 'x', 'i', 't', '\0'};

	char** menuExit = new char* [2];
	int* locationXmenuExit = new int(1);
	menuExit[0] = new char[9] {'1', '.', ' ', 'Y', 'e', 's', ' ', '|', '\0'};
	menuExit[1] = new char[6] {'2', '.', ' ', 'N', 'o', '\0'};

	int* mode = new int(0);

	char** menuMode = new char* [5];
	int* locationXmenuMode = new int(0);
	menuMode[0] = new char[13] {'1', '.', ' ', 'C', 'l', 'a', 's', 's', 'i', 'c', ' ', '|', '\0'};
	menuMode[1] = new char[15] {'2', '.', ' ', 'A', 'd', 'v', 'e', 'n', 't', 'u', 'r', 'e', ' ', '|', '\0'};
	menuMode[2] = new char[13] {'3', '.', ' ', 'E', 'n', 'd', 'l', 'e', 's', 's', ' ', '|', '\0'};
	menuMode[3] = new char[13] {'4', '.', ' ', 'D', 'r', 'i', 'v', 'i', 'n', 'g', ' ', '|', '\0'};
	menuMode[4] = new char[8] {'5', '.', ' ', 'B', 'a', 'c', 'k', '\0'};

	int* adventureModeLvl = new int(0);
	int* adventureModeMaxLvl = new int(1);

	char** menuModeAdventure = new char* [7];
	int* locationXmenuModeAdventure = new int(0);
	menuModeAdventure[0] = new char[13] {'1', '.', ' ', 'F', 'i', 'r', 's', 't', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[1] = new char[14] {'2', '.', ' ', 'S', 'e', 'c', 'o', 'n', 'd', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[2] = new char[13] {'3', '.', ' ', 'T', 'h', 'i', 'r', 'd', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[3] = new char[14] {'4', '.', ' ', 'F', 'o', 'u', 'r', 't', 'h', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[4] = new char[13] {'5', '.', ' ', 'F', 'i', 'f', 't', 'h', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[5] = new char[13] {'6', '.', ' ', 'S', 'i', 'x', 't', 'h', ' ', 'l', 'v', 'l', '\0'};
	menuModeAdventure[6] = new char[8] {'7', '.', ' ', 'B', 'a', 'c', 'k', '\0'};

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

		int* exit = new int(0);
		startMenu(menuStart, locationXmenuStart, topCountingMoves, topCountingReturnedMoves, topPointCounter, topMaxCounter, menuMode, mode, locationXmenuMode, menuModeAdventure, locationXmenuModeAdventure, adventureModeLvl, adventureModeMaxLvl, menuExit, locationXmenuExit, exit);
		if (*exit == 1) {
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
		//field[2][3] = 1024;
		//field[3][3] = 1024;

		selectionRandomOutput(field); // по игре сразу 2 создают числа а не 1
		selectionRandomOutput(field); // а вот и 2
		switch (*mode) {
		case 0:
			cout << "Classic mode" << endl << endl;
			break;
		case 1:
			cout << "Adventure mode" << endl << menuModeAdventure[*adventureModeLvl - 1] << endl << endl;
			break;
		case 2:
			cout << "Endless mode" << endl << endl;
			break;
		}
		gameOutput(field);
		do { // бесконечность не предел
			lastField = addOneMoveLastField(lastField, сountingMoves, field);
			if (*mode == 0) {
				dataCheckClassic(field, move, сountingMoves, lastField, countingReturnedMoves, endGame);
				cout << "Classic mode" << endl << endl;
				gameOutput(field); // и показываем пользователю что он сделал
				gameEndClassic(field, endGame);
			}
			else if (*mode == 1) {
				dataCheckAdventure(field, move, сountingMoves, lastField, countingReturnedMoves, endGame, adventureModeMaxLvl);
				cout << "Adventure mode" << endl << menuModeAdventure[*adventureModeLvl - 1] << endl << endl;
				gameOutput(field); // и показываем пользователю что он сделал
				if (*endGame == 1) {
					cout << endl << "You complete this lvl and you unlocked next lvl in Adventure mode!!!" << endl;
				}
				gameEndAdvenchure(field, endGame, adventureModeLvl, adventureModeMaxLvl, сountingMoves);
			}
			else if (*mode == 2) {
				dataCheckClassic(field, move, сountingMoves, lastField, countingReturnedMoves, endGame);
				cout << "Endless mode" << endl << endl;
				gameOutput(field); // и показываем пользователю что он сделал
				gameEndEndless(field, endGame);
			}
		} while (*endGame == 0);
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
		if (*endGame == 1) {
			cout << endl << "You WIN!!!" << endl << endl;
			cout << "Your account: " << pointCounter << '!' << endl
				<< "Your max number: " << maxCounter << endl
				<< "Your number of moves: " << *сountingMoves << endl
				<< "Your number of returned moves: " << *countingReturnedMoves << endl;
			cout << endl;
			cout << "Press any ESC to back..." << endl;
			move = _getch();
			while (move != 27 && move != 32) {
				move = _getch();
			}
		}
		else if (*endGame == 2) {
			cout << endl << "You lose(" << endl << endl;
			cout << "Your account: " << pointCounter << '!' << endl
				<< "Your max number: " << maxCounter << endl
				<< "Your number of moves: " << *сountingMoves << endl
				<< "Your number of returned moves: " << *countingReturnedMoves << endl;
			cout << endl;
			cout << "Press any ESC to back..." << endl;
			move = _getch();
			while (move != 27 && move != 32) {
				move = _getch();
			}
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

	return 0;
}