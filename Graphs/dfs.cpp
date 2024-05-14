#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 5;
vector<int> adj[N];
int n, m;
vector<bool> visited(N, false);

void dfs(int u){
	cout << u << ' ';
	visited[u] = true;
	for(const int &v: adj[u]){
		if(!visited[v]) dfs(v);
	}
}

void input(){
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for(int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end(), greater<int>());
}

int main(){
	freopen("data.inp", "r", stdin);
	input();
	for(int i = 1; i <= n; i++){
		if(!visited[i]) dfs(i);
	}
	return 0;
}