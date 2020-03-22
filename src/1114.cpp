class Foo {
 public:
  Foo() {}

  void first(function<void()> printFirst) {
    unique_lock<mutex> l{m};
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    b1 = true;
    cv1.notify_one();
  }

  void second(function<void()> printSecond) {
    unique_lock<mutex> l{m};
    cv1.wait(l, [this] { return b1; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    b2 = true;
    cv2.notify_one();
  }

  void third(function<void()> printThird) {
    unique_lock<mutex> l{m};
    cv2.wait(l, [this] { return b2; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  mutex m;
  condition_variable cv1;
  condition_variable cv2;
  bool b1 = false;
  bool b2 = false;
};
