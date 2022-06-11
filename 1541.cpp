#include <iostream>
#include <string>
using namespace std;

string s;
int parsing[50] = { 0 };

int main() {
	cin >> s;

	//parsing
	string tmp = "+"; int index = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-' || s[i] == '+') {
			parsing[index] = stoi(tmp);
			tmp = s[i];
			index++;
		}
		else {
			tmp += s[i];
		}
	}
	if (tmp != "") {
		parsing[49] = stoi(tmp);
	}
	/*
	for (int i = 0; i < 50; i++) {
		cout << parsing[i] << endl;
	}
	*/

	//cal
	int answer = 0; bool trigger = false;
	for (int i = 0; i < 50; i++) {
		if (parsing[i] < 0) {//음수
			trigger = true;
			answer += parsing[i];
		}
		else {//양수
			if (trigger) {
				answer -= parsing[i];
			}
			else {
				answer += parsing[i];
			}
		}
	}
	cout << answer;
	return 0;
}