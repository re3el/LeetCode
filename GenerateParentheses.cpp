class Solution {
public:
    void generate(vector<string> &res, string curr, int open, int close)
    {
        if(open == 0 && close == 0)
        {
            res.push_back(curr);
            curr.clear();
            return;        
        }
        if(open > 0)
            generate(res,curr+'(',open-1,close+1);
        if(close > 0)
            generate(res,curr+')',open,close-1);
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string>res;
        string curr = "";
        generate(res,curr,n,0);
        return res;
    }        
};