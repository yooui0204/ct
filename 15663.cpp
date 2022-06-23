#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[8] = { 0 };
bool used[8] = { false };
int answer[8] = { 0 };

void bt(int counter) {
	if (counter == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int tmp = -1;
	for (int i = 0; i < N; i++) {
		if (used[i]) continue;
		if (tmp == num[i]) continue;

		tmp = num[i];
		used[i] = true;
		answer[counter] = num[i];
		bt(counter + 1);
		used[i] = false;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	bt(0);
	return 0;
}