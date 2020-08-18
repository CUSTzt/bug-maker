#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
struct rbtree: tree<T,null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>{};
#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt","w",stdout);
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const ll inf = 0x3f3f3f3f3f3f3f3f;

rbtree<pii> rbt;

int n,l,k;

ll solve(VI a){
    ll sum=0;
    for(int i=0;i<n;i++){
        rbt.insert({a[i],i});
        if(i>=l-1){
            sum+=(*rbt.find_by_order(k-1)).fi;
            if(i>=l)rbt.erase({a[i-l],i-l});
            // cout << "sum === " << sum << endl;
        }
    }
    return sum;
}

void rel(){
    cin >> n >> l >> k;
    VI a(n), mx1(n), mx2(n), mn(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int left = 0, right = n - 1;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            mx1[i] = a[right--];
        } else {
            mx1[i] = a[left++];
        }
    }
     left = 0, right = n - 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            mx2[i] = a[right--];
        } else {
            mx2[i] = a[left++];
        }
    }

    left = 0, right = n - 1;
    for (int i = 0; i < k - 1; i++) {
        mn[i] = a[right--];
    }
    for (int i = k - 1; i < n - 1; i++) {
        mn[i] = a[left++];
    }
    mn[n - 1] = a[right];

    cout << " --- debug -- " << endl;
    for(int i = 0; i < n; i++){
        cout << mx1[i] << " \n"[i==n-1];
    }
    
    for(int i = 0; i < n; i++){
        cout << mx2[i] << " \n"[i==n-1];
    }
    for(int i = 0; i < n; i++){
        cout << mn[i] << " \n"[i==n-1];
    }
    ll r1=0,r2=inf;
    r1=max<ll>({solve(mx1),solve(mx2),solve(mn)});
    r2=min<ll>({solve(mx1),solve(mx2),solve(mn)});
    cout<<r1<<' '<<r2<<endl;
}
int main(){
    // IN;
    IOS;
    int _;cin>>_;
    while(_--)rel();
    return 0;
}
