class Solution {
public:
    string licenseKeyFormatting(string S, int K) 
    {
        int len = S.length(), cnt = 0;        
        string res;
        
        for(int i=len-1; i>=0; i--)
        {            
            if(S[i] == '-') continue;
            if((cnt)%K == 0) res += '-';            
            if(S[i]>=97 && S[i]<=122) res += S[i]-32;
            else res += S[i];
            cnt++;
        }
        if(res.length() == 0) return "";
        res = res.substr(1);
        reverse(res.begin(),res.end());
        return res;
    }
};