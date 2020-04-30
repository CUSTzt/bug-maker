// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn 1000100
#define lowbit(x) x&(-x)
int n, m, op, x, y, inv[maxn], a[maxn];
struct BIT {
    int t[maxn];
    void upd(int i, int k) {
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
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    BIT bit1, bit2 , 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    return 0;
}