class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        int m = rooms.size();
        if(m == 0) return;
        int n = rooms[0].size();
        queue<pair<int,int>>que;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(rooms[i][j] == 0)
                    que.push(make_pair(i,j));
            }
        }
        
        while(!que.empty())
        {
            pair<int,int> pt = que.front();
            que.pop();
            int i = pt.first;
            int j = pt.second;                    
            
            if(i>0 && rooms[i-1][j] == INT_MAX)
            {
                rooms[i-1][j] = 1 + rooms[i][j];
                que.push(make_pair(i-1,j));
            }
            if(i<m-1 && rooms[i+1][j] == INT_MAX)
            {
                rooms[i+1][j] = 1 + rooms[i][j];
                que.push(make_pair(i+1,j));
            }
            if(j>0 && rooms[i][j-1] == INT_MAX)
            {
                rooms[i][j-1] = 1 + rooms[i][j];
                que.push(make_pair(i,j-1));
            }
            if(j<n-1 && rooms[i][j+1] == INT_MAX)
            {
                rooms[i][j+1] = 1 + rooms[i][j];
                que.push(make_pair(i,j+1));
            }
        }
    }
};