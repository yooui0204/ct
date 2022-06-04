#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
set<string> s;
int answer;
vector<string> ans;

void sol() {
	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
	}

	for (int i = 0; i < M; i++) {
		int size = s.size();
		cin >> str;
		s.insert(str);

		if (s.size() == size) {
			answer++;
			ans.push_back(str);
		}
	}
}

int main() {
	sol();
	cout << answer<<'\n';
    sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i]<<'\n';
	}
	return 0;
}