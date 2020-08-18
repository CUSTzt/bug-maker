#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N1 = 1e2 + 11, N2 = 1e3 + 10;
const int INF = 0x3f3f3f3f;
 
int head[N1], to[N2], nex[N2], cap[N2], cnt;
 
int dis[N1], n, m, s, t;
 
inline ll read() {
  ll f = 1, x = 0;
  char c = getchar();
  while(c < '0' || c > '9') {
    if(c == '-')    f = -1;
    c = getchar();
  }
  while(c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f * x;
}
 
void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
}
 
void add(int x, int y, int w) {
    to[cnt] = y;
    nex[cnt] = head[x];
    cap[cnt] = w;
    head[x] = cnt++;
}
 
bool bfs() {
    memset(dis, -1, sizeof dis);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        if(temp == t)   return true;
        for(int i = head[temp]; ~i; i = nex[i]) {
            if(dis[to[i]] == -1 && cap[i]) {
                dis[to[i]] = dis[temp] + 1;
                q.push(to[i]);
            }
        }
    }
    return false;
}
 
int dfs(int rt, int f) {
    if(rt == t) return f;
    int delta = f;
    for(int i = head[rt]; ~i; i = nex[i]) {
        if(dis[to[i]] == dis[rt] + 1) {
            int temp = dfs(to[i], min(delta, cap[i]));
            cap[i] -= temp;
            cap[i ^ 1] += temp;
            delta -= temp;
        }
        if(delta == 0)  break;
    }
    return f - delta;
}
 
int Dinic() {
    int ans = 0;
    while(bfs()) ans += dfs(s, INF);
    return ans;
}
 
int main() {
    // freopen("in.txt", "r", stdin);
    while(scanf("%d %d", &n, &m) != EOF) {
      init();
      s = 0, t = n << 1 | 1;
      int sum = 0;
      for(int i = 1; i <= n; i++) {
        int temp = read();
        sum += temp;
        add(0, i, temp);
        add(i, 0, 0);
        add(i + n, t, temp);
        add(t, i, 0);
      }
      for(int i = 1; i <= m; i++) {
        int x = read(), y = read();
        add(x, y + n, 1);
        add(y + n, x, 0);
        add(y, x + n, 1);
        add(x + n, y, 0);
      }
      puts(Dinic() != sum ? "No" : "Yes");
    }
    return 0;
}