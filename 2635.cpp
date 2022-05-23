#include <iostream>
#include <vector>
using namespace std;

int N;
int counter = 0;
vector<int> v;
vector<int> answer;

void print() {
    cout << answer.size() << '\n';
    for (int i = 1; i < answer.size(); i++)
        cout << answer[i] << ' ';
}

void copy() {
    answer.clear();
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i]);
    }
}

void solve(int a, int b) {
    if (a - b < 0) {
        if (answer.size() < v.size())
            copy();
        return;
    }
    v.push_back(a - b);
    solve(b, a - b);
}

void input() {
    cin >> N;
}

int main() {
    input();
    for (int i = 1; i <= N; i++) {
        v.clear();
        v.push_back(N);
        v.push_back(i);
        solve(N, i);
    }
    print();
    return 0;
}