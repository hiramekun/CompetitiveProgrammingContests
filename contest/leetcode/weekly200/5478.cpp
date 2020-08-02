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
    int maxSum(vector<int> &nums1, vector<int> &nums2) {
        nums1.emplace_back(1e9), nums2.emplace_back(1e9);
        ll n1 = nums1.size(), n2 = nums2.size();
        ll i1 = 0, i2 = 0;
        ll ans = 0;
        ll now1 = 0, now2 = 0;
        while (i1 < n1 || i2 < n2) {
            if (nums1[i1] < nums2[i2]) {
                now1 += nums1[i1++];
            } else if (nums2[i2] < nums1[i1]) {
                now2 += nums2[i2++];
            } else {
                ans += max(now1, now2) + nums1[i1];
                now1 = now2 = 0;
                i1++, i2++;
            }
        }
        ans -= 1e9;
        ans %= mod;
        if (ans < 0) ans += mod;
        return ans;
    }
};