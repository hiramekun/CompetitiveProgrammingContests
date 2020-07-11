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
    ll h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> c(h, vector<char>(w));
    ll all_cnt = 0;
    rep(i, h) rep(j, w) {
        cin >> c[i][j];
        if (c[i][j] == '#') all_cnt++;
    }

    ll ans = 0;
    vector<vector<bool>> paint(h + 1, vector<bool>(w + 1));
    auto rec = [&](auto &&f, ll ih, ll iw, bool next_paint) -> void {
      if (next_paint) paint[ih][iw] = true;
      if (ih == h-1 && iw == w-1) {
            ll tmp = all_cnt;
            rep(i, h) rep(j, w) if (paint[i][j]) tmp--;
            if (tmp == k) ans++;
            paint[ih][iw] = false;
            return;
        }
        if (ih == h-1) {
            f(f, ih, iw + 1, true);
            f(f, ih, iw + 1, false);
        } else {
            f(f, ih + 1, iw, true);
            f(f, ih + 1, iw, false);
        }
        paint[ih][iw] = false;
    };
    rec(rec, 0, 0, true);
    rec(rec, 0, 0, false);

    //    rep(h_bt, pow(2, h)) {
    //        rep(w_bt, pow(2, w)) {
    //            ll cnt = all_cnt;
    //            rep(i, h) {
    //                rep(j, w) {
    //                    if ((1 & h_bt >> i) == 1 || (1 & w_bt >> j) == 1) {
    //                        if (c[i][j] == '#') cnt--;
    //                    }
    //                }
    //            }
    //            if (cnt == k) ans++;
    //        }
    //    }
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
