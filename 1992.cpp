#include <cstdio>
using namespace std;

int pic[64][64];
int N;

void div(int start_x, int start_y, int n) {
	bool all_same = true;

	if (n == 1) {
		printf("%d", pic[start_y][start_x]);
		return;
	}

	for (int i = start_y; i < start_y + n; i++) {
		for (int j = start_x; j < start_x + n; j++) {
			if (pic[start_y][start_x] != pic[i][j]) {
				all_same = false;
				break;
			}
		}
	}

	if (all_same) {//all same
		printf("%d", pic[start_y][start_x]);
	}
	else {
		int k = n / 2;
		printf("(");
		div(start_x, start_y, k);
		div(start_x + k, start_y, k);
		div(start_x, start_y + k, k);
		div(start_x + k, start_y + k, k);
		printf(")");
	}
}

void input() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &pic[i][j]);
		}
	}
}

int main() {
	scanf("%d", &N);
	input();
	div(0, 0, N);
	return 0;
}