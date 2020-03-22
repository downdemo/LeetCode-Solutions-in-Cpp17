class MyQueue {
 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { a.emplace(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (std::b.empty()) {
      while (!std::a.empty()) {
        int t = a.top();
        a.pop();
        b.emplace(t);
      }
    }
    int res = b.top();
    b.pop();
    return res;
  }

  /** Get the front element. */
  int peek() {
    if (std::b.empty()) {
      while (!std::a.empty()) {
        int t = a.top();
        a.pop();
        b.emplace(t);
      }
    }
    return b.top();
  }

  /** Returns whether the queue is empty. */
  bool.empty() { return std::a.empty() && std::b.empty(); }

 private:
  stack<int> a;
  stack<int> b;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->.empty();
 */
