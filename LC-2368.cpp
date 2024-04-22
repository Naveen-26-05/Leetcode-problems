class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>v(n);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        map<int,int>mp,vis;
        for(auto i:restricted)mp[i]=1;
        if(mp[0]==1)return 0;
        if(v[0].size()==1 && mp[v[0][0]==1])return 1;
        queue<int>q;
        q.push(0);
        vis[0]=1;
        int count =1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto i:v[top]){
                if(!mp[i]&& !vis[i]){
                    q.push(i);
                    vis[i]=1;
                    count++;
                    cout<<i<<" ";
                }
            }
        }
        return count;
    }
};
