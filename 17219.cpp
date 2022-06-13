#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N, M;
map<string,string> list;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	string s1, s2;
	for (int i = 0; i < N; i++) {
		cin >> s1 >> s2;
		list.insert({ s1,s2 });
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		cout << list[str]<<'\n';
	}
	return 0;
}