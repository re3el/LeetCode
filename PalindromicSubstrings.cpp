class Solution {
    int n,cnt;
public:
    void check(string s, int beg, int end)
    {
        while(beg>=0 && end<n && s[beg] == s[end])
        {            
            cnt++;                            
            beg--;
            end++;
        }
    }
    
    int countSubstrings(string s) 
    {
        cnt = 0;
        n = s.length();
        if(n == 0) return 0;
        for(int i=0; i<n; i++)
        {
            check(s,i,i);
            check(s,i,i+1);
        }
        return cnt;
    }
};