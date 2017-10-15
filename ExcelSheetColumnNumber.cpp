class Solution {
public:
    int titleToNumber(string s) 
    {
        string rev = s;
        reverse(rev.begin(),rev.end());
        
        int res(0),exp(0);
        for(char i:rev)
        {
            int val = i - 'A' + 1;            
            res += pow(26,exp) * val;
            exp++;
        }
        return res;
    }
};