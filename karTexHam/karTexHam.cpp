//GRAPH
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main( )
{
	//variables
	int C1[80], C2[80], T1[80], T2[80], T3[80], A[80][80] = { 0 }, B[80][80] = { 0 }, C[80][80], D[80][80];
	int n, m, i, j, k, t1 = 0, t2 = 0, t3 = 0, t4 = 0, length;
	float km, knk;
	bool t;

	//input n
	cout << "N =";
	cin >> n;

	//input C[i][j] matrix
	for (i = 1; i <= n; i++) {
		cin >> C1[i];
		cin >> C2[i];
	}

	//output C[i][j] matrix
	cout << "\n----------------------------\n\n";
	for (i = 1; i <= n; i++)
		cout << C1[i] << "  " << C2[i] << endl;
	cout << "\n----------------------------\n\n";

	//get t1 t2 t3 t4
	for (i = 1; i <= n; i++)
		if (!(find(begin(C2), end(C2), C1[i]) != end(C2)) && !(find(begin(T1), end(T1), C1[i]) != end(T1)))
			T1[++t1] = C1[i];
		else if ((find(begin(C2), end(C2), C1[i]) != end(C2)) && C2[i] != 0 && !(find(begin(T2), end(T2), C1[i]) != end(T2)))
			T2[++t2] = C1[i];
		else if (C2[i] == 0)
			T3[++t3] = C1[i];

	for (i = 1; i <= n; i++)
		for (j = 1; j <= t2; j++)
			if (C1[i] == T2[j])
				for (k = 1; k <= t2; k++)
					if (C2[i] == T2[k]) {
						t4++;
						break;
					}

	for (i = 1; i <= n; i++)
		A[C1[i]][C2[i]] = 1;

	m = *max_element(C1, C1 + n + 1);
	//get km, knk
	km = (float)t2 / (float)m;
	knk = (float)t4 / (float)n;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= m; j++) {
			cout << A[i][j] << "   ";
			B[i][j] = A[i][j];
			D[i][j] = A[i][j];

		}
		cout << "\n" << endl;
	}
	cout << "A^1\n" << "--------------------------" << endl;

	t = true;
	length = 1;
	while (t) {
		for (i = 1; i <= m; i++)
			for (j = 1; j <= m; j++) {
				C[i][j] = 0;
				for (k = 1; k <= m; k++)
					C[i][j] = C[i][j] + B[i][k] * A[k][j];
			}
		for (i = 1; i <= m; i++)
			for (j = 1; j <= m; j++)
				D[i][j] = D[i][j] + C[i][j];

		for (i = 1; i <= m; i++) {
			for (j = 1; j <= m; j++) {
				cout << C[i][j] << "   ";
				B[i][j] = C[i][j];
			}
			cout << "\n" << endl;
		}
		cout << "A^" << length + 1 << "\n" << "--------------------------" << endl;

		for (i = 1; i <= m; i++)
			if (B[i][i] == 1) {
				cout << "grafum goyutyun uni contur" << endl;
				system("pause");
				return 0;
			}

		t = false;
		for (i = 1; i <= m; i++) {
			for (j = 1; j <= m; j++)
				if (B[i][j] != 0) {
					t = true;
				}
		}
		length++;
	}
	cout << "---------\nlength =" << length - 1 << "\n----------" << endl;

	cout << "t1 = " << t1 << " { ";
	for (i = 1; i <= t1; i++)
		cout << T1[i] << " ";
	cout << " } \n\n";

	cout << "t2 = " << t2 << " { ";
	for (i = 1; i <= t2; i++)
		cout << T2[i] << " ";
	cout << " } \n\n";

	cout << "t3 = " << t3 << " { ";
	for (i = 1; i <= t3; i++)
		cout << T3[i] << " ";
	cout << " } \n\n";

	cout << "t4 = " << t4 << endl << endl;

	cout << "km = " << km << "\nKnK = " << knk << endl << endl;

	cout << "-----------------------" << endl << endl;
	cout << "the sum of matrices" << endl;

	for (i = 1; i <= m; i++) {
		for (j = 1; j <= m; j++) {
			cout << D[i][j] << "   ";

		}
		cout << "\n";
	}

	system("pause");
	return 0;
}