class Solution {
public:
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};
    vector<int> dfs(vector<vector<int>>& land , int i , int j){
        vector<int>res(4,0);
        queue<pair<int,int>>q;
        q.push({i,j});
        land[i][j]=0;
        res[0]=i;
        res[1]=j;
        res[2]=i;
        res[3]=j;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(top.first < res[0]){
                res[0]=top.first;
                res[1]=top.second;
            }else if(top.first == res[0] && top.second < res[1]){
                res[0]=top.first;
                res[1]=top.second;
            }
            if(top.first > res[2]){
                res[2]=top.first;
                res[3]=top.second;
            }else if(top.first == res[2] && top.second > res[3]){
                res[2]=top.first;
                res[3]=top.second;
            }
            for(int k=0;k<4;k++){
                int nx = top.first + x[k];
                int ny = top.second + y[k];
                if(nx >= 0 && nx < land.size() && ny >=0 && ny<land[0].size()){
                    if(land[nx][ny]==1){
                        q.push({nx,ny});
                        land[nx][ny]=0;
                    }
                }
            }
        }
        return res;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>res;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[i].size();j++){
                if(land[i][j]==1){
                    res.push_back(dfs(land , i , j));
                }
            }
        }
        return res;
    }
};
