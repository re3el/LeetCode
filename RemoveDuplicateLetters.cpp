class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        vector<int>chars(256,0);
        vector<bool>visited(256,false);
                
        for(auto c:s)
            chars[c]++;
        
        // since all chars > 0
        string res = "0";
        for(auto c:s)
        {            
            chars[c]--;
            if(visited[c]) continue;
            
            while(c < res.back() && chars[res.back()] > 0)
            {
                visited[res.back()] = false;
                res.pop_back();                
            }
            
            res += c;
            visited[c] = true;
        }
        return res.substr(1);
    }
};