class Solution {
    int m,n;
public:
    
    int computeNext(vector<vector<int>>& board, int i, int j) 
    {
        int cnt = 0;        
        for(int I=max(0,i-1); I <= min(i+1,m-1); I++)                 
            for(int J=max(0,j-1); J <= min(j+1,n-1); J++)                     
                cnt += (board[I][J] & 1);
        
        // subtract itself since it's included in the top
        cnt -= (board[i][j] & 1);            
        return cnt;                      
    }    
    
    void gameOfLife(vector<vector<int>>& board) 
    {
        m = board.size();
        if(m == 0) return;
        
        n = board[0].size();
        for(int i=0; i<m; i++)    
        {
            for(int j=0; j<n; j++) 
            {
                int cnt = computeNext(board,i,j);                    
                if(board[i][j] == 1 && (cnt == 2 || cnt == 3))                    
                    board[i][j] = 3;                    
                if(board[i][j] == 0 && cnt == 3)
                    board[i][j] = 2;  
            }
        }
        
        for(int i=0; i<m; i++)        
            for(int j=0; j<n; j++)            
                board[i][j] >>= 1;
    }
};