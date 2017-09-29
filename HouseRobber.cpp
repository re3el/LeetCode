class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0) return 0;
        
        int robBefore = 0, robNow = nums[0];
        
        for(int i=1; i<n; i++)
        {
            int tmp = robNow;
            robNow = max(robNow, robBefore + nums[i]);
            robBefore = max(tmp, robBefore);            
        }
        return max(robNow,robBefore);
    }
};