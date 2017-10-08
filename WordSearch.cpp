class Solution {
    int m,n;
public:
    bool checkNow(vector<vector<char>>& board, string word, int i, int j) 
    {
        if(word.size() == 0) return true;
        if(i < 0 || j < 0 || i >=m || j >= n || board[i][j] == ' ' || board[i][j] != word[0]) return false;
        
        char a = board[i][j];
        board[i][j] = ' ';
          
        string sub = word.substr(1);            
        bool res = (checkNow(board,sub,i+1,j) || checkNow(board,sub,i-1,j) 
                || checkNow(board,sub,i,j+1) || checkNow(board,sub,i,j-1));
        
        board[i][j] = a;
        return res;        
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        m = board.size();
        if(m == 0) return false;
        
        n = board[0].size();        
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == word[0])
                {
                    if (checkNow(board,word,i,j) == true) 
                        return true;
                }
            }
        }
        return false;
    }
};