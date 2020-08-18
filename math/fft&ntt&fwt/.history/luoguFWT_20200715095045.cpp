#include <bits/stdc++.h>
#define MAXN 1<<18
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
}

void UFWT(int a[], int n, int op) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                // xor:
                if (op == 1)
                    // a[i + j] = 1LL * (x + y) * REV % MOD,
                    // a[i + j + d] = (1LL * (x - y) * REV % MOD + MOD) % MOD;
                // and:
                if (op == 2) a[i + j] = x - y;
                // or:
                if (op == 3) a[i + j + d] = y - x;
            }
}
void solve(int a[], int b[], int n, int op) {
    FWT(a, n, op);
    FWT(b, n, op);
    for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * b[i] % MOD;
    UFWT(a, n, op);
}
int n , m , A[MAXN], B[MAXN], a[MAXN], b[MAXN];
void reflush(){
    for(int i = 0; i < n; i++) a[i] = A[i], b[i] = B[i];
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0) , cout.tie(0);
    cin >> m;
    n = 1 << m;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    reflush(); 
    solve(a, b , n , 3);
    for(int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n-1];
    }
    
    reflush(); 
    solve(a, b , n , 2);
    for(int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n-1];
    }
    
    reflush(); 
    solve(a, b , n , 1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n-1];
    }
    
    return 0;
}
