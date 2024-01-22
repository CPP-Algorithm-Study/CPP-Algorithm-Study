class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
    {
        //0에서 1로 길 찾기
        int m = matrix.size(), n = matrix[0].size();
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)  // 0이면 queue에 넣기
                    q.push({i, j});
                else matrix[i][j] = -1; //0이 아니면 -1로 바꾸기
            }
        }
        while (!q.empty())
        {
            int nx=q.front().first;
            int ny=q.front().second;
            q.pop();

            for (int i=0;i<4;i++) {
                int x = nx + dx[i], y = ny + dy[i];
                //행렬의 범위를 벗어났다면 || 방문하지않은 곳인데 이미 현재 위치에서의 거리보다 더 짧은 거리라면
                if (x < 0 || x >= m || y < 0 || y >= n ||(matrix[x][y] <= matrix[nx][ny] && matrix[x][y]!=-1)) 
                    continue;
                matrix[x][y] = matrix[nx][ny] + 1;
                q.push({x, y});
            }
        }
        return matrix;
    }
};
