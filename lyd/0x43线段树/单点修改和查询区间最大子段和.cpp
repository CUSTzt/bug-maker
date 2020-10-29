const int maxn=5e5+10;
typedef long long ll;
struct node
{
	ll ls,rs,sum,mx;
}tr[maxn*4];
node up(node a,node b)
{
	node rec;
	rec.ls=max(a.sum+b.ls,a.ls);
	rec.rs=max(a.rs+b.sum,b.rs);
	rec.sum=a.sum+b.sum;
	rec.mx=max(max(a.rs+b.ls,a.mx),b.mx);
	return rec;
}
void build(int l,int r,int k)
{
	if(l==r){
		scanf("%lld",&tr[k].sum);
		tr[k].rs=tr[k].sum;tr[k].ls=tr[k].sum;tr[k].mx=tr[k].sum;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,2*k);
	build(mid+1,r,2*k+1);
	tr[k]=up(tr[2*k],tr[2*k+1]);
}
void updata(int l,int r,int L,int R,ll v,int k)
{
	if(l==r){
		tr[k].sum=v;tr[k].rs=tr[k].sum;tr[k].ls=tr[k].sum;tr[k].mx=tr[k].sum;
		return;
	}
	int mid=l+r>>1;
	if(mid>=L)	updata(l,mid,L,R,v,2*k);
	if(mid<R)	updata(mid+1,r,L,R,v,2*k+1);
	tr[k]=up(tr[2*k],tr[2*k+1]);
}
node query(int l,int r,int L,int R,int k)
{
	if(l>=L&&r<=R)
		return tr[k];
	int mid=l+r>>1;node t1,t2;
	if(mid>=L)	t1=query(l,mid,L,R,2*k);
	if(mid<R)	t2=query(mid+1,r,L,R,2*k+1);
	if(mid>=L&&mid>=R)	return t1;
	if(mid<R&&mid<L)	return t2;
	return up(t1,t2);
}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	build(1,n,1);
	while(m--){
		int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);
		if(t1==1){
			if(t2>t3)	swap(t2,t3);
			cout<<query(1,n,t2,t3,1).mx<<endl;
		}
		else{
			updata(1,n,t2,t2,t3,1);
		}
	}
}