#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

string myitoa(int num)
{
    int sign = 1;
    if(num < 0) 
    {
        sign = -1;
        if(num == INT_MIN) return "write the min_value";
        else num *= -1;
    }
    
    string res;
    do
    {
        res += '0' + num%10;
        num /= 10;
    }while(num);
    
    if(sign == -1) res += '-';
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    cout<<myitoa(1233232);
    return 0;
}
