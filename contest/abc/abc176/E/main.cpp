#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<ll, ll>;
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

void solve() {
    ll h, w, m;
    cin >> h >> w >> m;
    ump<ll, ll> rows, cols;
    ump<ll, ll> rows2, cols2;
    vector<P> v(m);
    rep(i, m) {
        ll h1, w1;
        cin >> h1 >> w1;
        rows[h1]++, cols[w1]++;
        rows2[h1]++, cols2[w1]++;
        v[i] = P(h1, w1);
    }
    ll mx1 = 0;
    ll x;
    each(e, rows) {
        if (e.second > mx1) {
            mx1 = e.second;
            x = e.first;
        }
    }
    rep(i, m) {
        if (v[i].first == x) cols[v[i].second]--;
    }
    ll mx2 = 0;
    ll y;
    each(e, cols) {
        if (e.second > mx2) {
            mx2 = e.second;
            y = e.first;
        }
    }
    ll ans1 = mx1 + mx2;

    mx2 = 0;
    each(e, cols2) {
        if (e.second > mx2) {
            mx2 = e.second;
            y = e.first;
        }
    }
    rep(i, m) {
        if (v[i].second == y) rows2[v[i].first]--;
    }
    mx1 = 0;
    each(e, rows2) {
        if (e.second > mx1) {
            mx1 = e.second;
            x = e.first;
        }
    }
    ll ans2 = mx1 + mx2;

    cout << max(ans1, ans2) << '\n';
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
