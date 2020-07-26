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
    ll q, l;
    cin >> q >> l;
    vl ns, nums;
    ll cursize = 0;
    rep(_, q) {
        string op;
        cin >> op;
        if (op == "Push") {
            ll n, m;
            cin >> n >> m;
            ns.emplace_back(n);
            cursize += n;
            if (cursize > l) {
                cout << "FULL" << '\n';
                return;
            }
            nums.emplace_back(m);
        } else if (op == "Pop") {
            ll n;
            cin >> n;
            cursize -= n;
            while (n && !nums.empty()) {
                if (n >= ns.back()) {
                    n -= ns.back();
                    ns.pop_back();
                    nums.pop_back();
                } else {
                    ns.back() -= n;
                    n = 0;
                }
            }
            if (n) {
                cout << "EMPTY" << '\n';
                return;
            }
        } else if (op == "Top") {
            if (nums.empty()) {
                cout << "EMPTY" << '\n';
                return;
            } else {
                cout << nums.back() << '\n';
            }
        } else if (op == "Size") {
            cout << cursize << '\n';
        }
    }
    cout << "SAFE" << '\n';
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