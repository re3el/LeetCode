class Solution {
public:
    void compute(int k, int n, vector<vector<int>> &res, vector<int> &curr, int begin)
    {
        if(!n && !k)
        {
            res.push_back(curr);
            return;
        }
        
        if(!k || !n) return;
        
        for(int i=begin; i<10 && i<=n; i++)
        {
            curr.push_back(i);
            compute(k-1,n-i,res,curr,i+1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> res;
        vector<int> curr;
        compute(k,n,res,curr,1);
        return res;
    }
};