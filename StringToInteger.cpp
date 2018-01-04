class Solution {
public:
    int myAtoi(string str) 
    {   
        int sign = 1;
        int pos = str.find_first_not_of(' ');
        if (str[pos] == '-' || str[pos] == '+')
            sign = (str[pos++] == '-') ? -1:1;
        
        long res = 0;
        while(str[pos] >= '0' && str[pos] <= '9')
        {
            res = res*10 + str[pos++] - '0';
            if(res*sign < INT_MIN) return INT_MIN;
            if(res*sign > INT_MAX) return INT_MAX;
        }
        
        return res*sign;
    }
};