#include <bits/stdc++.h>
using namespace std;

template<typename T>
T QuickCompute(T x, uint64_t k) {
  T re;
  while(k) {
    if (k&1) re=re*x;
    x=x*x;
    k>>=1;
  }
  return re;
}

struct Num {
  explicit Num(uint64_t x) :v(x) {}
  uint64_t v;
  static uint64_t m;
};
uint64_t Num::m = 0;

struct Inc : public Num {
  Inc(uint64_t x=0) :Num(x) {}
  Inc operator*(Inc o) {
    v%=m;
    o.v%=m;
    for(;;) {
      uint64_t d=~v;
      if (d>=o.v){
        return (v+o.v)%m;
      } else {
        v=(v+d)%m;
        o.v-=d;
      }
    }
  }
};

struct Add : public Num {
  Add(uint64_t x=0) :Num(x) {}
  Add operator*(const Add& o) {
    return (Inc(v)*Inc(o.v)).v;
  }
};

struct Mul : public Num {
  Mul(uint64_t x=1) :Num(x) {}
  Mul operator*(const Mul& o) {
    return QuickCompute(Add(v), o.v).v;
  }
};

namespace swapn {

int n;
struct Swap {
  static constexpr int N = 100;

  Swap() {
    for (int i = 0; i < n; ++i)
      v[i] = i;
  }
  Swap operator*(const Swap& o) {
    Swap a;
    for (int i = 0; i < n; ++i) {
      a.v[i] = v[o.v[i]];
    }
    return a;
  }
  void input() {
    for(int i=0;i<n;i++)
      cin>>v[i];
  }
  void output()const {
    for(int i=0;i<n;i++)
      cout<<v[i]<<(i==n-1?'\n':' ');
  }
  
  int v[N];
};

}  // namespace swapn
using swapn::Swap;

template<typename T>
void solve() {
  uint64_t n;
  T x;
  cin>>x.v>>n>>T::m;
  T ans=QuickCompute(x, n);
  cout<<ans.v<<endl;
}

template<>
void solve<Inc>() {
  Inc a,b;
  cin>>a.v>>b.v>>Num::m;
  cout<<(a*b).v<<endl;
}

template<>
void solve<Swap>() {
  using swapn::n;
  int k;
  uint64_t m;
  cin>>n>>m>>k;
  Swap be,op;
  be.input();
  int x,y;
  while(k--){
    cin>>x>>y;
    assert(max(x,y)<=swapn::Swap::N);
    swap(op.v[--x],op.v[--y]);
  }
  Swap ans=be*QuickCompute(op, m);
  ans.output();
}

int main() {
    // freopen("data.in","r",stdin);
  int id;
  cin>>id;
  int T;
  cin>>T;
  while(T--) {
    if (id==5) solve<Inc>();
    else if(id==6) solve<Add>();
    else if(id==7) solve<Mul>();
    else if(id==8) solve<Swap>();
    else assert(false);
  }
  return 0;
}

