#include <queue>
#include <iostream>
using namespace std;

int N;
bool visit[50];
int score[50] = { 0 };
int member[50][50];

int init() {
	for (int i = 0; i < 50; i++) {
		visit[i] = false;
	}
}

int bfs(int index) {
	init();
	int answer=-1;
	queue<pair<int,int>> q;
	visit[index] = 1;
	q.push({index,0});
	while (!q.empty()) {
		int tmp_node = q.front().first;
		int tmp_count=q.front().second;
		answer = tmp_count;

		q.pop();

		for (int i = 0; i < N; i++) {
			if (member[tmp_node][i] == 1&&visit[i]==0) {
				q.push({ i,tmp_count+1 });
				visit[i] = 1;
			}
		}
	}
	return answer;
}

void input() {
	cin >> N;
	while(true){
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		member[a-1][b-1] = 1;
		member[b-1][a-1] = 1;
	}
}

int main() {
	input();
	int minV=9999;
	for (int i = 0; i < N; i++) {
		score[i] = bfs(i);
		minV = score[i] < minV ? score[i] : minV;
	}
	int counter = 0;
	for (int i = 0; i < N; i++) {
		if (score[i] == minV) {
			counter++;
		}
	}
	cout << minV << ' ' << counter << endl;
	for (int i = 0; i < N; i++) {
		if (score[i] == minV) {
			cout << i + 1<<' ';
		}
	}
	return 0;
}