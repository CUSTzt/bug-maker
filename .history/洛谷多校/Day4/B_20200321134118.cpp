// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const double PI = acos(-1.0);
const int N = 1e6+100;
double h , r , d;
double qiuque(double x){
    return x*x*(3*r-x)*PI/3;
}
double banqiiu,tot, sum;
double f(int x){
    return PI*r*r*x;
}
double check(double x){
    if(x>=0&&x<=r){
        return qiuque(x);
    }
    if(x>r&&x<=h+r){
        return banqiiu+f(x-r);
    }
    if(x > h+r&&h<=h+2*r){
        return tot-qiuque(2*r+h-x);
    }
}
int main()
{
    cin >> h >> r >> d;
    double l = 0;
    vector<double>ans;
    banqiiu = PI*2*r*r*r/3;
    tot = PI*r*r*h+PI*4*r*r*r/3;
    while(l+d<=2*h+r){
        ans.pb(check(min(l+d,h+2*r))-check(l));
        l+=d;
    }
    for(auto it:ans){
        printf("%.10f\n",it);
    }
    return 0;
}