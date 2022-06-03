#include <iostream>
#include <vector>
using namespace std;

int N;
int answer[] = { 0,0 };
vector<vector<int>> colorPaper;

bool allSame(int n ,int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (colorPaper[y + i][x + j]!=colorPaper[y][x]) {
				return false;
			}
		}
	}
	return true;
}

void sol(int n, int x, int y) {
	if (n == 1 || allSame(n, x, y)) {
		answer[colorPaper[y][x]] += 1;
		return;
	}
	sol(n / 2, x, y);
	sol(n / 2, x+n/2, y);
	sol(n / 2, x, y + n / 2);
	sol(n / 2, x + n / 2, y + n / 2);
}

void input() {
	cin >> N;
	colorPaper.resize(N, vector<int> (N));
	for (int i = 0; i < N; i++) {
		for(int j=0;j<N;j++)
			cin >> colorPaper[i][j];
	}
}

int main() {
	input();
	sol(N,0,0);
	cout << answer[0] <<'\n' << answer[1];

	return 0;
}