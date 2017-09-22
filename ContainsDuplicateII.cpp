class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,vector<int>> hashT;
        for(int i=0; i<nums.size(); i++)
        {
            if (hashT.find(nums[i]) != hashT.end())
            {                
                vector<int> val = hashT[nums[i]];
                for (int j=0; j<val.size(); j++)
                {                         
                    if (abs(i - val[j]) <= k)
                        return true;                    
                }                
            }
            hashT[nums[i]].push_back(i);
        }
        return false;
    }
};