 // 给定整数【a，b），求区间内有多少个素数
 // a < b <= 1e12      b - a <= 1e6
 // b以内合数的最小质因数一定不超过√b 如果有√b 以内的素数表，就可以把埃式筛法用到
 // 【a，b）上，也就是说，先分别做好【2，√b ）的表和【a，b）的表，然后从【2，√b）的表中
 // 筛得素数的同时，也将其倍数从【a，b）的表中划区，最后剩下【a，b）内的素数 了

typedef long long ll ;
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

//注意a==1 的情况   要减去1
//对区间【a，b）内的整数执行筛法  is_prime[i-a] = true;   <=>i 是 素数
void segement_sieve(ll a, ll b){
	for(int i = 0;(ll)i * i < b; i++)is_prime_small[i] = true;
	for(int i = 0; i < b - a; i++)is_prime[i] = true;

	for(int i = 2; (ll)i * i < b; i++){
		if(is_prime_small[i]){
			for(int j = 2 * i;(ll )j * j < b;j+= i )is_prime_small[j] = false; //筛【2，√b）
			for(ll j = max(2LL, (a+i-1) / i) * i; j < b; j += i)is_prime[j-a] = false;//筛【a，b）
		}
	}
}
//!!!!  is_prime[i-a] = true;   <=>i 是 素数