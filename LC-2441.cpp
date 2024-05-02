class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int>mp;
        int res =-1;
        for(auto i:nums)mp[i]=1;
        for(auto i:nums){
            if(mp[i*-1]){
                res = max(res , abs(i));
            }
        }
        return res;
    }
};
