void FFT(complex*A,int type)
{
	for(int i=0;i<limit;i++)
	  if(i<r[i])swap(A[i],A[r[i]]);
	for(int mid=1;mid<limit;mid<<=1)
	{
		complex Wn(cos(Pi/mid),type*sin(Pi/mid));
		for(int R=mid<<1,j=0;j<limit;j+=R)
		{
			complex w(1,0);
			for(int k=0;k<mid;k++,w=w*Wn)
			{
				complex x=A[j+k],y=w*A[j+mid+k];
				A[j+k]=x+y;
				A[j+mid+k]=x-y;
			}
		}
	}
	if(type==-1)
	{
		for(int i=0;i<limit;i++)
		  A[i]=A[i]/limit;
	}
}
ll omega[2][21][1<<20];
void pre()//预处理单位根，可以显著优化NTT常数
{
	for(int mid=1,i=0;i<=20;mid<<=1,i++)
	{
		ll w1=quick_pow(3,(MOD-1)/(mid<<1));
		ll w2=quick_pow(3,MOD-1-(MOD-1)/(mid<<1));
		omega[0][i][0]=omega[1][i][0]=1;
		for(int k=1;k<mid;k++)
		{
			omega[1][i][k]=omega[1][i][k-1]*w1%MOD;
			omega[0][i][k]=omega[0][i][k-1]*w2%MOD;
		}
	}
}
void NTT(ll*A,int type)
{
	for(int i=0;i<limit;i++)
	  if(i<r[i])swap(A[i],A[r[i]]);
	if(type==-1)type=0;
	for(int mid=1,i=0;mid<limit;mid<<=1,i++)
	{
		for(int R=mid<<1,j=0;j<limit;j+=R)
		{
			for(int k=0;k<mid;k++)
			{
				ll x=A[j+k]%MOD,y=omega[type][i][k]*A[j+mid+k]%MOD;
				A[j+k]=x+y;
				A[j+mid+k]=x-y;
			}
		}
	}
	for(int i=0;i<limit;i++)
	{
		A[i]%=MOD;
		if(A[i]<0)A[i]+=MOD;
	}
	if(type==0)
	{
		ll inv=quick_pow(limit,MOD-2);
		for(int i=0;i<limit;i++)A[i]=A[i]*inv%MOD;
	}
}
void FWT_or(ll*A,int type)
{
	for(int mid=1;mid<limit;mid<<=1)
	  for(int R=mid<<1,j=0;j<limit;j+=R)
		for(int k=0;k<mid;k++)
		  if(type==1)A[j+mid+k]+=A[j+k];
		  else A[j+mid+k]-=A[j+k];
	for(int i=0;i<limit;i++)
	{
		A[i]%=MOD;
		if(A[i]<0)A[i]+=MOD;
	}
}
void FWT_and(ll*A,int type)
{
	for(int mid=1;mid<limit;mid<<=1)
	  for(int R=mid<<1,j=0;j<limit;j+=R)
		for(int k=0;k<mid;k++)
		  if(type==1)A[j+k]+=A[j+mid+k];
		  else A[j+k]-=A[j+mid+k];
	for(int i=0;i<limit;i++)
	{
		A[i]%=MOD;
		if(A[i]<0)A[i]+=MOD;
	}
}
void FWT_xor(ll*A,int type)
{
	for(int mid=1;mid<limit;mid<<=1)
	  for(int R=mid<<1,j=0;j<limit;j+=R)
		for(int k=0;k<mid;k++)
		{
			ll x=A[j+k],y=A[j+mid+k];
			A[j+k]=x+y;
			A[j+mid+k]=x-y;
			if(A[j+k]>MOD)A[j+k]-=MOD;
			if(A[j+mid+k]<0)A[j+mid+k]+=MOD;
			if(type==-1)
			{
				A[j+k]=A[j+k]*inv2%MOD;
				A[j+mid+k]=A[j+mid+k]*inv2%MOD;
			}
		}
}
