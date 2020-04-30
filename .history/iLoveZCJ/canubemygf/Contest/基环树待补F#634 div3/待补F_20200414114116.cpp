// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
string c[N], mp[N];
int n , m , vis[N], cnt[N], ans , res;
vector<int > G[N], rG[N], black;
void add_edge(int u , int v){
	G[u].pb(v);
	rG[v].pb(u);
}
int get_id(int x, int y){
	return x * m + y;
}

void up() {
	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _; cin >> _; while (_--) up();
	return 0;
}