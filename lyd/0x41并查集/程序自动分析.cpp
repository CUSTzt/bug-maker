// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int fa[N];
void init(int n) {for (int i = 0; i <= n; i++) fa[i] = i;}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void Union(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    fa[x] = y;
}
void up(){
    map<int , int > mp;
    int n, fl = 1; cin >> n;
    init( 2 * n + 10);
    int u , v , op, cnt = 1, sz = 0;
    vector<int> a;
    for(int i = 1; i <= n; i++){
        cin >> u >> v >> op;
        if(mp.count(u)) u = mp[u]; else {mp[u] = cnt++;u=mp[u];}
        if(mp.count(v)) v = mp[v]; else {mp[v] = cnt++;v=mp[v];}
        if(!op){
            a.push_back(u), a.push_back(v), sz++;
        }else Union(u , v);
    }
    for(int i = 0; i < sz; i++){
        if(find(a[i*2]) == find(a[i*2+1])){fl = 0;break;}
    }
    cout << (fl ? "YES" : "NO") << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _;cin >> _;
    while(_--) up();
    return 0;
}