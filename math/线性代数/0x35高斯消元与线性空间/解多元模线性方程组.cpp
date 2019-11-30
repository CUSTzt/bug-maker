int a[maxn][maxn];
int x[maxn];
bool free_x[maxn];
int n;
int mod;
int gcd(int x, int y)
{
    if(y == 0)
        return x;
    return gcd(y,x%y);
}
int lcm(int x, int y)
{
    return x/gcd(x,y)*y;
}
int Gauss()
{
    int i,j;
    int row,col,max_r;// 当前这列绝对值最大的行;
    int LCM;
    int ta,tb;
    int tmp;
    for(row=0,col=0; row<n&&col<n; row++,col++)
    {
        // 枚举当前处理的行.
        // 找到该col列元素绝对值最大的那行与第row行交换.(为了在除法时减小误差)
        max_r=row;
        for(i=row+1; i<n; i++)
        {
            if(abs(a[i][col])>abs(a[max_r][col]))
                max_r=i;
        }
        if(max_r!=row)
        {
            // 与第row行交换
            for(j=row; j<n+1; j++)
                swap(a[row][j],a[max_r][j]);
        }
        if(a[row][col]==0)
        {
            // 说明该col列第row行以下全是0了，则处理当前行的下一列.
            row--;
            continue;
        }
        for(i=row+1; i<n; i++)
        {
            // 枚举要删去的行.
            if(a[i][col]!=0)
            {
                LCM=lcm(abs(a[i][col]),abs(a[row][col]));
                ta=LCM/abs(a[i][col]);
                tb=LCM/abs(a[row][col]);
                if(a[i][col]*a[row][col]<0) tb=-tb;//异号的情况是相加
                for(j=col; j<n+1; j++)
                {
                    a[i][j]=(((a[i][j]*ta-a[row][j]*tb)%mod+mod)%mod);
                }
            }
        }
    }
    // 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0).
    for(i=row; i<n; i++)
    {
        if(a[i][col]!=0)  return -1;
    }
    // 2. 无穷解的情况: 在n * (n + 1)的增广阵中出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵.
    // 且出现的行数即为自由变元的个数.
    if(row<n)
    {
        int free_index;
        int free_x_num;
        //自由变元有n-row个,即不确定的变元至少有var-k个.
        for(i = row-1; i>=0; i--)
        {
            // 用于判断该行中的不确定的变元的个数,如果超过1个,则无法求解,它们仍然为不确定的变元.
            free_x_num = 0;
            for(j = 0; j<n; j++)
            {
                if(a[i][j] && free_x[j])
                {
                    free_x_num++;
                    free_index = j;
                }
            }
            if(free_x_num>1)
                continue;
            tmp = a[i][n];
            for(j = 0; j<n; j++)
            {
                if(a[i][j] && free_index != j)
                    tmp -= a[i][j]*x[j]%mod;
                tmp = (tmp%mod+mod)%mod;
            }
            x[free_index] = tmp/a[i][free_index];
            free_x[free_index] = 0;
 
        }
 
        return n-row;
    }
     // 3. 唯一解的情况: 在n * (n + 1)的增广阵中形成严格的上三角阵.
    // 计算出Xn-1, Xn-2 ... X0.
    for(i=n-1; i>=0; i--)
    {
        tmp=a[i][n];//等式右边的数
        for(j=i+1; j<n; j++)
        {
            if(a[i][j]!=0) tmp-=a[i][j]*x[j];//把已知的解带入，减去，只剩下，一个未知的解
            tmp=(tmp%mod+mod)%mod;
        }
        while(tmp%a[i][i]!=0)//外层每次循环都是为了求 a[i][i],因为它是每个方程中唯一一个未知的变量（求该方程时）
            tmp+=mod;//因为不确定，而aug[i][i]必须得为整数才可以，周期为mod
        x[i]=(tmp/a[i][i])%mod;
    }
    return 0;
}
