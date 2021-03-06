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
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int n, k;
vector<ll> h;

void solve() {
    ll dp[half_inf + k];
    rep(i, half_inf + k) dp[i] = inf;
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
        }
    }
    cout << dp[n - 1] << endl;
}

int main() {
    cin >> n >> k;
    h.resize(n);
    rep(i, n) cin >> h[i];
    solve();
    return 0;
}
