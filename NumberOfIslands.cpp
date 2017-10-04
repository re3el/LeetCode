class Solution {  
    int n,m;
public:    
    void check(vector<vector<char>>& grid, int i, int j) 
    {        
        if(i < 0 || j < 0 || i == n || j == m || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        check(grid,i+1,j);
        check(grid,i-1,j);
        check(grid,i,j+1);
        check(grid,i,j-1);        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {       
        int res = 0;
        n = grid.size();
        if(n==0) return res;
        
        m = grid[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1')
                {
                    check(grid,i,j);
                    res++;
                }
            }
        }        
        return res;
    }
};