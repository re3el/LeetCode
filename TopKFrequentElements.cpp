/* good use of multimap and map*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int,int> hashT;
        multimap<int,int,greater<int>> mapT;
        for(int i=0; i<nums.size(); i++)
        {
            hashT[nums[i]]++;
        }
        
        for(auto i:hashT)
        {
            mapT.insert(make_pair(i.second,i.first));
        }
        
        vector<int>res;
        for(auto i:mapT)
        {            
            res.push_back(i.second);            
            k--;
            if(k==0)
                break;
        }
        return res;
    }
};