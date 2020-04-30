#include <stdio.h>
#include <stdlib.h>
#include<math.h>
double  cal(double a,double b,int op)
{
    switch (op)
    {
    case 0:
        return(a+b);
    case 1:
        return(a-b);
    case 2:
        return(a*b);
    case 3:
        return(a/b);
    }
}
int  isEqual(double d1,double d2)
{
    double d=d1-d2;
    d=fabs(d);
    return(d<=0.001);
}
int re;
void  judge(int v0,int v1,int v2,int v3)
{
    int count=0,f1,f2,f3;
    for ( f1=0; f1<4; f1++)
        for ( f2=0; f2<4; f2++)
            for ( f3=0; f3<4; f3++)
            {
                double t1,t2,t3;
                t1=cal(v0,v1,f1);
                t2=cal(t1,v2,f2);
                t3=cal(t2,v3,f3);
                if (isEqual(t3,))
                    count++;
                t1=cal(v0,v1,f1);
                t2=cal(v2,v3,f3);
                t3=cal(t1,t2,f2);
                if (isEqual(t3,24))
                    count++;
                t1=cal(v1,v2,f2);
                t2=cal(v0,t1,f1);
                t3=cal(t2,v3,f3);
                if (isEqual(t3,24))
                    count++;
                t1=cal(v1,v2,f2);
                t2=cal(t1,v3,f3);
                t3=cal(v0,t2,f1);
                if (isEqual(t3,24))
                    count++;
                t1=cal(v2,v3,f3);
                t2=cal(v1,t1,f2);
                t3=cal(v0,t2,f1);
                if (isEqual(t3,24))
                    count++;
            }
    if (count==0)
        printf("No\n");
    else
        printf("Yes\n");
}
int  main()
{
    int v0,v1,v2,v3,t,i;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d %d %d %d %d",&v0,&v1,&v2,&v3,&re);
        judge(v0,v1,v2,v3);
    }
    return 0;
}