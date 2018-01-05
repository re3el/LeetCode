class Solution {
public:
    int n;
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        n = nums.size();
        for(int i=0; i<n; i++)
        {
            int sum = target-nums[i];
            vector<vector<int>>subRes;
            threeSum(nums,sum,i+1,subRes);                           
            for(int j=0; j<subRes.size(); j++)
            {
                vector<int>curr;
                curr.push_back(nums[i]);
                curr.insert(curr.end(),subRes[j].begin(),subRes[j].end());
                res.push_back(curr);
            }            
            while(i+1<n && nums[i] == nums[i+1]) i++;                            
        }
        return res;
    }
    
    void threeSum(vector<int>& nums, int target, int index, vector<vector<int>>& subRes) 
    {
        for(int i=index; i<n; i++)
        {
            int sum = target-nums[i];
            int j = i+1, k = n-1;
            
            while(j<k)
            {
                if(nums[j]+nums[k] < sum) j++;
                else if(nums[j]+nums[k] > sum) k--;
                else
                {
                    subRes.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
            }
            while(i+1<n && nums[i] == nums[i+1]) i++;
        }        
    }
};