#ifdef MY_DEBUG
#include <bits/stdc++.h>
using namespace std;
#endif

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
class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<vector<pair<ll, bool>>> G(n);
        rep(i, connections.size()) {
            ll a, b;
            a = connections[i][0], b = connections[i][1];
            G[a].emplace_back(make_pair(b, true));
            G[b].emplace_back(make_pair(a, false));
        }

        vector<bool> seen(n);
        ll ans = 0;
        auto rec = [&](auto &&f, ll now) -> void {
            seen[now] = true;
            each(e, G[now]) {
                if (seen[e.F]) continue;
                if (!e.S)
                    f(f, e.F);
                else {
                    ans++;
                    f(f, e.F);
                }
            }
        };
        rec(rec, 0);
        return ans;
    }
};