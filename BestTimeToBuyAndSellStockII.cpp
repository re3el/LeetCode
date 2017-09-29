class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int min = INT_MAX;        
        int profit = 0;
        
        for(int i:prices)
        {
            if (i<min) min = i;
            if (i-min > 0)
            {
                profit += i-min;
                min = i;
            }                
        }
        
        return profit;
    }
};