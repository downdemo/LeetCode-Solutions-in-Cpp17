class ZeroEvenOdd {
 public:
  ZeroEvenOdd(int n) { this->n = n; }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    while (cur <= n) {
      unique_lock<mutex> l{m};
      cv.wait(l, [this] { return b; });
      if (cur <= n) {
        printNumber(0);
      }
      b = false;
      cv.notify_all();
    }
  }

  void even(function<void(int)> printNumber) {
    while (cur <= n) {
      unique_lock<mutex> l{m};
      cv.wait(l, [this] { return !b && cur % 2 == 0; });
      if (cur <= n) {
        printNumber(cur++);
      }
      b = true;
      cv.notify_all();
    }
  }

  void odd(function<void(int)> printNumber) {
    while (cur <= n) {
      unique_lock<mutex> l{m};
      cv.wait(l, [this] { return !b && cur % 2 == 1; });
      if (cur <= n) {
        printNumber(cur++);
      }
      b = true;
      cv.notify_all();
    }
  }

 private:
  int n;
  int cur = 1;
  mutex m;
  condition_variable cv;
  bool b = true;
};
