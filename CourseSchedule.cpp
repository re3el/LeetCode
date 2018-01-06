class Solution {
public:
    vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<unordered_set<int>> graph(numCourses);
        for(auto i:prerequisites)
        {
            graph[i.second].insert(i.first);
        }
        return graph;
    }
    
    bool dfsCycle(vector<unordered_set<int>> &graph, int node, vector<bool> &visited, vector<bool> &onpath)
    {
        if(visited[node]) return false;
        
        visited[node] = onpath[node] = true;
        for(auto i:graph[node])
        {
            if(onpath[i] || dfsCycle(graph,i,visited,onpath))   
                return true;
        }
        onpath[node] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<unordered_set<int>> graph;
        graph = makeGraph(numCourses,prerequisites);
        vector<bool> visited(numCourses,false), onpath(numCourses,false);
        
        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i] && dfsCycle(graph,i,visited,onpath))
                return false;
        }
        return true;
    }
};