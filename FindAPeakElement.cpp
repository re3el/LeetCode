class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int n = nums.size();
        int low = 0, high = n-1, mid1, mid2;
        
        while(low < high)
        {
            mid1 = low + (high-low)/2;
            mid2 = mid1 + 1;
            if (nums[mid1] < nums[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};