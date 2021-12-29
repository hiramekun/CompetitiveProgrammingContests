#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
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
    string x;
    cin >> x;

    vl table(x.size());

    rep(i, min(ll(x.size()), ll(101))) {
        string sub = x.substr(0, i);
        rep(j, sub.size()) { table[j] += sub[sub.size() - j - 1] - '0'; }
    }
    cout << table << '\n';
    vl ans(x.size());
    reverse(all(table));
    rep(i, table.size()) {
        ll e = table[i];
        if (e >= 100) {
            if (ans.size() < i + 2) {
                rep(j, i + 2 - ans.size() + 1) reverse(all(ans));
                ans.eb(0);
                reverse(all(ans));
            }
            ans[i + 2] += e / 100;
            e %= 100;
        }
        if (e >= 10) {
            if (ans.size() < i + 1) {
                rep(j, i + 1 - ans.size() + 1) reverse(all(ans));
                ans.eb(0);
                reverse(all(ans));
            }
            ans[i + 1] += e / 10;
            e %= 10;
        }
        ans[i] += e;
        if (ans[i] >= 10) {
            if (ans.size() < i + 1) {
                rep(j, i + 1 - ans.size() + 1) reverse(all(ans));
                ans.eb(0);
                reverse(all(ans));
            }
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    cout << ans << '\n';
    reverse(all(ans));
    string strAns;
    each(e, ans) strAns += (e + '0');
    cout << strAns << '\n';
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
