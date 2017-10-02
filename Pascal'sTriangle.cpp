class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>res;
        if(numRows == 0) return res;
        
        res.push_back({1});        
        vector<int>tmp;    
        
        for(int i=1; i<numRows; i++)
        {
            tmp.push_back(1);
            vector<int>curr = res.back();
            for(int j=1; j<curr.size(); j++)
                tmp.push_back(curr[j-1]+curr[j]);            
            tmp.push_back(1);
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};