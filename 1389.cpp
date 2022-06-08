#include <iostream>
#include <queue>
using namespace std;

int N; int M;
bool connect[101][101] = { false };
bool visit[101] = { false };

void init() {
	for (int i = 1; i <= N; i++) {
		visit[i] = false;
	}
}

int BFS(int user) {
	int return_value=0;
	queue<pair<int, int>> q;
	q.push({ user,0 });
	int counter = 0;

	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visit[i] == true) continue;

			if (connect[tmp.first][i]) {
				visit[i] = true;
				q.push({ i, tmp.second + 1 });
				return_value += tmp.second;
			}
			if (connect[i][tmp.first]) {
				visit[i] = true;
				q.push({ i, tmp.second + 1 });
				return_value += tmp.second;
			}
		}
	}
	init();
	return return_value;
}

int main() {
	cin >> N >> M;
	
	//make connect matrix
	for (int i = 0; i < M; i++) {
		int user1; int user2;
		cin >> user1 >> user2;
		connect[user1][user2] = true;
		//connect[user2][user1] = true;
	}
	int tmp; int min=9999; int answer=-1;

	for (int i = 1; i <= N; i++) {
		tmp = BFS(i);
		if (tmp < min) {
			min = tmp;
			answer = i;
		}
	}
	cout << answer;
	return 0;
}