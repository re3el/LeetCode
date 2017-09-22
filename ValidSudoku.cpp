class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int rows[9][9] = {0};
        int columns[9][9] = {0};
        int boxes[9][9] = {0};
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j]-'0'-1;
                    int k = i/3 * 3 + j/3;                    
                    if (rows[i][num] == 1 || columns[j][num] == 1 || boxes[k][num] == 1)
                        return false;
                    rows[i][num] = columns[j][num] = boxes[k][num] = 1;
                }
            }
        }
        return true;
    }
};