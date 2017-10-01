class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {        
        int n = digits.size();
        
        for(int i=n-1; i>=0; i--)    
        {
            if(digits[i] != 9)
            {
                digits[i]++;
                return digits;
            }
            else            
                digits[i] = 0;            
        }
        if(digits[0] == 0)
        {
            deque<int>deq(digits.begin(),digits.end());
            deq.push_front(1);
            return vector<int>(deq.begin(),deq.end());
        }
        return digits;
    }
};