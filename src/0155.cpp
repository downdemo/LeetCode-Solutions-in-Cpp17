class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    stackAll.emplace(x);
    if (stackMin.empty() || x <= stackMin.top()) {
      stackMin.emplace(x);
    }
  }

  void pop() {
    if (stackAll.top() == stackMin.top()) {
      stackMin.pop();
    }
    stackAll.pop();
  }

  int top() { return stackAll.top(); }

  int getMin() { return stackMin.top(); }

 private:
  stack<int> stackAll;
  stack<int> stackMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
