class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        
        int low = 0, high = m-1, mid;
        int row = -1, column = -1;
        while(low < high)
        {
            mid = low + (high-low)/2;
            if (matrix[mid][n-1] == target) return true;
            if (matrix[mid][n-1] > target)
            {
                if(matrix[mid][0] <= target)
                {
                    row = mid;
                    break;
                }
                else
                    high = mid -1;
            }
            else
                low = mid + 1;
        }
        
        if(row == -1) row = low;
        low = 0, high = n-1;
        while(low <= high)
        {
            mid = low + (high - low)/2;
            if (target == matrix[row][mid]) return true;
            if (matrix[row][mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
        
    }
};