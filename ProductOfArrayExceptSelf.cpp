class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        int begin = 1, end = 1;
        vector<int>res(n,1);
        
        for(int i=0; i<n; i++)
        {            
            res[i] *= begin;
            begin *= nums[i];
            res[n-1-i] *= end;
            end *= nums[n-1-i];
        }
        
        return res;
    }
};