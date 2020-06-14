/**
 * Created by hiramekun at 18:23 on 2020-06-14.
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
    ll x, y;
    ll n;
    cin >> x >> y >> n;
    vector<P> xy(n);
    rep(i, n) cin >> xy[i].F >> xy[i].S;
    double ans = ll_inf;
    for (ll i = 1; i < n + 1; ++i) {
        ll x1 = xy[i - 1].first, y1 = xy[i - 1].second;
        ll x2 = xy[i < n ? i : 0].first, y2 = xy[i < n ? i : 0].second;
        double s = 1 / 2.0 * abs((x1 - x) * (y2 - y) - (x2 - x) * (y1 - y));
        // teihen * len * 1/2 = s;
        double len = 2 * s / sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
        ans = min(ans, len);
    }
    cout << fixed << setprecision(10) << ans << endl;
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
