#include <iostream>
#include <Windows.h>
#include <iomanip>

const int SIZEMATRIX = 17;

using namespace std;

void createMatrix(int[][SIZEMATRIX]);
void showMatrix(int[][SIZEMATRIX]);
void findQuantityInAllMatrix(int[][SIZEMATRIX]);
int findQuantityInStr(int[], int);
void countZeroes(int[][SIZEMATRIX]);
void countDownTriangle(int[][SIZEMATRIX]);
const int randomNumberInRange(int);
void menu(int[][SIZEMATRIX]);

int main()
{
	system("chcp 1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int matrix[SIZEMATRIX][SIZEMATRIX];
	createMatrix(matrix);
	menu(matrix);
	return 0;
}

void countZeroes(int matrix[][SIZEMATRIX]) {
	cout << "б) Количество ненулевых строк:";
	bool flag = true;
	int counter = 0;
	for (int i = 0; i < SIZEMATRIX; i++) {
		for (int j = 0; j < SIZEMATRIX; j++) {
			if (matrix[i][j] != 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			counter++;
		}
		else {
			flag = true;
		}
	}
	cout << counter;
}

void countDownTriangle(int matrix[][SIZEMATRIX]) {
	cout << "в)Cумма элементов матрицы под нижней диагональю: ";
	int sum = 0;
	for (int i = 0; i < SIZEMATRIX; i++) {
		for (int j = 0; j < SIZEMATRIX; j++) {
			if (j - i <= 0) {
				sum += matrix[i][j];
			}
		}
	}
	cout << sum;
}

int findQuantityInStr(int str[], int value)
{
	int k = 0;
	for (int i = 0; i < SIZEMATRIX; i++)
	{
		if (str[i] < value)
		{
			k++;
		}
	}
	return k;
}

void findQuantityInAllMatrix(int matrix[][SIZEMATRIX])
{
	cout << "а)";
	cout << "Задайте значение: ";
	int value = 0;
	cin >> value;
	for (int i = 0; i < SIZEMATRIX; i++)
	{
		cout << "Количество элементов, меньших заданного значения в строке " << i + 1 << " равно: " << findQuantityInStr(matrix[i], value) << endl;
	}
}

void showMatrix(int matrix[][SIZEMATRIX])
{
	cout << "Созданная матрица:\n";
	for (int i = 0; i < SIZEMATRIX; i++)
	{
		for (int j = 0; j < SIZEMATRIX; j++)
		{
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void createMatrix(int matrix[][SIZEMATRIX])
{
	for (int i = 0; i < SIZEMATRIX; i++)
	{
		for (int j = 0; j < SIZEMATRIX; j++)
		{
			matrix[i][j] = randomNumberInRange(12);
		}
	}
}

const int randomNumberInRange(int zone)
{
	return rand() % (2 * zone) - zone;
}

void menu(int matrix[][SIZEMATRIX]) {
	int menu_num = 100;
	createMatrix(matrix);
	while (menu_num != 0) {
		system("cls");
		cout << "1 - Вывести матрицу\n";
		cout << "2 - а)Количество элементов, меньших заданного значения\n";
		cout << "3 - б)Количество ненулевых строк\n";
		cout << "4 - в)Cумма элементов матрицы под нижней диагональю\n";
		cout << "0 - Выход из программы\n";
        cout << "Выберите пункт: ";
		cin >> menu_num;
        cout <<'\n';
		switch (menu_num)
		{
		case 1:
			showMatrix(matrix);
			cout << '\n';
			system("pause");
			break;
		case 2:
			findQuantityInAllMatrix(matrix);
            cout << '\n';
			system("pause");
			break;
		case 3:
            countZeroes(matrix);
			cout << '\n';
			system("pause");
            break;
		case 4:
			countDownTriangle(matrix);
			cout << '\n';
			system("pause");
            break;
		case 0:
			cout << "Досвидания\n";
			system("pause");
			break;
		default:
			cout << "Введите число из списка";
            cout << '\n';
			system("pause");
			break;
		} 
	}
}
