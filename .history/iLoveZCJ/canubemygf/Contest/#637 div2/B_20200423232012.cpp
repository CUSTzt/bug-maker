// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , k , a[N], b[N];
void up() {
    cin >> n>> k;
    vector <int>vis(n+10,0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        b[i] = a[i] - a[i-1];
    }
    for(int i = 2; i < n;i++){
        if(b[i]>0&&a[i+1] <0){
            vis[i] = 1;
        }
        
    }
    int le = 1, mx = 0;
    for(int i = 2;i <= k; i++){
        if(vis[i])mx++;
    }
    int tp = mx;
    for(int i = k+1; i < n; i++){
        if(vis[i]){
            tp++;
        }
        if(vis[i-k])tp--;
        if(tp > mx){
            le = i-k+1;
            mx = tp;
        }
    }
    cout << mx + 1 << ' ' << le << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}