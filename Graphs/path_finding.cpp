#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 1e3 + 4;
int n, m, s, t;
vector<int> adj[N];
int parent[N];
bool visited[N];

void input() {
	cin >> n >> m >> s >> t;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void DFS(int u) {
	visited[u] = true;
	for (const int &v : adj[u]) {
		if (!visited[v]) {
			parent[v] = u;
			DFS(v);
		}
	}
}

int main() {
	freopen("data.inp", "r", stdin);
	input();
	memset(parent, 0, sizeof(parent));
	memset(visited, 0, sizeof(visited));
	DFS(s);
	if (parent[t] == 0) cout << "There is no path from " << s << " to " << t << endl;
	else {
		int u = t;
		stack<int> Stk;
		while (u != 0) {
			Stk.push(u);
			u = parent[u];
		}
		
		while (!Stk.empty()) {
			cout << Stk.top() << ' ';
			Stk.pop();
		}
	}

	return 0;
}





