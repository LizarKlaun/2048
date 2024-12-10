#include <iostream>
#include <string>

using namespace std;

void gameOutput(int** field) { // здесь создаём мы функцию которая выводит всю игру
	int a = 0; // нужно чтобы проверяло есть ли в массиве 2 мерные или ещё больше числа чтобы перестраиватся можно было типо то больше интерфейс то меньше
	for (int i = 0; i < 4; i++) { // перебераем все числа во всех масивах
		for (int j = 0; j < 4; j++) {
			if (field[i][j] > a) { // cмотрим является ли оно двухзначное
				a = field[i][j];
			}
		}
	}
	for (int i = 0; i < 4; i++) { // снова перебераем всё
		for (int j = 0; j < 4; j++) {
			if (a >= 100) { // если число двухзначное то интерфейсе будет в 2 раза больше пробелов но не в месте где число двухзначное
				if (field[i][j] >= 100) {
					cout << field[i][j] << " ";
				}
				else if (field[i][j] >= 10) {
					cout << field[i][j] << "  ";
				}
				else {
					cout << " " << field[i][j] << "  ";
				}
			} // иначе нет
			else if (a >= 10) { // если трёхзначное то пробел цифре будет в 3 раза больше а в двухзначном будет в 2 раза больше пробел
				if (field[i][j] >= 10) {
					cout << field[i][j] << " ";
				}
				else {
					cout << field[i][j] << "  ";
				}
			}
			else {
				cout << field[i][j] << " ";
			}
		}
		if (a >= 100) {
			cout << endl;
		}
		cout << endl;
	}
}

void selectionRandomOutput(int** field) { // функция для создания рандомного число в рандомном месте после хода пользователя
	srand(time(NULL));
	int randomNumber = rand() % 12;
	int counterZero = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (field[i][j] == 0) {
				counterZero++;
			}
		}
	}
	int randZero = rand() % counterZero;
	int indexZero = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (field[i][j] == 0) {
				if (indexZero == randZero) {
					if (randomNumber < 8) {
						field[i][j] = 2;
						return;
					}
					else if (randomNumber < 11) {
						field[i][j] = 4;
						return;
					}
					else if (randomNumber == 11) {
						field[i][j] = 8;
						return;
					}
				}
				else {
					indexZero++;
				}
			}
		}
	}
}

