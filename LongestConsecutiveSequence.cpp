class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size() == 0) return 0;
        
        set<int> setT(nums.begin(),nums.end());
        auto itr = setT.begin();
        int val = *itr, cnt = 1, res = 1;
        while(true)
        {            
            itr++;
            if(itr == setT.end()) break;
            if(val+1 == *itr) cnt++;                            
            else{
                res = max(res,cnt);
                cnt = 1;                
            }
            val = *itr;
        }
        return max(res,cnt);
    }
};