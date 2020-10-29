#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define eps 1e-8
typedef long long ll;
const double PI = acos(-1.0);
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int a[maxn][32];    //前缀线性基
int pos[maxn][32];  //第i位是1对应哪个元素
void Insert(int id, int t, int p) {
    for (int j = 31; j >= 0; j--) {
        if (!(t & (1 << j))) continue;
        if (!a[j]) {
            a[id][j] = t;
            pos[id][j] = p;
            break;
        }
        if (pos[id][j] < p) {
            swap(pos[id][j], p);
            swap(a[id][j], t);
        }
        t ^= a[id][j];
    }
}
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 31; j >= 0; j--) {
            pos[i][j] = pos[i - 1][j];
            a[i][j] = a[i - 1][j];
        }
        Insert(i, x, i);
    }
    scanf("%d", &m);
    while (m--) {
        int ans = 0;
        int l, r;
        scanf("%d%d", &l, &r);
        if (l > r) swap(l, r);
        ans = 0;
        for (int j = 31; j >= 0; j--) {
            if (pos[r][j] < l) continue;
            ans = max(ans, ans ^ a[r][j]);
        }
        printf("%d\n", ans);
    }
    return 0;
}