class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i<n-1){
                if(s[i]==s[i+1]) dp[i][i+1]=2;
                else dp[i][i+1]=1;
            }
        }

        int len=3;
        while(len<=n){
            int i=0;
            while(i<n-len+1){
                int j=i+len-1;
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]); //eg: xcyx -> (x to y) + (c to x) - (c to y) + (c to y) +(xx)1
                i++;
            }
            len++;
        }
        return dp[0][n-1];
    }
};