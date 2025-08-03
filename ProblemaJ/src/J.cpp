#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;

		if (n == 0) break;

		pair<int, int> most_freq(-1, -1);
		map<int, int> freq;
		while (n--) {
			int d;
			cin >> d;
			int f = ++freq[d];

			if (f > most_freq.second || f == most_freq.second && d < most_freq.first)
				most_freq = {d, f};
		}
		cout << most_freq.first << "\n";
	}
}
