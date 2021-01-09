#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
struct Trie {
	int ch[30], cnt;
	multiset<int> *st;	
	Trie() {st = NULL;}
}trie[MAXN];
char str[MAXN];
int tot, n;
void insert(int root, char *s) {
	int len = strlen(s+1);
	for(int i = 1; i <= len; i++) {
		int cur = s[i]-'a';
		if(trie[root].ch[cur] == 0) trie[root].ch[cur] = ++tot;
		root = trie[root].ch[cur];
	} 
	trie[root].cnt++;
}
void dfs(int x, int dep) {
	bool flag = 0;
	for(int i = 0; i < 26; i++) {
		if(trie[x].ch[i] == 0) continue; 
		dfs(trie[x].ch[i], dep+1); flag = 1;
		if(trie[x].st == NULL) trie[x].st = trie[trie[x].ch[i]].st;
		else {
			if(trie[x].st->size() < trie[trie[x].ch[i]].st->size()) 
				swap(trie[x].st, trie[trie[x].ch[i]].st);
			for(auto y : *trie[trie[x].ch[i]].st) {
				trie[x].st->insert(y);
			}
		}

	}
	if(!flag) trie[x].st = new multiset<int> (); 
	if(trie[x].cnt) trie[x].st->insert(dep);
	if(trie[x].cnt == 0 && x != 0) {
		trie[x].st->erase(--trie[x].st->end());
		trie[x].st->insert(dep);
	}

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
        cin >> (str+1), insert(0, str);
    for(auto j = 0; j < strlen(str+1); j++)
    assert(str[j] >= 'a' && str[j] <= 'z');
    }
    // for(int i = 1; i <= n; i++) assert(str[i] >= 'a' && str[i] <= 'z');
	dfs(0, 0); int ans = 0;
	for(auto x : *trie[0].st) ans += x;
	cout << ans; 
	return 0;
}
