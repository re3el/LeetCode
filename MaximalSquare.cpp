class Solution {    
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m = matrix.size();
        if (m == 0) return 0;
        int res = 0;
        
        int n = matrix[0].size();
        vector<vector<int>>dp(2,vector<int>(n,0));
        int maxSize = 0;
        
        
        for(int i=0; i<n; i++)
        {
            dp[0][i] = matrix[0][i] - '0';
            maxSize = max(maxSize,dp[0][i]);
        }
        
        for(int i=1; i<m; i++)
        {                        
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '0') continue;
                dp[1][j] = 1 + min(dp[0][j-1], min(dp[1][j-1], dp[0][j]));
                maxSize = max(maxSize,dp[1][j]);
            }
            swap(dp[0],dp[1]);
            fill(dp[1].begin(),dp[1].end(),0);
        }
        return maxSize*maxSize;
    }
};