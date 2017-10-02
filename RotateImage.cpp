class Solution {
public:
    // clockwise rotation
    void rotate(vector<vector<int>>& matrix) 
    {        
        reverse(matrix.begin(),matrix.end());
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=i+1; j<matrix[i].size(); j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }        
    }
    
    // anticlockwise rotation
    void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}
};