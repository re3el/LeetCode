class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int slen = word1.length(), tlen = word2.length();        
        vector<vector<int>>dp(slen+1,vector<int>(tlen+1,0));
        
        for(int i=1;i<=slen;i++)
            dp[i][0] = i;
        for(int j=1;j<=tlen;j++)
            dp[0][j] = j;
        
        for(int i=1; i<=slen; i++)
        {
            for(int j=1; j<=tlen; j++)
            {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));                
            }
        }
        return dp[slen][tlen];    
    }
};