#include<bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<pair<ll,ll>>q;
ll n , k , a;
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a;
        q.push({-a, 0});
    }
    while((n-1)%(k-1)){n++, q.push({0,0});}
    ll ans = 0;
    while(q.size()>1){
        ll num = 0, w= 0;
        for(int i = 1; i <= k; i++){
            num+=q.top().first;
            w=min(w,q.top().second);q.pop();
        }
        ans += -num;
        q.push({num,w-1});
    }
    cout << ans << endl << -q.top().second << endl;
}