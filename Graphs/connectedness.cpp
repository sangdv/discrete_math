#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3 + 4;
int n, m, cnt = 0;
vector<int> adj[N];
int id[N];

void input() {
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void DFS(int u) {
	id[u] = cnt;
	for (const int &v : adj[u]) {
		if (id[v] == 0) DFS(v);
	}
}

int main() {
	freopen("data.inp", "r", stdin);
	input();
	memset(id, 0, sizeof(id));
	for (int u = 1; u <= n; u++) {
		if (id[u] == 0) {
			cnt++;
			DFS(u);
		}
	}

	cout << "Number of connected components: " << cnt << endl;
	for (int u = 1; u <= n; u++)
		cout << u << ": " << id[u] << endl;
	return 0;
}





