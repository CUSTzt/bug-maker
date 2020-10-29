#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
const int maxn = 25;
struct node {
    int t1, t2, t3;
    // friend bool operator<(node a, node &b) { return a.t3 < b.t3; }
} q[10086];
bool cmp(node a , node b){
    return a.t3 < b.t3;
}
int f[maxn], e[maxn][maxn];
int getf(int x) { return f[x] == x ? x : (f[x] = getf(f[x])); }
map<string, int> m;
vector<int> s;
int main() {
    for (int i = 1; i < 22; i++) f[i] = i;
    for (int i = 1; i < 22; i++)
        for (int j = 1; j < 22; j++) e[i][j] = 1e9;
    int n;
    scanf("%d", &n);
    m["Park"] = 1;
    int tot = 2;
    for (int i = 1; i <= n; i++) {
        string t1, t2;
        int t3;
        cin >> t1 >> t2 >> t3;
        if (m[t1] == 0) m[t1] = tot++;
        if (m[t2] == 0) m[t2] = tot++;
        e[m[t1]][m[t2]] = e[m[t2]][m[t1]] = min(e[m[t1]][m[t2]], t3);
    }
    for (int i = 2; i < tot; i++)
        if (e[1][i] != 1e9) s.push_back(i);
    n = 0;
    for (int i = 1; i < tot; i++)
        for (int j = i + 1; j < tot; j++) {
            if (e[i][j] != 1e9) q[++n] = (node){i, j, e[i][j]};
        }
    sort(q + 1, q + 1 + n, cmp);
    int t = s.size();
    int ans = 1e9;
    int k;
    scanf("%d", &k);
    for (int h = 1; h < (1 << t); h++) {
        int cnt = 0, sum = 0, temp = 0, x = 0;
        for (int i = 0; i < t; i++) {
            if (h & (1 << i)) x += (1 << s[i]), cnt++;
        }
        if (cnt > k) continue;
        for (int i = 1; i < 22; i++) f[i] = i;
        for (int i = 1; i <= n; i++) {
            int t1 = getf(q[i].t1);
            int t2 = getf(q[i].t2);
            if (t1 != t2) {
                if (q[i].t1 == 1) {
                    if (x & (1 << q[i].t2)) {
                        f[t1] = t2;
                        sum++;
                        temp += q[i].t3;
                    }
                } else {
                    f[t1] = t2;
                    sum++;
                    temp += q[i].t3;
                }
            }
            if (sum == tot - 2) {
                ans = min(ans, temp);
                break;
            }
        }
    }
    printf("Total miles driven: %d\n", ans);
}