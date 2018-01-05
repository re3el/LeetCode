class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        // k<size check
        priority_queue<int,vector<int>,greater<int>>pq;                
        int i;
                
        for(i=0; i<k; i++)        
            pq.push(nums[i]);         
        
        while(i != nums.size())
        {
            if(nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);                               
            }
            i++;
        }
        
        return pq.top();
    }
};