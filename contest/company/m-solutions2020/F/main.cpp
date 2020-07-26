#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<ll, pair<ll, char>>;
template <typename T> using pq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for (ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for (auto &i : mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template <class T> ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}

template <class T> istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

template <class T> ostream &operator<<(ostream &out, const vector<vector<T>> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << '\n';
    return out;
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
bool compare_y(P a, P b) { return a.S < b.S; }

void solve() {
    ll n;
    cin >> n;

    P xy[n];
    rep(i, n) {
        ll x, y;
        char move;
        cin >> x >> y >> move;
        xy[i] = P{x, pair<ll, char>{y, move}};
    }

    auto rec = [&](auto &&f, P *a, ll n) -> ll {
        if (n <= 1) return ll_inf;
        ll m = n / 2;
        ll x = a[m].first;
        ll y = a[m].second.first;
        char mova = a[m].S.S;

        ll d = min(f(f, a, m), f(f, a + m, n - m));
        inplace_merge(a, a + m, a + n, compare_y);

        vector<pair<ll, ll>> b;
        rep(i, n) {
            char mov2 = a[i].S.S;
            ll x2 = a[i].F;
            ll y2 = a[i].S.F;
            if (mova == mov2) continue;
            if (mova == 'U') {
                if (mov2 == 'R') {
                    if (x > x2 && x - x2 == y - y2) {
                        if (x - x2 >= d) continue;
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dx);
                    }
                } else if (mov2 == 'L') {
                    if (x2 > x && x2 - x == y - y2) {
                        if (x2 - x >= d) continue;
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dx);
                    }
                } else if (mov2 == 'D') {
                    if (y > y2 && x == x2) {
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dy);
                    }
                }
            } else if (mova == 'D') {
                if (mov2 == 'R') {
                    if (x > x2 && x - x2 == y2 - y) {
                        if (x - x2 >= d) continue;
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dx);
                    }
                } else if (mov2 == 'L') {
                    if (x2 > x && x2 - x == y2 - y) {
                        if (x2 - x >= d) continue;
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dx);
                    }
                } else if (mov2 == 'U') {
                    if (y2 > y && x == x2) {
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dy);
                    }
                }
            } else if (mova == 'L') {
                if (mov2 == 'D') {
                    if (x > x2 && x - x2 == y - y2) {
                        if (x - x2 >= d) continue;
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dx);
                    }
                } else if (mov2 == 'U') {
                    if (x < x2 && x2 - x == y - y2) {
                        if (x2 - x >= d) continue;
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dx);
                    }
                } else if (mov2 == 'R') {
                    if (x > x2 && y == y2) {
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dx);
                    }
                }
            } else if (mova == 'R') {
                if (mov2 == 'D') {
                    if (x2 > x && x2 - x == y - y2) {
                        if (x2 - x >= d) continue;
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dx);
                    }
                } else if (mov2 == 'U') {
                    if (x2 < x && x - x2 == y - y2) {
                        if (x - x2 >= d) continue;
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dx);
                    }
                } else if (mov2 == 'L') {
                    if (x < x2 && y == y2) {
                    } else
                        continue;
                    rep(j, b.size()) {
                        ll dx = a[i].F - b[b.size() - j - 1].F;
                        ll dy = a[i].S.F - b[b.size() - j - 1].S;
                        if (dy >= d) break;
                        d = min(d, dx);
                    }
                }
            }
            b.emplace_back(a[i].F, a[i].S.F);
        }
        return d;
    };
    sort(xy, xy + n);
    ll ans = rec(rec, xy, n);
    if (ans == ll_inf)
        cout << "SAFE" << '\n';
    else
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
