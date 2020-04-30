double x,y,r;
vector<pair<double,double> > V;
typedef pair<double,double> PAIR;
PAIR yuan;
bool judge(PAIR P)// 判断是否在圆内
{
    if( (P.first-x)*(P.first-x) + (P.second-y)*(P.second-y) -r*r <=0)
        return 1;
    return 0;
}
bool Judis(PAIR P1,PAIR P2,double R) //线段与圆的关系
{
 
    if(judge(P1)&&judge(P2))//都在圆内 不相交
        return false;
    if(!judge(P1)&&judge(P2)||judge(P1)&&!judge(P2))//一个圆内一个圆外 相交
        return true;
    double A,B,C,dist1,dist2,angle1,angle2;//Ax+By+C=0;//(y1-y2)x +(x2-x1)y +x1y2-y1x2=0
    if(P1.first==P2.first)
        A=1,B=0,C= -P1.first;
    else if(P1.second==P2.second)
        A=0,B=1,C= -P1.second;
    else
    {
        A = P1.second-P2.second;
        B = P2.first-P1.first;
        C = P1.first*P2.second - P1.second*P2.first;
    }
    dist1 = A * yuan.first + B * yuan.second + C;
    dist1 *= dist1;
    dist2 = (A * A + B * B) * R * R;
    if (dist1 > dist2) return false;//点到直线距离大于半径r  不相交
    angle1 = (yuan.first - P1.first) * (P2.first - P1.first) + (yuan.second - P1.second) * (P2.second - P1.second);
    angle2 = (yuan.first - P2.first) * (P1.first - P2.first) + (yuan.second - P2.second) * (P1.second - P2.second);
    if (angle1 > 0 && angle2 > 0) return true;//余弦都为正，则是锐角 相交
    return false;//不相交
}