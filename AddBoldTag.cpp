class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) 
    {
        int n = s.length();
        vector<bool>bold(n,false);
                
        for(int i=0,end=0; i<n; i++)
        {            
            for(string word:dict)
            {     
                int len = word.length();
                if(i+len<=n && s.substr(i,len) == word){
                    end = max(end,i+len);
                }
            }
            bold[i] = end > i;
        }
        
        string res;
        for(int i=0; i<n; i++)
        {
            if(!bold[i]){
                res += s[i];
                continue;
            }
            int j = i;
            while(bold[j] && j<n) j++;
            res += "<b>" + s.substr(i,j-i) + "</b>";
            i = j-1;
        }
        return res;
    }
    
};