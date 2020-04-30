// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
struct node{
    int u , v;
    ll cost;
    node(){}
    node(int u , int v , ll cost){
        u=u,v=v,
    };
}edge[N];
bool cmp(const node a , const node b){
    return a.cost < b.cost;
}
int n , m ;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}