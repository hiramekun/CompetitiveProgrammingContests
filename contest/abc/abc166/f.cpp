/**
 * Created by hiramekun at 21:38 on 2020-05-03.
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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<string> ans;
    auto rec = [&](auto &&f, ll idx, ll a_p, ll b_p, ll c_p) -> bool {
        if (idx == n) return true;
        string now = s[idx];
        if (now == "AB") {
            if (a_p > 0 && f(f, idx + 1, a_p - 1, b_p + 1, c_p)) {
                ans.eb("B");
                return true;
            }
            if (b_p > 0 && f(f, idx + 1, a_p + 1, b_p - 1, c_p)) {
                ans.eb("A");
                return true;
            }
            if (!ans.empty()) ans.pop_back();
            return false;
        } else if (now == "AC") {
            if (a_p > 0 && f(f, idx + 1, a_p - 1, b_p, c_p + 1)) {
                ans.eb("C");
                return true;
            }
            if (c_p > 0 && f(f, idx + 1, a_p + 1, b_p, c_p - 1)) {
                ans.eb("A");
                return true;
            }
            if (!ans.empty()) ans.pop_back();
            return false;
        } else { // now == "BC"
            if (b_p > 0 && f(f, idx + 1, a_p, b_p - 1, c_p + 1)) {
                ans.eb("C");
                return true;
            }
            if (c_p > 0 && f(f, idx + 1, a_p, b_p + 1, c_p - 1)) {
                ans.eb("B");
                return true;
            }
            if (!ans.empty()) ans.pop_back();
            return false;
        }
    };
    if (rec(rec, 0, a, b, c)) {
        cout << "Yes" << '\n';
        reverse(all(ans));
        cout << ans << '\n';
    } else {
        cout << "No" << '\n';
    }
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
