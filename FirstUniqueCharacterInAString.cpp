class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char,pair<int,int>>hashT;
        for(int i=0; i<s.length(); i++)
        {
            hashT[s[i]].first++;
            hashT[s[i]].second = i;
        }
        
        int ind = INT_MAX;
        for(auto i:hashT)
        {
            if(i.second.first == 1) ind = min(ind,i.second.second);
        }
        return ind == INT_MAX ? -1 : ind;
    }
};