#include<bits/stdc++.h>

using namespace std;
double n , p1 ,p2 ,v1, v2;
void up(){
    scanf("%lf%lf%lf%lf%lf",&n,&p1,&v1,&p2,&v2);
    if(p1 > p2){
        swap(v1,v2), swap(p1,p2);
    }
    double ans = min({(p1+n)/v1,(2*n-p2)/v2,(p2+n)/v2,(2*n-p1)/v1,max(p2/v2,(n-p1)/v1)});
    auto chk = [&](double p){
        return max(min((2*p-p1)/v1,(p+p1)/v1),min((n-p+n-p2)/v2,(n+p2-2*p)/v2));
    };
    double l = p1, r = p2;
    for(int i = 1; i <= 100; i++){
        double midl = l + (r-l) / 3.0;
        double midr = r - (r-l) / 3.0;
        if(chk(midl) > chk(midr)){
            l = midl;
            ans = min(ans, chk(l));
        }else{
            r = midr;
            ans = min(ans, chk(r));
        }
    }
    printf("%.10f\n",ans);
}
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        up();
    }
    return 0;
}