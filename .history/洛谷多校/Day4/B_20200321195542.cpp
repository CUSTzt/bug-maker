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
#define eps 1e-8
#define fi first
#define se second
#define eb emplace_back
#define close std::ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define FOR(i, x, y) for (LL i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (LL i = (x), _##i = (y); i > _##i; --i)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define CASET int ___T; scanf("%d", &___T); for(int __CS=1;__CS<=___T;__CS++)
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
int p[maxn],c[maxn];
int m ;
bool isprime(int x){
    int m = sqrt(x+0.5);
    for(int i = 2; i <=m; i++){
        if(x % i == 0)return false;
    }return true;
}
void divide(int n){
	m = 0;
	int sqrtn = sqrt(n);
	for(int i = 2; i <= sqrtn; i++){
		if(n % i == 0){  //i是质数
			p[++m] = i;
			c[m] = 0;
			while(n % i == 0)n /= i,c[m]++; // 除掉所有的i
		}
	}
	if(n > 1)//n是质数
		p[++m] = n, c[m] = 1;
	/*for(int i = 1; i <= m; i++)
		cout << p[i] << '^' << c[i] <<endl;*/
}
int main()
{
    CASET{
        int x;
        cin >> x;
        /*if(isprime(x)){
            cout << x << endl;
            continue;
        }*/
        int mn = 1;
        divide(x);
        for(int i = 1; i <= m; i++){
            int tmp = p[i],cc = 1;
            while(cc < c[i]){
                tmp+=p[i];
                int zz = tmp;
                while(zz){
                    cc+=zz/tmp;
                    zz/=tmp;
                }
            }
            mn=max(tmp,mn);
        }
        cout << mn << endl;
    }
    
}