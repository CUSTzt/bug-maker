package he;

import java.util.Scanner;

public class Big {
	static long mult(long x, long y, long n) {
		long s = 1;
		if(x > 0 && y > 0 || x<0&&y<0) s = 1;
		else if(x>0 && y < 0 || x<0&&y>0) s= -1;
		else s = 0;
		x = Math.abs(x);
		y = Math.abs(y);
		if (n == 1) {
			//System.out.println("x = "+x+" y = "+y+" n = "+n+" s = "+s);
			return x * y * s;
		}
		else {
			long t = 1;
			for (int i = 0; i < n/2; i++) {
				t *= 10;
			}
			long a = x/t;
			long b = x%t;
			long c = y/t;
			long d = y%t;
			long m1 = mult(a, c, n / 2);
			long m2 = mult(a - b, d - c, n / 2);
			long m3 = mult(b, d, n / 2);
			long e = 1;
			for (int j = 0; j < n; j++) {
				e *= 10;
			}
			long r = 1;
			for (int k = 0; k < n / 2; k++) {
				r *= 10;
			}
			//s = s * (a * c * e + ((a - d) * (b - c)) * r + b * d);
			s = s*(m1*e+(m2+m1+m3)*r+m3);
			return s;
		}
	}

	public static void main(String[] args) {
		Big big = new Big();
		Scanner cin = new Scanner(System.in);
		long n = cin.nextLong();
		long x = cin.nextLong();
		long y = cin.nextLong();
		System.out.println(big.mult(x, y, n));
	}
}

