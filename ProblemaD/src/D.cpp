#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, S, P;
	cin >> N >> S >> P;

	vector<bool> album(N, false);

	int coste_ind = 0;
	vector<int> prices(N);
	for (int i = 0; i < N; ++i) {
		cin >> prices[i];
		coste_ind += prices[i];
	}

	int min_coste = min(P*S, coste_ind);

	int coste_actual = 0;

	for (int i = 0; i < S; ++i) {
		for (int j = 0; j < 5; ++j) {
			int cromo;
			cin >> cromo;
			--cromo;

			if (!album[cromo]) {
				// No tenemos el cromo, nos ahorramos comprarlo
				album[cromo] = true;
				coste_ind -= prices[cromo];
			}
		}

		coste_actual += P;

		min_coste = min(min_coste, coste_actual + coste_ind);
	}

	cout << min_coste << "\n";
}
