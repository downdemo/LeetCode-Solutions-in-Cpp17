class FooBar {
 public:
  FooBar(int n) { this->n = n; }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> l{m};
      cv1.wait(l, [this] { return b1; });
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      b1 = false;
      b2 = true;
      cv2.notify_one();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> l{m};
      cv2.wait(l, [this] { return b2; });
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      b1 = true;
      b2 = false;
      cv1.notify_one();
    }
  }

 private:
  int n;
  mutex m;
  condition_variable cv1;
  condition_variable cv2;
  bool b1 = true;
  bool b2 = false;
};
