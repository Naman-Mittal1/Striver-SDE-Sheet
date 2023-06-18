#include <bits/stdc++.h>

vector<int> findSpans(vector<int> &price) {
  stack<pair<int, int>> s;
  vector<int> ans(price.size());

  for (int i = 0; i < price.size(); i++) {
    int span = 1;
    while (s.size() and s.top().first <= price[i]) {
      span += s.top().second;
      s.pop();
    }
    s.push({price[i], span});
    ans[i] = span;
  }
  return ans;
}