//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 10007;
const int N = 4e4+100;
map<int , int > mp;
int val[N], v[N], bl[N], m, blo, cnt[N], n, id;
int f[505][505];
std::vector<int> vec[N];
void pre(int x){
    memset(cnt , 0 , sizeof cnt);
    int mx = 0 , ans = 0;
    for(int i = (x-1) * blo + 1; i <= n; i++){
        cnt[v[i]]++;
        int t = bl[i];
        if(cnt[v[i]] > mx || (cnt[v[i]] == mx && val[v[i]] < val[ans])){
            ans = v[i], mx = cnt[v[i]];
        }
        f[x][t] = ans;
    }
}
int query(int l , int r, int x){
    return upper_bound(vec[x].begin(),vec[x].end(),r)-lower_bound(vec[x].begin(),vec[x].end(),l);
}
int query(int a , int b){
    int ans , mx;
    ans = f[bl[a]+1][bl[b]-1];
    mx = query(a, b , ans);
    for(int i = a; i <= min(bl[a] * blo, b); i++){
        int t = query(a , b , v[i]);
        if(t > mx || (t == mx && val[v[i]] < val[ans])) ans = v[i], mx = t;
    }
    if(bl[a] != bl[b]){
        for(int i = (bl[b] - 1) * blo; i <= b; i++){
            int t = query(a , b , v[i]);
            if(t > mx || (t == mx && val[v[i]] < val[ans])) ans = v[i], mx = t;
        }
    }
    return ans;
}
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
     blo = sqrt(n);
    //blo = 233;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(mp[v[i]] == 0){
            mp[v[i]] = ++id;
            val[id] = v[i];
        }
        v[i] = mp[v[i]];
        vec[v[i]].emplace_back(i);
    }
    for(int i = 1; i <= n; i++){
        bl[i] = (i-1) / blo+1;
    }
    for(int i = 1; i <= bl[n]; i++) pre(i);
    int xx = 0;
    for(int i = 1; i <= m; i++){
        int a , b ;
        cin >> a >> b;
        a = (xx + a - 1) % n+1;
        b = (xx + b - 1) % n+1;
        if(a > b)swap(a, b);
        xx = val[query(a, b)];
        cout << xx << endl; 
    }
    return 0;
}