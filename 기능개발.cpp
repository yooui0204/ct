#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i=0;i<speeds.size();i++){
        int day;
        if((100-progresses[i])%speeds[i]==0){
            day=(100-progresses[i])/speeds[i];
        }
        else{
            day=(100-progresses[i])/speeds[i]+1;
        }
        q.push(day);
    }
    
    for(int i=0;!q.empty();i++){
        int counter=0;
        while(!q.empty() && q.front()<=i){
            counter++;
            q.pop();
        }
        if(counter!=0)
            answer.push_back(counter);
    }
    
    return answer;
}