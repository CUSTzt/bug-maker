//求\sum_{i=1}^n n/i 
//枚举左端点和右端点，右端点n/(n/l)
for(int l=1,r;l<=n;l=r+1){
    r=n/(n/l);
    ans+=(n/l)*(r-l+1);
}

//如果求\sum_{i=1}^n n/i A[i]
//树状数组访问前缀和。
for(int l = 1; l <= n; l = r+1){
    r = n / (n/l);
    ans += query(n/l)*(r-l+1);
}