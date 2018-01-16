class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        int n = A.size();
        if(n < 3) return 0;
        
        vector<int> dp(n,0);
        for(int i=n-1; i>=1; i--)
            A[i] -= A[i-1];
                        
        int j = 0;
        for(int i=1; i<n-1; i++)
        {            
            if(A[i] == A[i+1])
            {
                dp[i] = dp[i-1] + (++j);            
                dp[i-1] = 0;
            }
            else            
                j = 0;                            
        }
        
        int res = 0;
        for(auto i:dp)
            res += i;
        
        return res;
    }
};