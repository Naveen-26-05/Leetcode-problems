class Solution {
public:
    bool bfs( int source, int destination , vector<vector<int>>& edges , vector<int>& vis){
        queue<int>q;
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto i:edges[top]){
                if(vis[i]==0){
                    if(i == destination){
                        return true;}
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        if(source == destination) return true;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return bfs(source , destination , adj , vis);
    }
};
