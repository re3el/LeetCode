class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int n = nums.size()-1;
        if(n < 0) return false;
        while(n-1 >= 0 && nums[n] == nums[n-1])
            n--;
        
        int low = 0, high = n, mid;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(nums[mid] == target) return true;
            
            if(nums[low] <= nums[mid])
            {
                if(target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if(nums[mid] <= nums[high])
            {
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};