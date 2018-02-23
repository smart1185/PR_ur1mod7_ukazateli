#include <stdio.h>
#include <iostream>
#include <locale.h>

#include <time.h>

using namespace std;

enum typeSort { waning, ascending };

void printArr(int *a, int size);
void arrFill(int *a, int size);
int summ(int *A, int size);
void sortArr(int *arr, int *cntE1, typeSort typeS);
void sortW(int *arr);
void sortA(int *arr);
void fillArrNeg(int *mas, int length);

int negElem(int *arr, int *size);
int posElem(int *arr, int *size);
int zeroElem(int *arr, int *size);

int countEven(int *arr, int size);

void arrFillD(double *a, int size);
void printArrD(double *a, int sizee);
double maxNull(double *a, int size);

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int  N;
	do
	{
		cout << "\t\t----Введите номер задания: ";
		cin >> N;
		cout << endl;
		switch (N)
		{
		case 1:
			/*1.Напишите программу, чтобы вычислить сумму всех элементов в массиве с помощью указателей.*/
		{
			int *pointer, a[10], sum = 0;
			pointer = a;
			arrFill(pointer, 10);
			sum = summ(pointer, 10);
			printArr(pointer, 10);
			printf("сумма элементов массива = %d\n", sum);
		}
		break;

		case 2:
			/*2.Напишите программу, чтобы напечатать элементы массива в обратном порядке*/
		{
			int *pointer, a[10];
			pointer = a;
			printf("Исходный массив:\n");
			arrFill(pointer, 10);
			printArr(pointer, 10);
			printf("Массива в обратном порядке:\n");
			for (int i = 10 - 1; i >= 0; i--)
			{
				printf("[%d]%d  ", i, *(pointer + i));
			}
		}
		cout << endl;
		break;

		case 3:
			/*3.Напишите программу, которая сортирует список целых чисел в порядке возрастания. Однако, если в командной строке
			присутствует отрицательное число, ваша программа должна сортировать список в порядке убывания. (Вы можете использовать
			любую процедуру сортировки, которую вы хотите)*/
		{
			int *pointer, a[10], size = 10;
			pointer = a;
			printf("Исходный массив:\n");
			fillArrNeg(pointer, 10);
			printArr(pointer, 10);
			printf("Отсортированный массив:\n");
			for (int i = 0; i < 10; i++)
			{
				if (*pointer < 0)
					sortArr(pointer, &size, ascending);
				else sortArr(pointer, &size, waning);
			}
			printArr(pointer, 10);
		}
		cout << endl;
		break;

		case 4:
			/*4.Пользуясь двумя указателями на массив целых чисел, скопировать один массив в другой. Использовать в программе
			арифметику указателей для продвижения по массиву, а также оператор разыменования.*/
		{
			int *pointer1, *pointer2, a1[10], a2[10] = { 0 };
			pointer1 = a1;
			pointer2 = a2;
			printf("1-й массив:\n");
			fillArrNeg(a1, 10);
			printArr(a1, 10);
			cout << endl;
			printf("2-й массив:\n");
			printArr(a2, 10);
			cout << endl;
			printf("Скопировали первый 1-й массив во 2-й \n");
			for (int i = 0; i < 10; i++)
				(*(pointer2 + i) = *(pointer1 + i));
			printArr(a2, 10);
			cout << endl;
		}
		cout << endl;
		break;

		case 5:
			/*5.Пользуясь указателем на массив целых чисел, изменить порядок следования элементов массива на противоположный.
			Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.*/
		{
			int *pointer1, *pointer2, a1[10], a2[10] = { 0 };
			pointer1 = &a1[0];
			pointer2 = &a2[9];
			printf("Исходный массив:\n");
			fillArrNeg(a1, 10);
			printArr(a1, 10);
			cout << endl;
			for (int i = 0; i < 10; i++)
			{
				*(pointer2--) = *(pointer1 + i);
			}
			printf("Реверс массива:\n");
			for (int i = 1; i <= 10; i++)
			{
				printf("[%d]%d ", i, *(pointer2 + i));
			}
			cout << endl;
		}
		cout << endl;
		break;

		case 6:
			/*6.Написать функцию, которая получает указатель на массив и его размер, и возвращает количество отрицательных,
			положительных и нулевых элементов массива.*/
		{
			int  a[10], size = 10;
			int *p = a, *psize = &size;
			printf("Массив:\n");
			fillArrNeg(p, *psize);
			printArr(p, *psize);
			printf("Количество отрицательных элементов = %d\n", negElem(p, psize));
			printf("Количество положительных элементов = %d\n", posElem(p, psize));
			printf("Количество нулевых элементов = %d\n", zeroElem(p, psize));

		}
		cout << endl;
		break;

		case 7:
			/*7.Даны два массива: А[M] и B[N] (M и  N вводятся с клавиатуры). Необходимо создать третий массив минимально
			возможного размера, в котором нужно собрать общие элементы двух массивов без повторений.*/
		{
			int m, n;
			int a1[100] = { 0 }, a2[100] = { 0 }, a3[100] = { 0 };
			int *p1 = a1, *p2 = a2, *p3 = a3;
			int indexp3 = 0, j = 0;
			cout << "Введите количество элементов массивов: " << endl;
			cin >> m >> n;
			arrFill(p1, m);
			cout << "1-й массив: " << endl;
			printArr(p1, m);
			cout << "2-й массив: " << endl;
			arrFill(p2, n);
			printArr(p2, n);
			cout << "третий массив минимально возможного размера:" << endl;
			while (j < m)
			{
				for (int i = 0; i < n; i++)
				{
					int repeat = 0;
					if (*(p1 + i) == *(p2 + j))
					{
						for (int k = 0; k < m + n; k++)
							if (*(p1 + i) == *(p3 + k))
								repeat++;
						if (repeat == 0)
						{
							*(p3 + indexp3) = *(p1 + i);
							cout << "[" << indexp3 << "] " << *(p3 + indexp3) << " ";
							indexp3++;
						}
					}
				}
				j++;
			}
		}
		cout << endl;
		break;

		case 8:
			/*8.Напишите функцию countEven (int *, int), которая получает целочисленный массив и его размер, и возвращает число
			четных чисел в массиве.*/
		{
			int  a[10], size = 10;
			int *p = a, *psize = &size;
			printf("Массив:\n");
			fillArrNeg(p, *psize);
			printArr(p, *psize);
			printf("\n");
			printf("Число четных чисел в массиве = %d\n", countEven(a, *psize));
		}
		cout << endl;
		break;

		case 9:
			/*9.Напишите функцию, которая возвращает указатель на максимальное значение массива double. Если массив пуст,
			верните NULL.*/
		{
			const int size = 5;
			double a[size] = { 0 };
			double *p = a;
			char q;
			printf("Заполнить массив? (y/n)");
			cin >> q;
			if (q == 'n')
			{
				printArrD(p, size);
				cout << endl;
				printf("%g", maxNull(p, size));
			}
			else if (q == 'y')
			{
				arrFillD(p, size);
				cout << endl;
				printf("Максисальный элемент массива = %g", maxNull(p, size));
			}
			cout << endl;
		}
		cout << endl;
		break;

		

		default: {cout << "Задания с таким номером не существует" << endl; }
		}
	} while (N > 0 && N < 10);
	cout << "\t\t\t\t\tКОНЕЦ." << endl;
	system("pause");
}

