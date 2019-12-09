/**
 * Created by hiramekun at 23:31 on 2019-10-22.
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
    ll n, c;
    cin >> n >> c;
    vl a(n - 1);
    vl b(n - 1);
    cin >> a;
    cin >> b;

    vl dp(n); // i階に行くまでの最小コスト

    bool prev_elav = false;
    rep(i, n - 1) {
        if (prev_elav) {
            if (a[i] < b[i]) {
                dp[i + 1] = dp[i] + a[i];
                prev_elav = false;
            } else {
                dp[i + 1] = dp[i] + b[i];
                prev_elav = true;
            }
        } else {
            if (a[i] < b[i] + c) {
                dp[i + 1] = dp[i] + a[i];
                prev_elav = false;
            } else {
                dp[i + 1] = dp[i] + b[i] + c;
                prev_elav = true;
            }
        }
    }
    cout << dp << '\n';
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
