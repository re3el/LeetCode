class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int,int>hashT;
        for(int i=0; i<nums.size(); i++)
        {
            hashT[nums[i]]++;            
            if (hashT[nums[i]] > 1)
                return true;
        }
                
        return false;
    }
};