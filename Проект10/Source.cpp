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
		cout << "\t\t----������� ����� �������: ";
		cin >> N;
		cout << endl;
		switch (N)
		{
		case 1:
			/*1.�������� ���������, ����� ��������� ����� ���� ��������� � ������� � ������� ����������.*/
		{
			int *pointer, a[10], sum = 0;
			pointer = a;
			arrFill(pointer, 10);
			sum = summ(pointer, 10);
			printArr(pointer, 10);
			printf("����� ��������� ������� = %d\n", sum);
		}
		break;

		case 2:
			/*2.�������� ���������, ����� ���������� �������� ������� � �������� �������*/
		{
			int *pointer, a[10];
			pointer = a;
			printf("�������� ������:\n");
			arrFill(pointer, 10);
			printArr(pointer, 10);
			printf("������� � �������� �������:\n");
			for (int i = 10 - 1; i >= 0; i--)
			{
				printf("[%d]%d  ", i, *(pointer + i));
			}
		}
		cout << endl;
		break;

		case 3:
			/*3.�������� ���������, ������� ��������� ������ ����� ����� � ������� �����������. ������, ���� � ��������� ������
			������������ ������������� �����, ���� ��������� ������ ����������� ������ � ������� ��������. (�� ������ ������������
			����� ��������� ����������, ������� �� ������)*/
		{
			int *pointer, a[10], size = 10;
			pointer = a;
			printf("�������� ������:\n");
			fillArrNeg(pointer, 10);
			printArr(pointer, 10);
			printf("��������������� ������:\n");
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
			/*4.��������� ����� ����������� �� ������ ����� �����, ����������� ���� ������ � ������. ������������ � ���������
			���������� ���������� ��� ����������� �� �������, � ����� �������� �������������.*/
		{
			int *pointer1, *pointer2, a1[10], a2[10] = { 0 };
			pointer1 = a1;
			pointer2 = a2;
			printf("1-� ������:\n");
			fillArrNeg(a1, 10);
			printArr(a1, 10);
			cout << endl;
			printf("2-� ������:\n");
			printArr(a2, 10);
			cout << endl;
			printf("����������� ������ 1-� ������ �� 2-� \n");
			for (int i = 0; i < 10; i++)
				(*(pointer2 + i) = *(pointer1 + i));
			printArr(a2, 10);
			cout << endl;
		}
		cout << endl;
		break;

		case 5:
			/*5.��������� ���������� �� ������ ����� �����, �������� ������� ���������� ��������� ������� �� ���������������.
			������������ � ��������� ���������� ���������� ��� ����������� �� �������, � ����� �������� �������������.*/
		{
			int *pointer1, *pointer2, a1[10], a2[10] = { 0 };
			pointer1 = &a1[0];
			pointer2 = &a2[9];
			printf("�������� ������:\n");
			fillArrNeg(a1, 10);
			printArr(a1, 10);
			cout << endl;
			for (int i = 0; i < 10; i++)
			{
				*(pointer2--) = *(pointer1 + i);
			}
			printf("������ �������:\n");
			for (int i = 1; i <= 10; i++)
			{
				printf("[%d]%d ", i, *(pointer2 + i));
			}
			cout << endl;
		}
		cout << endl;
		break;

		case 6:
			/*6.�������� �������, ������� �������� ��������� �� ������ � ��� ������, � ���������� ���������� �������������,
			������������� � ������� ��������� �������.*/
		{
			int  a[10], size = 10;
			int *p = a, *psize = &size;
			printf("������:\n");
			fillArrNeg(p, *psize);
			printArr(p, *psize);
			printf("���������� ������������� ��������� = %d\n", negElem(p, psize));
			printf("���������� ������������� ��������� = %d\n", posElem(p, psize));
			printf("���������� ������� ��������� = %d\n", zeroElem(p, psize));

		}
		cout << endl;
		break;

		case 7:
			/*7.���� ��� �������: �[M] � B[N] (M �  N �������� � ����������). ���������� ������� ������ ������ ����������
			���������� �������, � ������� ����� ������� ����� �������� ���� �������� ��� ����������.*/
		{
			int m, n;
			int a1[100] = { 0 }, a2[100] = { 0 }, a3[100] = { 0 };
			int *p1 = a1, *p2 = a2, *p3 = a3;
			int indexp3 = 0, j = 0;
			cout << "������� ���������� ��������� ��������: " << endl;
			cin >> m >> n;
			arrFill(p1, m);
			cout << "1-� ������: " << endl;
			printArr(p1, m);
			cout << "2-� ������: " << endl;
			arrFill(p2, n);
			printArr(p2, n);
			cout << "������ ������ ���������� ���������� �������:" << endl;
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
			/*8.�������� ������� countEven (int *, int), ������� �������� ������������� ������ � ��� ������, � ���������� �����
			������ ����� � �������.*/
		{
			int  a[10], size = 10;
			int *p = a, *psize = &size;
			printf("������:\n");
			fillArrNeg(p, *psize);
			printArr(p, *psize);
			printf("\n");
			printf("����� ������ ����� � ������� = %d\n", countEven(a, *psize));
		}
		cout << endl;
		break;

		case 9:
			/*9.�������� �������, ������� ���������� ��������� �� ������������ �������� ������� double. ���� ������ ����,
			������� NULL.*/
		{
			const int size = 5;
			double a[size] = { 0 };
			double *p = a;
			char q;
			printf("��������� ������? (y/n)");
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
				printf("������������ ������� ������� = %g", maxNull(p, size));
			}
			cout << endl;
		}
		cout << endl;
		break;

		

		default: {cout << "������� � ����� ������� �� ����������" << endl; }
		}
	} while (N > 0 && N < 10);
	cout << "\t\t\t\t\t�����." << endl;
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

/*6.�������� �������, ������� �������� ��������� �� ������ � ��� ������, � ���������� ���������� �������������,
������������� � ������� ��������� �������.*/
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

/*8.�������� ������� countEven (int *, int), ������� �������� ������������� ������ � ��� ������, � ���������� �����
������ ����� � �������.*/
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

/*9.�������� �������, ������� ���������� ��������� �� ������������ �������� ������� double. ���� ������ ����, ������� NULL.*/
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
