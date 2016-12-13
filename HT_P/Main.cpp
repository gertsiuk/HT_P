#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//// Initializing
void UInAlgorithm();
int** DefineMatrix(int n, int m);
void FillMatrixRnd(int **Array, int n, int m, int begin, int end);
int FrequencyOfEvenDigit(int **Array, int n, int m);
int MostUsefullEvenDigit(int **Array, int n, int m, int begin, int end);
void ChangeDigits(int **Array, int n, int m, int FrequentlyNumber, int Frequence);
void OutputArray(int **Array, int n, int m);

int main()
{
	UInAlgorithm();
	system("pause");
	return 0;
}

void UInAlgorithm()
{
	int n, m;
	int begin = 0;
	int end = 10;
	cout << "Define n-size: ";
	cin >> n;
	cout << endl;
	cout << "Define m-size: ";
	cin >> m;
	cout << endl;
	int ** Array = DefineMatrix(n, m);
	FillMatrixRnd(Array, n, m, begin, end);
	OutputArray(Array, n, m);
	int FrenquencyUsedDigit = FrequencyOfEvenDigit(Array, n, m);
	cout << "Frequency of using digit: " << FrenquencyUsedDigit << endl;
	int MostUsefullEvenDigitVar = MostUsefullEvenDigit(Array, n, m, begin, end);
	cout << "Most usefull even digit is " << MostUsefullEvenDigitVar << endl;

	ChangeDigits(Array, n, m, MostUsefullEvenDigitVar, FrenquencyUsedDigit);
	OutputArray(Array, n, m);
}

int** DefineMatrix(int n, int m)
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}
	return matrix;
}

void FillMatrixRnd(int **Array, int n, int m, int begin, int end)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Array[i][j] = rand() % end + begin;
		}
	}
}

int FrequencyOfEvenDigit(int **Array, int n, int m)
{
	int countOfDigits = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Array[i][j] % 2 == 0) countOfDigits++;
		}
	}

	int frequency = (int)((float)((float)countOfDigits / (float)(n * m))*100);
	return frequency;
}

int MostUsefullEvenDigit(int **Array, int n, int m, int begin, int end)
{
	// Array of frequently of using digits
	int * FrequentlyUsedArray = new int[end];

	for (int k = 0; k < end; k++)
	{
		FrequentlyUsedArray[k] = 0;
	}
	// Counting digit finding
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
				FrequentlyUsedArray[Array[i][j] - begin]++;
		}
	}
	// Finding maximal of using
	int max=0;
	int indexOfmax = 0;
	for (int k = 0; k < end; k++)
	{
		if ((k + begin) % 2 == 0)
		{
			if (max<FrequentlyUsedArray[k])
			{
				max = FrequentlyUsedArray[k];
				indexOfmax = k;
			}
		}
	}
	int mostUsefullFrequentlyNumber = indexOfmax + begin;
	return mostUsefullFrequentlyNumber;
}

void ChangeDigits(int **Array, int n, int m, int FrequentlyNumber, int Frequence)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Array[i][j] == FrequentlyNumber) Array[i][j] = (int)(((float)Frequence / (float)100)*(float)FrequentlyNumber);
		}
	}
}

void OutputArray(int **Array, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << Array[i][j] << "\t";
		}
		cout << endl;
	}
}