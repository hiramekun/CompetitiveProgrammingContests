#include <cstring>
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
typedef pair<int, int> P;
#define i_inf int(1e9)
#define i_half_inf int(1e5)
#define ll_inf ll(1e9)*ll(1e9)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int max_n = i_half_inf;
ll n, a[max_n];

void solve() {
    sort(a, a + n);
    ll dp[n];
    dp[0] = a[0];
    repone(i, n - 1) dp[i] = dp[i - 1] + a[i];
    ll target = a[n - 1], ans = 1;
    repr(i, n - 1) {
        if (dp[i] * 2 >= target) ans++;
        else {
            target = a[i + 1];
            if (dp[i] * 2 >= target) ans++;
            else break;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];
    solve();
    return 0;
}
