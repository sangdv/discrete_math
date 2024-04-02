#include <iostream>
using namespace std;

const int N = 20;
int x[N], xopt[N]; // x1, x2, ..., xn
int w[N], v[N];
int n, b, bk, fk = 0, fopt = 0;

void UpdateSol() {
	if (fopt < fk) {
		fopt = fk;
		for (int i = 1; i <= n; i++)
			xopt[i] = x[i];
	}
}

void TRY(int k) {
	int tk = bk >= w[k] ? 1 : 0;
	for (int y = 0; y <= tk; y++) {
		x[k] = y;
		bk -= w[k] * x[k];
		fk += v[k] * x[k];
		if (k == n) UpdateSol();
		else TRY(k + 1);
		bk += w[k] * x[k];
		fk -= v[k] * x[k];
	}
}

void input() {
	cin >> n >> b;
	for (int i = 1; i <= n; i++) 
		cin >> v[i];
	for (int i = 1; i <= n; i++) 
		cin >> w[i];
}

int main() {
	freopen("data.inp", "r", stdin);
	input();
	bk = b;
	TRY(1);
	cout << fopt << endl;
	for (int i = 1; i <= n; i++)
		cout << xopt[i] << ' ';
	cout << endl;
	return 0;
}


