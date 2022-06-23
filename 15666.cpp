#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[8] = { 0 };
int answer[8] = { 0 };

void bt(int counter, int start) {
	if (counter == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int tmp = -1;
	for (int i = start; i < N; i++) {
		if (tmp == num[i]) continue;

		tmp = num[i];
		answer[counter] = num[i];
		bt(counter + 1, i);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	bt(0,0);

	return 0;
}