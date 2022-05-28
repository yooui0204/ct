#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int big=people.size()-1;
    int small=0;
    
    sort(people.begin(),people.end());
    
    while(big>=small){
        if(big==small){
            answer++;
            break;
        }
        if(people[big]+people[small]>limit){
            answer++;
            big-=1;
        }
        else{
            answer++;
            big-=1;
            small+=1;
        }
    }
    
    return answer;
}