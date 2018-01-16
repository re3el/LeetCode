class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) 
    {
        unordered_map<int,int>days;
        int n = flowers.size();     
        
        for(int i=0; i<n; i++)        
            days[flowers[i]-1] = i+1;
        
        int left = 0, right = k+1, res = INT_MAX;
        for(int i=0; i<n; i++)
        {            
            if(days[i] > days[left] && days[i] > days[right])
                continue;
            
            if(i == right)
                res = min(res,max(days[left],days[right]));
            
            left = i;
            right = i+k+1;
        }
        return (res == INT_MAX)?-1:res;
    }
};