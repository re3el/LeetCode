class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0) return {};
        
        vector<string>res;                
        for(int i=0; i<n; i++)
        {
            string curr = to_string(nums[i]);
            int tmp = i;
            
            while(i < n-1 && nums[i] + 1 == nums[i+1]) i++;
            
            if(tmp == i) res.push_back(curr);
            else res.push_back(curr + "->" + to_string(nums[i]));
        }
        return res;
    }
};