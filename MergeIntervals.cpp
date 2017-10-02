/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(const Interval &a, const Interval &b)
{
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        int n = intervals.size();        
        vector<Interval> res;
        if (n == 0) return res;
                
        sort(intervals.begin(), intervals.end(), comp);
        res.push_back(intervals[0]);
        int k = 0;
        for(int i=1; i<n; i++)
        {
            k = res.size()-1;            
            if(intervals[i].start <= res[k].end)
            {
                if(intervals[i].end > res[k].end)                
                    res[k].end = intervals[i].end;                
            }
            else            
                res.push_back(intervals[i]);            
        }
        
        return res;
    }
};