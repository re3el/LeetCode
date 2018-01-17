class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int res = 0;
        vector<int> pos;
        pos.push_back(-1);
        
        for(int i=0; i<nums.size(); i++)
            if(nums[i] == 0) pos.push_back(i);
        
        pos.push_back(nums.size());
        
        for(int i=2; i<pos.size(); i++)
            res = max(res,pos[i]-pos[i-2]-1);
        
        if(pos.size() == 2) return nums.size();
        return res;
    }
};