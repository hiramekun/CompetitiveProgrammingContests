/**
 * Created by hiramekun at 20:44 on 2019-12-08.
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
    ll n;
    cin >> n;

    vl a(n);
    vvl xy(n, vl(n, -1));

    rep(i, n) {
        cin >> a[i];

        rep(j, a[i]) {
            ll x, y;
            cin >> x >> y;
            x--;
            xy[i][x] = y;
        }
    }
    ll ans = 0;
    rep(i, pow(2, n)) {
        vl tmp(n, -1); // 1:正直, -1:未定, 0:不親切決定
        bool out = false;
        rep(j, n) { // j番目の人
            if (1 & i >> j) { // 正直とする
                if (tmp[j] == 0) out = true;
                rep(l, n) {
                    if (xy[j][l] == -1) continue;
                    if (tmp[l] == -1) tmp[l] = xy[j][l];
                    else {
                        if (tmp[l] == xy[j][l]) continue;
                        else {
                            out = true;
                            break;
                        }
                    }
                }
            }
        }
        ll res = 0;
        rep(j, n) {
            if ((1 & i >> j) == 1 && tmp[j] == 0) break;
            if ((1 & i >> j) == 1 || tmp[j] == 1) {
                res++;
                rep(l, n) {
                    if (xy[j][l] == -1) continue;
                    if (tmp[l] == -1) tmp[l] = xy[j][l];
                    else {
                        if (tmp[l] == xy[j][l]) continue;
                        else {
                            out = true;
                            break;
                        }
                    }
                }
            }
        }
        if (out) continue;

        ans = max(ans, res);
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
