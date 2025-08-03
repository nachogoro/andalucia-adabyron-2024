#include <bits/stdc++.h>

using namespace std;

using freq_t = map<char, int>;

bool is_superset(const freq_t& canon, const freq_t& candidate) {
	if (canon.size() < candidate.size()) return false;

	for (auto [c, f] : candidate) {
		if (!canon.count(c) || canon.at(c) < f) return false;
	}
	return true;
}

freq_t count(string_view s) {
	freq_t r;
	for (auto c : s) { r[c]++; }
	return r;
}

int main() {
	string line;
	int n;
	getline(cin, line);
	cin >> n;
	// Skip trailing newline

	auto canon = count(line);

	getline(cin, line);
	string result = "";

	while (n--) {
		getline(cin, line);
		auto candidate = count(line);
		if (is_superset(canon, candidate)) {
			if (line.size() > result.size()
					|| (line.size() == result.size() && line < result))
				result = line;
		}
	}
	if (result == "")
		cout << "No es posible\n";
	else
		cout << result << "\n";
}
