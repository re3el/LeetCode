class Solution {
public:
    vector<int> countBits(int num) 
    {
        if(num == 0) return {0};
        vector<int> dp(num+1);
        dp[0] = 0, dp[1] = 1;
        int exp = 2;
        
        for(int i=2; i<=num; i++)
        {
            int j = 0;
            while(i<=num && i<pow(2,exp))
            {
                dp[i++] = 1 + dp[j++];                
            }
            
            if(i>num) break;
            else i--;
            
            exp++;
        }
        return dp;
    }
};