class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int>hashT;
        for(auto i:s)
            hashT[i]++;
        for(auto i:t)
            hashT[i]--;
        for(auto i:hashT)
        {
            if(i.second != 0)
                return false;
        }
        return true;
    }
};