void playerMoveOutput(int** field, char* move) { // cоздаём функцию для возможности ходить
	if (move[0] == 'w' || move[0] == 'W') { // конкретно здесь он ходит на верх
		for (int j = 0; j < 4; j++) { //цикл который переберает массив масивов
			int a = 0; //нужны для проверки сколько раз уже применялась сумма
			int b = 0; //тоже самое
			int c = 0; //опять тоже самое
			for (int i = 0; i < 4; i++) { // цикл который переберает все числа в масиве
				if (field[i][j] != 0) { // чтобы не переберало все нолики в массивах
					if (field[0][j] == field[1][j] && i != 0 && a != 1 && field[0][j] != 0 && field[0][j] == field[i][j] || field[0][j] == field[2][j] && field[1][j] == 0 && i != 0 && a != 1 || field[0][j] == field[3][j] && field[2][j] == 0 && field[1][j] == 0 && i != 0 && a != 1) { // проверяет на схожость чисел с теми который находятся перед ними и то что между ними стоят только 0 на указаной пользователем строчке чтобы их прибавить и на то что это число не является 1 числом в строчке
						//cout << "plus : 0 : 0 . i: " << i << ". j: " << j << endl;
						a = 1;
						field[0][j] += field[i][j]; // плюсуем их
						field[i][j] = 0; // то число удаляем
					}
					else if (field[1][j] == field[2][j] && i != 0 && i != 1 && b != 1 || field[1][j] == field[3][j] && field[2][j] == 0 && i != 0 && i != 1 && b != 1) { // тоже самое но в другом столбике только теперь проверяет что число и не 2 число в строчке 
						//cout << "plus : 0 : 1" << endl;
						b = 1;
						field[1][j] += field[i][j];
						field[i][j] = 0;
					}
					else if (field[2][j] == field[3][j] && i != 0 && i != 1 && i != 2 && c != 1) { //опять тоже самое но также в другом столбике и смотрит чт чилсло не является ещё и 3 в строчке
						//cout << "plus : 0 : 2" << endl;
						c = 1;
						field[2][j] += field[i][j];
						field[i][j] = 0;
					}
					// 4 число нет смысла проверять потому что такого в жизни не как не может произойти и типо смысл..... не вижу смысла
					if (field[0][j] == 0) { // проверяет что 1 число в строчке уоторая указана пользователем выше не заполнено уже каким-то а если да то перемещяет предыдущее число в 1 строчку
						//cout << "reverse : 0 : 0 . i: " << i << ". j: " << j << endl;
						field[0][j] = field[i][j]; // перемещяем его
						field[i][j] = 0; // удаляем прошлое
					}//                                                                                                                                                                         |
					else if (field[1][j] == 0 && i != 0) { // тоже самое но уже только если 1 число уже заполнено то проверяет заполнено ли 2 число в той строчке от пользователя и если да то \|/
						//cout << "reverse : 0 : 1 . i: " << i << ". j: " << j << endl;
						field[1][j] = field[i][j]; // мы перемещяем на конкретно то место в масиве которое свободно
						field[i][j] = 0; // также забываем его
					}
					else if (field[2][j] == 0 && i != 0 && i != 1) { // и снова тоже самое что и выше но тут уже проверяется 3 число в строчке
						//cout << "reverse : 0 : 2 . i: " << i << ". j: " << j << endl;
						field[2][j] = field[i][j];
						field[i][j] = 0;
					}
					// и здесь тоже проверять 4 смысла нет потому что такого не может быть
				}
			}
		}
	}

	else if (move[0] == 'a' || move[0] == 'A') { // здесь уже влево. Что и как работает написал сверху /|\ 
		for (int i = 0; i < 4; i++) { //                                                                |
			int a = 0;
			int b = 0;
			int c = 0;
			for (int j = 0; j < 4; j++) {
				if (field[i][j] != 0) {
					if (field[i][0] == field[i][1] && j != 0 && a != 1 && field[i][0] != 0 && field[i][0] == field[i][j] || field[i][0] == field[i][2] && field[i][1] == 0 && j != 0 && a != 1 || field[i][0] == field[i][3] && field[i][1] == 0 && field[i][2] == 0 && j != 0 && a != 1) {
						//cout << "plus : 1 : 0" << endl;
						a = 1;
						field[i][0] += field[i][j];
						field[i][j] = 0;
					}
					else if (field[i][1] == field[i][2] && j != 0 && j != 1 && b != 1 || field[i][1] == field[i][3] && field[i][2] == 0 && j != 0 && j != 1 && b != 1) {
						//cout << "plus : 1 : 1" << endl;
						b = 1;
						field[i][1] += field[i][j];
						field[i][j] = 0;
					}
					else if (field[i][2] == field[i][3] && j != 0 && j != 1 && j != 2 && c != 1) {
						//cout << "plus : 1 : 2" << endl;
						c = 1;
						field[i][2] += field[i][j];
						field[i][j] = 0;
					}
					if (field[i][0] == 0) {
						//cout << "reverse : 1 : 0 . i: " << i << ". j: " << j << endl;
						field[i][0] = field[i][j];
						field[i][j] = 0;
					}
					else if (field[i][1] == 0) {
						//cout << "reverse : 1 : 1 . i: " << i << ". j: " << j << endl;
						field[i][1] = field[i][j];
						field[i][j] = 0;
					}
					else if (field[i][2] == 0 && j != 0) {
						//cout << "reverse : 1 : 2 . i: " << i << ". j: " << j << endl;
						field[i][2] = field[i][j];
						field[i][j] = 0;
					}
				}
			}
		}
	}

	else if (move[0] == 's' || move[0] == 'S') { // теперь вниз... что и как сверху и ещё выше
		for (int j = 3; j > -1; j--) {
			int a = 0;
			int b = 0;
			int c = 0;
			for (int i = 3; i > -1; i--) {
				if (field[i][j] != 0) {
					if (field[3][j] == field[2][j] && i != 3 && a != 1 && field[3][j] != 0 && field[3][j] == field[i][j] || field[3][j] == field[1][j] && field[2][j] == 0 && i != 3 && a != 1 || field[3][j] == field[0][j] && field[2][j] == 0 && field[1][j] == 0 && i != 3 && a != 1) {
						//cout << "plus : 2 : 0" << endl;
						a = 1;
						field[3][j] += field[i][j];
						field[i][j] = 0;
					}
					else if (field[2][j] == field[1][j] && i != 2 && i != 3 && b != 1 || field[2][j] == field[0][j] && field[1][j] == 0 && i != 2 && i != 3 && b != 1) {
						//cout << "plus : 2 : 1" << endl;
						b = 1;
						field[2][j] += field[i][j];
						field[i][j] = 0;
					}
					else if (field[1][j] == field[0][j] && i != 1 && i != 2 && i != 3 && c != 1) {
						//cout << "plus : 2: 2" << endl;
						c = 1;
						field[1][j] += field[i][j];
						field[i][j] = 0;
					}
					if (field[3][j] == 0) {
						//cout << "reverse : 2 : 0 . i: " << i << ". j: " << j << endl;
						field[3][j] = field[i][j];
						field[i][j] = 0;
					}
					else if (field[2][j] == 0 && i != 3) {
						//cout << "reverse : 2 : 1 . i: " << i << ". j: " << j << endl;
						field[2][j] = field[i][j];
						field[i][j] = 0;
					}
					else if (field[1][j] == 0 && i != 3) {
						//cout << "reverse : 2 : 2 . i: " << i << ". j: " << j << endl;
						field[1][j] = field[i][j];
						field[i][j] = 0;
					}
				}
			}
		}
	}

	else if (move[0] == 'd' || move[0] == 'D') { // сейчас направо...... что да как это надо листать выше и ещё выше почти до потолка
		for (int i = 3; i > -1; i--) {
			int a = 0;
			int b = 0;
			int c = 0;
			for (int j = 3; j > -1; j--) {
				if (field[i][j] != 0) {
					if (field[i][3] == field[i][2] && j != 3 && a != 1 && field[i][3] != 0 && field[i][3] == field[i][j] || field[i][3] == field[i][1] && field[i][2] == 0 && j != 3 && a != 1 || field[i][3] == field[i][0] && field[i][2] == 0 && field[i][1] == 0 && j != 3 && a != 1) {
						//cout << "plus : 1 : 0" << endl;
						a = 1;
						field[i][3] += field[i][j];
						field[i][j] = 0;
					}
					else if (field[i][2] == field[i][1] && j != 2 && j != 3 && b != 1 || field[i][2] == field[i][0] && field[i][1] == 0 && j != 3 && j != 2 && b != 1) {
						//cout << "plus : 1 : 1" << endl;
						b = 1;
						field[i][2] += field[i][j];
						field[i][j] = 0;
					}
					else if (field[i][1] == field[i][0] && j != 1 && j != 2 && j != 3 && c != 1) {
						//cout << "plus : 1 : 2" << endl;
						c = 1;
						field[i][1] += field[i][j];
						field[i][j] = 0;
					}
					if (field[i][3] == 0) {
						//cout << "reverse : 1 : 0 . i: " << i << ". j: " << j << endl;
						field[i][3] = field[i][j];
						field[i][j] = 0;
					}
					else if (field[i][2] == 0 && j != 3) {
						//cout << "reverse : 1 : 1 . i: " << i << ". j: " << j << endl;
						field[i][2] = field[i][j];
						field[i][j] = 0;
					}
					else if (field[i][1] == 0 && j != 3) {
						//cout << "reverse : 1 : 2 . i: " << i << ". j: " << j << endl;
						field[i][1] = field[i][j];
						field[i][j] = 0;
					}
				}
			}
		}
	}
}

