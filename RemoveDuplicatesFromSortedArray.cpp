class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size(), j = 0, i = 0;        
        for(i=1; i<n; i++)
        {
            while(i<n && nums[i] == nums[j]) i++; 
            if(i >= n) break;
            swap(nums[i], nums[++j]);
        }        
        return j+1;
    }
};