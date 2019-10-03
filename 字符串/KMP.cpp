// lero
//计算串str的next数组，nxt[i] 表示str[0] ~ str[i-1]的最长相同前后缀
int GETNEXT(char *str)
{
    int len=strlen(str);
    nxt[0]=nxt[1]=0;//初始化
    for(int i=1;i<len;i++)
    {
        int j=nxt[i];
        while(j&&str[i]!=str[j])//一直回溯j直到str[i]==str[j]或j减小到0
        j=nxt[j];
        nxt[i+1]=str[i]==str[j]?j+1:0;//更新next[i+1]
    }
    return len;//返回str的长度
}
//返回S串中第一次出现模式串T的开始位置
int KMP(char *S,char *T)
{
    int l1=strlen(S),l2=GETNEXT(T);//l2为T的长度
    int i,j=0,ans=0;
    for(i=0;i<l1;i++)
    {
        while(j&&S[i]!=T[j])//发生失配则回溯
        j=nxt[j];
        if(S[i]==T[j])
        j++;
        if(j==l2)//成功匹配则退出
        break;
    }
    if(j==l2)
        return l2;//返回第一次匹配成功的位置
    else
        return j;//若匹配不成功则返回-1
}



int kmp(char *str, char *ptr, int slen)
{
    static int next[MAXN];
    next[0] = next[1] = 0;
    int plen = strlen(ptr);
    if (slen == 0 || plen == 0) return 0;
 
    for (int i = 1, j; i < plen; i++)
    {
        j = next[i];
        while (j && ptr[i] != ptr[j])
            j = next[j];
        next[i+1] = (ptr[j] == ptr[i]) ? j+1 : 0;
    }
 
    int j = 0;
    for (int i = max(slen-plen-1,0); i < slen; i++)
    {
        while (j && ptr[j] != str[i])
            j = next[j];
        if (ptr[j] == str[i]) ++j;
    }
 
    return j;
}