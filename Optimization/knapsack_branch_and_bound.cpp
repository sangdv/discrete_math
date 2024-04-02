#include <iostream>
using namespace std;

const int N = 20;
const int INF = 1e9;
int n, b;
int x[N], xopt[N];
int curVal = 0, bk, optVal = -INF;

struct Item {
	int w, v;
};

Item arr[N];

bool ItemCmp(const Item &a, const Item &b) {
	return (1.0 * a.v) / a.w > (1.0 * b.v) / b.w;
}

void input() {
	cin >> n >> b;
	for (int i = 1; i <= n; i++)
		cin >> arr[i].w;
	for (int i = 1; i <= n; i++)
		cin >> arr[i].v;
	sort(arr + 1, arr + n + 1, ItemCmp);

	// for (int i = 1; i <= n; i++)
	// 	cout << arr[i].v << ' ' << arr[i].w << endl;
}

void UpdateSol() {
	if (curVal > optVal) {
		optVal = curVal;
		for (int i = 1; i <= n; i++)
			xopt[i] = x[i];
	}
}

void TRY(int k) {
	for (int y = bk / arr[k].w; y >= 0; y--) {
		x[k] = y;
		curVal += x[k] * arr[k].v;
		bk -= x[k] * arr[k].w;
		if (k == n) UpdateSol();
		else {
			float g = curVal + bk * (1.0 * arr[k].v) / arr[k].w;
			if (g > optVal) TRY(k + 1);
		}
		curVal -= x[k] * arr[k].v;
		bk += x[k] * arr[k].w;
	}
}

int main() {
	freopen("data.inp", "r", stdin);
	input();
	bk = b;
	TRY(1);
	cout << optVal << endl;
	for (int i = 1; i <= n; i++)
		cout << xopt[i] << ' ';
	cout << endl;
	return 0;
}


