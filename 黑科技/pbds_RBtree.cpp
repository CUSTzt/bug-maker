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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    RBTree X;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        X.insert(p);
        if(i & 1){
            cout << X.findKth((i+1)/2-1) << endl;
        }
    }
    return 0;
}