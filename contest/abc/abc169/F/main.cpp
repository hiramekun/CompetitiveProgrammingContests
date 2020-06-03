#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll mod = 998244353;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(s + 1));
    dp[0][0] = 1;
    rep(i, n) {
        rep(j, s + 1) {
            dp[i + 1][j] += ((dp[i][j] * 2) % mod);
            dp[i + 1][j] %= mod;
            if (j + a[i] <= s) {
                dp[i + 1][j + a[i]] += dp[i][j];
                dp[i + 1][j + a[i]] %= mod;
            }
        }
    }
    cout << dp[n][s] << '\n';
    return 0;
}
