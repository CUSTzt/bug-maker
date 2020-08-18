// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
// #define mp make_pair
#define pb push_back

const double eps = 1e-8;
const int N = 1e6 + 100;
struct node {
    double pos, v;
    friend int operator<(node a, node b) {
        if (a.pos == b.pos)
            return a.v > b.v;
        else
            return a.pos > b.pos;
    }
} a[N];
pair<int, double> st[N];
map<pair<int, int>, int> mp;
double calc(double s, double a1, double a2) { return s * 2.0 / (a2 - a1); }
int cmp(double a, double b) {
    double mx = max(a, b), mn = min(a, b);
    if (fabs(mx - mn) < eps) return 0;
    if (a < b)
        return -1;
    else
        return 1;
}
void up() {
    int n;
    cin >> n;
    mp.clear();
    for (int i = 1; i <= n; i++) {
        int pos , v;
        cin >> pos >> v;
        a[i].pos = pos;
        a[i].v = v;
    }
    sort(1 + a, 1 + n + a);
    int top = 0;
    st[0] = {0, 0};
    int mx = a[1].v;
    st[++top] = {1, 0};
    mp[{(int)a[1].pos, (int)a[1].v}] = 1;
    for (int i = 2; i <= n; i++) {
        if (cmp(a[i].v, mx) < 0) continue;
        while (top &&
               cmp(st[top].second, calc(a[st[top].first].pos - a[i].pos,
                                        a[st[top].first].v, a[i].v)) >= 0)
            top--;
        st[top + 1] = {i, calc(a[st[top].first].pos - a[i].pos,
                               a[st[top].first].v, a[i].v)};
        top++;
        mp[{(int)a[i].pos, (int)a[i].v}]++;
        mx = a[i].v;
    }
    int ans = 0;
    for (int i = 1; i <= top; i++)
        if (mp[{(int)a[st[i].first].pos, (int)a[st[i].first].v}] == 1) ans++;
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}