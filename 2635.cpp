#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
vector<int> answer;
int size = -1;
int counter = 0;

void copyVector() {
	answer.clear();
	for (int i = 0; i < v.size(); i++)
		answer.push_back(v[i]);
}

void makeVector(int N,int i, int start) {
	if (N - i < 0) {
		if (answer.size() < v.size()) {
			copyVector();
			counter = start;
		}
		v.clear();
		return;
	}
	v.push_back(N - i);
	makeVector(i, N - i, start);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		makeVector(N, i,i);
	}
	cout << answer.size()+2 << '\n';
	cout << N << ' ' << counter << ' ';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
}