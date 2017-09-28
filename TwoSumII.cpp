class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int n = numbers.size(); 
        int low = 0, high = n-1;
        while(low < high)
        {
            int val = numbers[low] + numbers[high];
            if (val == target) return {low+1,high+1};
            else if (val < target) low++;
            else high--;
        }
        return {low+1,high+1};
    }
};