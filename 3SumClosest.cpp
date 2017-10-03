class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n = nums.size();
        if(n < 3) return -1;
        
        sort(nums.begin(),nums.end());            
        int res = nums[0]+nums[1]+nums[2];
        for(int i=0; i<n; i++)
        {
            int val = nums[i];
            int j = i+1, k = n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target) return sum;
                
                if(abs(sum-target) < abs(res-target))
                    res = sum;
                
                if(sum > target)
                    k--;
                else
                    j++;                
            }
        }
        return res;
    }
};