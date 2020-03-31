/**
 * Created by hiramekun at 07:51 on 2020-03-31.
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
    char a[h][w];
    stack<P> q;
    bool used[h][w];
    rep(i, h) rep(j, w) used[i][j] = false;
    rep(i, h) rep(j, w) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                q.push(P(i, j));
                used[i][j] = true;
            }
        }
    ll ans = 0;
    while (!q.empty()) {
        stack<P> q2;
        q2 = q;
        q = stack<P>();
        bool plus = false;

        while (!q2.empty()) {
            P now = q2.top();
            q2.pop();
            ll x = now.F, y = now.S;
            rep(i, 4) {
                ll nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || h - 1 < nx || ny < 0 || w - 1 < ny) continue;
                if (!used[nx][ny]) {
                    if (!plus) ans++, plus = true;
                    used[nx][ny] = true;
                    q.push(P(nx, ny));
                }
            }
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
