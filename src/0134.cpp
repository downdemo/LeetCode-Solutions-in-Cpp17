class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int res = 0;
    int mn = INT_MAX;
    int x = 0;
    for (int i = 0; i < gas.size(); ++i) {
      x += gas[i] - cost[i];
      if (x < mn) {
        mn = x;
        res = i;
      }
    }
    if (x < 0) {
      return -1;
    }
    if (res == gas.size() - 1) {
      return 0;
    }
    return res + 1;
  }
};
