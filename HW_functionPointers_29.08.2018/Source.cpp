#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

// 1.	***Реализовать 3 функции каждая из которых принимает указатель на массив и количество элементов
// и возвращает указатель на новый массив.
// Первая функция ищет простые числа и заносит их в новый массив,
// вторая – все числа кратные трем, третья – все четные числа.
// Затем напишите функцию, которая принимает указатель на одну из этих функций, указатель на массив и количество элементов.
// Добавьте меню, в котором пользователь может выбрать желаемую операцию.
// Простое число – это число, которое делиться ТОЛЬКО на 1 и на себя(2, 5, 7, 11 и т.д.).
// Рекомендации:
// Сначала посчитайте количество простых элементов в массиве, потом уже создайте новый массив и занесите туда эти числа.
bool prime(int a) {
	if (a < 0 || a == 0 || a == 1) return false;
	for (int i = 2; i < a; i++)
	{
		if (a%i == 0) return false;
	}
	return true;
}
void arr_prime(int* &a, int &n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		if (prime(a[i])) k++;

	if (k == 0)
	{
		cout << "No prime numbers" << endl << endl;
		return;
	}

	int *tmp = new int[k];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (prime(a[i]))
			tmp[j++] = a[i];
	}
	delete[] a;
	a = tmp;
	n = k;
}
void arr_3(int* &a, int &n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 3 == 0) k++;

	int *tmp = new int[k];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 3 == 0)
			tmp[j++] = a[i];
	}
	delete[] a;
	a = tmp;
	n = k;
}
void arr_even(int* &a, int &n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0) k++;

	int *tmp = new int[k];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
			tmp[j++] = a[i];
	}
	delete[] a;
	a = tmp;
	n = k;
}
void f3(int *&a, int &n, void(*f)(int*&, int&)) {
	f(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;
}
int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
			int *a;
			int n = 10;
			a = new int[n];

			cout << "Дан массив чисел:" << endl;
			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 100 - 20;
				cout << a[i] << " ";
			}
			cout << endl;

			void(*f[3])(int *&, int&) = { arr_prime, arr_3, arr_even };

			int choice;
			cout << "Выберите функцию, которая выбирает из массива:" << endl << "0 (простые числа), 1 (кратные 3), 2 (четные)" << endl;
			cin >> choice; // нельзя зациклить, т.к. каждую итерацию использует указатель на новый массив
			// если же в f3 не передавать по ссылкеб возникнет конфликт

			f3(a, n, *f[choice]);
	
			delete[] a;

	}
	system("pause");
	return 0;
}