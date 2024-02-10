class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(1001,vector<int>(1001));
        int n=s.size(),cnt=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            cnt++;
            if(i<n-1 && s[i]==s[i+1]) {
                dp[i][i+1]=1;
                cnt++;
                }
        }
        int length=3;
        while(length<=n){
            int i=0;
            while(i<n-length+1){
                int j=i+length-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=1;
                    cnt++;
                }
                i++;
            }
            length++;
        }
        return cnt;
    }
};