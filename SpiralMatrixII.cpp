class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>>res(n,vector<int>(n,0));
        int k = 0, up = 0, down = n-1, left = 0, right = n-1;
        
        while(true)
        {
            for(int j=left; j<=right; j++) res[up][j] = ++k;
            if(++up > down) break;
            
            for(int i=up; i<=down; i++) res[i][right] = ++k;
            if(--right < left) break;
            
            for(int j=right; j>=left; j--) res[down][j] = ++k;
            if(--down < up) break;
            
            for(int i=down; i>=up; i--) res[i][left] = ++k;
            if(++left > right) break;
        }
        
        return res;
    }
};