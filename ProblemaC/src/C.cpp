#include <bits/stdc++.h>

using namespace std;

void colorear(
		const vector<vector<int>>& adj,
		vector<int>& color_nodo,
		int start,
		int color) {
	if (color_nodo[start] != -1) return;

	color_nodo[start] = color;
	for (auto neighbour : adj[start]) {
		colorear(adj, color_nodo, neighbour, color);
	}
}

map<int, int> componentes_conexas(const vector<vector<int>>& adj) {
	vector<int> componente_asignada(adj.size(), -1);
	map<int, int> contador;

	int componente = 1;

	for (int start = 0; start < adj.size(); ++start) {
		if (componente_asignada[start] != -1) {
			// Nodo ya pertenece a una componente
			contador[componente_asignada[start]]++;
			continue;
		}

		colorear(adj, componente_asignada, start, componente);
		contador[componente]++;
		componente++;
	}
	return contador;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<vector<int>> adj(N, vector<int>());
		while(M--) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		long tiendas = 0;
		long combinaciones = 1;

		for (auto [k, v] : componentes_conexas(adj)) {
			tiendas++;
			combinaciones = (combinaciones * v) % (10^9 + 7);
		}

		cout << tiendas << " " << combinaciones << "\n";
	}
}
