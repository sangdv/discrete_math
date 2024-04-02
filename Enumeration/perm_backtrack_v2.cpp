#include <iostream>
using namespace std;

const int N = 15;
int n;
int a[N];
bool visited[N];

void PrintSol() {
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void TRY(int k) {
	for (int j = 1; j <= n; j++) {
		if (!visited[j]) {
			a[k] = j;
			visited[j] = true;
			if (k == n) PrintSol();
			else TRY(k + 1);
			visited[j] = false;
		}
	}
}

int main() {
	cin >> n;
	memset(visited, false, sizeof(visited));
	TRY(1);
	return 0;
}



