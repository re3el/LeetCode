class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        bool next = false;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                next = true;
                for(int j=n-1; j>i ; j--)
                {
                    if(nums[j] > nums[i])
                    {
                        swap(nums[j],nums[i]);
                        break;
                    }
                }
                //cout<<nums[i]<<":"<<i<<endl;
                reverse(nums.begin()+i+1,nums.end());
                break;
            }
        }
        if(next == false) reverse(nums.begin(),nums.end());
    }
};