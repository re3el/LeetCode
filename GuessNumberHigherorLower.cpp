// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) 
    {
        int low = 1, high = n, mid;
        while(low < high)
        {
            mid = low + (high-low)/2;
            int val = guess(mid);
            if (val == 0) return mid;
            else if(val < 0) high = mid-1;
            else low = mid + 1;                
        }
        return low;
    }
};