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
    ll n;
    cin >> n;
    vl a(n + 1);
    cin >> a;
    vl ne_max(n + 1);
    rep(i, n + 1) {
        ll maxv;
        if (i > 50)
            maxv = ll_inf;
        else
            maxv = pow(2, i);
        if (i >= 1) {
            ne_max[i] = max(0LL, min(ne_max[i - 1] * 2 - a[i], maxv - a[i]));
        } else {
            ne_max[i] = max(0LL, maxv - a[i]);
        }
    }
    if (n == 0) {
        if (a[0] == 0)
            cout << 0 << '\n';
        else if (a[0] == 1)
            cout << 1 << '\n';
        else
            cout << -1 << '\n';
        return;
    }

    if (a.back() == 0) {
        cout << -1 << '\n';
        return;
    }
    ll now_v = a.back();
    ll ans = now_v;
    for (ll i = n - 1; i >= 0; --i) {
        if (now_v > ne_max[i] * 2) {
            cout << -1 << '\n';
            return;
        }
        now_v = min(ne_max[i] + a[i], now_v + a[i]);
        ans += now_v;
    }
    if (ans < 0) {
        cout << -1 << '\n';
    } else
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
