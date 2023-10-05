#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int vis[5][5];

//현재 상태에서 둘다 최적의 플레이를 할 때 남은 이동 횟수
int solve(int curx,int cury, int opx, int opy,vector<vector<int>> &board){
    
    if(vis[curx][cury]) return 0;    
    int ret = 0;
  
    for(int dir = 0; dir < 4; dir++){
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];
        
        if(nx<0||ny<0||nx>=board.size()||ny>=board[0].size()) continue;
        if(vis[nx][ny]||board[nx][ny]==0) continue; //발판 없으면

        vis[curx][cury]=1; //직전에 있던 발판 방문 표시
        
        int val=solve(opx,opy,nx,ny,board)+1; //두 캐릭터가 움직인 횟수의 총합
        //val이 짝수이면 패배, val이 홀수이면 승리
        // 앞으로 짝수번 이동을 더 한다 -> 나 상대 나 상대 ...나 상대로 끝남 -> 상대로 끝나는거면 내가 진다는 것
        
        vis[curx][cury]=0;
        
        //cout<<ret<<" "<<val<<endl;
       
        // 1. 현재 저장된 턴은 패배인데 새로 계산된 턴은 승리인 경우
        if(ret % 2 == 0 && val % 2 == 1) ret = val; // 바로 갱신
        // 2. 현재 저장된 턴과 새로 계산된 턴이 모두 패배인 경우
        else if(ret % 2 == 0 && val % 2 == 0) ret = max(ret, val); // 최대한 늦게 지는걸 선택
        // 3. 현재 저장된 턴과 새로 계산된 턴이 모두 승리인 경우
        else if(ret % 2 == 1 && val % 2 == 1) ret = min(ret, val); // 최대한 빨리 이기는걸 선택

        
    }
    
    return ret;
    
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
   
    return solve(aloc[0],aloc[1],bloc[0],bloc[1],board);

   
}
