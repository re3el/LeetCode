class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            while(nums[i]>0 && nums[i] <= nums.size() && nums[i] != i+1 && nums[i] != nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);             
        }
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};