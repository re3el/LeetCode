class Solution {
public:
    int mySqrt(int x) 
    {
        if(x == 1) return x;
        if(x<0) return INT_MIN;
        int res;
        int low = 0, high = x, mid;
        
        while(low < high)
        {
            mid = low + (high-low)/2;
            if (mid  <= x/mid && (mid+1) > x/(mid+1) ) return mid;
            else if (mid < x/mid) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};