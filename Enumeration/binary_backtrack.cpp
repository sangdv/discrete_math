#include <iostream>
using namespace std;

const int N = 20;
int a[N];
int n;

void PrintSol() {
	for (int i = 1; i <= n; i++)
		cout << a[i];
	cout << endl;
}

void TRY(int k) {
	for (int y = 0; y <= 1; y++) {
		a[k] = y;
		if (k == n) PrintSol();
		else TRY(k + 1);
	}
}

int main() {
	cin >> n;
	TRY(1);
	return 0;
}
