class MyStack {
  public:
    queue<int> main, temp;
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        // transfer to temp
        while (!main.empty()) {
            temp.push(main.front());
            main.pop();
        }
        // add and transfer
        main.push(x);
        while (!temp.empty()) {
            main.push(temp.front());
            temp.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = main.front();
        main.pop();
        return top;
    }

    /** Get the top element. */
    int top() {
        return main.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */