class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int visited[50][50];
    vector<vector<int>> ans;

    void bfs(int sr, int sc, int color,int sizex,int sizey){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        int origin=ans[sr][sc];

        while(!q.empty()){
            int cx=q.front().first;
            int cy=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                
                int x=cx+dx[i];
                int y=cy+dy[i];
                
                
                if(x<0||y<0||x>=sizex||y>=sizey)continue;
                
                if(visited[x][y]==1||ans[x][y]!=origin) continue;
                
                q.push({x,y});
                visited[x][y]=1;      
            }
        }

        for(int i=0;i<sizex;i++){
            for(int j=0;j<sizey;j++){
                if(visited[i][j]==true){
                    ans[i][j]=color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        for(int i=0;i<image.size();i++){
            vector<int> v;
            for(int j=0;j<image[0].size();j++){
                
                v.push_back(image[i][j]);
                
            }
            ans.push_back(v);
        }

        int sizex=image.size(),sizey=image[0].size();
        bfs(sr,sc,color,sizex,sizey);

        

        return ans;
    }
};
