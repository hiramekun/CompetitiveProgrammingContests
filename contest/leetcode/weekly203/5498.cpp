#ifdef MY_DEBUG
#include <bits/stdc++.h>
using namespace std;
#endif

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
class Solution {
public:
    int stoneGameV(vector<int> &stoneValue) {
        ll n = stoneValue.size();
        vector<ll> d(n + 1), dr(n + 1);
        // d[i+1] - d[i]: iのあたい
        // dr[i] - dr[i+1]: iのあたい
        rep(i, n) d[i + 1] = d[i] + stoneValue[i];
        for (ll i = n - 1; i >= 0; --i) {
            dr[i] = dr[i + 1] + stoneValue[i];
        }
        ll l = 0, r = n - 1;
        ll ans = 0;
        while (r - l >= 1) {
            pair<ll, P> valCntIdx = {0, {0, 0}};
            for (ll i = l; i <= r; ++i) {
                // iとi+1の間で切る
                ll left = d[i + 1] - d[l];
                ll right = dr[i + 1] - dr[r + 1];
                if (left < right) {
                    valCntIdx = max(valCntIdx, {left, {i - l + 1, i}});
                } else if (right < left) {
                    valCntIdx = max(valCntIdx, {right, {r - i, i}});
                } else {
                    valCntIdx = max(valCntIdx, {right, {max(i - l + 1, r - i), i}});
                }
            }
            ans += valCntIdx.first;
            ll left = d[valCntIdx.second.second + 1] - d[l];
            ll right = dr[valCntIdx.second.second + 1] - dr[r + 1];
            if (left < right) {
                r = valCntIdx.second.second;
            } else if (right < left) {
                l = valCntIdx.second.second + 1;
            } else {
                if (r - valCntIdx.second.second > valCntIdx.second.second - l + 1) {
                    l = valCntIdx.second.second + 1;
                } else {
                    r = valCntIdx.second.second;
                }
            }
        }
        return ans;
    }
};