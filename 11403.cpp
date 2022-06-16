#include <iostream>
using namespace std;

int N;
int origin[100][100] = { 0 };
int mini[100][100] = { 0 };

void Floyd() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (origin[i][j])mini[i][j] = origin[i][j];
			else mini[i][j] = 9999;
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				mini[i][j] = min(mini[i][j], mini[i][k] + mini[k][j]);
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> origin[i][j];
		}
	}
}

int main() {
	input();
	Floyd();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mini[i][j]!=9999) {
				cout << 1 << ' ';
			}
			else {
				cout << 0 << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}