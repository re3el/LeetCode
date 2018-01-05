class Solution {
public:
    void compute(vector<int> nums, vector<vector<int>> &res, int ind, int len)
    {
        if(ind == len)
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=ind; i<len; i++)
        {
            if(i != ind && nums[i] == nums[ind]) continue;
            swap(nums[i],nums[ind]);
            compute(nums,res,ind+1,len);                        
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        compute(nums,res,0,n);
        return res;
    }
};