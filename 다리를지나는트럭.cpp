#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weight_on_birdge=0;
    int index = 0;
    queue<int> bridge_queue;

    for (int i = 0;i < bridge_length;i++) {
        bridge_queue.push(0);
    }

    do
    {
        weight_on_birdge -= bridge_queue.front();
        bridge_queue.pop();

        if (index != truck_weights.size()) {
            if (weight_on_birdge + truck_weights.at(index) <= weight) {
                bridge_queue.push(truck_weights.at(index));
                weight_on_birdge += bridge_queue.back();
                index++;
            }
            else {
                bridge_queue.push(0);
            }
        }
        else {
            bridge_queue.push(0);
        }
          
        answer++;
    } while (weight_on_birdge != 0);

    return answer;
}