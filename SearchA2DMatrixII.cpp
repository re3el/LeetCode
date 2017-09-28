class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        if(m==0) return false;
        
        int n = matrix[0].size();
        int i=0, j=n-1;
        while(i<m && j>-1)
        {
            int val = matrix[i][j];
            if (val == target) return true;
            else if(val < target) i++;
            else j--;
        }
        return false;
    }
};