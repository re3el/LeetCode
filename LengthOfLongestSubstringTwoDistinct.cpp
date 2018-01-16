class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        vector<int>count(256,0);
        int n = s.length(), cnt = 0, res = 0, beg = 0;
        
        for(int i=0; i<n; i++)
        {
            if(count[s[i]]++ == 0) cnt++;
            while(cnt > 2 && beg < n)
            {
                if(--count[s[beg]] == 0) --cnt;
                beg++;
            }
            res = max(res,i-beg+1);
        }
        return res;
    }
    
};