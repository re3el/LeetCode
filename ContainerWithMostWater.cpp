class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int i = 0, j= n-1;
        int area = 0;
        
        while(i<j)
        {
            int front = height[i];
            int back = height[j];
            int minH = min(front,back);
            area = max(area, minH*(j-i));
            
            while(i<j && height[i] <= minH) i++;
            while(i<j && height[j] <= minH) j--;
        }
        return area;        
    }
};