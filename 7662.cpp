#include <iostream>
#include <set>
using namespace std;

int N;
int M;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> M;
		multiset<int> mSet;
		char c; int num;
		for (int j = 0; j < M; j++) {
			cin >> c >> num;

			if (c == 'I') {
				mSet.insert(num);
			}
			else {
				if (mSet.empty())
					continue;
				if (num == -1) {
					mSet.erase(mSet.begin());
				}
				else {
					auto k = mSet.end();
					k--;
					mSet.erase(k);
				}
			}
		}
		if (mSet.empty()) {
			cout << "EMPTY\n";
		}
		else {
			auto iter = mSet.end();
			iter--;
			cout << *iter << " " << *mSet.begin()<<'\n';
		}
	}
	return 0;
}