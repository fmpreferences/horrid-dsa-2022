#include <bits/stdc++.h>

#define rep(i, s, f) for (size_t i = (s); i < (f); i++)
#define repeach(t, i, j) for (t i : j)
#define repv(i, s, f, v) for (size_t i = (s); i < (f); i += (v))
#define mpr(a, b) make_pair((a), (b))
#define printeach(a)                                                           \
  for (const auto x : (a))                                                     \
  std::cout << x << ' '
#define ntuple(n) array<int, n>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using t3 = ntuple(3);

signed main() {
  int n, e;
  cin >> n >> e;
  vector<vector<pii>> adj(n, vector<pii>());
  rep(i, 0, e) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(mpr(v, w));
  }

  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  priority_queue<pii, vector<pii>, function<bool(pii, pii)>> q(
      [](pii a, pii b) -> bool { return a.second < b.second; });
  q.emplace(mpr(0, 0));
  while (!q.empty()) {
    auto t = q.top();
    auto u = t.first;
    q.pop();
    for (auto v: adj[u]) {
      auto nd = dist[u] + v.second;
      if (nd < dist[v.first]) {
        q.emplace(mpr(v.first, nd));
        dist[v.first] = nd;
      }
    }
  }
  printeach(dist);
}

// 8 16 0 1 5 0 4 9 0 7 8 1 2 12 1 3 15 1 7 4 2 3 3 2 6 11 3 6 9 4 5 4 4 6 20 4 7 5 5 2 1 5 6 13 7 5 6 7 2 7