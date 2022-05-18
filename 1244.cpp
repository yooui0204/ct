#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> v;

void toggle(int i) {
	if (v[i] == 1)
		v[i] = 0;
	else
		v[i] = 1;
}

void male(int num) {
	for (int i = num; i <= N; i+=num) {
		toggle(i);
	}
}

void female(int num) {
	toggle(num);

	for (int i = 1 ; ; i++) {
		if (num - i<=0 || num + i>N)
			break;
		if (v[num + i] == v[num - i]) {
			toggle(num + i);
			toggle(num - i);
		}
		else
			break;
	}
}

int main() {
	cin >> N;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	cin >> M;
	int gender; int number;
	for (int i = 0; i < M; i++) {
		cin >> gender >> number;

		if (gender == 1) {
			male(number);
		}
		else {
			female(number);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << v[i] << ' ';
		if (i % 20 == 0)
			cout << '\n';
	}

	return 0;
}