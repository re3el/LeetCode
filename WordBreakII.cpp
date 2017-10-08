class Solution {
    int len;
public:
    void getStrings(unordered_map<int,unordered_set<int>> hashT, string s, string str, int pos, vector<string> &res)
    {                        
        if(pos == len)
        {            
            str.erase(str.length()-1);
            res.push_back(str);            
            str.clear();
            return;
        }        
        if(pos > len) return;        
        unordered_set<int>curr = hashT[pos];        
        for(auto i:curr)
        {                     
            getStrings(hashT,s,str+s.substr(pos,i)+' ',i+pos,res);
        }
        return;
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        len = s.length();
        if(len == 0) return {};
        
        vector<string>res;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int,unordered_set<int>> hashT;
        vector<bool>dp(len+1);
        dp[0] = true;        
        
        for(int i=1; i<=len; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(dp[j] != 0 && dict.find(s.substr(j,i-j)) != dict.end())
                {
                    hashT[j].insert(i-j);
                    dp[i] = true;
                }
            }
        }
        
        if(dp[len] == false) return {};    
        if(hashT[0].size() == 0) return {};        
        getStrings(hashT,s,"",0,res);
        
        return res;
    }
};