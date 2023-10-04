#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    vector<pair<int,int>> q; //다리를 건너는 트럭
    queue<int> complete; //다리를 지난 트럭
    
    int pt=0; //올라올 트럭 인덱스
    int qWeight=0; //현재 다리에 올라와있는 트럭들의 무게
    
    while(true){
        
        if(complete.size()==truck_weights.size()) //다리를 지난 트럭이 초기 대기 트럭 수랑 같아지면
            break;

        answer++; //초 증가

        if(!q.empty()&&q[0].second==bridge_length){ //다리를 건너는 트럭이 비어있지않고 가장 앞 트럭의 시간이 다리길이와 같으면
            
            qWeight-=q[0].first; //맨 앞 트럭 무게 빼주기
            complete.push(q[0].first); //완료 트럭으로 옮기기
            q.erase(q.begin()); //트럭 내림
            
        }
        
        //새 트럭이 올라와도 다리가 견딜수 있으면 && 새로 올라올 트럭의 인덱스가 전체트럭 크기보다 작으면
        if(qWeight+truck_weights[pt]<=weight&&pt<truck_weights.size()){ 
            
            qWeight+=truck_weights[pt];
            q.push_back({truck_weights[pt],0}); //새로 트럭 올리기
            pt++; //다음 트럭 가리키기
            
        }
        
        for(int i=0;i<q.size();i++){
            q[i].second++; //다리를 건너는 모든 트럭의 간 거리 1씩 올려주기
        }

    }
    return answer;
}
