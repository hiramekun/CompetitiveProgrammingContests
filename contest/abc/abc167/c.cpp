/**
 * Created by hiramekun at 20:39 on 2020-05-10.
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
    ll n, m, x;
    cin >> n >> m >> x;

    vl c(n);
    vvl a(n, vl(m));
    rep(i, n) {
        cin >> c[i];
        rep(j, m) {
            cin >> a[i][j];
        }
    }

    ll ans = ll_inf;
    rep(i, pow(2, n)) {
        ll tmp = 0;
        vl rikai(m);
        rep(j, n) {
            if (((i >> j) & 1) == 1) {
                // j番目を読む
                tmp += c[j];
                rep(l, m) {
                    rikai[l] += a[j][l];
                }
            }
        }
        bool b = false;
        rep(j, m) {
            if (rikai[j] < x) {
                b = true;
                break;
            }
        }
        if (!b) ans = min(ans, tmp);
    }
    if (ans == ll_inf) cout << -1 << '\n';
    else cout << ans << '\n';
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
