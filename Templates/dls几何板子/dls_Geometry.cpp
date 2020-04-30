
#define db double 

const db EPS = 1e-9
//实数比较
inline int sign(db a){return a < -EPS ? -1 : a > EPS; }
inline int cmp(db a , db , b){return sign(a - b); }

//点
struct P{
	db x, y;
	db() {}
	P(db _x , db _y) : x(_x), y(_y){}
	P operator+(P p){ return {x + p.x , y + p.y}; }
	P operator-(P p){ return {x - p.x , y - p.y}; }
	P operator*(db d){ return {x * d, y * d};}
	P operator/(db d){ return {x / d, y / d};}

	bool operator<(P p)const {
		int c = cmp(x , p.x);
		if(c)return c == -1 ;
		return cmp(y , p.y) == -1;
	}

	bool operator==(P o)const {
		return cmp(x, o.x) == 0 && cmp(y, o.y) == 0;
	}	
	db distTo(P p){ return (*this-p).abs();}
	db alpha(){ return atan2(y , x); }
	void read(){ cin >> x >> y ; }
	void write(){ cout<<"("<<x<<","<<y<<")"<<endl;}
	db abs(){ return sqrt(abs2());}
	db abs2(){ return x*x+y*y;}
	P rot90(){ return P(-y , x);}
	P unit(){ return *this/abs();}
	int quad()const {return sign(y) == 1 || (sign(y) == 0 && sign(x) <= 0);}
	db dot(P p){ return x * p.x + y * p.y;} // 点积
	dl det(P p){ return x * p.y - y * p.x;} // 叉积
	
};
