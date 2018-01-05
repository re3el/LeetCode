class Solution {
public:
    void compute(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &curr, int begin)
    {
        if(!target)
        {
            res.push_back(curr);
            return;
        }
        
        int n = candidates.size();
        for(int i=begin; i<n && candidates[i] <= target; i++)
        {
            curr.push_back(candidates[i]);
            compute(candidates,target-candidates[i],res,curr,i+1);
            curr.pop_back();
            while(i < n-1 && candidates[i] == candidates[i+1]) i++;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        compute(candidates,target,res,curr,0);
        return res;
    }
};