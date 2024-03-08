class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp; 
        int mx=0,ans=0;

        for(auto x :nums){
            mp[x]++;
            mx=max(mp[x],mx);
        }
        for(auto x :mp){
            if(x.second==mx){
                ans+=x.second;
            }
        }
        return ans;
    }
};