void dataCheck(int** field, char* move, int* countingMoves, int*** lastField) {
	cout << "LOL1" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			lastField[*countingMoves][i][j] = field[i][j];
		}
	}

	int*** tempLastField = new int** [*countingMoves];
	for (int k = 0; k < *countingMoves; k++) {
		tempLastField[k] = new int* [4];
		for (int i = 0; i < 4; i++) {
			tempLastField[k][i] = new int[4];
			for (int j = 0; j < 4; j++) {
				tempLastField[k][i][j] = lastField[k][i][j];
			}
		}
	}

	cout << "LOL2" << endl;
	for (int k = 0; k < *countingMoves; ++k) {
		for (int i = 0; i < 4; ++i) {
			delete[] lastField[k][i];
		}
		delete[] lastField[k];
	}
	delete[] lastField;

	lastField = new int** [*countingMoves + 1];
	for (int k = 0; k < *countingMoves; k++) {
		lastField[k] = new int* [4];
		for (int i = 0; i < 4; i++) {
			lastField[k][i] = new int[4];
			for (int j = 0; j < 4; j++) {
				lastField[k][i][j] = tempLastField[k][i][j];
			}
		}
	}

	lastField[*countingMoves + 1] = new int* [4];
	for (int i = 0; i < 4; ++i) {
		lastField[*countingMoves + 1][i] = new int[4];
		for (int j = 0; j < 4; j++) {
			lastField[*countingMoves + 1][i][j] = field[i][j];
		}
	}

	for (int k = 0; k < *countingMoves; ++k) {
		for (int i = 0; i < 4; ++i) {
			delete[] tempLastField[k][i];
		}
		delete[] tempLastField[k];
	}
	delete[] tempLastField;
	cout << "Make your " << *countingMoves << "st move: ";
	cin >> move; // даём возмонжость выбрать куда походить
	playerMoveOutput(field, move);
	int similarityField = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (lastField[*countingMoves+1][i][j] != field[i][j]) {
				similarityField = 1;
			}
		}
	}
	if (similarityField == 1) {
		++*countingMoves; // прибавляем к числу ходов 1
		selectionRandomOutput(field); // вызываем рандом
		gameOutput(field); // и показываем пользователю что он сделал
	}
	else if (*countingMoves > 0) {
		if (move[0] == 'b' || move[0] == 'b' && move[1] == 'a' && move[2] == 'c' && move[3] == 'k') {
			--*countingMoves;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					field[i][j] = lastField[*countingMoves][i][j];
				}
			}
			gameOutput(field); // и показываем пользователю что он сделал
		}
	}
	else {
		return;
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
	//field[2][3] = 2;
	//field[3][3] = 0;

	selectionRandomOutput(field); // по игре сразу 2 создают числа а не 1
	selectionRandomOutput(field); // а вот и 2
	gameOutput(field);
	int* endGame = new int(0);
	char move[10]; // создаём переменную отвечающию за выбраный ход игрока
	int* сountingMoves = new int(1); // число его ходов
	do { // бесконечность не предел
		dataCheck(field, move, сountingMoves, lastField);
		gameEnd(field, endGame);
	} while (*endGame == 0);
	if (*endGame == 1) {
		cout << "You WIN!!!" << endl;
	}
	else if (*endGame == 2) {
		cout << "You lose(";
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

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			delete[] lastField[i][j];
		}
		delete[] lastField[i];
	}
	delete[] lastField;
	lastField = nullptr;
}