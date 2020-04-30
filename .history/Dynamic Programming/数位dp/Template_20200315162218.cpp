class Class_DigitalDP//数位DP（记忆化搜索实现）
{
	private:
		#define Size 15//如果是int范围内，数字长度不会超过15，这个Size要视题目而定
		int len,num[Size],f[Size][10];//len存储数字长度，num记录数字的每一位，f则用于记忆化
		inline void Init(LL x) {len=0;while(x) num[++len]=x%10,x/=10;num[len+1]=0;}//初始化，将x这个数字按位保存下来
		inline int dfs(int x,int s,int flag)//x记录剩余的位数，s记录当前的状态，flag记录当前是否肯定在求解的范围内（0表示不一定，1表示一定）
		{
			register int i,lim=9,w=0;//w用于统计答案
			if(!x) return OK(s);//如果剩余位数为0，就判断当前状态是否满足条件，并退出函数
			if(flag&&~f[x][s]) return f[x][s];//如果当前状态肯定在求解范围内，且已访问并求解过当前状态，就返回曾经求解出的答案
			if(!flag) (Right(num[x])&&(w+=dfs(x-1,GetStatus(s,num[x]),0),0),lim=num[x]-1;//如果不保证在求解范围内，则对这一位上的最大值单独处理，并仍不能保证在求解范围内
			for(i=0;i<=lim;++i) if(Right(i)) w+=dfs(x-1,GetStatus(s,i),1);//枚举每一个数字，如果这个数字符合条件，就继续搜索
			if(flag) f[x][s]=w;//如果当前状态肯定在求解的范围内，就将求解出的答案记录下来，实现记忆化
			return w;//返回答案
		}
	public:
		Class_DigitalDP() {for(register int i=0,j;i<Size;++i) for(j=0;j<9;++j) f[i][j]=-1;}//初始化f数组为-1
		inline int GetAns(int x) {return (void)(Init(x)),dfs(len,0,0);}//将这个数按位保存下来，然后记忆化搜索求解
}DigitalDP;
