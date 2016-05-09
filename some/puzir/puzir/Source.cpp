#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void print(int**P, int n);
int main()
{
	int **P;
	int n = 5;
	srand(time(0));
	P = new int*[10];
	for (int i = 0; i < n; i++)
		P[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			P[i][j] = rand() % 10;
	print(P,n);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n - 1; k++) {
			for (int j = 0; j < n - 1 - k; j++) {
				if (P[i][j] > P[i][j+1]) {
					int t = P[i][j];
					P[i][j] = P[i][j+1];
					P[i][j+1] = t;
					print(P, n);
				}
			}
		}
	}
	print(P, n);

	
	system("pause");
	return 0;
}

void print(int**P, int n) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << P[i][j] << " ";
		cout << endl;
	}
}