#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int W, H;
int N;
vector<int> sliceX(1,0);
vector<int> sliceY(1,0);
vector<int> distanceX;
vector<int> distanceY;

void makeDisVec(vector<int>& v1,vector<int>& v2) {
	sort(v1.begin(), v1.end());
	for (int i = 0; i < v1.size() - 1; i++) {
		v2.push_back(v1[i + 1] - v1[i]);
	}
	sort(v2.begin(), v2.end());
}

void input() {
	cin >> W >> H >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 0) {
			sliceY.push_back(b);
		}
		else {
			sliceX.push_back(b);
		}
	}
	sliceY.push_back(H);
	sliceX.push_back(W);
}

int main() {
	input();
	makeDisVec(sliceX,distanceX);
	makeDisVec(sliceY,distanceY);
	cout << distanceY.back() * distanceX.back();
	return 0;
}