#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int const N = 1234567;
int const INF = 1 << 30;
int sz[N], d[N], killed[N], countThem[N + N], val[N], q[N], parent[N];
long long add[N];
long long paths[N];
vector<int> edges[N];
int n;
vector<int> children;
void dfs(int v, int pv) {
  sz[v] = 1;
  d[v] = -INF;
  int len = (int) edges[v].size();
  for (int it = 0; it < len; it++) {
    int to = edges[v][it];
    if (to == pv || killed[to]) continue;
    dfs(to, v);
    sz[v] += sz[to];
  }
}
void go(int v) {
  dfs(v, -1);
  int all = sz[v];
  {
    int pv = -1;
    while (true) {
      bool changed = false;
      int len = (int) edges[v].size();
      for (int it = 0; it < len; it++) {
        int to = edges[v][it];
        if (killed[to] || to == pv) continue;
        if (sz[to] * 2 >= all) {
          pv = v;
          v = to;
          changed = true;
          break;
        }
      }
      if (!changed) break;
    }
  }
  // printf("centroid = %d\n", v);
  auto f = [&](){
    for (int i = n - all; i <= n + all; i++) {
      countThem[i] = 0;
    }
    bool addRoot = false;
    d[v] = val[v];
    for (int start : children) {
      if (killed[start]) continue;
      if (start == v) {
        countThem[val[v] + n]++;
        addRoot = true;
        continue;
      }
      int head = 0;
      int tail = 0;
      q[tail++] = start;
      d[start] = val[start];
      parent[start] = v;
      while (head < tail) {
        int cur = q[head++];
        int need = -d[cur] - 1 + n;
        add[cur] = (need >= 0 ? countThem[need] : 0) + (need >= 1 ? countThem[need - 1] : 0);
        // printf("add[%d] = %lld\n", cur, add[cur]);
        int len = (int) edges[cur].size();
        for (int it = 0; it < len; it++) {
          int to = edges[cur][it];
          if (killed[to] || d[to] != -INF) continue;
          d[to] = d[cur] + val[to];
          parent[to] = cur;
          q[tail++] = to;
        }
      }
      for (int i = tail - 1; i >= 0; i--) {
        // printf("parent[%d] = %d\n", q[i], parent[q[i]]);
        int len = (int) edges[q[i]].size();
        for (int it = 0; it < len; it++) {
          int to = edges[q[i]][it];
          if (killed[to] || to == parent[q[i]]) continue;
          add[q[i]] += add[to];
          // printf("add[%d] += add[%d] = %lld\n", q[i], to, add[to]);
        }
        paths[q[i]] += add[q[i]];
        // printf("paths[%d] += %lld\n", q[i], add[q[i]]);
      }
      if (addRoot) {
        paths[v] += add[start];
        // printf("paths[%d] += %lld\n", v, add[start]);
      }
      for (int i = 0; i < tail; i++) {
        countThem[d[q[i]] + val[v] + n]++;
        d[q[i]] = -INF;
      }
    }
  };
  children.resize(edges[v].size() + 1);
  int len = (int) edges[v].size();
  for (int i = 0; i < len; i++) {
    children[i] = edges[v][i];
  }
  children.back() = v;
  f();
  reverse(children.begin(), children.end());
  f();
  killed[v] = true;
  for (int to : edges[v]) {
    if (killed[to]) continue;
    go(to);
  }
}
int read() {
  int c = getchar();
  while (c <= 32) c = getchar();
  int x = 0;
  while (c > 32) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
int main() {
  int x;
  n = read();
  x = read();
  for (int i = 0; i + 1 < n; i++) {
    int v = read();
    int u = read();
    --v;
    --u;
    edges[v].push_back(u);
    edges[u].push_back(v);
  }
  for (int i = 0; i < n; i++) {
    int y = read();
    val[i] = y >= x ? 1 : -1;
  }
  go(0);
  long long best = 0;
  for (int i = 0; i < n; i++) {
    // printf("paths[%d] = %lld\n", i, paths[i]);
    if (val[i] == -1 && paths[i] > best) {
      best = paths[i];
    }
  }
  printf("%lld\n", best);
}
