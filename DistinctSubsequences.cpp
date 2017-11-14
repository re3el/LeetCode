class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int slen = s.length();
        int tlen = t.length();
        
        vector<vector<int>>dp(tlen+1,vector<int>(slen+1));
        for(int j=0; j<=slen; j++)
            dp[0][j] = 1;
        
        for(int i=0; i<tlen; i++)
            dp[i+1][0] = 0;
        
        for(int i=0; i<tlen; i++)
        {
            for(int j=0; j<slen; j++)
            {
                if(t[i] == s[j])
                    dp[i+1][j+1] = dp[i][j] + dp[i+1][j];
                else
                    dp[i+1][j+1] = dp[i+1][j];
            }
        }
        return dp[tlen][slen];
    }
};