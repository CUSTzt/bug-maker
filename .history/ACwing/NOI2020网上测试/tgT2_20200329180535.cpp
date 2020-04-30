// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn 100000
#define lowbit(x) (x & -x)
int n, m, op, x, y, inv[maxn], a[maxn];
struct BIT {
    int t[maxn];
    void upd(int i, int k) {
        if (!i) return;
        while (i <= n) {
            t[i] += k;
            i += lowbit(i);
        }
    }
    int ask(int x) {
        int res = 0;
        while (x) {
            res += t[x];
            x -= lowbit(x);
        }
        return res;
    }
 } bit1, bit2, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    //BIT bit1, bit2, t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t.upd(a[i], 1);
        inv[i] = i - t.ask(a[i]);
        bit1.upd(inv[i], 1);
        bit2.upd(inv[i], inv[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> op >> x;
        if (x == 1) {
            if (a[x] < a[x + 1]) {
                bit1.upd(inv[x], -1), bit1.upd(inv[x] + 1, 1);
                bit2.upd(inv[x], -inv[x]), bit2.upd(inv[x] + 1, inv[x] + 1);
                ++inv[x];
            } else {
                bit1.upd(inv[x + 1], -1), bit1.upd(inv[x + 1] - 1, 1);
                bit2.upd(inv[x + 1], -inv[x + 1]),
                    bit2.upd(inv[x + 1] - 1, inv[x + 1] - 1);
                --inv[x + 1];
            }
            swap(a[x], a[x + 1]);
            swap(inv[x], inv[x + 1]);
        } else {
            if (x >= n) {
                cout << "0\n";
                continue;
            } else {
                ll t2 = bit2.ask(n) - bit2.ask(x);
                ll t1 = bit1.ask(n) - bit1.ask(x);
                cout << t2 - t1 * x << endl;
            }
        }
    }
    return 0;
}