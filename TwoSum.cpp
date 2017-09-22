class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int>hashT;
        int size = nums.size();
        
        for(int i=0; i<size; i++)
        {
            if(hashT.find(target - nums[i]) != hashT.end())    
            {
                return {hashT[target-nums[i]],i};
            }
            hashT[nums[i]] = i;
        }
        return {};
    }
};