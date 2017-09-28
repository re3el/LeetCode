class Solution {
public:
    int divide(int dividend, int divisor) 
    {                
        if( !divisor || (dividend == INT_MIN && divisor == -1) )
            return INT_MAX;
        
        int sign = ((divisor<0)^(dividend<0) ? -1:1);
        long long divs = labs(divisor);
        long long divd = labs(dividend);
        
        int res = 0;
        while(divd >= divs)
        {
            long long tmp = divs;
            long long multiple = 1;
            while(divd >= tmp<<1)
            {
                tmp <<= 1;
                multiple <<= 1;
            }
            divd -= tmp;
            res += multiple;
        }
        return sign*res;
    }
};