// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define rbset(T) \
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
struct RBTree {
    rbset(int) rb;
    void insert(int x) { rb.insert(x); }
    void remove(int x) { rb.erase(x); }
    int findKth(int x) { return *rb.find_by_order(x); }
    int findElementRank(int x) { return rb.order_of_key(x); }
};
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    RBTree X;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        X.insert(p);
        if(i & 1){
            cout << X.
        }
    }
    return 0;
}