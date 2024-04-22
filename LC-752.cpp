class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<vector<int>> adj = {
            {9, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}, {6, 8}, {7, 9}, {8, 0}
        };
        map<string,int>mp;
        for(auto x: deadends) mp[x] = 1;
        map<string,int>vis;
        queue<string>q;
        if(mp["0000"]==1)return -1;
        if(target =="0000")return 0;
        string s = "0000";
        q.push(s);
        int count=0;
        while(!q.empty()){
            int len = q.size();
            while(len--) {
                s =  q.front();
                q.pop();
                
                if(s == target){
                    return count;
                }
                for(int i=0;i<4;i++){
                    for(auto j:adj[s[i]-'0']){
                        string v = s;
                        v[i]=j+'0';
                        if(vis[v]==0 && !mp[v] ){
                            q.push(v);
                            vis[v]=1;
                        }
                    }
                }
            }
            count++;
        }
        return -1;

    }
};
