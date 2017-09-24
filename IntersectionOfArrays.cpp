class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int>setT(nums1.begin(),nums1.end());        
        vector<int>res;
        
        for(auto i:nums2)
        {
            if (setT.find(i) != setT.end())
            {
                res.push_back(i);
                setT.erase(i);
            }
        }
        return res;
    }
};