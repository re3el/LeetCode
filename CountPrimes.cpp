class Solution {
public:
    int countPrimes(int n) 
    {
        if(n <= 0) return 0;
        vector<bool>dp(n,false);
        int count = 0;
        
        for(int i=2; i<n; i++)
        {
            if(dp[i] == false) count++;
            for(int j=2; i*j<n; j++)
            {
                dp[i*j] = true;
            }
        }
        return count;
    }
};