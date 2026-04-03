class MinStack {
public:
    stack <long long> s;
    long long mini;
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        long long v = val;
        if(s.empty()){
            s.push(v);
            mini=v;
        }
        else{
            if(v<mini){
                s.push(2*v-mini);
                mini=val;
            }
            else{
                s.push(v);
            }
        }
    }
    
    void pop() {
        // if(s.empty()) return -1;
        long long curr=s.top();
        s.pop();
        if(curr<=mini){
            mini=2*mini-curr;
        }
    }
    
    int top() {
        long long curr = s.top();

        if(curr >= mini) return (int)curr;
        else return (int)mini;
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return (int)mini;
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */