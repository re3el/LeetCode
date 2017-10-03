class Solution {
public:
    string reverseVowels(string s) 
    {
        int first=0,last=s.size()-1;
        while(first<last)
        {
            first = s.find_first_of("aeiouAEIOU",first);
            last = s.find_last_of("aeiouAEIOU",last);
            if(first<last)
                swap(s[first++],s[last--]);
        }
        return s;
    }
};