// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxn = 1e6+100;

int n;// a[maxn];
void up() {
    cin >> n;
    vector<int>a(n);
    map<int , int > MP;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum+=abs(a[i]);
        MP[a[i]]++;
    }
    ll ans = LONG_LONG_MAX;
    sort(a.begin(),a.end());
    for(int i = 0; i <= n; i++){
        ll tmp = sum;
        if(a[i] < 0){

        }else {

        }
        ans = min(tmp , ans)
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}