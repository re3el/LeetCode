class Solution {
public:
    int repeatedStringMatch(string A, string B) 
    {
        int lenA = A.length();
        int lenB = B.length();
        if(lenB == 0) return 1;
        
        string chk = A;
        int cnt = 1;
        while(chk.length() < lenB + 2*lenA)
        {
            if(chk.find(B) != string::npos) return cnt;           
            cnt++;
            chk += A;
        }
        return -1;
    }
};