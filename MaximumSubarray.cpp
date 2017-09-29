class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0) return -1;
        
        int max_here = nums[0], max_final = nums[0];
        for(int i=1; i<n; i++)
        {
            max_here = max(max_here + nums[i], nums[i]);
            max_final = max(max_final, max_here);
        }
        return max_final;
    }
};