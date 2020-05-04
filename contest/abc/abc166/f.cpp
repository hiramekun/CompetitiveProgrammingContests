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
    if (a > 2 * n) a = 2 * n;
    if (b > 2 * n) b = 2 * n;
    if (c > 2 * n) c = 2 * n;
    map<string, ll> mp;
    vector<string> ss;
    rep(i, n) {
        string s;
        cin >> s;
        ss.eb(s);
        mp[s]++;
    }
    ll ab_all = 0, ac_all = 0, bc_all = 0;
    ll ab_a_plus = 0, ac_a_plus = 0, bc_b_plus = 0;
    rep(i, n) {
        if (ss[i] == "AB") {
            ab_all++;
            if (b == 0) {
                b++, a--;
            } else {
                a++, b--;
                ab_a_plus++;
            }
            if (a < 0) {
                cout << "No" << '\n';
                return;
            }
        } else if (ss[i] == "AC") {
            ac_all++;
            if (c == 0) {
                c++, a--;
            } else {
                a++, c--;
                ac_a_plus++;
            }
            if (a < 0) {
                cout << "No" << '\n';
                return;
            }
        } else { // "BC"
            bc_all++;
            if (c == 0 && b == 0) {
                if (a > 0 && ab_a_plus > 0) ab_a_plus--, a--, b++;
                else if (a > 0 && ac_a_plus > 0) ac_a_plus--, a--, c++;
                else {
                    cout << "No" << '\n';
                    return;
                }
            }

            if (c == 0) {
                c++, b--;
            } else if (b == 0) {
                b++, c--;
                bc_b_plus++;
            } else {
                b++, c--;
            }
        }
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
