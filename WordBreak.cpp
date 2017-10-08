class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int len = s.length();
        unordered_set<string>usetT(wordDict.begin(),wordDict.end());
        vector<bool>dp(len+1);
        dp[0] = true;
        
        for(int i=1; i<=len; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(dp[j] && usetT.find(s.substr(j,i-j)) != usetT.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[len];
    }
};