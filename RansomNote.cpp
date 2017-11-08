class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char,int>hashT;
        for(char i:magazine){
            hashT[i]++;
        }
        
        for(char i:ransomNote){
            if(hashT[i]-- <= 0) return false;            
        }
        return true;
    }
};