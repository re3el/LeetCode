/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) 
    {
        int n = points.size();
        unordered_map<double, set<pair<int, int>> >hashT;
        int maxPoints = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j != i && j<n; j++)
            {
                double yCoordDiff = points[i].y - points[j].y;
                double xCoordDiff = (points[i].x - points[j].x);
                if (xCoordDiff == 0)
                {                                        
                    hashT[INT_MAX].insert(make_pair(points[i].x, points[i].y));
                    hashT[INT_MAX].insert(make_pair(points[j].x, points[j].y));
                    if (hashT[INT_MAX].size() > maxPoints)
                        maxPoints = hashT[INT_MAX].size();
                }
                else
                {
                    double slope = yCoordDiff/xCoordDiff ;                    
                    hashT[slope].insert(make_pair(points[i].x, points[i].y));
                    hashT[slope].insert(make_pair(points[j].x, points[j].y));
                    
                    if (hashT[slope].size() > maxPoints)
                        maxPoints = hashT[slope].size();
                }                
            }
            hashT.clear();
        }
        return n == 1 ? 1 : maxPoints;
    }
};