/**
 * Created by hiramekun at 12:08 on 2020-05-24.
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


/* ------------- ANSWER ------------- */
/* ---------------------------------- */
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

class Solution {
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MIN));
        dp[0][0] = 0;
        for (int i1 = 1; i1 <= n1; ++i1) {
            for (int i2 = 1; i2 <= n2; ++i2) {
                dp[i1][i2] = max(dp[i1][i2 - 1], dp[i1][i2]);
                dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2]);
                dp[i1][i2] = max(dp[i1][i2],
                                 max(0, dp[i1 - 1][i2 - 1]) + nums1[i1 - 1] * nums2[i2 - 1]);
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    vector<int> nums1{2, 1, -2, 5}, nums2{3, 0, -6};
    cout << Solution().maxDotProduct(nums1, nums2) << '\n';
}