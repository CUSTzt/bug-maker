//枚举左端点和右端点，右端点n/(n/l)
for(int l=1,r;l<=n;l=r+1){
    r=n/(n/l);
    ans+=(n/l)*(r-l+1);
}
