class Solution {
public:
    bool check(unordered_map<char,int> &hashT)
    {
        for(auto i:hashT)
            if(i.second != 0) return false;
        return true;
    }
    
    bool checkInclusion(string s1, string s2) 
    {
        int n1 = s1.length(), n2 = s2.length();
        if(n2 < n1) return false;
        
        bool flag;
        unordered_map<char,int>hashT;
        for(char i:s1) hashT[i]++;
                        
        string sub;
        for(int i=0; i<n1; i++)
            hashT[s2[i]]--;
                
        for(int i=0; i<n2; i++)
        {
            flag = check(hashT);
            if(flag) return true;
            
            hashT[s2[i]]++;
            
            if(i+n1 >= n2) return false;
            hashT[s2[n1+i]]--;
        }

        return false;
    }
};