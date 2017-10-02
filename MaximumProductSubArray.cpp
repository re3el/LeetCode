class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0) return -1;
        
        int tmp;
        int max_now = nums[0], min_now = nums[0], max_total = nums[0];            
        for(int i=1; i<nums.size(); i++)
        {
            tmp = max_now;
            max_now = max(max_now*nums[i], max(min_now*nums[i], nums[i]));
            min_now = min(min_now*nums[i], min(tmp*nums[i], nums[i]));
            max_total = max(max_total, max_now);
        }
        return max_total;
    }
};