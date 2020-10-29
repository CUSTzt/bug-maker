#include<bits/stdc++.h>
using namespace std;

const int N = 3100;
const double PI = acos(-1.0);

struct Node{
    double x,y,angle;
    int id;
    bool operator < (const Node& A) const {
        return angle<A.angle;
    }
}a[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=3*n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
        double &res=a[i].angle;
        res=atan2(a[i].y,a[i].x);
        if(res<0)res=2*PI+res;
    }
    sort(a+1,a+1+3*n);
    for(int i=1;i<=3*n;i++)cout<<a[i].id<<" \n"[i%3==0];
}
int main(){
    int _;cin>>_;
    while(_--)solve();
    return 0;
}