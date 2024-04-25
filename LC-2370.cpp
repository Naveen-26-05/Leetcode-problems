class Solution {
public:
    int func(int ind,string&s,int&k,int prev,vector<vector<int>>&dp){
        if(ind>=s.size()){
            return 0;
        }
        if(dp[ind][prev]!=-1){
            return dp[ind][prev]; 
        }
        int pick=0;
        int notpick=0; 
        if(prev==0||abs(s[ind]-prev)<=k){
            pick=1+func(ind+1,s,k,s[ind],dp); 
        }
        notpick=0+func(ind+1,s,k,prev,dp); 
        return dp[ind][prev]=max(pick,notpick); 
    }
    int longestIdealString(string s, int k) {
        int prev=0;
        vector<vector<int>>dp(s.size()+1,vector<int>(150,-1)); 
        return func(0,s,k,prev,dp);
    }
};
