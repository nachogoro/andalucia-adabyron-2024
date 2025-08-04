#include <bits/stdc++.h>

using namespace std;

void descomponer(
		int cantidad,
		int coste,
		int beneficio,
		vector<pair<int, int>>& objetos) {
	int potencia = 1;

	while (cantidad >= potencia) {
		objetos.push_back({potencia*coste, potencia*beneficio});
		cantidad -= potencia;
		potencia *= 2;
	}

	if (cantidad != 0) {
		objetos.push_back({cantidad*coste, cantidad*beneficio});
	}
}

int knapsack(const vector<pair<int, int>>& objetos, int m) {
	vector<int> dp(m+1, 0);
	for (auto& obj : objetos) {
		for (int masa = m; masa >= obj.first; --masa) {
			if (obj.first <= masa) {
				dp[masa] = max(obj.second + dp[masa - obj.first], dp[masa]);
			}
		}
	}

	return dp[m];
}

int main() {
	int n, m, cy, dy;
	cin >> n >> m >> cy >> dy;

	vector<pair<int, int>> objetos;
	descomponer(n / cy, cy, dy, objetos);

	for (int i = 0; i < m; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		descomponer(min(n / c, a / b), c, d, objetos);
	}

	cout << knapsack(objetos, n) << "\n";
}
