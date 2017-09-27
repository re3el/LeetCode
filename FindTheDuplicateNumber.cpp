class Solution {
public:
    int count(vector<int> &nums, int target)
    {
        int res = 0;
        for(auto i:nums)
        {
            if(i <= target)
                res++;
        }        
        return res;
    }
    
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        int low = 1, high = n-1, mid;
        
        while(low < high)
        {
            mid = low + (high-low)/2;
            if (count(nums, mid) > mid )
                high = mid;
            else
                low = mid+1;            
        }
        return low;
    }
};