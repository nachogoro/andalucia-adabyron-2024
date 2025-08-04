#include <bits/stdc++.h>

using namespace std;

int main() {
	int R, C;
	cin >> R >> C;

	vector<vector<int>> m(R, vector<int>(C));
	vector<vector<int>> dp(R, vector<int>(C, 0));

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> m[i][j];
			dp[i][j] = m[i][j];

			if (i > 0) {
				dp[i][j] += dp[i-1][j];
			}
			if (j > 0) {
				dp[i][j] += dp[i][j-1];
			}
			if (i > 0 && j > 0) {
				dp[i][j] -= dp[i-1][j-1];
			}
		}
	}

	int Q;
	cin >> Q;

	int max_vasos = 0;
	int max_id = 0;

	while(Q--) {
		int id, r1, c1, r2, c2;
		cin >> id >> r1 >> c1 >> r2 >> c2;

		r1--; c1--;
		r2--; c2--;

		int vasos = dp[r2][c2];
		int left = (c1 > 0) ? dp[r2][c1-1] : 0;
		int top = (r1 > 0) ? dp[r1-1][c2] : 0;
		int top_left = (c1 > 0 && r1 > 0) ? dp[r1-1][c1-1] : 0;

		vasos = vasos - left - top + top_left;

		if (vasos > max_vasos || (vasos == max_vasos && id < max_id)) {
			max_vasos = vasos;
			max_id = id;
		}
	}

	cout << max_id << " " << max_vasos << "\n";
}
