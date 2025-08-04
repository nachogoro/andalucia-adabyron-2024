#include <bits/stdc++.h>

using namespace std;

bool es_bipartito(const vector<vector<int>>& grafo) {
	int n = grafo.size();
	vector<int> color(n, -1); // -1: no visitado, 0 y 1: colores

	for (int start = 0; start < n; ++start) {
		if (color[start] != -1) continue; // Ya visitado

		queue<int> q;
		q.push(start);
		color[start] = 0;

		while (!q.empty()) {
			int u = q.front(); q.pop();

			for (int v : grafo[u]) {
				if (color[v] == -1) {
					color[v] = 1 - color[u];
					q.push(v);
				} else if (color[v] == color[u]) {
					return false; // Conflicto: mismo color en ambos lados
				}
			}
		}
	}

	return true;
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> grafo(n);

		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}

		if (es_bipartito(grafo)) {
			cout << "Que comience la batalla\n";
		} else {
			cout << "Mejor nos vamos de cena o algo\n";
		}
	}

	return 0;
}

