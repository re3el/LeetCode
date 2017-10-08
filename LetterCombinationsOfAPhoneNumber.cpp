class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {        
        if(digits.size() == 0) return {};
        
        vector<string> res = {""};
        unordered_map<char,string>hashT = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        
        for(int i=0; i<digits.size(); i++)
        {
            string sub = hashT[digits[i]];
            vector<string>curr;
            for(int j=0; j<sub.size(); j++)
            {
                for(int k=0; k<res.size(); k++)
                {
                    curr.push_back(res[k]+sub[j]);
                }
            }
            swap(res,curr);
        }
        return res;
    }
};