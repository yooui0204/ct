#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int l[32]={0};
int r[32]={0};

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    
    for(int i=0;i<lost.size();i++){
        l[lost[i]]=1;
    }
    for(int i=0;i<reserve.size();i++){
        r[reserve[i]]=1;
    }
    
    for(int i=0;i<=n;i++){
        if(r[i]==1 && l[i]==1){
            r[i]=0; l[i]=0;
            answer++;
        }
    }
    
    for(int i=1;i<n;i++){
        if(l[i]==0) 
            continue;

        if(r[i-1]==1){
            answer++;
            r[i-1]=0;
        }
        else if(r[i+1]==1){
            answer++;
            r[i+1]=0;
        }
    }
    return answer;
}