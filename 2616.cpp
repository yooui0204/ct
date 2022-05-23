#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> ruler;

void fold(double a,double b) {
	double mid = (a + b) / 2;
	if (a > b) swap(a, b);

}

void input() {
	cin >> N;
	ruler.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> ruler[i].first >> ruler[i].second;
	}
}

int main() {
	return 0;
}