class Solution {
public:
    bool isOneEditDistance(string s, string t) 
    {
        int slen = s.length(), tlen = t.length();        
        for(int i=0; i<min(slen,tlen); i++)
        {
            if(s[i] != t[i])
            {
                if(slen == tlen) return s.substr(i+1) == t.substr(i+1);
                else if(slen > tlen) return s.substr(i+1) == t.substr(i);
                else return s.substr(i) == t.substr(i+1);
            }
        }
        return abs(slen-tlen)==1;
    }
};