#include <iostream>
#include <queue>
#include <string>
using namespace std;

long long N, M;

int bfs() {
	queue<pair<long long, long long>> q;
	q.push({ N,1 });

	while (!q.empty()) {
		long long front_N = q.front().first;
		long long counter = q.front().second;
		q.pop();

		if (front_N == M) {
			return counter;
		}
		else {
			if (front_N * 2 <= M) {
				q.push({front_N * 2 ,counter + 1 });
			}
			if (front_N + 1 <= M) {
				q.push({front_N*10 + 1 ,counter + 1 });
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	cout<<bfs();
	return 0;
}