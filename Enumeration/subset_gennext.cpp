#include <iostream>
using namespace std;

const int N = 20;
int n, m;
int a[N];

void NextSubSet() {
	int k = m;
	while (a[k] == n - m + k) k--;
	a[k]++;
	for (int i = k + 1; i <= m; i++) 
		a[i] = a[k] + i  - k;
}

void PrintCurSubSet() {
	for (int i = 1; i <= m; i++)
		cout << a[i] << ' ';
	cout << endl;
}

bool IsEnd() {
	for (int i = 1; i <= m; i++)
		if (a[i] != n - m + i) return false;
	return true;
}

void Generate() {
	bool stop = false;
	while (!stop) {
		PrintCurSubSet();
		if (!IsEnd()) NextSubSet();
		else stop = true;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		a[i] = i;
	Generate();
	return 0;
}



