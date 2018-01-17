class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res;
        unordered_set<int> setT(nums1.begin(),nums1.end());        
        for(auto i:nums2)
        {
            if(setT.count(i))
            {
                res.push_back(i);
                setT.erase(i);
            }
        }
        return res;
    }
};