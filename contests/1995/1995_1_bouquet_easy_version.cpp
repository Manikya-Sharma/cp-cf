#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
typedef long long ll;
typedef long double ld;

// ref: https://codeforces.com/blog/entry/131847
void solution_fn() {
    ll n;
    ll m;
    cin >> n >> m;
    vector<ll> flowers(n);
    for (ll i = 0; i < n; i++) {
        cin >> flowers[i];
    }
    sort(flowers.begin(), flowers.end());

    ll i = 0;
    ll ans = 0;
    while (i < n) {
        ll j = i;
        while (flowers[i] == flowers[j])
            j++;
        ll k = j;
        while (flowers[i] + 1 == flowers[k])
            k++;
        for (ll l = 0; l <= j - i; l++) {
            if (l * flowers[i] > m)
                continue;
            ll cost = l * flowers[i];
            ll sec_freq = min((m - cost) / (flowers[i] + 1), 1ll * k - j);
            cost += sec_freq * (flowers[i] + 1);
            ans = max(ans, cost);
        }
        i = j;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solution_fn();
    }
    return 0;
}
