#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    string strArr[100001];

    string name;
    unordered_map <string, int> pocketMon;
    for (int i = 1; i <= N; i++) {
        cin >> name;

        pocketMon.insert(make_pair(name, i));
        strArr[i] = name;
    }

    for (int i = 0; i < M; i++) {
        string input;
        cin >> input;
        if (pocketMon.find(input) != pocketMon.end()) {
            cout << pocketMon.find(input)->second << "\n";
        }
        else {
            int num = stoi(input);
            cout << strArr[num] << "\n";
        }
    }

    return 0;
}