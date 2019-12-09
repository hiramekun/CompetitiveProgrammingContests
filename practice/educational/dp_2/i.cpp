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
#include <numeric>
#include <stack>
#include <iomanip>

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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        ll n;
        cin >> n;
        vector<double> p(n);
        rep(i, n) cin >> p[i];
        double ans = 0;

        double dp[n + 1][n + 1]; // dp[i][j] 最初のi枚のコインを投げた時に，表がj枚となる確率．
        rep(i, n + 1) rep(j, n + 1) dp[i][j] = 0.0;
        dp[0][0] = 1.0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i + 1][j + 1] += dp[i][j] * p[i];
                dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
            }
        }
        for (int i = n / 2 + 1; i <= n; ++i) {
            ans += dp[n][i];
        }

        cout << fixed << setprecision(10) << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}