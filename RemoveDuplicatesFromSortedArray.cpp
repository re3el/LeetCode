class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size(), j = 0;            
        for(int i=0; i<n; i++)
        {
            int tmp = nums[i];
            swap(nums[i],nums[j++]);            
            while(i+1<n && tmp == nums[i+1]) i++;            
        }
        return j;
    }
};