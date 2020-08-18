// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , a[N], k;
void up() {
    // cin >> n >> k;
    // for(int i = 1; i <= n; i++){
    //     cin >> a[i];
    // }
    // vector<int>v;
    // int sum = 0;
    // v.pb(0);
    // for(int i = 1; i <= k; i++){
    //     v.pb(a[i]);
    //     sum += a[i];
    // }
    
    // for(int i = k+1; i <= n; i++){
    //     v.pb(a[i-k]);
    //     v.pb(a[i]);
    // }
    // int fl = 0;
    // int si = v.size();
    // int tp = sum;
    // for(int i = k+1; i < si;i++){
    //     tp-=v[i-k];
    //     tp+=v[i];
    //     if(tp!=sum){fl = 1;break;}
    // }
    // if(!fl){
    //     cout << v.size()-1 << endl;;
    //     for(int i = 1; i < si; i++){
    //         cout << v[i] << ' ';
    //     }cout << endl;
    // }else {
    //     cout << -1 << endl;
    // }
    cin >> n >> k;
    vector<int > a(n+10);
    map<int , int > zz;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        zz[a[i]]++;
    }
    if(zz.size()>k){
        cout << -1 << endl;
        return ;
    }
    vector<int > c;
    for(auto it : zz){
        c.pb(it.ff);
    }
    for(int i = 1; i <= n; i++){
        if(c.size() >= k)break;
        if(zz.count(i) == 0){
            c.pb(i);
        }
    }
    int zb = 1;
    cout << n*c.size() << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < c.size(); j++){
            cout << c[j] << ' ';
            zb++;
        }
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}