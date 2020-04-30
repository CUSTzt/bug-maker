#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;        //FFT模板
                            //位数不同的高精度乘法

const int maxn=1e6+5;

struct Complex //复数类
{
    double x,y;
    Complex(double dx=0,double dy=0)
    {
        x=dx;
        y=dy;
    }
};

Complex operator +(Complex a,Complex b)
{
    return Complex(a.x+b.x,a.y+b.y);
}
Complex operator -(Complex a,Complex b)
{
    return Complex(a.x-b.x,a.y-b.y);
}
Complex operator *(Complex a,Complex b)
{
    return Complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}

const double pi=acos(-1.0); //PI
int limit=1,bit=0; //limit为最终扩充的长度 limit = 1<<bit
int wz[maxn<<2];
int re[maxn<<2]; //存储结果
Complex a[maxn<<2],b[maxn<<2];
char s1[maxn],s2[maxn];//存储两个整数

void FFT(Complex *A,int inv)
{
    for(int i=0;i<limit;i++)
        if(i<wz[i])
            swap(A[i],A[wz[i]]);
    for(int mid=1;mid<limit;mid<<=1)
    {
        Complex wn(cos(pi/mid),inv*sin(pi/mid));
        for(int i=0;i<limit;i+=mid<<1)
        {
            Complex w(1,0);
            for(int j=0;j<mid;j++,w=w*wn)
            {
                Complex t1=A[i+j];
                Complex t2=w*A[i+mid+j];
                A[i+j]=t1+t2;
                A[i+mid+j]=t1-t2;
            }
        }
    }
}

int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        memset(wz,0,sizeof(wz));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        limit=1,bit=0;
        int temp;
        int len1=strlen(s1),len2=strlen(s2);
        int len=len1+len2;
        while(limit<=len)
        {
            limit<<=1;
            bit++;
        }               //一个n位的十进制数 可以看做一个n-1次多项式
        //cout << "limit === "  << limit << endl << "bit ==== " << bit << endl;
        
        for(int i=len1-1,j=0;i>=0;i--,j++)
        {
            a[j].x=s1[i]-48;
            a[j].y=0;
        }
        for(int i=len2-1,j=0;i>=0;i--,j++)
        {
            b[j].x=s2[i]-48;
            b[j].y=0;
        }
        for(int i=0;i<limit;i++)
            wz[i]=(wz[i>>1]>>1)|((i&1)<<(bit-1));
        FFT(a,1);
        FFT(b,1);
        for(int i=0;i<limit;i++)
            a[i]=a[i]*b[i];
        FFT(a,-1);
        memset(re,0,sizeof(re));
        for(int i=0;i<=limit;i++)
        {
            re[i]+=(int)(a[i].x/limit+0.5);
            if(re[i]>=10) //进位
            {
                re[i+1]+=re[i]/10;
                re[i]%=10;
                if(i==limit)
                    ++limit;
            }
        }
        while(!re[limit]&&limit>=1)//去除高位的0
            limit--;
        while(limit>=0)
            printf("%d",re[limit--]);
        printf("\n");
    }
    return 0;
}


