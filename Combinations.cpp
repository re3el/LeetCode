class Solution {
public:
    void combinations(int n, int k, vector<vector<int>>&res, vector<int> &curr, int begin)
    {
        if(k == 0)
        {
            res.push_back(curr);
            return;
        }
        
        for(int i=begin; i<=n; i++)
        {
            curr.push_back(i);
            combinations(n,k-1,res,curr,i+1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>>res;
        vector<int>curr;
        combinations(n,k,res,curr,1);
        return res;
    }
};