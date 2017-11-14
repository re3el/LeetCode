class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> res;
        
        int i=0;
        while(i<n)
        {
            if(nums[i] != nums[nums[i]-1]) swap(nums[i],nums[nums[i]-1]);
            else i++;
        }
        
        for(i=0; i<n; i++)
        {
            if(nums[i] != i+1) 
                res.push_back(i+1);
        }
        return res;                    
    }
};