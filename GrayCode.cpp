class Solution {
public:
    vector<int> grayCode(int n) 
    {
        if(n == 0) return {0};
        
        int len = pow(2,n);
        vector<int>dp(len);
        dp[0] = 0, dp[1] = 1;
                
        int exp = 1, limit = 2, cnt = 2;
        while(cnt < len)
        {
            limit = pow(2,exp);            
            for(int i=0; i<limit; i++)
            {
                cnt++;
                dp[limit+i] = limit + dp[limit-1-i];                
            }
            exp++;
        }
        return dp;
    }    
};