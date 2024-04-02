#include <iostream>
using namespace std;

const int M = 20;
int n, m;
int a[M];

void PrintSol() {
	for (int i = 1; i <= m; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void TRY(int k) {
	for (int y = a[k - 1] + 1; y <= n - (m- k); y++) {
		a[k] = y;
		if (k == m) PrintSol();
		else TRY(k + 1);
	}
}

int main() {
	cin >> n >> m;
	a[0] = 0;
	TRY(1);
	return 0;
}