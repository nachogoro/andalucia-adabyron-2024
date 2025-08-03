#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;

		int cifras = ceil(log10(n+1));
		int d = n;

		int sum = 0;
		while (d > 0) {
			int digit = d%10;
			d /= 10;
			sum += pow(digit, cifras);
		}

		if (sum == n)
			cout << "SEGURO\n";
		else
			cout << "INSEGURO\n";
	}
}
