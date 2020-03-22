class FizzBuzz {
 public:
  FizzBuzz(int n) { this->n = n; }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    unique_lock<mutex> l{m};
    while (cur <= n) {
      cv.wait(l, [this] { return cur > n || (cur % 3 == 0 && cur % 5 != 0); });
      if (cur <= n) {
        printFizz();
        ++cur;
      }
      cv.notify_all();
    }
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {
    unique_lock<mutex> l{m};
    while (cur <= n) {
      cv.wait(l, [this] { return cur > n || (cur % 5 == 0 && cur % 3 != 0); });
      if (cur <= n) {
        printBuzz();
        ++cur;
      }
      cv.notify_all();
    }
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz) {
    unique_lock<mutex> l{m};
    while (cur <= n) {
      cv.wait(l, [this] { return cur > n || (cur % 3 == 0 && cur % 5 == 0); });
      if (cur <= n) {
        printFizzBuzz();
        ++cur;
      }
      cv.notify_all();
    }
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {
    unique_lock<mutex> l{m};
    while (cur <= n) {
      cv.wait(l, [this] { return cur > n || (cur % 3 != 0 && cur % 5 != 0); });
      if (cur <= n) {
        printNumber(cur);
        ++cur;
      }
      cv.notify_all();
    }
  }

 private:
  int n;
  int cur = 1;
  mutex m;
  condition_variable cv;
};
