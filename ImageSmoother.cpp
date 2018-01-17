class Solution {
    int m,n;
public:
    void compute(vector<vector<int>>& matrix, vector<vector<int>>& res, int i, int j)
    {
        int cnt = 0, sum = 0;
        for(int I=max(0,i-1); I<=min(m-1,i+1); I++)
        {
            for(int J=max(0,j-1); J<=min(n-1,j+1); J++)
            {
                sum += matrix[I][J];
                cnt++;
            }
        }        
        res[i][j] = sum/cnt;
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) 
    {
        m = M.size();
        if(m == 0) return {{}};
        n = M[0].size();
        
        vector<vector<int>>res(m,vector<int>(n,0));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                compute(M,res,i,j);
        
        return res;
    }
};