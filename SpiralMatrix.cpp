class Solution {   
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        
        vector<int>res(m*n);
        int up = 0, down = m-1, left = 0, right = n-1, pos = 0;
        while(true)
        {
            for(int i=left; i<=right; i++) res[pos++] = matrix[up][i];
            if(++up > down) break;
            
            for(int i=up; i<=down; i++) res[pos++] = matrix[i][right];
            if(--right < left) break;
            
            for(int i=right; i>=left; i--) res[pos++] = matrix[down][i];
            if(--down < up) break;
            
            for(int i=down; i>=up; i--) res[pos++] = matrix[i][left];
            if(++left > right) break;
        }
        return res;
    }
};