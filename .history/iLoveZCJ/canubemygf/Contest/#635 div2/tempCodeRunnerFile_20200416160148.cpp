// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    set<int >s;
    for(int i = 1; i <= 10; i++){
        s.insert(i);
    }
    while(1){
        int n;
        cin >> n;
        auto it = s.lower_bound(n);
        auto i = it;
        cout << "*it === " << *it << endl;
        cout << "*i === " << *i << endl;
    }
    return 0;
}