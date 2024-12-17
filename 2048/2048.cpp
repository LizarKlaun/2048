#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cctype>

using namespace std;

#include "Move.h"
#include "Output.h"
#include "ChoosingRandomNumber.h"

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
			tempLastField[*countingMoves-1][i][j] = field[i][j];
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

void dataCheck(int** field, char* move, int* countingMoves, int*** lastField, int* countingReturnedMoves) {
	while (true) {
		cout << "Make your " << *countingMoves << "st move: ";
		cin >> move; // даём возмонжость выбрать куда походить
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
		else if (*countingMoves > 1) {
			if (move[0] == 'b' || move[0] == 'b' && move[1] == 'a' && move[2] == 'c' && move[3] == 'k') {
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
		}
		else {
			
		}
	}
}

void gameEnd(int** field, int* endGame) {
	int similarityСells = 0;
	for (int i = 0; i < 4; i++) { // проверка на конец игры
		for (int j = 0; j < 4; j++) {
			if (field[i][j] == 2048) {
				*endGame = 1;
			}
			if (i != 3) {
				if (field[i][j] == field[i + 1][j]) {
					similarityСells += 1;
				}
			}
			if (j != 3) {
				if (field[i][j] == field[i][j + 1]) {
					similarityСells += 1;
				}
			}
			if (field[i][j] == 0) {
				similarityСells += 1;
			}
		}
	}
	if (similarityСells == 0) {
		*endGame = 2;
	}
}

int main()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем хэндл консоли
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(consoleHandle, &cursorInfo); // Получаем информацию о курсоре
	cursorInfo.bVisible = false; // Скрываем курсор
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
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

	int* endGame = new int(0);
	char move[10]; // создаём переменную отвечающию за выбраный ход игрока
	int* counterAllMoves = new int(1);
	int* сountingMoves = new int(1); // число его ходов
	int* countingReturnedMoves = new int(0);
	char mode[10];
	cout << "Select game mode: " << endl;
	cout << "1. Adventure | ";
	cout << "2. Endless | ";
	cout << "3. Endless";
	cin >> mode;

	//field[0][0] = 128;
	//field[1][0] = 64;
	//field[2][0] = 32;
	//field[3][0] = 8;
	//
	//field[0][1] = 64;
	//field[1][1] = 32;
	//field[2][1] = 16;
	//field[3][1] = 2;
	//
	//field[0][2] = 32;
	//field[1][2] = 16;
	//field[2][2] = 8;
	//field[3][2] = 4;
	//
	//field[0][3] = 2;
	//field[1][3] = 8;
	//field[2][3] = 4;
	//field[3][3] = 0;

	selectionRandomOutput(field); // по игре сразу 2 создают числа а не 1
	selectionRandomOutput(field); // а вот и 2
	gameOutput(field);
	do { // бесконечность не предел
		lastField = addOneMoveLastField(lastField, сountingMoves, field);
		*counterAllMoves += 1;
		dataCheck(field, move, сountingMoves, lastField, countingReturnedMoves);
		gameEnd(field, endGame);
	} while (*endGame == 0);
	if (*endGame == 1) {
		cout << "You WIN!!!" << endl << endl;
		int pointCounter = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				pointCounter += field[i][j];
			}
		}
		int maxCounter = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (field[i][j] > maxCounter) {
					maxCounter = field[i][j];
				}
			}
		}
		cout << "Your account: " << pointCounter << '!' << endl
			<< "Your max number: " << maxCounter << endl
			<< "Your number of moves: " << *сountingMoves << endl
			<< "Your number of returned moves: " << *countingReturnedMoves << endl;
	}
	else if (*endGame == 2) {
		cout << "You lose(" << endl << endl;
		int pointCounter = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				pointCounter += field[i][j];
			}
		}
		int maxCounter = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (field[i][j] > maxCounter) {
					maxCounter = field[i][j];
				}
			}
		}
		cout << "Your account: " << pointCounter << '!' << endl
			 << "Your max number: " << maxCounter << endl
			 << "Your number of moves: " << *сountingMoves << endl
			 << "Your number of returned moves: " << *countingReturnedMoves << endl;
	}

	delete endGame;
	endGame = nullptr;

	delete сountingMoves;
	сountingMoves = nullptr;

	for (int i = 0; i < 4; i++) {
		delete[] field[i];
	}
	delete[] field;
	field = nullptr;

	for (int k = 0; k < *counterAllMoves; ++k) {
		for (int i = 0; i < 4; ++i) {
			delete[] lastField[k][i];
		}
		delete[] lastField[k];
	}
	delete[] lastField;
	lastField = nullptr;

	return 0;
}