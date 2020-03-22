class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int sz = prices.size();
    if (sz < 2) {
      return 0;
    }
    vector<int> hold(sz);
    vector<int> sold(sz);
    vector<int> cool(sz);
    hold[0] = -prices[0];
    for (int i = 1; i < sz; ++i) {
      hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
      sold[i] = max(cool[i - 1], sold[i - 1]);
      cool[i] = hold[i - 1] + prices[i];
    }
    return max(cool[sz - 1], sold[sz - 1]);
  }
};
