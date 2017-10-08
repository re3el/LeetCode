class Solution {
public:
    void findSets(vector<vector<int>> &res, vector<int> &nums, int start)
    {
        if(start == nums.size())
        {            
            res.push_back(nums);
            return;
        }
                
        for(int i=start; i<nums.size(); i++)
        {
            swap(nums[i],nums[start]);
            findSets(res,nums,start+1);
            swap(nums[start],nums[i]);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0) return {{}};
    
        vector<vector<int>>res;
        findSets(res,nums,0);
        return res;
    }    
};