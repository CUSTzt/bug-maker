// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int INF = 0x3f3f3f3f;
const int N = 1e6+100;
const int MOD = 1e9+7;
vector<int > v[N];
int prime[N], isprime[N];
int sieve(int n){
    int p = 0;
    for(int i = 0; i <= n; i++){
        isprime[i] = 1;
    }
    isprime[0]=isprime[1] = false;
    for(int i =2; i<=n ; i++){
        if(isprime[i])prime[p++] = i;
        for(int j = 0; j  < p ; j++){
            if(prime[j]*i > n)break;
            isprime[prime[j]*i]=false;
            if(i % prime[j] == 0)break;
        }
    }
    return p;
}
vector <int > G[N],tmp ;
int a[N], fa[N], n , is_square, k;
int ans , cnt , d[N];
void bfs(int x){
    tmp.clear();
    d[x] = 0;
    queue<int >q;
    q.push(x);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        tmp.pb(v);
        for(auto to : G[v]){
            if(d[to] == INF){
                d[to] = d[v] + 1;
                fa[to] = v;
                q.push(to);
            }else if(to!=fa[v] && v!=fa[to]) ans = min(ans , d[v]+d[to]+1);
        }
    }for(auto x : tmp)d[x] = INF, fa[x] = -1;
}
int main()
{
    int  p  = sieve(N);
    memset(is_square , 0 , size)
    cin >> n;


    return 0;
}