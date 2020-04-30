#include <bits/stdc++.h>

typedef long long int64;
typedef long double D;

int MOD;
const int MAXN = 524288;
const D PI = acos(-1);

struct complex {
    D real, imag;
    complex() { real = imag = 0; }
    complex(D x): real(x), imag(0) {} 
    complex(D x, D y): real(x), imag(y) {}
    inline complex conj() { return complex(real, -imag); }
    inline complex operator+(complex rhs) const { return complex(real + rhs.real, imag + rhs.imag); }
    inline complex operator-(complex rhs) const { return complex(real - rhs.real, imag - rhs.imag); }
    inline complex operator*(complex rhs) const { return complex(real * rhs.real - imag * rhs.imag,
                                                                 imag * rhs.real + real * rhs.imag); }
    inline complex operator*=(complex rhs) { return (*this) = (*this) * rhs; }
    //(a+bi)(c+di) = (ac-bd) + (bc+ad)i
    friend inline complex operator*(D x, complex cp) { return complex(x * cp.real, x * cp.imag); }
    inline complex operator/(D x) const { return complex(real / x, imag / x); }
    inline complex operator/=(D x) { return (*this) = (*this) / x; }
    friend inline complex operator/(D x, complex cp) { return x * cp.conj() / (cp.real * cp.real - cp.imag * cp.imag); }
    inline complex operator/(complex rhs) const { 
        return (*this) * rhs.conj() / (rhs.real * rhs.real - rhs.imag * rhs.imag); 
    }
    inline complex operator/=(complex rhs) { return (*this) = (*this) / rhs; }
    inline D length() { return sqrt(real * real + imag * imag); }
};

inline complex get_omega(int len, bool inv) {
    return inv ? complex(std::cos(2*PI / len), -std::sin(2*PI / len))
                :complex(std::cos(2*PI / len),  std::sin(2*PI / len));
}

inline void fft(int len, complex* A, bool inv = false) {
    static int R[MAXN+10];
    for(int i = 0; i < len; i++)
        R[i] = ((R[i>>1]>>1) | (len >> (i&1))) & (len-1);
    for(int i = 0; i < len; i++)
        if(R[i] > i) std::swap(A[i], A[R[i]]);
    for(int step = 1; step < len; step <<= 1) 
        for(int i = 0; i < len; i += (step<<1)) {
            complex omega = 1, t = 0, rt = get_omega(step<<1, inv);
            for(int j = 0; j < step; j++, omega *= rt) {
                t = A[i+j+step] * omega;
                A[i+j+step] = A[i+j] - t;
                A[i+j] = A[i+j] + t;
            }
        }
    if(inv)
        for(int i = 0; i < len; i++)
            A[i] /= len;
}

void mtt(int deg, int *lhs, int *rhs, int *ret) {
    static complex A[MAXN+10], B[MAXN+10], C[MAXN+10], D[MAXN+10],
                   E[MAXN+10], F[MAXN+10], G[MAXN+10], H[MAXN+10];
    int len; for(len = 1; len <= deg; len<<=1);
    for(int i = 0; i < len; i++) {
        lhs[i] %= MOD; rhs[i] %= MOD;
        A[i] = lhs[i] >> 15; B[i] = lhs[i] & 0x7fff;
        C[i] = rhs[i] >> 15; D[i] = rhs[i] & 0x7fff;
    }
    fft(len, A); fft(len, B); fft(len, C); fft(len, D);
    for(int i = 0; i < len; i++) {
        E[i] = A[i] * C[i]; F[i] = B[i] * C[i];
        G[i] = A[i] * D[i]; H[i] = B[i] * D[i];
    }
    fft(len, E, true); fft(len, F, true); 
    fft(len, G, true); fft(len, H, true);
    for(int i = 0; i < len; i++)
        ret[i] = (((int64(round(E[i].real)) % MOD)<<30) % MOD + ((int64(round(F[i].real)) % MOD)<<15) % MOD
            + ((int64(round(G[i].real)) % MOD)<<15) % MOD + int64(round(H[i].real)) % MOD) % MOD;
}

int deg, n, m, F[MAXN+10], G[MAXN+10], H[MAXN+10];

inline int readint() {
    int f=1, r=0; char c=getchar();
    while(!isdigit(c)) { if(c=='-')f=-1; c=getchar(); }
    while(isdigit(c)) { r=r*10+c-'0'; c=getchar(); }
    return f*r;
}
//给定F（x），G(x)
int main() {
    n = readint(); m = readint(); MOD = readint();
    for(int i = 0; i <= n; i++) 
        F[i] = readint();
    for(int i = 0; i <= m; i++)
        G[i] = readint();
    mtt((n+ m), F, G, H);
    for(int i = 0; i <= n + m; i++)
        printf("%d ", H[i]);
}