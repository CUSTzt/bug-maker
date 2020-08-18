#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

const int N = 50005;
int n, top, idx, ans[N];
struct Line {
    int id;
    double k, b;
    bool operator<(const Line &obj) const {
        return k != obj.k ? k < obj.k : b < obj.b;
    }
} raw[N], line[N], stk[N];
double getx(const Line &A, const Line &B) { return (B.b - A.b) / (A.k - B.k); }
void solve() {
    cin >> n;
    top = 0;
    for (int i = 1; i <= n; i++) {
        cin >> raw[i].b >> raw[i].k;
        raw[i].id = i, raw[i].b = -raw[i].b;
    }
    sort(raw + 1, raw + n + 1);
    line[idx = 1] = raw[1];
    for (int i = 2; i <= n; i++)
        line[raw[i].k == raw[i - 1].k ? idx : ++idx] = raw[i];
    for (int i = 1; i <= idx; i++) {
        while (top > 1 &&
               getx(line[i], stk[top]) <= getx(stk[top], stk[top - 1]))
            top--;
        stk[++top] = line[i];
    }
    for (int i = 1; i <= top; i++) ans[i] = stk[i].id;
    cout << top << endl;
}

int main() {
    // IOS
    int nol_cl = clock();

    freopen("leading-robots.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int _;
    cin >> _;
    while (_--) solve();
    printf("Time: %dms\n",
           int32_t((clock() - nol_cl) / (long double)CLOCKS_PER_SEC * 1000));
    cout << endl;
}
