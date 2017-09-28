class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>res;
        unordered_map<int,int>hashT;
        
        for(int i:nums1)
            hashT[i]++;
        
        for(int i:nums2)
        {                           
            if (hashT[i]-- > 0)
                res.push_back(i);            
        }
        return res;
    }
};