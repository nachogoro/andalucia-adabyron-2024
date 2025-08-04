#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;

		vector<int> v(N);
		vector<int> dp(N);

		for (int i = 0; i < N; ++i) {
			cin >> v[i];
		}

		dp[0] = 1;
		for (int i = 1; i < N; ++i) {
			if (v[i-1] > v[i]) {
				dp[i] = 1;
			} else {
				int ptr = i-1;
				while(ptr > 0 && v[ptr] <= v[i]) {
					ptr -= dp[ptr];
				}
				dp[i] = i - ptr;
			}
		}

		for (int i = 0; i < N; ++i) {
			cout << dp[i];
			if (i != N-1) cout << " ";
		}
		cout << "\n";
	}
}
