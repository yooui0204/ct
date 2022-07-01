#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int map[100][100][100] = { 0 };
int Z, Y, X;
int answer = -1;

struct tomato {
	int x;
	int y;
	int z;
};

queue<tomato> q;

bool IsInside(int ny, int nx ,int nz) {
	return (0 <= nx && 0 <= ny && 0 <= nz && nx < X && ny < Y && nz < Z);
}

void BFS() {
	while (!q.empty()) {
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (IsInside(ny, nx, nz) == true && (map[nz][ny][nx] == 0 || map[z][y][x]+1 < map[nz][ny][nx])) {
				map[nz][ny][nx] = map[z][y][x] + 1;
				q.push({ nx,ny,nz });
			}
		}
	}
}

void input() {
	cin >> X >> Y >> Z;
	for (int z = 0; z < Z; z++) {
		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				cin >> map[z][y][x];
				if (map[z][y][x] == 1)
					q.push({ x,y,z });
			}
		}
	}
}

int main() {
	input();
	BFS();
	for (int z = 0; z < Z; z++) {
		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				if (map[z][y][x] == 0) {
					cout << "-1";
					return 0;
				}
				if (answer < map[z][y][x])
					answer = map[z][y][x];
			}
		}
	}
	cout << answer-1;
	return 0;
}