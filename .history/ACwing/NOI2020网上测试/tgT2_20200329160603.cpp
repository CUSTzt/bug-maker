// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn 1000100
#define lowbit(x) x&(-x)
int n, inv[maxn],a[maxn];
struct BIT
{
    int t[maxn];
    void upd(int i , int k){
        while(i <= n){
            t[i]+=k;
            i+=lowbit(i);
        }
    }
    int ask(int )
};


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}