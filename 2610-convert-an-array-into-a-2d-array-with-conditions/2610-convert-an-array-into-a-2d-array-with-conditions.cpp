class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        int mx=0;
        for(auto& x:nums){
            mp[x]++;
            mx=max(mx,mp[x]);
        }
        while(mx){
            vector<int> res;
            for(auto& x: mp){
                if(x.second>0) {
                    res.push_back(x.first);
                    x.second--;
                }
            }
            ans.push_back(res);
            mx--;
        }
        return ans;
    }
};