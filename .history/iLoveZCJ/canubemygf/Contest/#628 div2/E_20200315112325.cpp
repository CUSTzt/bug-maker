// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

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
            if(d[to] == INF);
        }
    }
}
int main()
{
    
    return 0;
}