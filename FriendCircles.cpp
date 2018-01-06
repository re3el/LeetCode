
class Solution {
    int n,res;
public:        
    void dfs(vector<vector<int>> &M, vector<bool> &visited, int i)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[j] && M[i][j] == 1)
            {   
                visited[j] = true;
                dfs(M,visited,j);                
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) 
    {
        n = M.size(), res = 0;
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                dfs(M,visited,i);                
                res++;
            }
        }
        return res;
    }
};