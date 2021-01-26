//1.27这个板子是正确的。
#include<cstdio>
#include<bits/stdc++.h>
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)
#define swap(x,y) x ^= y, y ^= x, x ^= y
#define LL long long 
const int MAXN = 3 * 1e6 + 10, P = 998244353, G = 3, Gi = 332748118; 
char buf[1<<21], *p1 = buf, *p2 = buf;
using namespace std;
inline int read() { 
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int N, M, limit = 1, L, r[MAXN];
LL a[MAXN], b[MAXN], c[MAXN];
inline LL fastpow(LL a, LL k) {
    LL base = 1;
    while(k) {
        if(k & 1) base = (base * a ) % P;
        a = (a * a) % P;
        k >>= 1;
    }
    return base % P;
}
inline void NTT(LL *A, int type) {
    for(int i = 0; i < limit; i++) 
        if(i < r[i]) swap(A[i], A[r[i]]);
    for(int mid = 1; mid < limit; mid <<= 1) {  
        LL Wn = fastpow( type == 1 ? G : Gi , (P - 1) / (mid << 1));
        for(int j = 0; j < limit; j += (mid << 1)) {
            LL w = 1;
            for(int k = 0; k < mid; k++, w = (w * Wn) % P) {
                 int x = A[j + k], y = w * A[j + k + mid] % P;
                 A[j + k] = (x + y) % P,
                 A[j + k + mid] = (x - y + P) % P;
            }
        }
    }
}
constexpr int ADD = 30000;
int main() {
    int n, x, up = 30000 * 2 + 10, m, t;
    while(limit <= up * 2) limit <<= 1 , L++;
    for(int i = 0; i < limit; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));  
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        x += ADD;
        a[x]++;
    }
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> c[i];
        c[i] += ADD;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> x;
        x += ADD;
        b[x]++;
    }
    NTT(a , 1);NTT(b , 1);
    for(int i = 0; i < limit; i++) a[i] = (a[i] * b[i]) % P;
    NTT(a, -1); 
    LL inv = fastpow(limit, P - 2);
    for(int i = 0; i <= 120000; i++)
        a[i] = a[i]*inv%P;
    int ans = 0;
    for(int i = 1; i <= t; i++){
        ans += a[2* c[i]];
    }
    cout << ans << endl;
    /*N = read(); M = read();
    for(int i = 0; i <= N; i++) a[i] = (read() + P) % P;
    for(int i = 0; i <= M; i++) b[i] = (read() + P) % P;
    while(limit <= N + M) limit <<= 1, L++;
    for(int i = 0; i < limit; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));  
    NTT(a, 1);NTT(b, 1);    
    for(int i = 0; i < limit; i++) a[i] = (a[i] * b[i]) % P;
    NTT(a, -1); 
    LL inv = fastpow(limit, P - 2);
    for(int i = 0; i <= N + M; i++)
        printf("%d ", (a[i] * inv) % P);
    */
    return 0;
}