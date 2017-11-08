class Solution {
public:
    string intToRoman(int num) 
    {
        vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string res = "";
        
        for(int i=0; i<values.size(); i++)
        {
            while(num >= values[i])
            {
                num -= values[i];
                res += roman[i];
            }
        }
        return res;
    }
};