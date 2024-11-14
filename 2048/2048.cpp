#include <iostream>

using namespace std;

void gameOutput(int** field) { // здесь создаём мы функцию которая выводит всю игру
	int a = 0; // нужно чтобы проверяло есть ли в массиве 2 мерные или ещё больше числа чтобы перестраиватся можно было типо то больше интерфейс то меньше
	for (int i = 0; i < 4; i++) { // перебераем все числа во всех масивах
		for (int j = 0; j < 4; j++) {
			if (field[i][j] >= 10) { // cмотрим является ли оно двухзначное
				a = 1;
			}
			if (field[i][j] >= 100) { // теперь является ли оно трёхзначное
				a = 2;
			}
		}
	}
	for (int i = 0; i < 4; i++) { // снова перебераем всё
		for (int j = 0; j < 4; j++) {
			if (a == 1) { // если число двухзначное то интерфейсе будет в 2 раза больше пробелов но не в месте где число двухзначное
				if (field[i][j] >= 10) {
					cout << field[i][j] << " ";
				}
				else {
					cout << field[i][j] << "  ";
				}
			} // иначе нет
			else if (a == 2) { // если трёхзначное то пробел цифре будет в 3 раза больше а в двухзначном будет в 2 раза больше пробел
				if (field[i][j] >= 100) {
					cout << field[i][j] << " ";
				}
				else if (field[i][j] >= 10) {
					cout << field[i][j] << "  ";
				}
				else {
					cout << " " << field[i][j] << "  ";
				}
			}
			else {
				cout << field[i][j] << " ";
			}
		}
		if (a == 2) {
			cout << endl;
		}
		cout << endl;
	}
}

int** selectionRandomOutput(int** field) { // функция для создания рандомного число в рандомном месте после хода пользователя
	int x, y;
	srand(time(NULL));
	x = rand() % 4; // рандомный х в массиве массивов
	y = rand() % 4; // рандомный у в массиве чисел

	while (field[x][y] != 0) { // если число уже занято то проверяем снова
		srand(time(NULL));
		x = rand() % 4;
		y = rand() % 4;
	}

	field[x][y] = 2;
	return field;
}

int** playesMoveOutput(int** field, char move) { // cоздаём функцию для возможности ходить
	if (move == 'w' || move == 'W') { // конкретно здесь он ходит на верх
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

	else if (move == 'a' || move == 'A') { // здесь уже влево. Что и как работает написал сверху /|\ 
		for (int i = 0; i < 4; i++) { //                                                          |
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

	else if (move == 's' || move == 'S') { // теперь вниз... что и как сверху и ещё выше
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

	else if (move == 'd' || move == 'D') { // сейчас направо...... что да как это надо листать выше и ещё выше почти до потолка
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
					else if (field[i][2] == field[i][1] && j != 2 && j != 3 && b != 1 || field[i][2] == field[i][0] && field[i][1] == 0 && j != 2 && j != 2 && b != 1) {
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
	return field;
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

	//field[0][0] = 4;
	//field[1][0] = 2;
	//field[2][0] = 2;
	//field[3][0] = 8;

	selectionRandomOutput(field); // по игре сразу 2 создают числа а не 1
	selectionRandomOutput(field); // а вот и 2
	gameOutput(field);

	char move = 0; // создаём переменную отвечающию за выбраный ход игрока
	int countingMoves = 1; // число его ходов
	while (true) { // бесконечность не предел
		cout << "Make your " << countingMoves << "st move: ";
		cin >> move; // даём возмонжость выбрать куда походить
		if (move == 'w' || move == 'W' || move == 'a' || move == 'A' || move == 's' || move == 'S' || move == 'd' || move == 'D') { // проверка на оленя
			playesMoveOutput(field, move); //даём возможность походить
			countingMoves++; // прибавляем к числу ходов 1
			selectionRandomOutput(field); // вызываем рандом
			gameOutput(field); // и показываем пользователю что он сделал
		}
		else { // если проверка на оленя не удачна то запускаем всё заново
			exit; 
		}
	}
}