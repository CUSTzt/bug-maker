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
    return x*x*(3*r-h)*PI/3;
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
    banqiiu = PI
    while(l+d<=2*h+r){

    }
    for(auto it:ans){
        printf("%.10f\n",it);
    }
    return 0;
}