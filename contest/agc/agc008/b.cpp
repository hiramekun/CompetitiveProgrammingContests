#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> ump;
typedef pair<ll, ll> P;

ump mp;


ll n, k;
vector<ll> a;

void solve() {
    ll dp[n + 1];
    ll dp_g[n + 1];
    dp[0] = 0, dp_g[0] = 0;
    rep(i, n) {
        dp[i + 1] = dp[i] + a[i];
        dp_g[i + 1] = dp_g[i] + max(ll(0), a[i]);
    }
    ll ans = 0;
    for (int i = 0; i + k <= n; ++i) {
        ll temp = dp[i + k] - dp[i];
        ans = max(ans, temp + dp_g[i] + dp_g[n] - dp_g[i + k]);
        ans = max(ans, dp_g[i] + dp_g[n] - dp_g[i + k]);
    }

    cout << ans << endl;
}


int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        cin >> n >> k;
        a.resize(n);
        rep(i, n) cin >> a[i];

        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}