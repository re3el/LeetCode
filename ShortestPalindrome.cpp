class Solution {
public:
    // idea: find the longest palindrome substring starting from index 0; 
    //       once that is found, add the reverse of the remaining substring to the front    
    string shortestPalindrome(string s) 
    {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string tmp = s + '#' + rev;
        int len = tmp.length();
        vector<int> lcp(len,0);
        
        // lcp array of the KMP algorithm
        for(int i=1,j=0; i<len;)
        {
            if(tmp[i] == tmp[j])
            {
                lcp[i] = 1+j;
                i++;
                j++;                
                continue;
            }
            if(j != 0) j = lcp[j-1];
            else lcp[i++] = 0;            
        }        
        return rev.substr(0,s.length()-lcp[len-1]) + s;
    }
};