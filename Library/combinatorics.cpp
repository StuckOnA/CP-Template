#define combinator

int power(int x, int n)
{
    int res = 1;
    while (n) {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

vi fact(N), inv(N);

void precompute()
{
    fact[0] = 1;
	
    rep(i, 1, N) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
	
    inv[N - 1] = power(fact[N - 1], MOD - 2);
	
    per(N - 1) {
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    }
}

int ncr(int n, int r)
{
    if (r == 0) {
        return 1;
    }
	
    if (r > n) {
        return 0;
    }
	
    return (fact[n] * ((inv[r] * inv[n - r]) % MOD)) % MOD;
}

int npr(int n, int r) 
{
    return (fact[n] * inv[n - r]) % MOD;
}
