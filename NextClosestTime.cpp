class Solution {
public:
    string nextClosestTime(string time) 
    {
        // check if string is valid
        set<int>setT;
        int j = 0;
        for(auto i:time)
            if(i != ':') setT.insert(i-'0');             
        vector<int>nums(setT.begin(),setT.end());        
        
        int n = nums.size();
        int cnt = 0;
        vector<int>list(16,0);
        vector<string>listStr(16,"");
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {                
                int val = nums[i]*10 + nums[j];                
                if(val < 60) 
                {
                    list[cnt] = val;
                    if(val >= 0 && val < 10)
                        listStr[cnt] = '0'+ to_string(val);
                    else
                        listStr[cnt] = to_string(val);
                    cnt++;
                }
            }
        }
        nums.resize(cnt);
        
        string minsStr = time.substr(3,2);        
        string hrsStr = time.substr(0,2);
        int mins = stoi(minsStr);
        int hrs = stoi(hrsStr);        
                
        int i=0;
        while(i<cnt && list[i] <= mins) i++;        
        if(i == cnt){
            int i=0;
            while(i<cnt && list[i] <= hrs && list[i] < 24) i++;            
            if(i==cnt || list[i] > 23) return listStr[0]+":"+listStr[0];
            else return listStr[i]+":"+listStr[0];
        }
        return hrsStr+":"+listStr[i];
        
    }
};