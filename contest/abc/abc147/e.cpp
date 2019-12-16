/**
 * created by hiramekun at 20:44 on 2019-12-08.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
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

int main() {
    ll h, w;
    cin >> h >> w;
    int a[h][w], b[h][w];
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) cin >> b[i][j];

    ll max_diff = 2 * 80 * 160;
    bool dp[h][w][max_diff];
    rep(i, h) rep(j, w) rep(l, max_diff) dp[i][j][l] = false;

    ll mid = max_diff / 2;
    dp[0][0][b[0][0] - a[0][0] + mid] = true;
    dp[0][0][-b[0][0] + a[0][0] + mid] = true;

    rep(i, h) {
        rep(j, w) {
            rep(l, max_diff) {
                if (!dp[i][j][l]) continue;
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
    ll ans = 1e18;
    rep(i, max_diff) {
        if (dp[h - 1][w - 1][i]) ans = min(ans, abs(i - mid));
    }
    cout << ans << '\n';
}
