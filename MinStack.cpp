class MinStack {
    vector<int>stk;
    vector<int>minStk;    
public:
    /** initialize your data structure here. */
    MinStack() {        
    }
    
    void push(int x) 
    {
        stk.push_back(x);
        if(minStk.size() != 0)
        {
            int minTop = minStk.back();        
            if(minTop >= x)
                minStk.push_back(x);
        }
        else
            minStk.push_back(x);
    }
    
    void pop() {
        int top = stk.back();
        if(minStk.back() == top)
            minStk.pop_back();
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return minStk.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */