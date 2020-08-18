// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 1e6 + 100;
const int mod = 10007;
template <class T>
inline void ADD(T &x, T y) {
    x += y;
    if (x >= mod) x -= mod;
}
int n,len_ , len, a[N], id[N], op, l[N], r[N], c, left, right;
int lazy[N], lazy2[N];
void push_down(int id) {
    for (int i = l[id]; i <= r[id]; i++) {
        a[i] = (a[i] * lazy2[id] + lazy[id]) % mod;
    }
    lazy2[id] = 1;
    lazy[id] = 0;  // 清空标记
}
void update1(int left, int right, int add) {  // 区间加
    if (id[left] == id[right]) {              // 在同一块内就暴力修改
        push_down(id[left]);                  // 下传标记
        for (int i = left; i <= right; i++) {
            a[i] += add;
            a[i] %= mod;
        }
        return;
    }
    for (int i = id[left] + 1; i <= id[right] - 1; i++) {  // 完整块
        ADD(lazy[i], add);
    }
    push_down(id[left]);  //在两边不完整的块修改的时候也要先下传标记再修改
    for (int i = left; i <= r[id[left]]; i++) {
        a[i] += add;
        a[i] %= mod;
    }
    push_down(id[right]);
    for (int i = l[id[right]]; i <= right; i++) {
        a[i] += add;
        a[i] %= mod;
    }
}
void update2(int left, int right, int mul) {
    if (id[left] == id[right]) {
        push_down(id[left]);
        for (int i = left; i <= right; i++) {
            a[i] = a[i] * mul % mod;
        }
        return;
    }
    for (int i = id[left] + 1; i <= id[right] - 1; i++) {
        lazy2[i] = lazy2[i] * mul % mod;
        lazy[i] = lazy[i] * mul % mod;
    }
    push_down(id[left]);
    for (int i = left; i <= r[id[left]]; i++) {
        a[i] = a[i] * mul % mod;
    }
    push_down(id[right]);
    for (int i = l[id[right]]; i <= right; i++) {
        a[i] = a[i] * mul % mod;
    }
}
int query(int x) {  // 乘在加前面
    return (a[x] * lazy2[id[x]] + lazy[id[x]]) % mod;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    len = sqrt(n);
    len_ = 3 * len;
    id[1] = 0, l[0] = 1;
    for (int i = 2; i <= n; i++) {
        id[i] = (i - 1) / len;
        if (id[i] ^ id[i - 1]) {
            l[id[i]] = i;
            r[id[i - 1]] = i - 1;
        }
    }
    for (int i = 0; i <= id[n]; i++)  //需要清空标记
    {
        lazy[i] = 0;
        lazy2[i] = 1;
    }
    r[id[n]] = n;
    int opt, left, right;
    long long x, answer;
    for (int i = 1; i <= n; i++) {
        cin >> opt >> left >> right >> x;
        if (opt == 0) {
            update1(left, right, x);
        }
        if (opt == 1) {
            update2(left, right, x);
        }
        if (opt == 2) {
            // for(int i = 1;i <= n; i++){
            //     cout << a[i] << " \n"[i == n];
            // }
            // cout << "lazy == " << lazy[id[right]] << "   lazy2 === " << lazy2[id[right]] << endl;
            cout << query(right) << endl;
        }
    }
    return 0;
}