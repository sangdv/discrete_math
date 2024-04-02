#include <iostream>
using namespace std;

const int N = 15;
int n;
int a[N];

bool UCV(int j, int k) {
	for (int i = 1; i < k; i++)
		if (j == a[i]) return false;
	return true;
}

void PrintSol() {
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void TRY(int k) {
	for (int j = 1; j <= n; j++) {
		if (UCV(j, k)) {
			a[k] = j;
			if (k == n) PrintSol();
			else TRY(k + 1);
		}
	}
}

int main() {
	cin >> n;
	TRY(1);
	return 0;
}



