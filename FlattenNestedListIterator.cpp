/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    queue<int>flatList;
public:
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        flattenIterator(nestedList,flatList);
    }
    
    void flattenIterator(vector<NestedInteger> &nestedList, queue<int> &flatList) 
    {
        for(int i=0; i<nestedList.size(); i++)   
        {
            if(nestedList[i].isInteger())
                flatList.push(nestedList[i].getInteger());        
            else            
                flattenIterator(nestedList[i].getList(),flatList);                
        }
    }

    int next() 
    {
        int res = flatList.front();
        flatList.pop();
        return res;
    }

    bool hasNext() {
        return !flatList.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */