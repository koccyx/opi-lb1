#include <iostream>
#include <Windows.h>
#include <iomanip>

const int SIZEMATRIX = 17;

using namespace std;

void CreateMatrix(int[][SIZEMATRIX]);
void ShowMatrix(int[][SIZEMATRIX]);
void FindQuantityInAllMatrix(int[][SIZEMATRIX]);
int FindQuantityInRow(int[], int);
void CountZeroesRows(int[][SIZEMATRIX]);
void CountDownTriangle(int[][SIZEMATRIX]);
const int RandomNumberInRange(int, int);
void Menu(int[][SIZEMATRIX]);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int matrix[SIZEMATRIX][SIZEMATRIX];
	CreateMatrix(matrix);
	Menu(matrix);
	return 0;
}

void CountZeroesRows(int matrix[][SIZEMATRIX]) {
	cout << "�) ���������� ��������� �����:";
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

void CountDownTriangle(int matrix[][SIZEMATRIX]) {
	cout << "�)C���� ��������� ������� ��� ������ ����������: ";
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

int FindQuantityInRow(int array[], int minValue)
{
	int k = 0;
	for (int i = 0; i < SIZEMATRIX; i++)
	{
		if (array[i] < minValue)
		{
			k++;
		}
	}
	return k;
}

void FindQuantityInAllMatrix(int matrix[][SIZEMATRIX])
{
	cout << "�)";
	cout << "������� ��������: ";
	int minValue = 0;
	cin >> minValue;
	for (int i = 0; i < SIZEMATRIX; i++)
	{
		cout << "���������� ���������, ������� ��������� �������� � ������ " << i + 1 << " �����: " << FindQuantityInRow(matrix[i], minValue) << endl;
	}
}

void ShowMatrix(int matrix[][SIZEMATRIX])
{
	cout << "��������� �������:\n";
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

void CreateMatrix(int matrix[][SIZEMATRIX])
{
	for (int i = 0; i < SIZEMATRIX; i++)
	{
		for (int j = 0; j < SIZEMATRIX; j++)
		{
			matrix[i][j] = RandomNumberInRange(-10, 16);
		}
	}
}

const int RandomNumberInRange(int lowerEdge, int upperEdge)
{
	return rand() % (upperEdge + 1) - rand() % (lowerEdge + 1);
}

void Menu(int matrix[][SIZEMATRIX]) {
	int menuNum = 100;
	CreateMatrix(matrix);
	while (menuNum != 0) {
		system("cls");
		cout << "1 - ������� �������\n";
		cout << "2 - �)���������� ���������, ������� ��������� ��������\n";
		cout << "3 - �)���������� ��������� �����\n";
		cout << "4 - �)C���� ��������� ������� ��� ������ ����������\n";
		cout << "0 - ����� �� ���������\n";
		cout << "�������� �����: ";
		cin >> menuNum;
		system("cls");
		switch (menuNum)
		{
		case 1:
			ShowMatrix(matrix);
			cout << '\n';
			system("pause");
			break;
		case 2:
			FindQuantityInAllMatrix(matrix);
			cout << '\n';
			system("pause");
			break;
		case 3:
			CountZeroesRows(matrix);
			cout << '\n';
			system("pause");
			break;
		case 4:
			CountDownTriangle(matrix);
			cout << '\n';
			system("pause");
			break;
		case 0:
			cout << "�� ��������.\n";
			system("pause");
			break;
		default:
			cout << "������� ����� �� ������";
			cout << '\n';
			system("pause");
			break;
		}
	}
}