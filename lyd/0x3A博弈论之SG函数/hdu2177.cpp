 /************************************************
 # @Author:      miniLCT
 # @DateTime:    2019-07-16 16:21:43
 # @Description: 打好acm就能和cls一样天天吃小龙虾
 ***********************************************/
//S题
#include <bits/stdc++.h>

using namespace std;
#define eps 1e-8
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int maxn = 1e6+10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
int a[maxn],b[maxn];

int main()
{
    int a,b,temp,temp2,k,i, tmp;
    while(scanf("%d%d",&a,&b),a+b)
    {
        if(a>b)
            swap(a,b);
        k=b-a;    //求出差值
        temp=k*(1.0+sqrt(5.0))/2.0;    //求出差值对应的开头数
        if(a==temp)    //奇异局势
            printf("0\n");
        else
        {
            printf("1\n");
            if(abs(temp-a)==abs(temp+k-b) && temp < a){
            //取两堆中相同数量，判断差值是否相等
                printf("%d %d\n",temp,temp+k);
                tmp = temp;
            }

            //一堆中取
            if(a==0)    //0 0情况，第一种奇异局势
                printf("0 0\n");
            for(i=1;i<=b;i++)
            {
                temp=i*(1.0+sqrt(5.0))/2.0;    //开头
                if(temp == tmp)continue;
                temp2=temp+i;

                if(temp==a)
                    printf("%d %d\n",a,temp2);
                else if(temp2==a)
                    printf("%d %d\n",temp,a);
                else if(temp2==b)
                    printf("%d %d\n",temp,b);
            }
        }
    }
    return 0;
}