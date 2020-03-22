class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (q1.empty()) {
      q1.emplace(num);
      return;
    }
    if (num <= q1.top()) {
      q1.emplace(num);
      if (q1.size() == q2.size() + 2) {
        q2.emplace(q1.top());
        q1.pop();
      }
    } else {
      q2.emplace(num);
      if (q1.size() == q2.size() - 2) {
        q1.emplace(q2.top());
        q2.pop();
      }
    }
  }

  double findMedian() {
    if (q1.size() > q2.size()) {
      return q1.top();
    }
    if (q1.size() < q2.size()) {
      return q2.top();
    }
    return (q1.top() + q2.top()) / 2.0;
  }

 private:
  priority_queue<int> q1;
  priority_queue<int, vector<int>, greater<int>> q2;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
