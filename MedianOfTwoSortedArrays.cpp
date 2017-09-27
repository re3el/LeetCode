class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() > nums2.size())
            nums1.swap(nums2);
        
        int m = nums1.size();
        int n = nums2.size();    
        
        if (n == 0)
            return -1;
        
        int low = 0, high = m, mid = (m+n+1)/2;
        int i,j;
        while(low <= high)
        {
            i = (low + high)/2;
            j = mid - i;
            
            if (i>0 && nums1[i-1] > nums2[j])
                high = i - 1;
            else if(i<m && nums2[j-1] > nums1[i])
                low = i + 1;            
            else
            {
                double max_left, min_right;
                
                if (i==0) max_left = nums2[j-1];
                
                else if(j == 0) max_left = nums1[i-1];
                
                else max_left = max(nums1[i-1], nums2[j-1]);
                
                if ((m+n) % 2 == 1) return max_left;
                
                else
                {
                    if (i == m) min_right = nums2[j];
                    else if (j == n) min_right = nums1[i];
                    else min_right = min(nums1[i], nums2[j]);                    
                    return (max_left + min_right)/2.0;
                }                        
            }
            
        }
        
        return -1;        
    }
};