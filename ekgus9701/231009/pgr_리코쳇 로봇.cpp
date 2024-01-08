#include <string>
#include <vector>
#include<climits>
#include<queue>
#include<iostream>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int visited[105][105]={0};

int solve(int sx, int sy, vector<string> &board, int cnt,int ex, int ey){
    queue<pair<pair<int,int>,int>> q;
    int num=INT_MAX;
    
    q.push({{sx,sy},cnt});
    visited[sx][sy]=1;
    
    while(!q.empty()){
        
        int cx=q.front().first.first; //현재위치 x좌표
        int cy=q.front().first.second; //현재위치 y좌표
        
        int ccnt=q.front().second; //현재까지 몇번 걸렸는지
        
        q.pop();
        
      
        if(cx==ex&&cy==ey){ //목표 도착시
            num=min(num,ccnt);
        }
        
        for(int i=0;i<4;i++){ //사방으로 움직임
            int nx=cx;
            int ny=cy;
            for(int j=0;j<100;j++){ 
                //보드 크기가 100이니까 
                //1씩 움직여보면서 D나 보드 바깥으로 가는지 확인
                nx+=dx[i];
                ny+=dy[i];

                if(nx<0||ny<0||nx>=board.size()||ny>=board[0].length()){ //보드 바깥으로 가면 방금간거 취소
                    nx-=dx[i];
                    ny-=dy[i];
                    break;
                }

                if(board[nx][ny]=='D'){ //D면 방금 간거 취소
                    nx-=dx[i];
                    ny-=dy[i];
                    break;
                } 

            }
            
            if(visited[nx][ny]) continue; //멈춘 상태에서 방문한 장소라면 continue
            
            visited[nx][ny]=1; //방문 표시
            q.push({{nx,ny},ccnt+1});

        }
    }
    
    return num;
}

int solution(vector<string> board) {
    
    int startX=0,startY=0,endX=0,endY=0;
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].length();j++){
            if(board[i][j]=='R'){ //R일 때 x,y
                startX=i;
                startY=j;
            }
            else if(board[i][j]=='G'){ //G일때 x,y
                endX=i;
                endY=j;
            }
        }
    }
    
    int answer=solve(startX,startY,board,0,endX,endY);
    
    if(answer==INT_MAX)
        answer=-1;
    
    return answer;
}
