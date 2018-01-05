class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m = matrix.size();
        if(m == 0) return 0;
        
        int n = matrix[0].size();
        vector<int> left(n,0), right(n,n), height(n,0);        
        int maxArea = 0;
        for(int i=0; i<m; i++)
        {
            int cur_left = 0, cur_right = n;
            
            // height
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '1')                
                    height[j]++;    
                else height[j] = 0;
            }
            
            // left
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '1')                
                    left[j] = max(left[j],cur_left);
                else{ 
                    cur_left = j+1;
                    left[j] = 0;
                }
            }
            
            // right
            for(int j=n-1; j>=0; j--)
            {
                if(matrix[i][j] == '1')                
                    right[j] = min(right[j],cur_right);
                else{ 
                    cur_right = j;
                    right[j] = n;
                }
            }
            
            // area
            for(int j=0; j<n; j++)            
                maxArea = max(maxArea,(right[j]-left[j])*height[j]);            
        }
        return maxArea;
    }
};