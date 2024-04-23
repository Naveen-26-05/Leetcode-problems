class Solution {
public:

    int treeTraversal(int n , int node , vector<vector<int>>& adj){
        int ht =0;
        vector<int>vis(n,0);
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                int top = q.front();
                q.pop();
                for(auto i:adj[top]){
                    if(!vis[i]){
                    q.push(i);
                    vis[i]=1;}
                }
            }
            ht++;
        }
        return ht;

    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        set<int>s;
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            s.insert(edges[i][0]);
            s.insert(edges[i][1]);
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ht = INT_MAX;
        vector<int>res;
        for(auto i:s){
            int ht1 = treeTraversal(n , i , adj);
            if(ht1 < ht){
                res ={i};
                ht = ht1;
            }else if(ht1==ht){
                res.push_back(i);
            }
        }
        return res;
        
    }
};
