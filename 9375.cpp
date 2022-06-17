#include <iostream>
#include <map>
using namespace std;

int T;
int N;

int main() {
	cin >> T;

	while (T--) {
		cin >> N;
		string a, b;
		map<string, int> cloth;
		while (N--) {
			cin >> a >> b;

			if (cloth.find(b) != cloth.end()) {
				cloth[b]++;
			}
			else {
				cloth.insert({ b,1 });
			}
		}
		int answer = 1;
		for (auto i : cloth) {
			answer *= (i.second + 1);
		}
		cout << answer - 1 << '\n';
	}

	return 0;
}