/*************************************
 * Author : miniLCT
 * More : You build it. You run it
 ************************************/
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#define ll long long
#define int long long 
#define INF 0x3f3f3f3f 
#define lowbit(x) (x)&(-x)
#define FOR(i,f_start,f_end) for(int i=f_start;i<=f_end;++i) 
#define MT(x,i) memset(x,i,sizeof(x))
#define close std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1000000009;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const double E = exp(1);
const double EPS=1e-8;
const int maxn = 1e6+10;
long long multi(long long a,long long b,long long mod) {
    long long ret=0;
    while(b) {
        if(b&1)
            ret=(ret+a)%mod;
        a=(a<<1)%mod;
        b=b>>1;
    }
    return ret;
}
long long quickPow(long long a,long long b,long long mod) {
    long long ret=1;
    while(b) {
        if(b&1)
            ret=multi(ret,a,mod);  //直接相乘的话可能会溢出
        a=multi(a,a,mod);
        b=b>>1;
    }
    return ret;
}
int phi(int n){
    int ans = n;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            ans = ans / i *(i-1);
            while(n%i == 0)n/=i;
        }
    }
    if(n > 1) ans =ans / n * (n-1);  //质数
    return ans;
}
main()
{
    int kase = 0;
    int L;
    while(~scanf("%lld", &L)&& L){
        int d = __gcd(8ll, L);
        int n = 9*L / d;
        if(__gcd(10ll, n )!=1){
            printf("Case %lld: 0\n", ++kase);
        }
        else {
            int phii = phi(n);
            int ans = phii;
            int flag = 0;
            //int phii = phi(n);
            int m = sqrt(1.0*phii);
            for(int i = 1; i <= m;i++){
                if(phii % i == 0&&quickPow(10,i,n)==1){
                    flag = 1;
                    ans = i;
                    break;
                }
            }
            if(flag == 0){
                for(int i = m; i >= 2 ;i--){
                    if(phii % i==0&&quickPow(10,phii/i,n)==1){
                        ans = phii / i;
                        break;
                    }
                }
            }
            printf("Case %lld: %lld\n", ++kase, ans);
        }
    }
}