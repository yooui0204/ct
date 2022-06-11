#include <iostream>
using namespace std;

int N;
int M;
string Str;

int main() {
	int answer=0;
	cin >> N>>M>> Str;
	
	for (int i = 0; i < M; i++) {
		int k=0;
		if (Str[i] == 'O') continue;
		while(Str[i + 1] == 'O' && Str[i + 2] == 'I') {
			k++;
			if (k == N) {
				answer++;
				k--;
			}
			i += 2;
		}
	}
	cout << answer;
	return 0;
}