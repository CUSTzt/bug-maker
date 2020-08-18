else {
            int u = 1, v = 1;
            rep(i, 1, f[1].se) u *= f[1].fi;
            v = b / u;
            LL x, y;
            Exgcd(v, u, x, y);
            if (y > 0) {
                LL tmp = (y + v - 1) / v;
                y -= tmp * v, x += tmp * u;
            }
            if (x < 0) {
                LL tmp = (-x + u - 1) / u;
                y -= tmp * v, x += tmp * u;
            }
            x *= a, y *= a;
            if (x > 0 && y < 0)
                pr(x, u, -y, v);
            else
                puts("-1 -1 -1 -1");
        }