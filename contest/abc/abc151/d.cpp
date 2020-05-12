/**
 * Created by hiramekun at 01:18 on 2020-05-12.
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
    vector<string> s(h);
    rep(i, h) {
        cin >> s[i];
    }

    ll ans = 0;
    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == '#') continue;
            vector<vector<ll>> d(h, vector<ll>(w, ll_inf));
            d[i][j] = 0;

            ll tmp = 0;
            auto rec = [&](auto &&f, vector<P> &nxt) -> void {
                if (nxt.empty()) return;
                vector<P> nxt2;
                each(e, nxt) {
                    ll x = e.first, y = e.second;
                    rep(k, 4) {
                        ll nx = x + dx[k], ny = y + dy[k];
                        if (nx < 0 || h - 1 < nx || ny < 0 || w - 1 < ny) continue;
                        if (s[nx][ny] == '#' || d[nx][ny] < ll_inf) continue;
                        d[nx][ny] = d[x][y] + 1;
                        tmp = max(tmp, d[nx][ny]);
                        nxt2.emplace_back(make_pair(nx, ny));
                    }
                }
                f(f, nxt2);
            };
            vector<P> now{make_pair(i, j)};
            rec(rec, now);
            ans = max(ans, tmp);
        }
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
