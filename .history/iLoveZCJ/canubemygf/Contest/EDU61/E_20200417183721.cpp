// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

ll a[100], ans, n;
void dfs(ll x, ll now){
    if(x == 9){
        ans = max(ans , now);
    }
}
void up(){
    cin >> n;
    for(int i = 1; i <= 8; i++){
        cin >> a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    up();   
    return 0;
}