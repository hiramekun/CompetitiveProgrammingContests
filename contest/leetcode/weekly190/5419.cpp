/**
 * Created by hiramekun at 12:08 on 2020-05-24.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll ll_inf = ll(1e18);

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
        ll n1 = nums1.size(), n2 = nums2.size();
        vector<vector<ll>> dp(n1 + 1, vector<ll>(n2 + 1, -ll_inf));
        dp[0][0] = 0;
        for (ll i1 = 1; i1 <= n1; ++i1) {
            for (ll i2 = 1; i2 <= n2; ++i2) {
                dp[i1][i2] = max(dp[i1][i2 - 1], dp[i1][i2]);
                dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2]);
                dp[i1][i2] = max(dp[i1][i2],
                                 max(0LL, dp[i1 - 1][i2 - 1]) + nums1[i1 - 1] * nums2[i2 - 1]);
            }
        }

        return dp[n1][n2];
    }

};

int main() {
    vector<int> nums1{2, 1, -2, 5}, nums2{3, 0, -6};
    cout << Solution().maxDotProduct(nums1, nums2) << '\n';
}