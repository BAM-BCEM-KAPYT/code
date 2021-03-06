#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	double **m, *o, *an, c = 0, temp = 0;
	int  a = 0, b = 0;

	cout << "Press number of variables: ";
	cin >> a;
	b = a;
	cout << endl;

	m = new double*[a];
	o = new double[a];
	an = new double[b];
	for (int i = 0; i < a; i++)
	{
		m[i] = new double[b];
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << "Press element m[" << i + 1 << "][" << j + 1 << "]: ";
			cin >> m[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < a; i++)
	{
		cout << "Press " << i + 1 << "th solution: ";
		cin >> o[i];
	}

	for (int i = 0; i < b; i++) {
		for (int j = i + 1; j < a; j++) {
			c = m[j][i] / m[i][i];
			if (c) {
				for (int k = i; k < b; k++)
				{
					m[j][k] = m[j][k] - m[i][k] * c;
				}
				o[j] = o[j] - o[i] * c;
			}
			else
				break;
		}
	}
	cout << endl << endl;

	cout << "Trapeceevidnaja matrix:" << endl << endl;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << m[i][j] << "      ";
		}
		cout << "|      " << o[i];
		cout << endl << endl;
	}

	an[b - 1] = o[b - 1] / m[b - 1][b - 1];
	for (int i = b - 2; i >= 0; i--)
	{
		temp = o[i];
		for (int j = i + 1; j < b; j++)
			temp -= m[i][j] * an[j];
		an[i] = temp / m[i][i];
	}
	
	cout << endl <<"Solutions:" << endl << endl;
	for (int i = 0; i < b; i++)
	{
		cout << "Solution #" << i + 1 << "= ";
	cout << an[i] << endl << endl;
	}
}
