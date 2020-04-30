#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
using LL = long long;
#define int long long
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%lld", &___T); for(int __CS=1;__CS<=___T;__CS++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 dlsrand(random_device{}());
mt19937 mrand(std::chrono::system_clock::now().time_since_epoch().count()); 
int rnd(int x) { return mrand() % x;}
LL bin(LL x, LL n, LL MOD) {LL ret = MOD != 1;for (x %= MOD; n; n >>= 1, x = x * x % MOD)if (n & 1) ret = ret * x % MOD;return ret;}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
const double PI = acos(-1.0);
constexpr int maxn = 1e6+10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7;
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
char tmp[maxn];
int len[maxn];
int init(char *st)
{
    int i,l=strlen(st);
    tmp[0]='@';
    for(i=1;i<=2*l;i+=2)
    {
        tmp[i]='#';
        tmp[i+1]=st[i/2];
    }
    tmp[2*l+1]='#';
    tmp[2*l+2]='$';
    tmp[2*l+3]=0;
    return 2*l+1;
}
int manacher1(char *st,int Len)
{
    int mx=0,ans=0,po=0;
    for(int i=1;i<len;i++)//mx最大回文串右边一个
    {
        if(mx>i)
            len[i]=min(mx-i,len[2*po-1]);
        else
            len[i]=1;
            len[i]++;
        if(len[i]+i>mx)
        {
            mx=len[i]+i;
            po=i;
        }
        ans=max(ans,len[i]);
    }
    return ans-1;
}
bool check(char c){
    if(c >= 'a' && c <= 'z'){
        return true;
    }return false;
}
char b[maxn], aa[maxn],ss[maxn];
int ZZ[maxn];
int lenb = 0, ans1,ans2, ret , mx, id , mm;
void work(int n){
    ss[++mm]='^';
    ss[++mm]='$';
    for(int i = 1; i <= n;i++){
        ss[++mm] = aa[i];
        ss[++mm] = '$';
    }
}
int main()
{
    CASET{
        scanf("%s", b+1);
        lenb = strlen(b+1);
        while(b[ans1+1]==b[lenb-ans1]){
            if(ans1 + 1 <= lenb / 2){
                ans1++;
            }else break;
        }
        for(int i = 1; i <= ans1 ; i++){
            cout << b[i];
        }
        for(int i = ans1+1; i <= lenb-ans1; ++i){
            aa[++ans2] = b[i];
        }
        WORK(ans2);
        for(int i = ans1; i>=1; --i){
            cout << b[i];
        }cout << endl;
    }
    
}