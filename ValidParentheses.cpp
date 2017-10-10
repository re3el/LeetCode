class Solution {
public:
    bool isValid(string s) 
    {
        unordered_map<char,char>hashT = {
            {')','('},
            {'}','{',},
            {']','['}
        };
        stack<int>stk;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else
            {                
                if(stk.size() == 0) 
                    return false;                
                if(hashT[s[i]] != stk.top())
                    return false;                
                stk.pop();
            }
        }        
        return (stk.size() == 0)? true:false;
    }
};