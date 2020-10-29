//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int ans,x[20],y[20];
char a[10][10];bool f[10][10];
int main(){
	for(int i=1;i<5;++i){
		cin>>a[i];
		for(int j=0;j<4;++j){
			if (a[i][j]=='-')f[i][j+1]=0;
			else f[i][j+1]=1;
		}
	}
	for(int i=1;i<5;++i)
		for(int j=1;j<5;++j){
			int t=f[i][j];
			for(int k=1;k<5;++k){
				t^=f[i][k];t^=f[k][j];
			}
			if (t){x[++ans]=i;y[ans]=j;}
		}
	cout<<ans<<endl;
	for(int i=1;i<=ans;++i)cout<<x[i]<<" "<<y[i]<<endl;
	return 0;
}