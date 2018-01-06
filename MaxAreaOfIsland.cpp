class Solution {
public:
    int m,n;
    int compute(vector<vector<int>> &grid, int i, int j)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        return 1 + compute(grid,i-1,j) + compute(grid,i+1,j) + compute(grid,i,j-1) + compute(grid,i,j+1);        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        m = grid.size();
        if(m == 0) return 0;
        n = grid[0].size();
        int res = 0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {                
                if(grid[i][j] == 1) res = max(res,compute(grid,i,j));               
            }
        }
        return res;
    }
};