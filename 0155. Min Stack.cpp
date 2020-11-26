class MinStack {
  public:
    /** initialize your data structure here. */
    stack<int> main, mins; // main is main stack, mins is for getMin
    MinStack() {
    }

    void push(int x) {
        main.push(x);
        if (mins.empty() || x <= mins.top())
            mins.push(x);
    }

    void pop() {
        if (main.top() == mins.top())
            mins.pop();
        main.pop();
    }

    int top() {
        return main.top();
    }

    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */