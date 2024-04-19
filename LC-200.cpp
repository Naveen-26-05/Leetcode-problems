class Solution {
public:
    int dx[4]={-1,0,1,0};
     int dy[4]={0,1,0,-1};
    void bfs(int i,int j,vector<vector<char>>&grid)
    {
         int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});     
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m)
                {
                    if(grid[new_x][new_y]=='1'){
                        grid[new_x][new_y]='0';
                         q.push({new_x, new_y});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    grid[i][j]='0';
                    bfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
                
    }
};
