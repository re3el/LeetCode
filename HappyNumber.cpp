class Solution {
public:
    bool isHappy(int n) 
    {
        int res = 0;
        int tmp = n;        
        set<int> setT;
        
        while(true)
        {
            setT.insert(tmp);
            res = 0;            
            while(tmp != 0)
            {
                int rem = tmp%10;
                res += rem*rem;
                tmp = tmp/10;
            }
            if(res == 1)
                return true;   
            if(setT.find(res) != setT.end())
                return false;                     
            tmp = res;            
            //cout<<tmp<<endl;
        }
    }
};