class Solution {
    vector<string> twenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                             "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};    
public:
    string helper(int num)
    {
        if(num == 0) return "";
        if(num < 20) return twenty[num] + " ";
        if(num < 100) return tens[num/10] + " " + helper(num%10);
        else return twenty[num/100] + " Hundred " + helper(num%100);
    }
                             
    string numberToWords(int num) 
    {
        if(num == 0) return "Zero";
        int i=0;
        string res;
        
        while(num > 0)
        {
            if(num % 1000 != 0)  
              res = helper(num%1000) + thousands[i] + " "+ res;
            i++;
            num /= 1000;
        }
        
        int pos = res.find_last_not_of(" \t");
        return res.substr(0,pos+1);
    }
};