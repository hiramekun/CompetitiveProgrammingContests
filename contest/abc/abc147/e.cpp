/**
 * Created by hiramekun at 20:44 on 2019-12-08.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<ll, ll>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}

template<class T>
istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

template<class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << '\n';
    return out;
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */

void solve() {
    ll h, w;
    cin >> h >> w;
    int a[h][w], b[h][w];
    ll max_diff = 0;
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) {
            cin >> b[i][j];
            max_diff = max(max_diff, 2 * abs(a[i][j] - b[i][j]) * (h + w) + 10);
        }

    bool dp[h][w][max_diff];
    rep(i, h) rep(j, w) rep(l, max_diff) dp[i][j][l] = false;

    ll mid = max_diff / 2;
    dp[0][0][b[0][0] - a[0][0] + mid] = true;
    dp[0][0][-b[0][0] + a[0][0] + mid] = true;

    rep(i, h) {
        rep(j, w) {
            rep(l, max_diff) {
                if (dp[i][j][l]) {
                    if (i + 1 <= h - 1) {
                        dp[i + 1][j][l + b[i + 1][j] - a[i + 1][j]] = true;
                        dp[i + 1][j][l - b[i + 1][j] + a[i + 1][j]] = true;
                    }
                    if (j + 1 <= w - 1) {
                        dp[i][j + 1][l + b[i][j + 1] - a[i][j + 1]] = true;
                        dp[i][j + 1][l - b[i][j + 1] + a[i][j + 1]] = true;
                    }
                }
            }
        }
    }
    ll ans = ll_inf;
    rep(i, max_diff) {
        if (dp[h - 1][w - 1][i]) ans = min(ans, abs(i - mid));
    }
    cout << ans << '\n';
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        solve();
#ifdef MY_DEBUG
    }
#endif
    return 0;
}
