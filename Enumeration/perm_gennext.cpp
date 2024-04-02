#include <iostream>
#include <algorithm>
using namespace std;

const int N = 15;
int n;
int a[N];

void NextPerm() {
	// xac dinh a[j]
	int j = n - 1;
	while (a[j] > a[j + 1]) j--;
	// xac dinh a[k]
	int k = n;
	while (a[k] < a[j]) k--;

	// int tmp = a[k];
	// a[k] = a[j];
	// a[j] = tmp;
	swap(a[j], a[k]);

	int left = j + 1, right = n;
	while (left < right) {
		swap(a[left], a[right]);
		left++;
		right--;
	}
}

void PrintCurPerm() {
	for (int i = 1; i <= n; i++) 
		cout << a[i] << ' ';
	cout << endl;
}

bool IsEnd() {
	for (int i = 1; i <= n; i++)
		if (a[i] != n - i + 1) return false;
	return true;
}

void Generate() {
	bool stop = false;
	while (!stop) {
		PrintCurPerm();
		if (!IsEnd()) NextPerm();
		else stop = true;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) a[i] = i;
	Generate();
	return 0;
}



