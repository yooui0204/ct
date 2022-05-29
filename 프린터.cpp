#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool isBiggest(deque<int>& dq){
    for(int i=1;i<dq.size();i++){
        if(dq[0]<dq[i]){
            return false;
        }
    }
    return true;
}

int solution(vector<int> priorities, int location) {
    int answer = 1;
    deque<int> dq;
    
    for(int i=0;i<priorities.size();i++){
        dq.push_back(priorities[i]);
    }
    
    int index=location;
    while(!dq.empty()){
        if(isBiggest(dq))
        {
            dq.pop_front();
            
            if(index==0)
                break;
            else{
                answer++;
                index--;
            }
        }
        else
        {
            dq.push_back(dq.front());
            dq.pop_front();
            
            if(index==0)
                index=dq.size()-1;
            else
                index--;
        }  
    }
    
    return answer;
}