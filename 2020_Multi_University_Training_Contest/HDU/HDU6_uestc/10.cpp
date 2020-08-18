#include<bits/stdc++.h>
using namespace std;
#define int __int128
#define ll __int128
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt","w",stdout);
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
// typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

const int N = 160,M = 1e4+10,MOD = 998244353;

ll fpow(ll a, ll k) { ll b = 1; for (; k; k>>=1,a=a*a%MOD) if (k&1) b=b*a%MOD; return b; }

ll a[N][N];
int g[N][N], dge[N];
ll gauss(int n) {
    ll sum = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            while (a[j][i]) {
                ll t = a[i][i] / a[j][i];
                for (int k = i; k <= n; k++) a[i][k] = (a[i][k] - a[j][k] * t);
                for (int k = i; k <= n; k++) swap(a[i][k], a[j][k]);
                sum = -sum;
            }
        }
        if (a[i][i] == 0) return 0;
        sum *= a[i][i];
    }
    return sum > 0 ? sum : -sum;
}

typedef pair<pii,int> P;
P b[M];
template <typename T>
void read(T &x) {
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    x *= f;
    return;
}
template <typename T>
void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &x : v) is >> x;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (!v.empty()) {
        os << v.front();
        for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
    }
    return os;
}
void solve(){
    memset(dge, 0, sizeof(dge));
    memset(a, 0, sizeof(a));
    memset(g, 0, sizeof(g));
    int n,m;
    //cin>>n>>m;
    read(n);read(m);
    vector<P> vec;
    for(int i=1,u,v,z;i<=m;i++){
        // cin>>u>>v>>z;
        read(u);read(v);read(z);
        b[i].fi.fi=u;
        b[i].fi.se=v;
        b[i].se=z;
        g[u][v]++, g[v][u]++;
        dge[u]++, dge[v]++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) a[i][j] = i == j ? dge[i] : -g[i][j];
    int al=gauss(n);
    ll INV=fpow(al,MOD-2);
    ll ans=0;
    for(int bit=0;bit<32;bit++){
        memset(dge, 0, sizeof(dge));
        memset(a, 0, sizeof(a));
        memset(g, 0, sizeof(g));
        for(int i=1;i<=m;i++){
            if(((b[i].se)>>bit)&1){
                int u=b[i].fi.fi,v=b[i].fi.se;
                g[u][v]++, g[v][u]++;
                dge[u]++, dge[v]++;
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) a[i][j] = i == j ? dge[i] : -g[i][j];
        ll now=gauss(n);
        ans=(ans+now*(1<<bit)%MOD)%MOD;
    }
    write(ans*INV%MOD);cout<<"\n";
    // cout<<ans*INV%MOD<<endl;
}

int32_t main(){
//    IN;
    IOS;
    int32_t _;cin>>_;
    while(_--)solve();
    return 0;
}