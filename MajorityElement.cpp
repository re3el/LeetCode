class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        if (nums.size() == 0) return -1;
        int count = 0, major;
        
        for(int i:nums)
        {
            if(count == 0) major = i;
            if(major == i) count++;
            else count--;            
        }
        
        return major;
    }
};