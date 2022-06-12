#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int T;
	int N, M, x, y;

	cin >> T;
	int i, j=0;
	for (int i = 0; i < T; i++) {

		cin >> M >> N >> x >> y;
		bool flag = false;
		int limit = lcm(M, N);
		for (int j = x; j <= limit; j+=M) {
			int temp = (j % N == 0) ? N : j % N;
			if (temp==y) {
				cout << j<<endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			printf("-1\n");

	}
	return 0;
}
