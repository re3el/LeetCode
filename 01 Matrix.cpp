class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        if(m == 0) return matrix;
        int n = matrix[0].size();
        queue<pair<int,int>>que;
        vector<vector<int>> res(m,vector<int>(n,0));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                    que.push(make_pair(i,j));
            }
        }
        
        while(!que.empty())
        {
            pair<int,int> pt = que.front();
            que.pop();
            int i = pt.first;
            int j = pt.second;
            
            if(i>0 && matrix[i-1][j] != 0)
            {
                res[i-1][j] = 1 + res[i][j];
                que.push(make_pair(i-1,j));
                matrix[i-1][j] = 0;
            }
            if(i<m-1 && matrix[i+1][j] != 0)
            {
                res[i+1][j] = 1 + res[i][j];
                que.push(make_pair(i+1,j));
                matrix[i+1][j] = 0;
            }
            if(j>0 && matrix[i][j-1] != 0)
            {
                res[i][j-1] = 1 + res[i][j];
                que.push(make_pair(i,j-1));
                matrix[i][j-1] = 0;
            }
            if(j<n-1 && matrix[i][j+1] != 0)
            {
                res[i][j+1] = 1 + res[i][j];
                que.push(make_pair(i,j+1));
                matrix[i][j+1] = 0;
            }            
        }
        return res;
    }
};