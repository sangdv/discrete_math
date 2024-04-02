#include <iostream>
using namespace std;

const int N = 20;
int b[N];
int n;

void NextBinaryStr() {
	for (int i = n; i >= 1; i--) {
		if (b[i] == 1) b[i] = 0;
		else {
			b[i] = 1;
			break;
		}
	}
}

void PrintCurBinaryStr() {
	for (int i = 1; i <= n; i++) 
		cout << b[i];
	cout << endl; // printf("\n");
}

bool IsEnd() {
	for (int i = 1; i <= n; i++)
		if (b[i] == 0) return false;
	return true;
}

void Generate() {
	bool stop = false;
	while (!stop) {
		PrintCurBinaryStr();
		if (!IsEnd()) 
			NextBinaryStr();
		else stop = true;
	}
}

int main() {
	cin >> n;
	Generate();
	return 0;
}

