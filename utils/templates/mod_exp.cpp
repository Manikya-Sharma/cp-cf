#define MOD (int)(1e9 + 7)
ll mod_exp(ll a, int b) {
    assert(b >= 0);
    if (b == 0) {
        assert(a != 0);
        return 1;
    }
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * 1ll * a) % MOD;
        b >>= 1;
    }
    return ans;
}
