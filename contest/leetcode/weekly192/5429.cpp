/**
 * Created by hiramekun at 11:37 on 2020-06-07.
 */
#ifdef MY_DEBUG

#include <bits/stdc++.h>

using namespace std;
#endif

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<ll, ll>;
template<typename T>
using pq = priority_queue<T>;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K>
using ump = unordered_map<T, K>;
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
class Solution {
public:
    vector<int> getStrongest(vector<int> &arr, int k) {
        sort(all(arr));
        ll mid = arr[(arr.size() - 1) / 2];
        minpq<pair<ll, ll>> pq;
        rep(i, arr.size()) {
            if (pq.empty() || pq.size() < k) pq.push(make_pair(abs(arr[i] - mid), arr[i]));
            else {
                P top = pq.top();
                P now = make_pair(abs(arr[i] - mid), arr[i]);
                if (now > top) {
                    pq.pop();
                    pq.push(now);
                }
            }
        }
        vector<int> ret;
        while(!pq.empty()) {
            ll top = pq.top().second;
            pq.pop();
            ret.eb(top);
        }
        return ret;
    }
};