#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {
    ll n, k;
    cin >> n >> k;
    ll r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    const ll RR = 0, SS = 1, PP = 2;

    ll ans = 0;
    for (ll i = 0; i < k; ++i) {
        vector<vector<ll>> dp(n / k + 10, vector<ll>(3));
        ll tmp = 0;
        for (ll j = i; j < n; j += k) {
            ll idx = j / k;
            rep(now, 3) {
                rep(prev, 3) {
                    if (idx > 0 && now == prev) continue;
                    dp[idx + 1][now] = max(dp[idx + 1][now], dp[idx][prev]);

                    if (t[j] == 'r' && now == PP) {
                        dp[idx + 1][now] = max(dp[idx + 1][now], dp[idx][prev] + p);
                    }
                    if (t[j] == 's' && now == RR) {
                        dp[idx + 1][now] = max(dp[idx + 1][now], dp[idx][prev] + r);
                    }
                    if (t[j] == 'p' && now == SS) {
                        dp[idx + 1][now] = max(dp[idx + 1][now], dp[idx][prev] + s);
                    }
                }
                tmp = max(tmp, dp[idx + 1][now]);
            }
        }
        ans += tmp;
    }
    cout << ans << '\n';
    return 0;
}
