class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        vector<int>count(256,0);
        int n = s.length();
        
        int beg = 0, num = 0, res = 0;
        for(int i=0; i<n; i++)
        {
            if(count[s[i]]++ == 0) num++;
            while(num > k && beg < n)
            {
                if(--count[s[beg]] == 0) num--;
                beg++;
            }
            res = max(res,i-beg+1);
        }
        return res;
    }
};