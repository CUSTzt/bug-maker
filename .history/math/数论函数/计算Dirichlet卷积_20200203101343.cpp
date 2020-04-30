//h = f * g 计算h(n)
//h(n) = (f * g)(n) = \sum_{i*j=n}(f[i]*g[j]) 
//由定义，枚举因数，O（√n）
h(n)=0;
for (int i=1;i*i<=n;i++){
    if (n%i)
        continue;
    h(n)+=f(i)*g(n/i);
    if (i*i!=n)
        h(n)+=f(n/i)*g(i);
}
//显然O（√n）太慢了，先枚举一个数i，然后枚举其倍数，O（nlogn）
memset(h , 0 , sizeof h);
for(int i = 1; i <= n; i++){
    for(int j = 1; i*j <= n; j++){
        h
    }
}