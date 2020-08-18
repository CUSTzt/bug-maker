// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

// http://hzwer.com/8053.html
// 维护整块是不是同一个数字
const int N = 1e6 + 100;
int n, tag[N], v[N], bl[N], blo;
void reset(int x) {
    if (tag[x] == -1)
        return;
    for (int i = (x - 1) * blo + 1; i <= blo * x; i++) {
        v[i] = tag[x];
    }
    tag[x] = -1;
}
int work(int a, int b, int c) {
    int ans = 0;
    reset(bl[a]);
    for (int i = a; i <= min(bl[a] * blo, b); i++) {
        if (v[i] != c)
            v[i] = c;
        else
            ans++;
    }
    if (bl[a] != bl[b]) {
        reset(bl[b]);
        for (int i = (bl[b] - 1) * blo + 1; i <= b; i++) {
            if (v[i] != c)
                v[i] = c;
            else
                ans++;
        }
    }
    for (int i = bl[a] + 1; i <= bl[b] - 1; i++) {
        if (tag[i] != -1) {
            if (tag[i] != c)
                tag[i] = c;
            else
                ans += blo;
        } else {
            for (int j = (i - 1) * blo + 1; j <= i * blo; j++)
                if (v[j] != c)
                    v[j] = c;
                else
                    ans++;
            tag[i] = c;
        }
    }
    return ans;
}
int32_t main() {
    memset(tag, 0xff, sizeof tag);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    blo = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) bl[i] = (i - 1) / blo + 1;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << work(a, b, c) << endl;
    }
    return 0;
}