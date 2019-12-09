/**
 * Created by hiramekun at 16:27 on 2019-10-03.
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

bool is_ore(char c) {
    if (c == '1' || c == '2') return false;
    return true;
}

void solve() {
    ll q;
    cin >> q;
    rep(_, q) {
        ll n;
        cin >> n;
        vector<string> a(2);
        cin >> a;

        P now = {0, 0};
        const ll L = 0, T = 1, U = 2;
        ll muki = L; // 0: 左から, 1: 上から, 2: 下から
        while (now.F != 1 || now.S != n) {
            ll i = now.F, j = now.S;
            if (i < 0 || 1 < i || j < 0 || n - 1 < j) {
                cout << "NO" << '\n';
                goto END;
            }
            switch (muki) {
                case L:
                    if (is_ore(a[i][j])) {
                        if (i == 0) now = {i + 1, j}, muki = T;
                        else now = {i - 1, j}, muki = U;

                    } else now = {i, j + 1}, muki = L;
                    break;
                case T:
                    if (is_ore(a[i][j])) now = {i, j + 1}, muki = L;
                    else now = {i + 1, j}, muki = T;
                    break;
                case U:
                    if (is_ore(a[i][j])) now = {i, j + 1}, muki = L;
                    else now = {i - 1, j}, muki = U;
                    break;
                default:
                    break;
            }
        }
        if (muki == L) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        END:;
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
