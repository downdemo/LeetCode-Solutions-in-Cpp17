class H2O {
 public:
  H2O() {}

  void hydrogen(function<void()> releaseHydrogen) {
    unique_lock<mutex> l{m1};
    cv.wait(l, [this] { return n < 2; });
    ++n;
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    cv.notify_one();
  }

  void oxygen(function<void()> releaseOxygen) {
    unique_lock<mutex> l{m2};
    cv.wait(l, [this] { return n >= 0; });
    n -= 2;
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    cv.notify_one();
  }

 private:
  int n = 0;
  mutex m1;
  mutex m2;
  condition_variable cv;
};
