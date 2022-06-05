#include <iostream>
using namespace std;

int N;
int set[21] = { 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	string str; int num;
	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "add") {
			cin >> num;
			if (set[num] == 0)
				set[num] = 1;
		}
		if (str == "remove") {
			cin >> num;
			if(set[num]==1)
				set[num] = 0;
		}
		if (str == "check") {
			cin >> num;
			if (set[num] == 1)
				cout << "1\n";
			else {
				cout << "0\n";
			}
		}
		if (str == "toggle") {
			cin >> num;
			if (set[num] == 1) {
				set[num] = 0;
			}
			else {
				set[num] = 1;
			}
		}
		if (str == "all") {
			for (int i = 1; i <= 20; i++) {
				set[i] = 1;
			}
		}
		if (str == "empty") {
			memset(set, 0, sizeof(set));
		}
	}
	return 0;
}