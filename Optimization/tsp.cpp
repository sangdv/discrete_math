#include <iostream>
using namespace std;

const int N = 15;
const int INF = 1e9;
int n, cmin = INF, x[N], xopt[N];
bool visited[N];
int C[N][N];
int curCost = 0, optCost = INF;

void UpdateSol() {
	if (curCost + C[x[n]][1] < optCost) {
		optCost = curCost + C[x[n]][1];
		for (int i = 1; i <= n; i++) 
			xopt[i] = x[i];
	}
}

void TRY(int k) {
	for (int v = 2; v <= n; v++) {
		if (!visited[v]) {
			x[k] = v;
			visited[v] = true;
			curCost += C[x[k - 1]][v];
			if (k == n) UpdateSol();
			else {
				int g = curCost + (n - k + 1) * cmin;
				if (g < optCost)
					TRY(k + 1);
			}
			visited[v] = false;
			curCost -= C[x[k - 1]][v];
		}
	}
}

int input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			cin >> C[i][j];
			if (i != j)
				cmin = min(cmin, C[i][j]);
		}
}

int main() {
	freopen("data.inp", "r", stdin);
	input();
	x[1] = 1; visited[1] = true;
 	TRY(2);
	cout << optCost << endl;
	for (int i = 1; i <= n; i++)
		cout << xopt[i] << " --> ";
	cout << 1 << endl;
	return 0;
}