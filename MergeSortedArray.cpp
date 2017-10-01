class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int end = n+m-1, i = m-1, j = n-1;
        
        while(j >= 0)
        {
            nums1[end--] = ( (i >= 0) && (nums1[i] >= nums2[j]) ) ? nums1[i--] : nums2[j--];
        }
    }
};