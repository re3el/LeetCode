class Solution {
public:    
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        int n = nums.size();                   
        if(n<3) return res;
        
        int sum;
        sort(nums.begin(),nums.end());            
        for(int i=0; i<n; i++)
        {                
            sum = 0 - nums[i];
            int j = i+1, k = n-1;
            while(j<k)
            {
                if(nums[j] + nums[k] == sum)
                {
                    res.push_back({nums[i], nums[j],nums[k]});
                    while(j<k && nums[j] == nums[j+1]) j++; 
                    while(j<k && nums[k] == nums[k-1]) k--; 
                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] < sum)
                    j++;
                else
                    k--;
            }
            while(i<n && nums[i] == nums[i+1]) i++;             
        }        
        return res;
    }
};