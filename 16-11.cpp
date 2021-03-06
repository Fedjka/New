
#include <string>
#include "stdafx.h"
#include <iostream>

using namespace std;


int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j]> brd);
		while (A[++i]< brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
int* sortHoar(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	return A;
};
void mergeSort(int *a, int l, int r)
{
	if (l == r) return; // границы сомкнулись
	int mid = (l + r) / 2; // определяем середину последовательности
						   // и рекурсивно вызываем функцию сортировки для каждой половины
	mergeSort(a, l, mid);
	mergeSort(a, mid + 1, r);
	int i = l;  // начало первого пути
	int j = mid + 1; // начало второго пути
	int *tmp = (int*)malloc(r * sizeof(int)); // дополнительный массив
	for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
	{
		// записываем в формируемую последовательность меньший из элементов двух путей
		// или остаток первого пути если j > r
		if ((j > r) || ((i <= mid) && (a[i] < a[j])))
		{
			tmp[step] = a[i];
			i++;
		}
		else
		{
			tmp[step] = a[j];
			j++;
		}
	}
	// переписываем сформированную последовательность в исходный массив
	for (int step = 0; step < r - l + 1; step++)
		a[l + step] = tmp[step];
}
void heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 <  n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n  &&  A[2 * pos + 2] >= A[t])
			t = 2 * pos + 2;
		if (A[pos] < A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}


void piramSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n>0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
	}
}
void Vyvod(int c[], int k)
{
	for (int e = 0; e < k; e++) {
		cout << c[e] << "   ";
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	int choice;
	int a[10];
	int b[10];
	int k = 0;
	int c[20];
	int e[20][20];
	int z[20];
	// Заполняем массив с клавиатуры
	for (int i = 0; i < 10; i++) {
		cout << "[" << i + 1 << "]" << ": ";
		cin >> a[i];
	}
	for (int j = 0; j < 10; j++) {
		cout << "[" << j + 1 << "]" << ": ";
		cin >> b[j];
	}
	// И выводим заполненный массив.
	cout << "\nВаш массив: ";

	for (int i = 0; i < 10; ++i) {
		cout << a[i] << " ";
	}

	cout << "\nВаш второй массив: ";

	for (int j = 0; j < 10; ++j) {
		cout << b[j] << " ";
	}
	for (int i = 0; i < 10; i++) {
		if (a[i] % 2 == 0) {
			c[k] = a[i];
			k++;
		}
		if (b[i] % 2 == 1) {
			c[k] = b[i];
			k++;
		}
	}

	cout << "\nВаш третий массив: ";

	for (int e = 0; e < k; e++) {
		cout << c[e] << " ";
	}	cout << endl;
	for (;;)
	{
		cout << "1 - Хоар(Она же,сортировка разделением)" << endl;
		cout << "2 - Пирамида" << endl;
		cout << "3 - Слияние" << endl;

		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:
			exit(0);

		case 1:
			memcpy(z, c, k * sizeof(int));
			sortHoar(z, 0, k - 1);
			Vyvod(z, k);
			break;
		case 2:
			memcpy(z, c, k * sizeof(int));
			heapify(z, z[0], k);
			piramSort(z, k);
			Vyvod(z, k);
			break;
		case 3:
			memcpy(z, c, k * sizeof(int));
			mergeSort(z, 0, k - 1);
			Vyvod(z, k);
			break;

		default:
			cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}