#include<bits/stdc++.h>

using namespace std;
const int maxn = 1000;
struct node{
	int start , end, id;
}a[maxn];
int cmp(node a , node b){ // ������򣬽���ʱ��Ϊ��һ�ؼ��֣���ʼʱ��Ϊ�ڶ��ؼ��֡�
	if(a.end == b.end)return a.start < b.start;
	return a.end < b.end;
}
int main(){
	int n;
	cout << "������������n:" << endl;
	cin >> n;
	cout << "������ " << n << " �У�ÿ�����������ֱ��ʾ���ǵĿ�ʼʱ��ͽ���ʱ�䡣"<< endl;
	for(int i = 1; i <= n; i++){
		cin >> a[i].start >> a[i].end;
		a[i].id = i;
	}
	sort(a+1, a+n+1, cmp);
	int j = 1;
	std::vector<node> v; // �ö�̬�����¼��Щ��ѡ��
	for(int i = 2; i <= n; i++){
		if(a[i].start >= a[j].end){
			v.push_back(a[i]); // ��ʾ���Ա�ѡ�ģ�ѹ�붯̬����v�У���¼һ��
			j = i;
		}
	}
	cout << "һ�����԰���" << v.size() << "�����" << endl;
	cout << "��Щ��ֱ�ı�ŷֱ���:" << endl;
	for(auto it : v){
		cout << it.id << " ";
	}
}

/*
���ݣ�
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/