void printArr(int *a, int sizee)
{
	for (int i = 0; i < sizee; i++)
		printf("[%d] %d ", i, *(a + i));

	printf("\n");
}


void arrFill(int *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 20;
	}
}

int summ(int *A, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += A[i];
	}
	return sum;
}

void sortArr(int *arr, int *cntE1, typeSort typeS)
{
	for (int i = 0; i < *cntE1; i++)
	{
		for (int j = *cntE1 - 1; j > i; j--)
		{
			switch (typeS)
			{
			case waning:
				sortW(arr + j);
				break;
			case ascending:
				sortA(arr + j);
				break;
			}
		}
	}
}

void sortW(int *arr)
{
	int temp;
	if (*arr < *(arr - 1))
	{
		temp = *arr;
		*arr = *(arr - 1);
		*(arr - 1) = temp;
	}
}

void sortA(int *arr)
{
	int temp;
	if (*arr > *(arr - 1))
	{
		temp = *arr;
		*arr = *(arr - 1);
		*(arr - 1) = temp;
	}
}

void fillArrNeg(int *mas, int length)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		mas[i] = 10 - rand() % 12;
	}
}

/*6.Написать функцию, которая получает указатель на массив и его размер, и возвращает количество отрицательных,
положительных и нулевых элементов массива.*/
int negElem(int *arr, int *size)
{
	int neg = 0;
	for (int i = 0; i < *size; i++)
	{
		if (arr[i] < 0)
			neg++;
	}
	return neg;
}
int posElem(int *arr, int *size)
{
	int pos = 0;
	for (int i = 0; i < *size; i++)
	{
		if (arr[i] > 0)
			pos++;
	}

	return pos;
}
int zeroElem(int *arr, int *size)
{
	int zero = 0;
	for (int i = 0; i < *size; i++)
	{
		if (arr[i] == 0)
			zero++;
	}
	return zero;
}

/*8.Напишите функцию countEven (int *, int), которая получает целочисленный массив и его размер, и возвращает число
четных чисел в массиве.*/
int countEven(int *arr, int size)
{
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
			cnt++;
	}
	return cnt;
}

/*9.Напишите функцию, которая возвращает указатель на максимальное значение массива double. Если массив пуст, верните NULL.*/
double maxNull(double *a, int size)
{
	double max = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(a + i) > max)
			max = *(a + i);
		else if (*(a + i) == 0)
			max = NULL;
	}
	return max;
}

void arrFillD(double *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 10 * 0.22;
		cout << "[" << i << "]" << a[i] << " ";
	}
}

void printArrD(double *a, int sizee)
{
	for (int i = 0; i < sizee; i++)
		printf("[%d] %d ", i, *(a + i));

	printf("\n");
}
