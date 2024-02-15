#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll n;
ll ans = 0;
ll mx_val = 0;

ll CalcSum(const vl& u) {
  auto ret = 0LL;
  for (auto i = 0; i < 5; ++i) {
    for (auto j = i + 1; j < 5; ++j) {
      for (auto k = j + 1; k < 5; ++k) {
        auto s = u[i] + u[j] + u[k];
        s %= 10;
        if (ret < s) {
          ret = s;
        }
      }
    }
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;

  for (auto i = 1LL; i <= n; ++i) {
    vl u(5);
    for (auto&& x : u) {
      cin >> x;
    }

    const auto& t = CalcSum(u);

    if (mx_val <= t) {
      mx_val = t;
      ans = i;
    }
  }

  cout << ans;

  return 0;
}