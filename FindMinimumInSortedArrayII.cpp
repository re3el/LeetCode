class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n = nums.size();
        int low = 0, high = n-1;
        int mid;
   
        while(low < high && nums[low] == nums[high])
            high--;
        
        while(low < high)
        {
            if (nums[low] < nums[high])
                return nums[low];
            mid = low + (high-low)/2;
            if (nums[low] <= nums[mid])
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low];
    }
};