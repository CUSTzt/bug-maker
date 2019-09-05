#include <stdio.h>
#include <string.h>
#define mem(a) memset(a, 0, sizeof(a))

int N, A[500010], T[500010];
__int64 ans;

void Merg_Sort(int x,int y)
{
    if(y-x<=1) return ;
    int mid = x + (y-x)/2;
    Merg_Sort(x,mid);
    Merg_Sort(mid,y);
    int p = x, q = mid, i=x;
    while(p<mid || q<y)
    {
        if(q>=y || (p<mid && A[p] <= A[q])) T[i++] = A[p++];
        else//else的条件是(p==mid || A[q] < A[p])
        {
            if(p<mid) ans+=(mid-p);//由于是p<mid,所以此时也就是相当于 A[q] < A[p]
            T[i++] = A[q++];       //上面同时A[p]是第一个<A[q]的数，所以+后面还有的数(mid-p)
        }
    }
    for(i=x;i<y;i++)
    {
        A[i] = T[i];
    }
}

int main()
{
    while(~scanf("%d", &N) && N)
    {
        mem(A); mem(T);
        for(int i=0;i<N;i++)
        {
            scanf("%d", &A[i]);
        }
        ans = 0;
        Merg_Sort(0,N);
        printf("%I64d\n",ans);//结果会超int32
    }
    return 0;
}