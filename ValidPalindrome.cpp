class Solution {
public:
    bool isPalindrome(string s) 
    {
        int len = s.length();
        if(len == 0) return true;
                
        for(int i=0,j=len-1; i<j; i++,j--)
        {            
            while(i<j && !isalnum(s[i])) i++; 
            while(i<j && !isalnum(s[j])) j--;
            
            if(toupper(s[i]) != toupper(s[j])) return false;
        }
        return true;
    }
};