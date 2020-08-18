#include <bits/stdc++.h>
#define MAXN 1 << 18
#define int long long 
#define INF 1000000000
#define MOD 998244353
#define REV 499122177
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
void FWT(int a[], int n, int op) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                // xor:
                if (op == 1)
                    a[i + j] = (x + y) % MOD,
                    a[i + j + d] = (x - y + MOD) % MOD;
                // and:
                if (op == 2) a[i + j] = x + y;
                // or:
                if (op == 3) a[i + j + d] = x + y;
            }
    for(int i = 0; i < n; i++) a[i] %= MOD;
}

void UFWT(int a[], int n, int op) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                // xor:
                if (op == 1)
                    a[i + j] = 1LL * (x + y) * REV % MOD,
                    a[i + j + d] = (1LL * (x - y) * REV % MOD + MOD) % MOD;
                // and:
                if (op == 2) a[i + j] = x - y;
                // or:
                if (op == 3) a[i + j + d] = y - x;
            }
}
void solve(int a[], int b[], int n, int op) {
    FWT(a, n, op);
    FWT(b, n, op);
    for (int i = 0; i < n; i++) a[i] %= MOD,  b[i] %= MOD;
    for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * b[i] % MOD;
    UFWT(a, n, op);
    for(int i = 0; i < n; i++) {while(a[i] < 0) a[i] += MOD; a[i] %= MOD;}
    for(int i = 0; i < n; i++) cout << a[i] << " \n"[i == n-1];
}
int n , m, A[MAXN], B[MAXN], a[MAXN], b[MAXN], x, c[MAXN], res[MAXN];
void reflush(){
    for(int i = 0; i < n; i++)a[i] = A[i], b[i] = B[i];
}
int32_t main() { 
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        a[x] ++;
    }
    FWT(a, MAXN, 1);
    for(int i = 0; i < MAXN; i++){
        b[i] = a[i], c[i] = 1;
    }
    for(int t = 1; t <= 19; t++){
        for(int j = 0; j < MAXN; j++){
            c[j] = 1ll * c[j] * b[j] % MOD;
            a[j] = c[j];
        }
        FWT(a, MAXN, 1);
        for(int j = MAXN-1; ~j; j--){
            if(a[j] % MOD) {
                res[t] = j;
                break;
            }
        }
    }
    for(int t = 20; t <= n; t++) res[t] = res[t -2];
    for(int i = 1; i <= n; i++) cout << res[i] << " \n"[i == n];
    return 0; 
}
