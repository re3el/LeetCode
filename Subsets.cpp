class Solution {
public:
    vector<vector<int>> findSets(vector<int>& nums) 
    {
        vector<vector<int>>res = {{}};       
        
        for(int i=0; i<nums.size(); i++)
        {      
            int n = res.size();
            for(int j=0; j<n;j++)
            {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }              
        }
        return res;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0)  return {};                
        return findSets(nums);        
    }
};