#pragma warning( disable : 6031 )
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

bool ruch(int** tab, const int& N, int wariant, int x, int y, int& nx, int& ny)
{
	switch (wariant) {
	case 1:
		nx = x + 1;
		ny = y - 2;
		break;
	case 2:
		nx = x + 2;
		ny = y - 1;
		break;
	case 3:
		nx = x + 2;
		ny = y + 1;
		break;
	case 4:
		nx = x + 1;
		ny = y + 2;
		break;
	case 5:
		nx = x - 1;
		ny = y + 2;
		break;
	case 6:
		nx = x - 2;
		ny = y + 1;
		break;
	case 7:
		nx = x - 2;
		ny = y - 1;
		break;
	case 8:
		nx = x - 1;
		ny = y - 2;
		break;
	}
	if (0 <= nx && nx < N && 0 <= ny && ny < N && tab[nx][ny] == 0)
	{
		return true;
	}
	return false;
}

bool skoczek(int** tab, const int& n, int x, int y, int ktory)
{
	int nx, ny, w;

	tab[x][y] = ktory;

	if (ktory == n * n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << tab[j][i] << " ";
			cout << endl;
		}
		return 1;
	}
	else
	{
		for (w = 1; w < 9; w++)
			if (ruch(tab, n, w, x, y, nx, ny) == true)
				if (skoczek(tab, n, nx, ny, ktory + 1) == true)
					return true;
		tab[x][y] = 0;
	}

	return false;
}

int main()
{
	const int n = 8;
	int a, b;

	int i, j;
	int** h = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{
		h[i] = (int*)malloc(n * sizeof(int));
	}

	printf("Algorytm konika szachowego\n");
	printf("Z ktorego miejsca chcesz zaczac. Podaj a:\n");
	scanf("%d", &a);
	printf("Z ktorego miejsca chcesz zaczac. Podaj b:\n");
	scanf("%d", &b);

	skoczek(h, n, a, b, 1);

	for (int i = 0; i < n; i++)
	{
		free(h[i]);
	}
	free(h);

	system("pause");

	return 0;
}
