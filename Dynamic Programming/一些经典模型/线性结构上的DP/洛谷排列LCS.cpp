// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , a[N], b[N], pos[N], f[N]; 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] , pos[a[i]] = i;
    for(int i = 1; i <= n; i++) cin >> b[i];
    int mx = 0;
    for(int i = 1; i <= n; i++){
        if(pos[b[i]] > f[mx]) f[++mx] = pos[b[i]];
        else{
            int l = 0, r = mx, mid;
            while(l < r){
                mid = (l+r) >> 1;
                if(f[mid] > pos[b[i]]) r = mid;
                else l = mid + 1;
            }
            f[l] = min(f[l], pos[b[i]]);
        }
    }
    cout << mx << endl;
    return 0;
}