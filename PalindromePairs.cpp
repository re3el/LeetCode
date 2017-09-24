class Solution {
public:
    bool checkPalindrome(string a)
    {
        int len = a.length();
        for(int i=0; i<len/2; i++)
        {
            if(a[i] != a[len-1-i])
                return false;
        }
        return true;
    }
        
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>> res;
        unordered_map<string,int>hashT;
        int n = words.size();
        for(int i=0; i<n; i++)
        {
            hashT[words[i]] = i;
        }
                
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=words[i].size(); j++)        
            {
                string str1 = words[i].substr(0,j);
                string str2 = words[i].substr(j);
                
                if(checkPalindrome(str1) == true)
                {
                    string revStr2 = str2;
                    reverse(revStr2.begin(), revStr2.end());
                    // hashT[revStr2] != i as we dont want the same string to be paired with itself
                    if(hashT.find(revStr2) != hashT.end() && hashT[revStr2] != i)
                    {
                        res.push_back({hashT[revStr2],i});
                    }                    
                }
                
                if(checkPalindrome(str2) == true)
                {
                    string revStr1 = str1;
                    reverse(revStr1.begin(), revStr1.end());
                    // str2.length() != 0, as we dont want to cover the cases {"abcd",""} {"","abcd"} twice
                    if (hashT.find(revStr1) != hashT.end() && hashT[revStr1] != i && str2.length() != 0)
                    {
                        res.push_back({i,hashT[revStr1]});
                    }
                }
            }                        
        }
        
        return res;
    }
};