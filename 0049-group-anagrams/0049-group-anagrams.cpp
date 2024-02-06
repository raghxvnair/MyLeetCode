class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> ump;
        for(auto s: strs){
            string t=s;
            sort(t.begin(),t.end());
            ump[t].push_back(s);
        }

        for(auto x: ump){
            ans.push_back(x.second);
        }
        return ans;
    }
};