#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef unsigned long long ull;
#define lsiz(x) int(x.size())
#define lch rt<<1
#define rch rt<<1|1
const ll Linf = 0x7f7f7f7f7f7f7f7f;
const int Inf = 0x3f3f3f3f;
const int P = 1e9+7;
char buf[100000],*p1=buf,*p2=buf;
inline char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    int w = 1, data = 0; char ch = 0;
    while(ch != '-' && (ch < '0' || ch > '9')) ch = nc();
    if(ch == '-') w = -1, ch = nc();
    while(ch >= '0' && ch <= '9') data = data * 10 + ch - '0', ch = nc();
    return w * data;
}
ll pw(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res % P * a % P) % P;
        a = (a % P * a % P) % P;
        b >>= 1;
    }
    return res;
}
int t[2000000];
int prime[2000000], vis[2000000], tot;
void Q_prime() {
    vis[1] = 1;
    for(int i = 2; i <= 1000000; i++) {
        if(vis[i]) continue;
        if(vis[i] == 0) prime[++tot] = i, t[i] = 1;
        for(int j = 2; i * j <= 1000000; j++) {
            vis[i * j] = 1;
            int cnt = 0, tmp = i * j;
            while(tmp % i == 0) cnt++, tmp /= i;
            t[i * j] += cnt;
        }
    }
}
int main() {
    #ifdef ONLINE_JUDGE
    #else
        freopen("input","r",stdin);
    #endif
    Q_prime();
    int _ = read();
    while(_--) {
        int n = read(), c = read();
        cout << pw(c, t[n]) << endl;
    }
    return 0;
}