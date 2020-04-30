1 int n,m,j,x1,y1,x2,y2,p;char op[9];
2 struct BIT{
3 int a[N][N];
4 void add(int x,int y,int p){for(;x<=n;x+=x&−x)for(j=y;j<=m;j+=j&−j)a[x][j]+=p;}
5 int sum(int x,int y){int t=0;for(;x;x−=x&−x)for(j=y;j;j−=j&−j)t+=a[x][j];return t;}
6 }T1,T2,T3,T4;
7 void up(int x,int y,int p){
8 if(!x||!y)return;
9 T1.add(x,y,x*y*p);
10 T2.add(x,1,x*p),T2.add(x,y,−x*p);
11 T3.add(1,y,y*p),T3.add(x,y,−y*p);
12 T4.add(1,1,p),T4.add(x,y,p);
13 T4.add(x,1,−p),T4.add(1,y,−p);
14 }
15 int ask(int x,int y){
16 return x&&y?T1.sum(x,y)+T2.sum(x,y)*y+T3.sum(x,y)*x+T4.sum(x,y)*x*y:0;
17 }
