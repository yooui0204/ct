#include <iostream>
#include <cmath>
using namespace std;

int N;
int dp[50001] = { 0,1 };

int main() {
	cin >> N;
	for (int i = 2; i <= 50000; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 2; j * j < i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[N];
}