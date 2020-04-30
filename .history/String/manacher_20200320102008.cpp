const int maxn=1e6+200;
int nxt[maxn*2],nxt1[maxn*2];
char str[maxn*2],s[maxn*2];
char ans_s[maxn*2];
int p[maxn*2];
int len1,len2;
void init(){//记得开两倍
	len1=strlen(s);
	nxt[0]=nxt[1]=p[0]=p[1]=0;
	str[0]='$';
	str[1]='#';
	for(int i=0;i<len1;i++){
		str[i*2+2]=s[i];
		str[i*2+3]='#';
		nxt[i*2+2]=nxt[i*2+3]=p[i*2+2]=p[i*2+3]=0;
	}
	len2=len1*2+2;
	nxt[len2]=p[len2]=0;
	str[len2]='*';
}
void manacher(){
	int id=0,mx=0;
	for(int i=1;i<len2;i++){
		if(mx>i)p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		for(;str[i+p[i]]==str[i-p[i]];p[i]++);
		if(p[i]+i>mx){
			mx=p[i]+i;
			id=i;
		}
	}
}