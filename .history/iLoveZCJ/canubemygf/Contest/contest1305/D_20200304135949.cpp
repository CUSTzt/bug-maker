#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
vector<vector<int >> e;
vector<int > deg;
int n ;
int main()
{
    ios::sync_with_stdio(flase);
    cin.tie(nullptr);
    cin >> n;
    e.resize(n);
    deg.resize(n);
    for(int i =0 ; i < n ; i++){
        int u , v;
        cin >> u >> v;
        --u , --v;
        e[u].push_back(v);
        e[v].push_back(u);
        ++deg[u],++deg[v];
    }
    int res = n;
    while(res > 1){
        int u , v;
        for(u = )
    }
    return 0;
}