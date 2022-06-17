#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> _plus;
priority_queue<int> _minus;

void pop() {
	if (_plus.empty() && _minus.empty()) {
		cout << "0" << '\n';
	}
	else if (_plus.empty()) {
		cout  << _minus.top() << '\n';
		_minus.pop();
	}
	else if (_minus.empty()) {
		cout <<_plus.top() << '\n';
		_plus.pop();
	}
	else {
		if (abs(_plus.top()) < abs(_minus.top())) {
			cout << _plus.top() << '\n';
			_plus.pop();
		}
		else {
			cout << _minus.top() << '\n';
			_minus.pop();
		}
	}
}

void push(int num) {
	if (num > 0) {
		_plus.push(num);
	}
	else {
		_minus.push(num);
	}
}

int main() {
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp == 0) {
			pop();
		}
		else {
			push(tmp);
		}
	}

	return 0;
}